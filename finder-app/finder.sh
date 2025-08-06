#!/bin/sh

if [ $# -lt 2 ]
then

  echo Not enough arguments!
  exit 1 
elif [ ! $d $1 ]
then
  echo Not a valid folder!
  exit 1
else
  filesdir=$1
  searchstr=$2
  NumOfFiles=$(ls -R -p $filesdir | grep -v / | wc -l)
  NumOfLines=$(grep -r "$searchstr" "$filesdir" 2>/dev/null | wc -l)
#  echo $(grep -r "$searchstr" "$filesdir" )
#  echo
#  echo $(ls -R -p $filesdir | grep -v / )
3  echo $NumOfFiles
  echo The number of files are $NumOfFiles and the number of matching lines are $NumOfLines
fi
