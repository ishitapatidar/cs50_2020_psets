from cs50 import get_string
import sys

# prompt key
if len(sys.argv) != 2:
    print("Usage:python caesar.py k")
    sys.exit(1)

k = int(sys.argv[1])

# prompt plaintext
p = get_string('Plaintext: ')
cipher = ''
# encipher
# for every character in plaintext
for i in p:

    # check if Alpha
    if i.isalpha() == True:

        # check if upper
        if i.isupper() == True:
            # set alphabet to A
            alpha = 'A'
        else:
            # set alphabet to a
            alpha = 'a'

        # subtract ascii of Alphabet from ascii of char,apply formula ,add ascii Alphabet
        c = chr((((ord(i) - ord(alpha)) + k) % 26) + ord(alpha))
        i = c

    # final string+charcter
    cipher += i

# print ciphertext
print('ciphertext: ' + cipher)

