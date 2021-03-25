#include <iostream>
#include <string>

/* ------- ex 1 -------*/

class Cd
{
private:
    char performers[50];
    char label[20];
    int selections;
    double playtime;
public:
    Cd(const char* s1, const char* s2, int n, double x)
        : selections(n), playtime(x)
    {
        strcpy_s(performers,50*sizeof(char),s1);
        strcpy_s(label,20*sizeof(char),s2);
    }

    Cd(const Cd& cd)
    {
        selections = cd.selections;
        playtime = cd.playtime;
        strcpy_s(performers, 50 * sizeof(char), cd.performers);
        strcpy_s(label, 20 * sizeof(char), cd.label);
    }

    Cd()
        : performers("null"), label("null"),selections(0),playtime(0)
    {}

    ~Cd()
    {
    }

    virtual void report() const
    {
        std::cout << "Performers : " << performers << "\n";
        std::cout << "Label : " << label << "\n";
        std::cout << "Selections : " << selections << "\n";
        std::cout << "Playtime : " << playtime << "\n";
    }

    Cd& operator=(const Cd& cd)
    {
        if (this == &cd) return *this;
        selections = cd.selections;
        playtime = cd.playtime;
        strcpy_s(performers, 50 * sizeof(char), cd.performers);
        strcpy_s(label, 20 * sizeof(char), cd.label);
        return *this;
    }

};

class Classic : public Cd
{
private:

    char mainTrack[20];

public:
    Classic() : Cd(), mainTrack("null") 
    {}
    
    Classic(const char* s1, const char* s2, const char* s3, int n, double x) : Cd(s1, s2, n, x)
    {
        strcpy_s(mainTrack, 20 * sizeof(char), s3);
    }

    Classic(const Classic& classic) : Cd(*this)
    {
        strcpy_s(mainTrack, 20 * sizeof(char), classic.mainTrack);
    }

    ~Classic()
    {
    }

    virtual void report() const
    {
        static_cast<Cd>(*this).report();
        std::cout << "mainTrack : " << mainTrack<< "\n";
    }

    Classic& operator=(const Classic& cd)
    {
        if (this == &cd) return *this;
        Cd::operator=(cd);
        strcpy_s(mainTrack, 20 * sizeof(char), cd.mainTrack);
        return *this;
    }

};

void Bravo(const Cd& cd)
{
    cd.report();
}

void ex1(void)
{
    Cd c1("Beatles", "Capitol", 14, 35.5);
    Classic c2 = Classic("Sonata fortepianowa B-dur, Fantazja C-moll", "Alfred Brendel", "Philips", 2, 57.17);

    Cd* pcd = &c1;

    std::cout << "Bezposrednie uzycie obiektu :\n";
    c1.report(); // metoda klasy Cd
    c2.report(); // metoda klasy Classic
   
    std::cout << "Uzycie wskaznika na typ cd :\n";
    pcd->report();
    pcd = &c2;
    pcd->report();

    std::cout << "Wywolanie funkcji z argumentem w postaci referencji do typu Cd :\n";
    Bravo(c1);
    Bravo(c2);

    std::cout << "Test przypisania :\n";
    Classic copy;
    copy = c2;
    copy.report();

    exit(0);
}

int main(void)
{
    short ex;
    std::cout << "Excersise(1) : ";
    std::cin >> ex;
    std::cout << "\n";
    switch (ex)
    {
    case 1:
        ex1();
        break;
        //case 2: ex2(); break;
        //case 6: ex6(); break;
    default:
        std::cout << "Theres no such excersise";
        break;
    }
    return 0;
}
