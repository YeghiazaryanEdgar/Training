#!/usr/bin/env python3

def initList():
    
    while True:
        try:
            theLength = int(input("Enter the length - "))
            if(theLength < 0):
                 raise ValueError("Cannot br < 0")
            break
        except (ValueError) as err:
            print(err)

    while True:
        try:
            givenNumbers = [int(x) for x in input("Input the elements - ").split()]
            if (theLength != len(givenNumbers)):
                raise ValueError("Arguments are too much")
            else:
                return givenNumbers
        except (ValueError) as arr:
            print(arr)

def enterIndexForList(len):

    while True:
        try:
            theIndex = int(input("Enter the Index - "))
            if (theIndex >= len):
                raise ValueError("Too Big index value")
        except (ValueError) as arr:
            print(arr)
        else:
            return theIndex

def mainFunc():
    givenNumbers = initList()
    givenIndex = enterIndexForList(len(givenNumbers))

    if (givenNumbers[givenIndex] > givenNumbers[-givenIndex]):
        givenIndex = -givenIndex

    for i in range(0, len(givenNumbers)):
        givenNumbers[i] = givenNumbers[givenIndex]

    print(givenNumbers)



mainFunc()
