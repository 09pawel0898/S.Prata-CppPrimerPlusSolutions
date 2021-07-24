#include "ex17_5.h"


void ex5(void)
{
    std::vector <std::string> boleksFriends;
    std::vector <std::string> loleksFriends;

    enterFriends("bolek.dat",boleksFriends);
    std::cout << "\nBolek's friends :\n";
    showFriends(std::cout,boleksFriends);

    enterFriends("lolek.dat",loleksFriends);
    std::cout << "\nLolek's friends :\n";
    showFriends(std::cout,loleksFriends);

    std::ofstream fOut("bolilol.dat", std::ios_base::out);
    if (!fOut.is_open())
    {
        std::cerr << "Cant open a file " << "bolilol.dat" << " for reading.";
        exit(EXIT_FAILURE);
    }

    std::vector <std::string> mergedFriends = mergeFriends(boleksFriends, loleksFriends);
    std::cout << "\nMerged friends :\n";
    showFriends(std::cout,mergedFriends);
    showFriends(fOut,mergedFriends);
    fOut.close();
}

static std::vector<std::string> mergeFriends(std::vector<std::string>& v1, std::vector<std::string>& v2)
{
    std::vector<std::string> merged;
    std::merge(v1.begin(),
        v1.end(),
        v2.begin(),
        v2.end(),
        std::back_inserter(merged));     //or std::insert_iterator<std::vector<std::string>>(merged,merged.begin()));


    merged.erase(std::unique(merged.begin(), merged.end()),
        merged.end());
    return merged;
}

static void showFriends(std::ostream& ostream, std::vector<std::string>& friends)
{
    std::copy(friends.begin(),
        friends.end(),
        std::ostream_iterator<std::string>(ostream, "\n"));
}

static void sortFriends(std::vector<std::string>& friends)
{
    std::sort(friends.begin(), friends.end());
}

static void enterFriends(const std::string& fName, std::vector<std::string>& friends)
{
    std::string new_friend = "";
    std::ifstream fIn(fName, std::ios_base::in);

    if (!fIn.is_open())
    {
        std::cerr << "Cant open a file " << fName << " for reading.";
        exit(EXIT_FAILURE);
    }

    while (fIn.good())
    {
        fIn >> new_friend;
        friends.push_back(new_friend);
    };
    fIn.close();
    sortFriends(friends);
}