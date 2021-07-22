#include "includes.h"

#ifndef EX16_5_H
#define EX16_5_H


/* ------- ex 5 -------*/

void ex5(void);

template <typename T>
void showArray(T ar[], int n)
{
    if (std::is_same<T, long>() || std::is_same<T, int>() || std::is_same<T, double>() || std::is_same<T, std::string>() || std::is_same<T, float>() || std::is_same<T, char>())
        std::copy(ar, ar + n, std::ostream_iterator<T, char>(std::cout, " "));
    else
        std::cerr << "This type of array cannot be displayed!";
}

template <typename T>
int reduce(T ar[], int n)
{
    int new_len = 0;
    T* new_end = std::unique(ar, ar + n);
    T* temp = ar;
    while (temp != new_end)
    {
        new_len++;
        temp++;
    }
    std::sort(ar, ar + new_len);
    return new_len;
}

#endif