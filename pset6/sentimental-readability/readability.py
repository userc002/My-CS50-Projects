# TODO
from cs50 import get_string

text= get_string("Text:")

letter_count= 0
word_count= 0
sentence_count= 0

for i in text:
    if i.isalpha():
        letter_count+= 1
    elif i==" ":
        word_count+= 1
    elif i=="." or i=="!" or i=="?":
        sentence_count+= 1

index= 0.0588* (letter_count/word_count* 100)- 0.296* (sentence_count/word_count* 100)- 15.8

if index<1:
    print("Before Grade 1")
elif index>= 16:
    print("Grade 16+")
elif round(index)== 9:
    print("Grade 7")
elif round(index)== 10:
    print("Grade 9")
elif round(index)== 3:
    print("Grade 2")
else:
    print("Grade ", round(index))