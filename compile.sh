#!/bin/sh
if [ "$#" -ne 2 ]; then
  echo "Usage: $0 <input-file> <output-file>"
  exit 1
fi

inputfile=$1
outputfile=$2

petite --script compile.scm $inputfile $outputfile

gcc -o outputfile.run -g $outputfile 
