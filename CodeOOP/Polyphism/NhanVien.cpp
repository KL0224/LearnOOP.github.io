#include <iostream>
#include <string>
#include<cstring>
#include <vector>
using namespace std;

class cNhanVien
{
protected:
    string hoTen;
    string ngaySinh;
    double luong;
public:
    cNhanVien() {}
    cNhanVien(string hoTen, string ngaySinh, double luong) : hoTen(hoTen), ngaySinh(ngaySinh), luong(luong) {}
    virtual void nhap();
    virtual void xuat();
    virtual double TinhLuong() = 0;
    friend double TongLuong(vector<cNhanVien*>);
    friend vector<cNhanVien*> LuongCaoNhat(vector<cNhanVien*>);
};

void cNhanVien::nhap()
{
    cin.ignore();
    cout << "Nhap ho va ten: ";
    getline(cin, hoTen);
    cout << "Nhap ngay sinh: ";
    getline(cin, ngaySinh);
}
void cNhanVien::xuat()
{
    cout << "----------------------------------------------------------------------" << endl;
    cout << "Ho ten nhan vien: " << hoTen << endl;
    cout << "Ngay sinh nhan vien: " << ngaySinh << endl;
}

double TongLuong(vector<cNhanVien*> nv)
{
    double sum = 0;
    for(int i = 0; i < nv.size(); i++)
    {
        sum += nv[i]->TinhLuong();
    }
    return sum;
}

class cNVSanXuat : public cNhanVien
{
private:
    double luongCanBan;
    int soSanPham;
public:
    cNVSanXuat() {}
    cNVSanXuat(string hoTen, string ngaySinh, double luong, double luongCanban, int soSanPham) : cNhanVien(hoTen, ngaySinh, luong), luongCanBan(luongCanBan), soSanPham(soSanPham) {}
    void nhap();
    void xuat();
    double TinhLuong();
};
void cNVSanXuat::nhap()
{
    cNhanVien::
        nhap();
    cout << "Nhap luong can ban: ";
    cin >> luongCanBan;
    cout << "Nhap so san pham: ";
    cin >> soSanPham;
}
void cNVSanXuat::xuat()
{
    cNhanVien::
        xuat();
    cout << "So san pham nhan vien san xuat: " << soSanPham << endl;
    cout << "Luong cua nhan vien san xuat " << hoTen << " la: " << TinhLuong() << endl;
    cout << "----------------------------------------------------------------------" << endl;
}
double cNVSanXuat::TinhLuong()
{
    return luongCanBan + soSanPham * 5000;
}

class cNVVanPhong : public cNhanVien
{
private:
    int soNgayLamViec;
public:
    cNVVanPhong() {}
    cNVVanPhong(string hoTen, string ngaySinh, double luong, int soNgayLamViec) : cNhanVien(hoTen, ngaySinh, luong), soNgayLamViec(soNgayLamViec) {}
    void nhap();
    void xuat();
    double TinhLuong();
};
void cNVVanPhong::nhap()
{
    cNhanVien::nhap();
    cout << "So ngay lam viec cua nhan vien: ";
    cin >> soNgayLamViec;
}
void cNVVanPhong::xuat()
{
    cNhanVien::xuat();
    cout << "So ngay lam viec cua nhan vien: " << hoTen << " la: " << soNgayLamViec << endl;
    cout << "Luong cua nhan vien la: " << TinhLuong() << endl;
    cout << "----------------------------------------------------------------------" << endl;
}
double cNVVanPhong::TinhLuong()
{
    return 100000 * soNgayLamViec;
}

int main()
{
    int size_sx;
    int size_vp;
    vector<cNhanVien*> nv;
    
    cin >> size_sx;
    for(int i = 0; i < size_sx; i++)
    {
        cNVSanXuat *sx = new cNVSanXuat;
        sx->nhap();
        nv.push_back(sx);
    }

    cin >> size_vp;
    for(int i = 0; i < size_vp; i++)
    {
        cNVVanPhong *vp = new cNVVanPhong;
        vp->nhap();
        nv.push_back(vp);
    }

    for(int i = 0; i < nv.size(); i++)
    {
        nv[i]->xuat();
    }

    cout << "Tong luong: " << TongLuong(nv);
    return 0;
}