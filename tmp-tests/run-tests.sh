#!/bin/sh
# set -x # verbose
# set -e # exit on error

# define text-colors
green='\033[0;32m'
red='\033[0;31m'
NC='\033[0m' # No Color

mkdir arch
cp -r ../arch/* arch/
cp ../functions.lib .
cp ../macros.h .

failed=0
passed=0
total=0


dir="tmp-tests"

for f in *.scm;
do 
	if [[ $f != pre.scm && $f != post.scm && $f != petite* ]]; then # only files that are not pre.scm post.scm and doesn't contain the prefix petite
		echo "###################################################"
		total=$[total+1]
		echo "Testing $f..."
		cat pre.scm $f post.scm > "petite-$f" # create file to be run with petite
		petite --script "petite-$f" > "petite-$f.out" 

		pushd .. >> /dev/null
		petite --script compile.scm "$dir/$f" "$dir/$f".c
		popd >> /dev/null
		executable=$(echo "$f" | cut -d"." -f1)

		# echo "Executing GCC"
		gcc -o "$executable" "$f.c"

		# echo "Running the executable"
		./"$executable" > "$f.out"

		# echo "Deleteing the executable and compiled file"
		rm -rf "$executable" "$f.c"

		if cmp -s "petite-$f.out" "$f.out"; then
		    # files are the same
			echo "${green}"
		    echo "**********************"
		    echo "* Test for $f passed *"
		    echo "**********************"
			echo "${NC}"
		    passed=$[passed+1]
		else
		    # files are different
			echo "${red}"
		    echo "**********************"
		    echo "* Test for $f FAILED *"
		    echo "Expected:"
		    cat "petite-$f.out"
		    echo "But got:"
		    cat "$f.out"
		    echo "**********************"
		    failed=$[failed+1]
			echo "${NC}"

		fi
		echo "###################################################"
	fi
done

echo "removig temporary files"
rm -rf arch macros.h functions.lib

echo "removig created files..."
rm -rf petite*

echo "removig output files"
rm -rf *.out

echo "Total passed tests: $passed"
echo "Total failed tests: $failed"
echo "Total tests: $total"
exit $failed
