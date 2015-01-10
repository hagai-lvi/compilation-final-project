#!/bin/sh
# set -x # verbose
# set -e # exit on error

verbose=false

while getopts "v" OPTION
do
  case $OPTION in
    v) verbose=true
       ;;
  esac
done

# define text-colors
red=$'\e[1;31m'
green=$'\e[1;32m'
end=$'\e[0m'

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
		total=$[total+1]
		echo "Testing $f..."
		cat pre.scm $f post.scm > "petite-$f" # create file to be run with petite
		petite --script "petite-$f" > "petite-$f.out" 

		pushd .. >> /dev/null
		petite --script compile.scm "$dir/$f" "$dir/$f".c
		popd >> /dev/null
		executable=$(echo "$f" | cut -d"." -f1)

		$verbose && echo "Executing GCC"
		gcc -o "$executable" "$f.c"

		$verbose && echo "Running the executable"
		./"$executable" > "$f.out"

		$verbose && echo "Deleteing the executable and compiled file"
		rm -rf "$executable" "$f.c"

		if cmp -s "petite-$f.out" "$f.out"; then
		    # files are the same
			printf ${green}
		    echo "**********************"
		    echo "* Test for $f passed *"
		    echo "**********************"
		    printf $end
		    passed=$[passed+1]
		else
		    # files are different
			printf ${red}
		    echo "**********************"
		    echo "* Test for $f FAILED *"
		    echo "Expected:"
		    cat "petite-$f.out"
		    echo "But got:"
		    cat "$f.out"
		    echo "**********************"
		    failed=$[failed+1]
			printf $end

		fi
	fi
done

$verbose && echo "removig temporary files"
rm -rf arch macros.h functions.lib

$verbose && echo "removig created files..."
rm -rf petite*

$verbose && echo "removig output files"
rm -rf *.out

echo "Total passed tests: $passed"
echo "Total failed tests: $failed"
echo "Total tests: $total"
exit $failed
