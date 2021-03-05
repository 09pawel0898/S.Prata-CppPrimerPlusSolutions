#include <iostream>
#include <string>

/* ------- ex 1 -------*/

void print_string(const char* str, int param = 0)
{
    static int num = 1;
    if(param== 0)
        std::cout << str << "\n";
    else
    {
        for(int i = 1 ; i <=num ; i++)
            std::cout << str << "\n";
    }
    std::cout << "\n";
    num++;
}


void ex1(void)
{
    print_string("String");
    print_string("String");

    print_string("String",1);
    print_string("String",1);
    print_string("String",1);
    print_string("String",1);
}

/* ------- ex 2 -------*/

const int bufSize = 30;
struct Bar
{
    char mbrand[bufSize];
    double mweight;
    int mcalories;
};

void set_bar(Bar& bar, const char* brand = "Millenium Munch", double weight = 2.85, int calories = 350)
{
    strcpy_s(bar.mbrand, bufSize, brand);
    bar.mweight = weight;
    bar.mcalories = calories;
}

void print_bar(Bar& bar)
{
    std::cout << bar.mbrand << "\n" << bar.mweight << "\n" <<bar.mcalories << "\n";
}
void ex2(void)
{
    Bar bar;
    set_bar(bar);
    print_bar(bar);
}

/* ------- ex 6 -------*/

template <typename T>
T maxn(T tab[], int size)
{
    T max = tab[0];
    for (int i = 1; i < size; i++)
        if (tab[i] > max)
            max = tab[i];
    return max;
}

template <> char* maxn<char*>(char* tab[25], int size)
{
    char* p_to_longest = tab[0];
    unsigned max_lenght = strlen(p_to_longest);

    for (int i = 1; i < size; i++)
    {
        if (strlen(tab[i]) > max_lenght)
        {
            max_lenght = strlen(tab[i]);
            p_to_longest = tab[i];
        }
    }
    return p_to_longest;
}

void ex6(void)
{
    int t1[3] = { 1,3,4 };
    std::cout << maxn(t1, 3) << "\n";
    
    char *tab[5];
    for (int i = 0; i < 5; i++)
        tab[i] = new char[25];

    strcpy_s(tab[0], 25, "ala");
    strcpy_s(tab[1], 25, "ma");
    strcpy_s(tab[2], 25, "kota");
    strcpy_s(tab[3], 25, "kudlatego");
    strcpy_s(tab[4], 25, "malego");
        
    //char** tab = t2;
    char* str = maxn(tab, 5);
    std::cout << str;
}

int main(void)
{
    short ex;
    std::cout << "Excersise : ";
    std::cin >> ex;
    std::cout << "\n";
    switch (ex)
    {
        case 1: ex1(); break;
        case 2: ex2(); break;
        case 6: ex6(); break;
    }
    return 0;
}
