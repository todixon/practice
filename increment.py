# increment number by one without using +

def increment(i):
    i = -(~ord(i))
    return chr(i)

n = 'a'
print(increment(n))    