#!/bin/sh
if [ "$#" -ne 2 ]; then
  echo "Usage: $0 <input-file> <output-file>"
  exit 1
fi

inputfile=$1
outputfile=$2

output=$(echo $outputfile | cut -d"." -f1)

petite --script compile.scm $inputfile $outputfile

gcc -o $output -g $outputfile

echo "Executable file is $output"
