#include "ex18_1.h"

void ex1(void)
{
    auto q = average_list({15.4,10.7,9.0});
    std::cout << q << std::endl;
    std::cout << average_list({ 20,30,19,17,45,38 }) << std::endl;
    auto ad = average_list<double>({ 'A',70,65.33 });
    std::cout << ad << std::endl;
    exit(EXIT_SUCCESS);
}

template <typename T>
static double average_list(std::initializer_list<T> args)
{
    double sum = 0;
    int count = 0;
    std::for_each(  args.begin(),
                    args.end(),
                    [&](const T& elem)
                    {
                        sum += elem;
                        count++;
                    });
    return sum / count;
}