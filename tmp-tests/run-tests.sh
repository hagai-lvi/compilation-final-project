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

bold=`tput bold`
smul=`tput smul`
normal=`tput sgr0`

# import the rellevant files from the compiler dir
mkdir arch
cp -r ../arch/* arch/
cp ../functions.lib .
cp ../macros.h .

# counters
failed=0
passed=0
total=0


dir="tmp-tests"

for f in *.scm;
do 
	if [[ $f != pre.scm && $f != post.scm && $f != petite* ]]; then # only files that are not pre.scm post.scm and doesn't contain the prefix petite
		total=$[total+1]
		echo "${bold}${smul}*** Testing $f... ***${normal}"

		should_delete=false # delete only if the script created files

		# If outputfile doesn't exist
		if ! [[ -e "petite-$f.out" ]]; then
			$verbose && echo "Output file already exist, skipping running with petite"
			cat pre.scm $f post.scm > "petite-$f" # create file to be run with petite
			petite --script "petite-$f" > "petite-$f.out" # run in petite and save the output
			should_delete=true
		fi 

		# compile with our compiler
		pushd .. >> /dev/null
		petite --script compile.scm "$dir/$f" "$dir/$f.c"
		popd >> /dev/null

		executable=$(echo "$f" | cut -d"." -f1)

		$verbose && echo "Executing GCC"
		# compile using GCC
		gcc -o "$executable" "$f.c"

		$verbose && echo "Running the executable"
		./"$executable" > "$f.out"

		$verbose && echo "Deleteing the executable and compiled file"
		rm -rf "$executable" "$f.c"

		# outputs of our compiler matches expected output
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

		# if we have created petite file and outputfile
		if [[ "$should_delete" = true ]]; then
			$verbose && echo "Deleting petite file and outfile"
			rm -rf "petite-$f" "petite-$f.out"
		fi

		$verbose && echo "Deleting c output file"
		rm -rf "$f.out"
		echo "${passed}/${total} passed"
	fi
done

$verbose && echo "removig temporary files"
rm -rf arch macros.h functions.lib

# $verbose && echo "removig created files..."
# rm -rf petite*

# $verbose && echo "removig output files"
# rm -rf *.out

echo "Total passed tests: $passed"
echo "Total failed tests: $failed"
echo "Total tests: $total"
exit $failed
