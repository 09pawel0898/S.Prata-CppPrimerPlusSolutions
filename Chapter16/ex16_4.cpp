#include "ex16_4.h"

void ex4(void)
{
    long ar[] = { 8,1,19,1,3,2,7,11,7,1,13};
    int len = 11;
    std::cout << "Array before reduce() : \n";
    showArray(ar, len);
    int new_len = reduce(ar, len);
    std::cout << "\nArray after reduce() : \n";
    showArray(ar, new_len);
}

static void showArray(long ar[], int n)
{
    std::copy(ar, ar + n, std::ostream_iterator<long, char>(std::cout, " "));
}

static int reduce(long ar[], int n)
{
    int new_len = 0;
    std::sort(ar, ar + n);
    long* new_end = std::unique(ar, ar + n);
    long* temp = ar;
    while (temp != new_end)
    {
        new_len++;
        temp++;
    }
    return new_len;
}
