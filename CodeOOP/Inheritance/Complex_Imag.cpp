#include <iostream>
#include <cmath>
class Complex
{
    friend std::ostream& operator<< (std::ostream&, Complex);
    friend class Imag;
    double re, im;
public:
    Complex(double r = 0, double i = 0) : re(r), im(i){}
    Complex operator+(Complex);
    Complex operator-(Complex);
    Complex operator*(Complex);
    Complex operator/(Complex);
    double Norm() const
    {
        return sqrt(re*re + im*im);
    }
};

class Imag : public Complex
{
public:
    Imag(double i = 0) : Complex(0, i){}
    Imag(const Complex& c) : Complex(0, c.im){}
    Imag& operator=(const Complex &c)
    {
        re = 0;
        im = c.im;
        return *this;
    }
    double Norm() const
    {
        return abs(im);
    }
};

std::ostream& operator<<(std::ostream& os, Complex a)
{
    if(a. re != 0) os << a.re << " ";
    if(a.im > 0) os << "+ " << a.im << "i\n";
    if(a.im < 0) os << a.im << "i\n";
    if(a.re == 0 && a.im == 0) os << "0\n";
    return os;
}

Complex Complex::operator+(Complex a)
{
    return Complex(this->re + a.re, this->im + a.im);
}

Complex Complex::operator-(Complex a)
{
    return Complex(this->re - a.re, this->im - a.im);
}

int main() 
{
    Imag i = 1;
    Complex z1(1, 1);
    Complex z2 = z1 - i;
    i = Complex(5, 2);
    Imag j = z1;
    std::cout << "z1 = " << z1;
    std::cout << "i = " << i;
    std::cout << "j = " << j; 
    return 0;
}