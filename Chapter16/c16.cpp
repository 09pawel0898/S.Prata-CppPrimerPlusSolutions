#include "ex16_1.h"
#include "ex16_2.h"
#include "ex16_3.h"
#include "ex16_4.h"
#include "ex16_5.h"
#include "ex16_6.h"
#include "ex16_7.h"
#include "ex16_8.h"
#include "ex16_9.h"
#include "ex16_10.h"

int main(void)
{
    

    short ex;
    std::cout << "Excersise(1,2,3,4,5,6,7,8,9,10) : ";
    std::cin >> ex;
    std::cout << "\n";
    switch (ex)
    {
        case 1: ex1();  break;
        case 2: ex2();  break;
        case 3: ex3();  break;
        case 4: ex4();  break;
        case 5: ex5();  break;
        case 6: ex6();  break;
        case 7: ex7();  break;
        case 8: ex8();  break;
        case 9: ex9();  break;
        case 10: ex10();  break;
    default:
        std::cout << "Theres no such excersise";
        break;
    }
    return 0;
}
