#!/usr/bin/env bash

function checkParam () {
   let x=$1           #When $1 value is string type is converts to 0  ;)
   if [ $x -eq 0 ] 
   then 
     return 1
   fi
     return 0
}
 
	
if [ $# -eq 1 ] 
then
    checkParam $1
    if [ $? -eq 1 ]
    then 
      echo "That's a string"
    else
      echo "That's a number"
    fi
else
    echo "Too few or too much of parameter!"
fi





