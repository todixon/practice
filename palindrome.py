# check to see if palindrome

a = input("enter sequence ")
# reverses inputted string and saves to b
b=a[::-1]

if a==b:
    print("palindrome")
else:
    print("not a palindrome")
    