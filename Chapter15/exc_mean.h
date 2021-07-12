// exc_mean.h -- klasy wyjątków dla funkcji hmean() i gmean()
#include <iostream>

class bad_hmean : public std::logic_error
{
    public:
        explicit bad_hmean(const std::string& msg = "Podano niepoprawne argumenty. Zgloszono wyjatek bad_hmean.") : std::logic_error(msg) {}
};

class bad_gmean : public std::logic_error
{
    public:
        bad_gmean(const std::string& msg = "Argumenty funkcji gmean() powinny byc >=0. Zgloszono wyjatek bad_gmean.") : std::logic_error(msg) {}
};


