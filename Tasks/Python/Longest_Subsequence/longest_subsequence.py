import argparse

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('-l', '--list', nargs='+', required=True)
    for _, value in parser.parse_args()._get_kwargs():
        if value is not None:
            someWords = value

S = someWords.pop(0)
print(S)
someWords = set(someWords)
print(someWords)

appropWord = []


def getApprWords(S, someWords):

    if S.find(" ") != -1:
        print("Haven't found enything")
    else:
        for word_i in someWords:
            index = 0
            for i in word_i:
                index = S.find(i, index)
                if index == -1:
                    break
            else:
                appropWord.append(word_i)


def longestWord(someWords):
    return max(someWords, key=len)


getApprWords(S, someWords)



if len(appropWord) == 0:
    print("There is no any word!")
else:
    print('The longest word is {}'.format(longestWord(appropWord)))


# Optimazation
  # Set's some elements length is longer
# Comments
# Set's element doesn't contain eny spaces





