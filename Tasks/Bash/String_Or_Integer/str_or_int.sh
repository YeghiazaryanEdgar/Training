#!/usr/bin/env bash

function strOrInt 
{
  if [[ "$1" =~ ^[0-9]+$ ]]
  then	  
     return 0
  else
     return 1
  fi
}       

strOrInt $1

echo $?

