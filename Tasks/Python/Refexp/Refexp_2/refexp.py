#!/usr/bin/env python3
import re

randWords = open("diff_words.txt", "r")

content = randWords.read()



wordList = re.sub("[^\w]", " ",  content).split()

capitalWords = []

for word in wordList:
    if(word[0].isupper()):
        capitalWords.append(word)


print(capitalWords)
