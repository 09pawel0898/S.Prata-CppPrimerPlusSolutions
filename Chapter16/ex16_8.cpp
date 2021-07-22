#include "ex16_8.h"

void ex8(void)
{
    std::vector <std::string> boleksFriends;
    std::vector <std::string> loleksFriends;

    std::cout << "Enter Bolek's friends : (\"end\" to finish) \n";
    enterFriends(boleksFriends);
    std::cout << "\nBolek's friends :\n";
    showFriends(boleksFriends);

    std::cout << "\n\nEnter Lolek's friends : (\"end\" to finish) \n";
    enterFriends(loleksFriends);
    std::cout << "\nLolek's friends :\n";
    showFriends(loleksFriends);

    std::vector <std::string> mergedFriends = mergeFriends(boleksFriends, loleksFriends);
    std::cout << "\nMerged friends :\n";
    showFriends(mergedFriends);
}

static std::vector<std::string> mergeFriends(std::vector<std::string>& v1, std::vector<std::string>& v2)
{
    std::vector<std::string> merged;
    std::merge( v1.begin(),
                v1.end(),
                v2.begin(),
                v2.end(),
                std::back_inserter(merged));     //or std::insert_iterator<std::vector<std::string>>(merged,merged.begin()));
               

    merged.erase(std::unique(merged.begin(), merged.end()),
                 merged.end());
    return merged;
}

static void showFriends(std::vector<std::string>& friends)
{
    std::copy(  friends.begin(), 
                friends.end(), 
                std::ostream_iterator<std::string>(std::cout, "\n"));
}

static void sortFriends(std::vector<std::string>& friends)
{
    std::sort(friends.begin(), friends.end());
}

static void enterFriends(std::vector<std::string>& friends)
{
    std::string new_friend = "";
    do 
    {
        std::cin >> new_friend;
        if(new_friend != "end")
            friends.push_back(new_friend);
    } while (new_friend != "end");
    sortFriends(friends);
}