import random

print('My name is')
for i in range(0,10,2):
    print('Jimmy Five Times (' + str(i) + ')')

total = 0
for num in range(95,101):
    total = total + num
print(total)

for i in range(5):
    print(random.randint(1,10))