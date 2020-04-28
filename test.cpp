// A simple C++ program for implementation of atoi
//#include <stdio>
#include <iostream>

// A simple atoi() function
int myAtoi(char *str)
{
    int res = 0; // Initialize result
    
    // Iterate through all characters of input string and
    // update result
    for (int i = 0; str[i] != '\0'; i++)
        res = res*10 + str[i] - '0';
    
    // return result.
    return res;
}

// Driver program to test above function
int main()
{
    char str[] = "89789";
    int val = myAtoi(str);
    printf ("%d ", val);
    std::cout << val <<std::endl;
    return 0;
}

