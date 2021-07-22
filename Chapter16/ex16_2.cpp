#include "ex16_2.h"

void ex2(void)
{
    cout << "Enter string :";
    std::string str;
    std::getline(cin >> std::ws, str);
    bool palindrome = isPalindrome(str);
    if (palindrome)
        cout << "Palindrome!";
    else
        cout << "Not a palindrome!";
}

static bool isPalindrome(std::string str)
{
    std::string reversed;
    std::for_each(str.begin(), str.end(),   [](char& c)
                                            { c = tolower(c); });

    str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());
    std::copy(str.rbegin(), str.rend(), std::insert_iterator<std::string>(reversed, reversed.begin()));
    //return (str == reversed) ? true : false; // i have no clue why this is not working fine, despite the fact that both strings are equivalent
    return (strcmp(reversed.c_str(), str.c_str())) ? false : true;
}

