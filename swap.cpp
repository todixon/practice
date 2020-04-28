#include <iostream>

void swap(int &a, int &b)
{
    int c = 0;
    c = a;
    a = b;
    b = c;
}

// avoids third temporary variable
void swap2(int &a, int &b)
{
    a = a+b;
    b = a-b;    //b now has original value of a
    a = a-b;    //a now has original value of b
}

int main()
{
    int s1 = 3;
    int s2 = 4;
    
    std::cout << s1 << "\t" << s2 <<std::endl;
    
    swap(s1,s2);
    
    std::cout << s1 << "\t" << s2 <<std::endl;
    
    swap2(s1, s2);
    
    std::cout << s1 << "\t" << s2 <<std::endl;
}
