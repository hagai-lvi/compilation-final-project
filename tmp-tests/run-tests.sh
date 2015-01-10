#!/bin/sh
# set -x # verbose
# set -e # exit on error

mkdir arch
cp -r ../arch/* arch/
cp ../functions.lib .
cp ../macros.h .


dir="tmp-tests"

for f in *.scm;
do 
	if [[ $f != pre.scm && $f != post.scm && $f != petite* ]]; then # only files that are not pre.scm post.scm and doesn't contain the prefix petite
		echo "###################################################"
		echo "Testing $f..."
		cat pre.scm $f post.scm > "petite-$f" # create file to be run with petite
		petite --script "petite-$f" > "petite-$f.out" 

		pushd .. >> /dev/null
		petite --script compile.scm "$dir/$f" "$dir/$f".c
		popd >> /dev/null
		executable=$(echo "$f" | cut -d"." -f1)

		echo "Executing GCC"
		gcc -o "$executable" "$f.c"

		echo "Running the executable"
		./"$executable" > "$f.out"

		echo "Deleteing the executable and compiled file"
		rm -rf "$executable" "$f.c"

		if cmp -s "petite-$f.out" "$f.out"; then
		    # files are the same
		    echo
		    echo "**********************"
		    echo "* Test for $f passed *"
		    echo "**********************"
		    echo
		else
		    # files are different
		    echo
		    echo "**********************"
		    echo "* Test for $f FAILED *"
		    echo "**********************"
		    echo
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
