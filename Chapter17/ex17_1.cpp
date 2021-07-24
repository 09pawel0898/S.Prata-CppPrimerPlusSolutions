#include "ex17_1.h"

void ex1(void)
{
    int count = 0;
    char c;

    std::cout << "Enter data : \n";
    while ((c = std::cin.get()) != '$')
    {
        count++;
        std::cout << c;
    }
    std::cin.putback(c);
    std::cout << "\nCount : " << count;
}
