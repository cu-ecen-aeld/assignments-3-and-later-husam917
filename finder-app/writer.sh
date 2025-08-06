#!/bin/sh

if [ $# -lt 2 ]
then

  echo Not enough arguments!
  exit 1 

else
  writefile=$1
  writestr=$2
  
  
  writedir=$(dirname "$writefile")
  
  mkdir -p "$writedir"
  if [ $? -ne 0 ]; then
    echo error: Failed to create directory path
    exit 1
#  else
#    echo path created $writedir
  fi


  echo $writestr > $writefile
  if [ $? -ne 0 ]; then
    echo error: Failed to write to file
    exit 1
#  else
#    echo data $writestr writtten to $writefile
  fi
fi
