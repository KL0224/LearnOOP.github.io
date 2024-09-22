#include <iostream>

class NhanVien
{
protected:
    std::string sMaSo;
    std::string sTen;
    double dLuongCoBan;
public:
    NhanVien() {}
     NhanVien(std::string sMaSo, std::string sTen, double dLuongCoBan) : sMaSo(sMaSo), sTen(sTen), dLuongCoBan(dLuongCoBan) {}
    virtual double TienThuong() = 0;
    virtual void Xuat() = 0;
};

class QuanLy : public NhanVien
{
private:
    double dTyLeThuong;
public:
    QuanLy() {}
    QuanLy(std::string sMaSo, std::string sTen, double dLuongCoBan, double dTyLeThuong) : NhanVien(sMaSo, sTen, dLuongCoBan), dTyLeThuong(dTyLeThuong) {}
    friend std::istream& operator>>(std::istream&, QuanLy&);
    double TienThuong();
    void Xuat();
};

class KySu : public NhanVien
{
private:
    double dSoGioLam;
public:
    KySu() {}
    KySu(std::string sMaSo, std::string sTen, double dLuongCoBan, double dSoGioLam) : NhanVien(sMaSo, sTen, dLuongCoBan), dSoGioLam(dSoGioLam){};
    friend std::istream& operator>>(std::istream&, KySu&);
    double TienThuong();
    void Xuat();
};

std::istream& operator>>(std::istream& is, QuanLy &a)
{
    std::cout << "Nhap quan ly:\n";
    std::cout << "Nhap ma so quan ly: "; is >> a.sMaSo;
    std::cout << "Nhap ten quan ly: "; is >> a.sTen;
    std::cout << "Nhap luong co ban cua quan ly: "; is >> a.dLuongCoBan;
    std::cout << "Nhap ty le thuong cua quan ly: "; is >> a.dTyLeThuong;
    return is;
}

std::istream& operator>>(std::istream& in, KySu &a)
{
    std::cout << "Nhap ky su:\n";
    std::cout << "Nhap ma so ky su: "; in >> a.sMaSo;
    std::cout << "Nhap ten ky su: "; in >> a.sTen;
    std::cout << "Nhap luong co ban cua ky su: "; in >> a.dLuongCoBan;
    std::cout << "Nhap so gio lam viec cua ky su: "; in >> a.dSoGioLam;
    return in;
}

double QuanLy::TienThuong() 
{
    return dTyLeThuong * dLuongCoBan;
}

double KySu::TienThuong()
{
    return dSoGioLam * 100000;
}

void QuanLy::Xuat()
{
    std::cout << "Xuat quan ly:\n";
    std::cout << "Ma so quan ly: " << sMaSo << "\n";
    std::cout << "Ten quan ly: " << sTen << "\n";
    std::cout << "Luong co ban quan ly: " << dLuongCoBan << "\n";
    std::cout << "Tien thuong quan ly: " << this->TienThuong() << "\n";
}

void KySu::Xuat()
{
    std::cout << "Xuat ky su:\n";
    std::cout << "Ma so ky su: " << sMaSo << "\n";
    std::cout << "Ten ky su: " << sTen << "\n";
    std::cout << "Luong co ban ky su: " << dLuongCoBan << "\n";
    std::cout << "Tien thuong ky su: " << this->TienThuong() << "\n";
}

int main()
{
    QuanLy k1;
    KySu k2;
    std::cin >> k1;
    std::cin >> k2;
    k1.Xuat();
    k2.Xuat();
    return 0;
}