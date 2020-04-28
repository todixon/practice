# estimate pi
import random

def estimate_pi(n):

    inside_circle = 0

    for i in range(0,n):
        # generate random coordinates between 0 and 1
        x = random.uniform(0,1)
        y = random.uniform(0,1)

        if (x**2 + y**2) < 1:
            inside_circle += 1
    
    print(4 * inside_circle / n)

estimate_pi(1000)
estimate_pi(1000000)
