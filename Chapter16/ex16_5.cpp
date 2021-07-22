#include "ex16_5.h"

void ex5(void)
{
    long ar1[] = { 8,1,19,1,3,2,7,11,7,1,13 };
    int len1 = 11;

    std::string ar2[] = { "du", "udd" , "aaa", "bbb", "du" , "du", "bbbbbbb" };
    int len2 = 7;

    std::cout << "\nArray1 before reduce() : \n";
    showArray<long>(ar1, len1);
    int new_len1 = reduce<long>(ar1, len1);
    std::cout << "\nArray1 after reduce() : \n";
    showArray<long>(ar1, new_len1);

    std::cout << "\nArray2 before reduce() : \n";
    showArray<std::string>(ar2, len2);
    int new_len2 = reduce<std::string>(ar2, len2);
    std::cout << "\nArray2 after reduce() : \n";
    showArray<std::string>(ar2, new_len2);
}
