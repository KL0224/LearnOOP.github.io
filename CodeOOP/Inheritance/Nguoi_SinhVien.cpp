#include <iostream>
#include <cstring>

// Superclass
class Nguoi
{
protected:
    char* cHoTen;
    int iNamSinh;
public:
    Nguoi();
    Nguoi(char* ht, int ns) : iNamSinh(ns)
    {
        cHoTen = strdup(ht);
    }
    ~Nguoi()
    {
        delete[] cHoTen;
    }
    void An() const 
    {
        std::cout << cHoTen << "an 3 phan com 25k mot ngay.\n";
    }
    void Ngu() const
    {
        std::cout << cHoTen << "ngu 6 tieng 1 ngay.\n";
    }
    void Xuat() const;
    friend std::ostream& operator<<(std::ostream&, Nguoi&);
};

// SubClass
class SinhVien : public Nguoi
{
protected:
    char* cMaSo;
public:
    SinhVien();
    SinhVien(char* ht, char* ms, int ns) : Nguoi(ht, ns)
    {
        cMaSo = strdup(ms);
    }
    ~SinhVien()
    {
        delete[] cMaSo;
    }
    void Xuat() const;
};

void Nguoi::Xuat() const
{
    std::cout << "Nguoi, ho ten: " << cHoTen;
    std::cout << " sinh nam: " << iNamSinh;
    std::cout << "\n"; 
}

void SinhVien::Xuat() const
{
    std::cout << "Sinh vien, ma so: " << cMaSo;
    std::cout << " , ho ten: " << cHoTen;
    std::cout << " sinh nam: " << iNamSinh;
    std::cout << std::endl;
}

int main()
{
    Nguoi k("Pham Anh Kiet", 2005);
    SinhVien l("Phan Thi Kim Loan", "23520816", 2006);
    std::cout << "1.\n";
    k.An(); l.An();
    std::cout << "2.\n";
    k.Xuat(); l.Xuat();
    l.Nguoi::Xuat();
    std::cout << "3.\n";
    //std::cout << k << "\n";
    //std::cout << l << "\n";
}
