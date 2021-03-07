#include <iostream>
#include <string>
#include <new>

/* ------- ex 3 -------*/

struct chaff
{
    char dross[20];
    int slag;

    void init_chaff(const char* _dross, int _slag)
    {
        strcpy_s(dross, 20, _dross);
        slag = _slag;
    }

    friend std::ostream& operator << (std::ostream& ostream, chaff& chaff)
    {
        ostream << chaff.dross << " "<<chaff.slag;
        return ostream;
    }
};

const int BUFSIZE = 512;
char buffer[BUFSIZE];

void ex3(void)
{
    chaff* pointer = new (buffer) chaff[2];
    pointer->init_chaff("something1", 20);
    std::cout << "First entity & - " << pointer<< "\n";
    std::cout << *pointer << "\n";
    pointer++;
    std::cout << "Second entity & - " << pointer << "\n";
    pointer->init_chaff("something2", 40);
    std::cout << *pointer;
    std::cout << "\nBuffer starting & - " << &buffer << "\n";
}


int main(void)
{
    short ex;
    std::cout << "Excersise : ";
    std::cin >> ex;
    std::cout << "\n";
    switch (ex)
    {
        case 3: ex3(); break;
        //case 2: ex2(); break;
        //case 6: ex6(); break;
    }
    return 0;
}
