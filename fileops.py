f = open('./some_file.txt','r')
file_data = f.read()
print(file_data)
f.close()

f = open('./some_file.txt','w')
f.write("Hello there!")
f.close()

f = open('./some_file.txt','r')
file_data = f.read()
print(file_data)
f.close()

files = []
for i in range(10000):
    files.append(open('some_file.txt','r'))
    print(i)