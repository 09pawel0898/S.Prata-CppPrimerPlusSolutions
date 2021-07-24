#include "includes.h"

#ifndef EX17_5_H
#define EX17_5_H


/* ------- ex 5 -------*/

void ex5(void);

// declaring static functions just for visualize this compilation unit interface in header file

static std::vector<std::string> mergeFriends(std::vector<std::string>& v1, std::vector<std::string>& v2);
static void showFriends(std::ostream& ostream, std::vector<std::string>& friends);
static void sortFriends(std::vector<std::string>& friends);
static void enterFriends(const std::string& fName, std::vector<std::string>& friends);

#endif