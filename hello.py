# This program says hello and asks for my name

print('Hello world!')
print('What is your name?') # ask for their name
myName = input()

print('It is good to meet you, ' + myName)

print('the length of your name is:')
print(len(myName))

print('What is your age?')
myAge = int(input())

print('You will be ' + str(int(myAge) + 1) + ' in a year.')

if myName == 'Alice':
    print('Hi Alice')
elif myAge < 12:
    print('You are not Alice, kiddo')
else:
    print('You are neither Alice nor a little kid')