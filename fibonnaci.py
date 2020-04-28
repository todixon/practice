def get_fib_naive(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        return get_fib_naive(n-1) + get_fib_naive(n-2)

def get_fib_iterative(n):
    prevprev, prev = 0, 0
    current = 1
    for _ in range(1,n):
        prevprev = prev
        prev = current
        current = prevprev + prev
    return current

def get_fib_memoized(n):
    memo = {}
    if n in memo:
        return memo[n]
    else:
        memo[n] = get_fib_naive(n)
        return memo[n]

for i in range(0,40):
    #print("naive method: {} iterative method: {} memoized method: {} ".format(get_fib_naive(i), get_fib_iterative(i), get_fib_memoized(i)))
    print("fib_naive({}) = {}".format(i, get_fib_naive(i)))
    print("fib_iterative({}) = {}".format(i, get_fib_iterative(i)))
    print("fib_memoized({}) = {}".format(i, get_fib_memoized(i)))
 
