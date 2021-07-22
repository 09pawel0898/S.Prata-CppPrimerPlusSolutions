#include "ex16_7.h"

void ex7(void)
{
    std::vector<int> myLotto;

    std::cout << "Generating 5 lotto attempts : \n";

    for (int attempt = 1; attempt <= 5; attempt++)
    {
        myLotto = Lotto(51, 6);
        std::cout << attempt << " : ";
        std::copy(myLotto.begin(), myLotto.end(), std::ostream_iterator<int, char>(std::cout, " "));
        std::cout << "\n";
    }
}

static std::vector<int> Lotto(int num_fields, int num_numbers)
{
    std::vector<int> lotto;
    lotto.reserve(num_numbers);
    int already_checked = 0;
    int num;

    auto numAlreadyPicked = [](const std::vector<int>& vec, int num)
    {
        for (auto& i : vec)
            if (i == num)
                return true;
        return false;
    };

    while (already_checked != num_numbers)
    {
        do
        {
           num = (rand() % num_fields) + 1;
        } while (numAlreadyPicked(lotto, num));
        lotto.push_back(num);
        already_checked++;
    }
    std::sort(lotto.begin(), lotto.end());
    return lotto;
}
