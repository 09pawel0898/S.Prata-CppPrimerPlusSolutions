﻿#include "ex18_1.h"
#include "ex18_2.h"
#include "ex18_3.h"


int main(int argc, char **argv)
{
    

    short ex;
    std::cout << "Excersise(1,2,3) : ";
    std::cin >> ex;
    std::cout << "\n";
    switch (ex)
    {
        case 1: ex1();  break;
        case 2: ex2();  break;
        case 3: ex3();  break;
    default:
        std::cout << "Theres no such excersise";
        break;
    }
    return 0;
}
