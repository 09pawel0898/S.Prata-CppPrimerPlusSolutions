#include "ex16_3.h"

static void loadWordsFromFile(std::vector<std::string>& vec)
{
    std::ifstream file("palindromes.txt");

    if (file.good())
    {
        std::string str;
        
        while (!file.eof())
        {
            std::getline(file, str);
            file >> std::ws;
            vec.push_back(str);
        }
        file.close();
    }
    else
        std::cerr << "Error. Cant open a file named palindromes.txt";
}

static bool isPalindrome(std::string str)
{
    std::string reversed;
    std::for_each(str.begin(), str.end(), [](char& c)
        { c = tolower(c); });

    str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());
    std::copy(str.rbegin(), str.rend(), std::insert_iterator<std::string>(reversed, reversed.begin()));
    //return (str == reversed) ? true : false; // i have no clue why this is not working fine, despite the fact that both strings are equivalent
    return (strcmp(reversed.c_str(), str.c_str())) ? false : true;
}

void ex3(void)
{
    std::vector<std::string> strings;
    loadWordsFromFile(strings);

    for (auto& str : strings)
    {
        if (isPalindrome(str))
            std::cout << str << " --> palindrome\n";
        else
            std::cout << str << " --> not a palindrome\n";
    }
}