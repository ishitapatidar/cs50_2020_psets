def factorial(n):
    fact=1
    for i in range(1,n+1):
        fact=fact*i
    return fact
n=int(input("enter no.: "))
print("the factorial is: ", factorial(n))
