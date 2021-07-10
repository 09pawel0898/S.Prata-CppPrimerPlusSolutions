#include <iostream>
#include <string>
#include "emp.h"
/* ------- ex 1 -------*/

using std::cout;
using std::endl;
using std::cin;

void ex1(void)
{
    
    employee em("Tadeusz", "Hubert", "Sprzedawca");
    cout << em << endl;
    em.ShowAll();

    manager ma("Amforiusz", "Smoczewski", "Malarz", 5);
    cout << ma << endl;
    ma.ShowAll();


    fink fi("Maurycy", "Okulski", "Hudraulik", "Julian Bar");
    cout << fi << endl;
    fi.ShowAll();
    highfink hf(ma, "Jan Kudlaty");  // recruitment?
    hf.ShowAll();

    cout << "Wczisnij dowolny klawisz aby przejsc do nastepnego etapu:\n";
    cin.get();
    highfink hf2;
    hf2.SetAll();

    cout << "Uzywa wskaznika abstr_emp * :\n";
    abstr_emp* tri[4] = { &em, &fi, &hf, &hf2 };
    for (int i = 0; i < 4; i++)
        tri[i]->ShowAll();
    exit(0);
}

int main(void)
{
    short ex;
    std::cout << "Excersise(1) : ";
    std::cin >> ex;
    std::cout << "\n";
    switch (ex)
    {
    case 1:
        ex1();
        break;
        //case 2: ex2(); break;
        //case 6: ex6(); break;
    default:
        std::cout << "Theres no such excersise";
        break;
    }
    return 0;
}
