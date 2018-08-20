#!/usr/bin/env bash

if [ ! -f $1 ]
then
    echo "File not found!"
else

c=1
lineCount=$(sed -n '$=' $1)

while [ $c -le $lineCount ]
do
  nthLine=$(sed "$c q;d" $1)
  echo $nthLine>>f2
  for (( i=0; i<2; i++ ))
  do
   echo "">>f2
  done
  ((c++))
done

fi




