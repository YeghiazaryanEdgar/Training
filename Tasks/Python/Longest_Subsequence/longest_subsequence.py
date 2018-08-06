#!/usr/bin/env python3

import argparse
import time
t0 = time.time()


def is_subseq(S, word):   # S: A string, word: A word from D
    index = 0
    for letter in word:
        if S.find(letter, index) == -1:
            return 0
        else:
            index = S.find(letter, index) + 1
    else:
        return 1


def longest_subseqs(S, D):   # S: A string, D: A list of words
    seqWords = []

    for word in D:
        if len(word) > len(S):
            continue
        if is_subseq(S, word):
            seqWords.append(word)

    if len(seqWords):  # Finds all longest subsequences with the same length
        return [w for w in seqWords if len(w) == len(max(seqWords, key=len))]
    return 0

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('-t', '--Text', nargs='+', help='The Text')
    parser.add_argument('-w', '--Words', nargs='+', help='Some words')
    args = parser.parse_args()
       # Example: -t word1 word2word3... -w word1 word2word3...

    S, D = ' '.join(args.Text), set(args.Words)

    print(longest_subseqs(S, D))

if __name__ == '__main__':
    main()


t1 = time.time()
print('Total time: {}'.format(t1 - t0))







