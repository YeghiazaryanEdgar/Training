#!/usr/bin/env python3

def add(x, y):
    return x + y

def sub(x, y):
   return  x - y

def mult(x, y):
    return x * y

def div(x, y):
    if y == 0:
        raise ValueError('Can not divide by zero!')
    return x / y

