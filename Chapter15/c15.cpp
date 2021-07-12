#include <iostream>
#include <string>
#include <exception>
#include "sales.h"

/* ------- ex 1 -------*/

using std::cout;
using std::endl;
using std::cin;

void ex5(void)
{
    using std::cin;
    using std::cout;
    using std::endl;

    double vals1[12] =
    {
        1220, 1100, 1122, 2212, 1232, 2334,
        2884, 2393, 3302, 2922, 3002, 3544
    };
    
    double vals2[12] =
    {
        12,11,22,21,32,34,
        28,29,33,29,32,25
    };

    Sales sales1(2011, vals1, 12);
    LabeledSales sales2("Blogstar", 2012, vals2, 12);

    cout << "Pierwszy blok try :\n";
    try
    {
        int i;
        cout << "Rok = " << sales1.Year() << endl;
        for (i = 0; i < 12; ++i)
        {
            cout << sales1[i] << " ";
            if (i % 6 == 5)
                cout << endl;
        }
        cout << "Rok = " << sales2.Year() << endl;
        cout << "Etykieta = " << sales2.Label() << endl;
        for (i = 0; i < 12; ++i)
        {
            cout << sales2[i] << " ";
            if (i % 6 == 5)
                cout << endl;
        }
        cout << "Koniec pierwszego bloku try\n";
    }
    catch (Sales::bad_index& bad)
    {
        cout << bad.what();
        LabeledSales::nbad_index* perr = dynamic_cast<LabeledSales::nbad_index*>(&bad);
        if(perr != nullptr)
            cout << "Firma : " << perr->label_val() << endl;
        cout << "Niepoprawany indeks : " << bad.bi_val() << endl;
    }
    cout << "\nKolejny blok try\n";
    
    try
    {
        sales2[2] = 37.5;
        sales1[20] = 23345;
        cout << "Koniec drugiego bloku try.\n";
    }
    catch (Sales::bad_index& bad)
    {
        cout << bad.what();
        LabeledSales::nbad_index* perr = dynamic_cast<LabeledSales::nbad_index*>(&bad);
        if (perr != nullptr)
            cout << "Firma : " << perr->label_val() << endl;
        cout << "Niepoprawany indeks : " << bad.bi_val() << endl;
    }
    cout << "Koniec\n";
    
    exit(0);
}

int main(void)
{
    short ex;
    std::cout << "Excersise(5) : ";
    std::cin >> ex;
    std::cout << "\n";
    switch (ex)
    {
    case 5:
        ex5();
        break;
        //case 2: ex2(); break;
        //case 6: ex6(); break;
    default:
        std::cout << "Theres no such excersise";
        break;
    }
    return 0;
}
