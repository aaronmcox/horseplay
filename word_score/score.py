
import sys

def score_word(word):
    sum = 0

    for letter in word:
        sum += ord(letter) - 96

    return sum


for word in sys.stdin:
    word = word.strip().lower()

    score = score_word(word)

    print(word, score)

