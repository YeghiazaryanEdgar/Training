import argparse
import time
t0 = time.time()


def longestWord(seqWords):
    print("The Longest subsequence is: {}".format(max(seqWords, key=len)))


def subsequenceWords(S, D):

    seqWords = []

    for word in D:
        if len(word) > len(S):
            continue
        index = 0
        for letter in word:
            if S.find(letter, index) == -1:
                break
            else:
                index = S.find(letter) + 1
        else:
            seqWords.append(word)

    if len(seqWords) == 0:
        print("There is no any words!")
    else:
        longestWord(seqWords)


def main():
    parser = argparse.ArgumentParser(description='Process some words')
    parser.add_argument('string')
    parser.add_argument('words', nargs='+')
    args = parser.parse_args()
    S, D = args.string, set(args.words)
    subsequenceWords(S, D)

if __name__ == '__main__':
    main()



t1 = time.time()
print('Total time: {}'.format(t1 - t0))


# Optimazation
# Set's some elements length is longer
# Comments






