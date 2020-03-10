# prompt for the number
while True:
    n = input("Height: ")

    if (n.isalpha() == False and n != ""):
        n = int(n)
        if (n > 0 and n < 9):
            break

# use loop for rows
for i in range(n):
    # use loop for space
    for space in range(n - (i + 1)):
        print(" ", end="")

    # use loop for block
    for block in range(i + 1):
        print("#", end="")
    print("")
