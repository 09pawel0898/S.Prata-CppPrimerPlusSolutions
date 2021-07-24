#include "ex17_7.h"

void ex7(void)
{
    std::vector<std::string> vostr;
    std::string temp;
    bool finished = false;
    
    std::cout << "Enter strings (enter empty row to finish):\n";
    std::cin >> std::ws;
    while(std::getline(std::cin, temp) && temp[0] != '\0')
        vostr.push_back(temp);

    std::cout << "Your data : \n";
    std::for_each(vostr.begin(), vostr.end(), showStr);
    
    std::ofstream fOut("strings.dat", std::ios_base::out | std::ios_base::binary);
    std::for_each(vostr.begin(), vostr.end(), Store(fOut));
    fOut.close();

    std::vector<std::string> vistr;
    std::ifstream fIn("strings.dat", std::ios_base::in | std::ios_base::binary);
    if (!fIn.is_open())
    {
        std::cerr << "Cant open file strings.dat for reading.";
        exit(EXIT_FAILURE);
    }
    getStrs(fIn, vistr);
    std::cout << "\nStrings read from the file : \n";
    std::for_each(vistr.begin(), vistr.end(), showStr);
    exit(EXIT_SUCCESS);
}

static void showStr(const std::string& str)
{
    std::cout << str << "\n";
}

static bool getStrs(std::ifstream& is, std::vector<std::string>& vec)
{
    if (!is.is_open())
    {
        std::cerr << "Cant read any data from a given stream in function getStrs.";
        return false;
    }
    else
    {
        std::size_t len;
        while (is.read((char*)&len, sizeof(std::size_t)) && is.eofbit)
        {

            char buf;
            std::string str = "";
            for (std::size_t i = 0; i < len; i++)
            {
                is.read(&buf, sizeof(char));
                str += buf;
            }
            vec.push_back(str);
        }
    }
    return true;
}



