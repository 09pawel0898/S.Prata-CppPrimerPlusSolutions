#include "ex16_1.h"

void ex1(void)
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

static bool isPalindrome(const std::string& str)
{
    std::string reversed;
    // using std::copy with std::insert_iterator to allocate memory in reversed string when copying 
    std::copy(str.rbegin(), str.rend(), std::insert_iterator<std::string>(reversed, reversed.begin()));
    return (str == reversed) ? true : false;
}

