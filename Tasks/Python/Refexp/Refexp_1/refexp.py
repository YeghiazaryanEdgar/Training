#!/usr/bin/env python3
import re

pattern = re.compile(r'\b[A-Z]+[a-zA-Z]*\b')

with open('diff_words.txt', 'r', encoding='utf-8') as f:
	contents = f.read()
	matches = pattern.finditer(contents)

uppercaseWords = []

for match in matches:
       uppercaseWords.append(match.group(0))

print(uppercaseWords)


