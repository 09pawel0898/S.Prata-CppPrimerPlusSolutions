#include "ex17_1.h"
#include "ex17_2.h"
#include "ex17_3.h"
#include "ex17_4.h"
#include "ex17_5.h"
#include "ex17_7.h"

int main(int argc, char **argv)
{
    

    short ex;
    std::cout << "Excersise(1,2,3,4,5,7) : ";
    std::cin >> ex;
    std::cout << "\n";
    switch (ex)
    {
        case 1: ex1();  break;
        case 2: ex2();  break;
        case 3: ex3(argc,argv);  break;
        case 4: ex4(argc,argv);  break;
        case 5: ex5();  break;
        case 7: ex7();  break;
    default:
        std::cout << "Theres no such excersise";
        break;
    }
    return 0;
}
