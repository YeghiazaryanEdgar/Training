#!/usr/bin/env python3

set1 = set(line.strip() for line in open('some_numbers_1'))
set2 = set(line.strip() for line in open('some_numbers_2'))

set3 = set1 & set2

f = open('overlap_numbers', 'a')

for item1 in set3:
    f.write("%s\n" % item1)

f.close()
