#include "includes.h"

#ifndef EX16_8_H
#define EX16_8_H


/* ------- ex 8 -------*/

void ex8(void);

// declaring static functions just for visualize this compilation unit interface in header file

static std::vector<std::string> mergeFriends(std::vector<std::string>& v1, std::vector<std::string>& v2);
static void showFriends(std::vector<std::string>& friends);
static void sortFriends(std::vector<std::string>& friends);
static void enterFriends(std::vector<std::string>& friends);
#endif