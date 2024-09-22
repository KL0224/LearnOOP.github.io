#include <iostream>
#include <cmath>
using namespace std;

class PhanSo
{
private:
    int iTu, iMau;
public:
    // Creat Contructor
    PhanSo();
    PhanSo(int, int);
    PhanSo(int);

    // Rút gọn phân số
    void RutGon();

    // Overloading
    friend PhanSo operator+(PhanSo, PhanSo);
    friend PhanSo operator-(PhanSo, PhanSo);
    friend PhanSo operator*(PhanSo, PhanSo);
    friend PhanSo operator/(PhanSo, PhanSo);
    friend bool operator>(PhanSo, PhanSo);
    friend bool operator<(PhanSo, PhanSo);
    friend bool operator==(PhanSo, PhanSo);
    friend bool operator!=(PhanSo, PhanSo);
    friend bool operator>=(PhanSo, PhanSo);
    friend bool operator<=(PhanSo, PhanSo);
    friend istream& operator>>(istream&, PhanSo&);
    friend ostream& operator<<(ostream&, PhanSo);
};

// Tạo contructor
PhanSo::PhanSo(){}

PhanSo::PhanSo(int iTu, int iMau)
{
    this->iTu = iTu;
    this->iMau = iMau;
}

PhanSo::PhanSo(int iTu)
{
    this->iTu = iTu;
    this->iMau = 1;
}

// Rút gọn phân số
int gcd__(int a, int b) {
    if (b == 0) return a;
    return gcd__(b, a % b);
}

void PhanSo::RutGon()
{
    int ucln = gcd__(abs(this->iTu), abs(this->iMau));
    this->iTu /= ucln;
    this->iMau /= ucln;
    if(this->iMau < 0)
    {
        this->iTu = -this->iTu;
        this->iMau = -this->iMau;
    }
    if(this->iTu == 0)
    {
        this->iMau = 1;
    }
}

PhanSo operator+(PhanSo a, PhanSo b)
{
    int tu = a.iTu*b.iMau + a.iMau*b.iTu;
    int mau = a.iMau*b.iMau;
    PhanSo c(tu, mau);
    c.RutGon();
    return c;
}

PhanSo operator-(PhanSo a, PhanSo b)
{
    int tu = a.iTu*b.iMau - a.iMau*b.iTu;
    int mau = a.iMau*b.iMau;
    PhanSo c(tu, mau);
    c.RutGon();
    return c;
}

PhanSo operator*(PhanSo a, PhanSo b)
{
    int tu = a.iTu*b.iTu;
    int mau = a.iMau*b.iMau;
    PhanSo c(tu, mau);
    c.RutGon();
    return c;
}

PhanSo operator/(PhanSo a, PhanSo b)
{
    int tu = a.iTu*b.iMau;
    int mau = a.iMau*b.iTu;
    PhanSo c(tu, mau);
    c.RutGon();
    return c;
}

bool operator>(PhanSo a, PhanSo b)
{
    return a.iTu*b.iMau > a.iMau*b.iTu;
}

bool operator<(PhanSo a, PhanSo b)
{
    return a.iTu*b.iMau < a.iMau*b.iTu;
}

bool operator==(PhanSo a, PhanSo b)
{
    return a.iTu*b.iMau == a.iMau*b.iTu;
}

bool operator!=(PhanSo a, PhanSo b)
{
    return a.iTu*b.iMau != a.iMau*b.iTu;
}

bool operator>=(PhanSo a, PhanSo b)
{
    return a.iTu*b.iMau >= a.iMau*b.iTu;
}

bool operator<=(PhanSo a, PhanSo b)
{
    return a.iTu*b.iMau <= a.iMau*b.iTu;
}

istream& operator>>(istream& in, PhanSo& a)
{
    cout << "Nhap tu so va mau so cua phan so: ";
    in >> a.iTu >> a.iMau;
    while(a.iMau == 0)
    {
        cout << "Ban da nhap sai mau so. Vui long nhap lai mau so";
        in >> a.iMau;
    }
    return in;
}

ostream& operator<<(ostream& out, PhanSo a)
{
    cout << a.iTu;
    if(a.iTu != 0 && a.iMau != 1)
    {
        cout << "/" << a.iMau;
    }
    return out;
}

int main()
{
    // Operator +-*/
    PhanSo a(3, 4), b(-1,2);
    cout << "Phan so a: " << a << endl;
    cout << "Phan so b: " << b << endl;

    PhanSo c = a + b;
    cout <<"Phan so sau khi cong: " << c << endl;

    PhanSo d = a - 2;
    cout << "Phan so sau khi tru: " << d << endl;

    PhanSo e = 3 * b;
    cout << "Phan so sau khi nhan: "<< e << endl;

    PhanSo f = a / b;
    cout << "Phan so sau khi chia: " << f << endl;

    // Operator > < >= <= == !=
    PhanSo m, n;
    cin >> m >> n;

    if(m > n)
    {
        cout << "Phan so m lon hon phan so n.\n";
    }
    if(m >= n)
    {
        cout << "Phan so m lon hon hoac bang phan so n.\n";
    }

    PhanSo p(2, 3);
    if(p < 2)
    {
        cout << "Phan so p nho hon 2.\n";
    }
    if(p <= 2)
    {
        cout << "Phan so p nho hon hoac bang 2.\n";
    }
    if(a != b)
    {
        cout << "Phan so a khac phan so b.\n";
    }

    PhanSo q(4, 6);
    if(p == q)
    {
        cout << "Phan so p bang phan so q.\n";
    }

    return 0;
}