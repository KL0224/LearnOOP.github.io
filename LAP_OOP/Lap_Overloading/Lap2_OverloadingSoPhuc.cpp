// Nạp chồng số phức
#include <iostream>

class SoPhuc
{
private:
    int iThuc, iAo;
public:
    // Contructor
    SoPhuc();
    SoPhuc(int);
    SoPhuc(int, int);

    // Operator
    friend SoPhuc operator+(SoPhuc, SoPhuc);
    friend SoPhuc operator-(SoPhuc, SoPhuc);
    friend SoPhuc operator*(SoPhuc, SoPhuc);
    friend SoPhuc operator/(SoPhuc, SoPhuc);
    friend bool operator==(SoPhuc, SoPhuc);
    friend bool operator!=(SoPhuc, SoPhuc);
    friend std::istream& operator>>(std::istream&, SoPhuc&);
    friend std::ostream& operator<<(std::ostream&, SoPhuc);
};

SoPhuc::SoPhuc()
{
    this->iThuc = 0;
    this->iAo = 0;
}

SoPhuc::SoPhuc(int iThuc)
{
    this->iThuc = iThuc;
    this->iAo = 0;
}

SoPhuc::SoPhuc(int iThuc, int iAo)
{
    this->iThuc = iThuc;
    this->iAo = iAo;
}

SoPhuc operator+(SoPhuc a, SoPhuc b)
{
    return SoPhuc(a.iThuc + b.iThuc, a.iAo + b.iAo);
}

SoPhuc operator-(SoPhuc a, SoPhuc b)
{
    return SoPhuc(a.iThuc - b.iThuc, a.iAo - b.iAo);
}

SoPhuc operator*(SoPhuc a, SoPhuc b)
{
    return SoPhuc(a.iThuc * b.iThuc - a.iAo * b.iAo, a.iThuc * b.iAo + a.iAo * b.iThuc);
}

SoPhuc operator/(SoPhuc a, SoPhuc b)
{
    return SoPhuc((a.iThuc * b.iThuc + a.iAo * b.iAo) / (b.iThuc * b.iThuc + b.iAo * b.iAo), (a.iAo * b.iThuc - a.iThuc * b.iAo) / (b.iThuc * b.iThuc + b.iAo * b.iAo));
}

bool operator==(SoPhuc a, SoPhuc b)
{
    return a.iThuc == b.iThuc && a.iAo == b.iAo;
}

bool operator!=(SoPhuc a, SoPhuc b)
{
    return !(a == b);
}

std::istream& operator>>(std::istream& is, SoPhuc &a)
{
    std::cout << "Nhap phan thuc va phan ao cua so phuc: ";
    is >> a.iThuc >> a.iAo;
    return is;
}

std::ostream& operator<<(std::ostream& os, SoPhuc a)
{
    std::cout << "So phuc: ";
    if(a.iThuc != 0) os << a.iThuc;
    if(a.iAo > 0) os << " + " << a.iAo << "i";
    else if(a.iAo < 0) os << " " << a.iAo << "i";
    std::cout << std::endl;
    return os;
}

int main()
{
    SoPhuc a(2, 4);
    SoPhuc b(1, -2);

    SoPhuc c = a + b;
    std::cout << c;

    SoPhuc d = a - b;
    std::cout << d;

    SoPhuc e = a * b;
    std::cout << e;

    SoPhuc f = a / b;
    std::cout << f;

    SoPhuc g;
    std::cin >> g;

    if(a == g)
    {
        std::cout << "Hai so phuc bang nhau.\n";
    }

    if(a != b)
    {
        std::cout << "Hai so phuc khac nhau.\n";
    }

    return 0;
}