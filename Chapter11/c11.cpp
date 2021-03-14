#include <iostream>
#include <string>
#include <new>

/* ------- ex 7 -------*/

class complex
{
private:
    double real;
    double im;

public:
    complex(double _real = 0,double _im = 0 )
        :   real(_real), im(_im)
    {}
    ~complex() {}

    bool is_zero(void) const { return (real == 0 && im == 0) ? true : false; }

    friend std::ostream& operator << (std::ostream& os, const complex& rhs)
    {
        os << "(" << rhs.real << "," << rhs.im << "i)";
        return os;
    }

    friend std::istream& operator >> (std::istream& is, complex& rhs)
    {
        is >> rhs.real >> rhs.im;
        return is;
    }

    complex operator + (const complex& rhs) const   {   return complex(this->real + rhs.real, this->im + rhs.im);   }
    complex operator - (const complex& rhs) const   {   return complex(this->real - rhs.real, this->im - rhs.im);   }
    complex operator * (const complex& rhs) const   {   return complex(this->real * rhs.real - this->im * rhs.im, this->real * rhs.im + this->im * rhs.real);}
    complex operator * (double rhs) const           {   return complex(this->real * rhs,this->im * rhs);}
    complex operator ~ (void) const                  {   return complex(this->real, -this->im); }
    
    friend complex operator * (double lhs, const complex& rhs)
    {
        return rhs * lhs;
    }


};

void ex7(void)
{
    
    complex a(3.0, 4.0);
    complex c;

    std::cout<<"Enter the complex number (type k to finish):\n";
    while(std::cin>>c)
    {
        std::cout<<"c is "<< c <<"\n";
        std::cout<<"conjugated c is "<< ~c << "\n";
        std::cout<<"a is "<< a <<"\n";
        std::cout<<"a + c - "<<a + c<<"\n";
        std::cout<<"a - c - "<<a - c<<"\n";
        std::cout<<"a * c - "<<a * c<<"\n";
        std::cout<<"2 * c - "<<2 * c<<"\n";
        std::cout<<"Enter the complex number (type k to finish):\n";
    }

    
}

int main(void)
{
    short ex;
    std::cout << "Excersise(7) : ";
    std::cin >> ex;
    std::cout << "\n";
    switch (ex)
    {
        case 7: 
            ex7(); 
        break;
        //case 2: ex2(); break;
        //case 6: ex6(); break;
        default: 
            std::cout<<"Theres no such excersise"; 
        break;
    }
    return 0;
}
