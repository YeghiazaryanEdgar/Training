#!/usr/bin/env bash

x=1
lineCount=$(sed -n '$=' f2)
kk=$lineCount

while true
do
  nth=$(sed "$x q;d" f2)
  if [ ${#nth} -eq 0 ]
  then
    sed -i "$x d" f2
    ((kk--))
  else
    ((x++))
  fi
  
  if [ $x -eq $kk ] 
  then
    break
  fi
done



 
