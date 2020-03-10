# prompt for height
while True:
    n = input("Height: ")
    if n.isalpha() == False and n != '':
        n = int(n)
        if n > 0 and n < 9:
            break

# loop for height
for i in range(n):
    # loop for space
    for space in range(n - (i + 1)):
        print(" ", end="")
    # loop for block
    for j in range(i + 1):
        print("#", end="")
    # spacce
    print("  ", end="")
    # loop for block
    for k in range(i + 1):
        print("#", end="")

    print("")
