#include <iostream>

int main()
{
    for(int i = 0; i<100; i++) {
        if(i % 15 == 0) {
            std::cout << "FizzBuzz" << std::endl;
        } else if(i % 3 == 0) {
            std::cout << "Fizz" << std::endl;
        } else if(i % 5 == 0) {
            std::cout << "Buzz" << std::endl;
        } else {
            std::cout << i << std::endl;
        }
    }
}
