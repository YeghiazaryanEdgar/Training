#!/usr/bin/env bash

# Generates code with 8 characters

init=0

for (( ; ; )) 
do

s=""

for value in {1..8}  # Generates and concatenate 8 symbols from alph file
do
   x=$(( 1 + $RANDOM % 62 ))
   d=$(sed "$x q;d" alph)
   s+="$d"
done

for(( i=1; i<=8; i++ ))  # Numbers count in the code
do
   if [[ "$(echo "$s" | head -c $i | tail -c 1)" =~ ^[0-9]+$ ]]
   then
      ((init++))
   fi   
done

if [ $init -ge 2 ] 
then
   echo $s
   break
fi

done






