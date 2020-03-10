import cs50


# prompt user for text
while True:
    s = cs50.get_string("Text: ")
    # validity check
    if s != "":
        break


letters, words, sentences = 0, 0, 0
# count letters
for i in s:
    if i in [".", "?", "!"]:
        sentences += 1
    elif i == " ":
        words += 1
    elif i.isalpha() == True:
        letters += 1


# for the last word
words += 1

l = (letters / words) * 100
s = (sentences / words) * 100

index = 0.0588 * l - 0.296 * s - 15.8

index = round(index)

if index > 16:
    print("Grade 16+")

elif index < 1:
    print("Before Grade 1")

else:
    print("Grade ", index)
