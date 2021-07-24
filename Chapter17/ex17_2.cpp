#include "ex17_2.h"

void ex2(void)
{
    std::string fName;
    std::cout << "Enter the destination file name : ";
    std::cin >> fName;

    std::ofstream fOut(fName, std::ios_base::out);
    char c;
    char sEOF = '$';
    if (fOut.is_open())
    {
        while ((c = std::cin.get()) && c != sEOF)
        {
            fOut << c;
        }
        fOut.close();
    }
    else
    {
        std::cerr << "Error when creating an output file.";
        exit(EXIT_FAILURE);
    }
    exit(0);
}
