#include <iostream>

const int N = 20;
// recursive example
int fib1(int n)
{
    if (n <= 2) {
        return 1;
    } else {
        return (fib1(n-1) + fib1(n-2));
    }
}


// iterative example w/dynamic programming
int fib2(int n)
{
    int f[n+1];
    f[1] = f[2] = 1;
    for(int i = 3; i<=n; i++) {
        f[i] = f[i-1] + f[i-2];
    }
    return f[n];
}

// iterative only storing last two fib
int fib3(int n)
{
    int a = 1, b = 1;
    for(int i = 3; i <= n; i++) {
        int c = a + b;
        a = b;
        b = c;
    }
    return b;
}
int main()
{
    for(int i=1; i <= N; i++) {
        std::cout << i << t" <<fib1(i) << "\t" <<fib2(i) << "\t" << fib3(i) <<std::endl;
    }
}
