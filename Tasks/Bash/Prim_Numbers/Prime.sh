#!/bin/bash

for i in {60000..63000}
do
  m=$(echo "sqrt($i)" | bc -l)
  k=${m%.*}
  isPrime=1

  for ((j=2; j<$k; j++))
  do 
     if (( $i % $j == 0 ))
     then
       isPrime=0
       break
     fi   
  done

  if [ $isPrime -eq 1 ]
  then 
    echo $i
  fi
done
