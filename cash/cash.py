from cs50 import get_float
# prompt user for change owed
while True:
    change = get_float("Change owed: ")
    if change > 0.00:
        break

# convert it into cents
change *= 100
change = int(round(change, 0))


# keep track of no. of coins used
coins = 0

# use the largest coin possible
if change >= 25:
    coins += change//25
    change %= 25

if change >= 10:
    coins += change//10
    change %= 10

if change >= 5:
    coins += change//5
    change %= 5

if change >= 1:
    coins += change

# print final no.
print(coins)
