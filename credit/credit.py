def credit():
    # prompt user for card number
    while True:
        number = input("Number: ")
        if number.isalpha() == False and number != '' and ('-' not in number):
            break

    n = len(number)

    # check validity in terms of format
    if (n == 15) and (number[0:2] in ['34', '37']):
        name = "AMEX"
    elif (n == 16) and (number[0:2] in ['51', '52', '53', '54', '55']):
        name = "MASTERCARD"
    elif (n in [13, 16]) and(number[0] == '4'):
        name = "VISA"
    else:
        return "INVALID"

    # multiply every other digit by 2 and convert the digits into a single string
    prod = ''.join([str(2*int(i)) for i in number[-2::-2]])

    # add product digits and then add the remaining digits
    endsum = sum(int(i) for i in prod) + sum(int(i) for i in number[-1::-2])

    # validate modulo 10
    if endsum % 10 == 0:
        return name

    else:
        return "INVALID"


print(credit())

