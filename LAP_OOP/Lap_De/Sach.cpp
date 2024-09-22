#include <iostream>
#include<string>
#include <vector>
using namespace std;

class Sach
{
protected:
    string sMaSach;
    string sTenSach;
    string sNhaXuatBan;
    int iSoLuong;
    double dDonGia;
public:
    Sach() {};
    Sach(string sMaSach, string sTenSach, string sNhaXuatBan, int iSoLuong, double dDonGia) : 
    sMaSach(sMaSach), sTenSach(sTenSach), sNhaXuatBan(sNhaXuatBan), iSoLuong(iSoLuong), dDonGia(dDonGia) {}
    virtual void Nhap() = 0;
    virtual double ThanhTien() = 0;
    virtual void Xuat() = 0;
};

class SachGiaoKhoa : public Sach
{
private:
    int iTinhTrang;
public: 
    SachGiaoKhoa() {};
    SachGiaoKhoa(string sMaSach, string sTenSach, string sNhaXuatBan, int iSoLuong, double dDonGia, int iTinhTrang) : 
    Sach(sMaSach, sTenSach, sNhaXuatBan, iSoLuong, dDonGia), iTinhTrang(iTinhTrang) {}
    void Nhap();
    double ThanhTien();
    void Xuat();
    static vector<SachGiaoKhoa*> TimSach(vector<SachGiaoKhoa*> sgk)
    {
        string sNXB;
        cout << "Nhap ten nha xuat ban: ";
        cin.ignore();
        getline(cin, sNXB);

        vector<SachGiaoKhoa*> nxb;
        for(int i = 0; i < sgk.size(); i++)
        {
            if(sgk[i]->sNhaXuatBan == sNXB)
            {
                nxb.push_back(sgk[i]);
            }
        }

        return nxb;
    }
};

void SachGiaoKhoa::Nhap()
{
    cout << "Nhap sach giao khoa.\n";
    cout << "Nhap ma sach: ";
    cin.ignore();
    getline(cin, sMaSach);
    cout << "Nhap ten sach: ";
    getline(cin, sTenSach);
    cout << "Nhap nha xuat ban: ";
    getline(cin, sNhaXuatBan);
    cout << "Nhap so luong sach: ";
    cin >> iSoLuong;
    cout << "Nhap don gia: ";
    cin >> dDonGia;
    cout << "Nhap tinh trang: ";
    cin >> iTinhTrang;
}

double SachGiaoKhoa::ThanhTien()
{
    if (this->iTinhTrang == 1) 
    {
        return iSoLuong * dDonGia;
    }

    return iSoLuong * dDonGia * 0.5;
}

void SachGiaoKhoa::Xuat()
{
    cout << "Sach giao khoa.\n";
    cout << "Ma sach: " << sMaSach << endl;
    cout << "Ten sach: " << sTenSach << endl;
    cout << "Nha xuat ban: " << sNhaXuatBan << endl;
    cout << "So luong sach: " << iSoLuong << endl;
    cout << "Don gia: " << dDonGia << endl;
    cout << "Tinh trang: " << iTinhTrang << endl;
    cout << "Thanh tien: " << this->ThanhTien() << endl;
}



class SachThamKhao : public Sach
{
private: 
    double dTienThue;
public:
    SachThamKhao() {};
    SachThamKhao(string sMaSach, string sTenSach, string sNhaXuatBan, int iSoLuong, double dDonGia, double dTienThue) : 
    Sach(sMaSach, sTenSach, sNhaXuatBan, iSoLuong, dDonGia), dTienThue(dTienThue) {}
    void Nhap();
    double ThanhTien();
    void Xuat();
};

void SachThamKhao::Nhap()
{
    cout << "Nhap sach tham khao.\n";
    cout << "Nhap ma sach: ";
    cin.ignore();
    getline(cin, sMaSach);
    cout << "Nhap ten sach: ";
    getline(cin, sTenSach);
    cout << "Nhap nha xuat ban: ";
    getline(cin, sNhaXuatBan);
    cout << "Nhap so luong sach: ";
    cin >> iSoLuong;
    cout << "Nhap don gia: ";
    cin >> dDonGia;
    cout << "Nhap tien thue: ";
    cin >> dTienThue;
}

double SachThamKhao::ThanhTien()
{
    return iSoLuong * dDonGia + dTienThue;
}

void SachThamKhao::Xuat()
{
    cout << "Sach tham khao.\n";
    cout << "Ma sach: " << sMaSach << endl;
    cout << "Ten sach: " << sTenSach << endl;
    cout << "Nha xuat ban: " << sNhaXuatBan << endl;
    cout << "So luong sach: " << iSoLuong << endl;
    cout << "Don gia: " << dDonGia << endl;
    cout << "Tien thue: " << dTienThue << endl;
    cout << "Thanh tien: " << this->ThanhTien() << endl;
}

typedef SachGiaoKhoa SGK;
typedef SachThamKhao STK;

int main()
{
    vector<SGK*> sgk;
    vector<STK*> stk;

    // Nhập danh sách sách giáo khoa
    int nSGK;
    cout << "Nhap so luong loai sach giao khoa khac nhau: ";
    cin >> nSGK;
    SGK* a = new SGK;

    for(int i = 0; i < nSGK; i++)
    {
        a->Nhap();
        sgk.push_back(a);
    }

    // Nhập danh sách sách tham khảo
    int nSTK;
    cout << "Nhap so luong loai sach tham khao khac nhau: ";
    cin >> nSTK;
    STK* b = new STK;

    for(int i = 0; i < nSTK; i++)
    {
        b->Nhap();
        stk.push_back(b);
    }

    // Xuất danh sách sách giáo khoa
    for(int i = 0; i < nSGK; i++)
    {
        sgk[i]->Xuat();
    }

    // Xuất danh sách sách tham khao
    for(int i = 0; i < nSTK; i++)
    {
        stk[i]->Xuat();
    }

    // Tìm loại sách có thành tiền thấp nhất
    // Tìm thành tiền thấp nhất
    double minThanhTien = 0;
    for(int i = 0; i < nSGK; i++)
    {
        if(minThanhTien > sgk[i]->ThanhTien())
        {
            minThanhTien = sgk[i]->ThanhTien();
        }
    }
    for(int i = 0; i < nSTK; i++)
    {
        if(minThanhTien > stk[i]->ThanhTien())
        {
            minThanhTien = stk[i]->ThanhTien();
        }
    }

    // Tìm sách có thành tiền thấp nhất
    vector<STK*> mtk;
    vector<SGK*> mgk;
    for(int i = 0; i < nSGK; i++)
    {
        if(minThanhTien == sgk[i]->ThanhTien())
        {
            mgk.push_back(sgk[i]);
        }
    }
    for(int i = 0; i < nSTK; i++)
    {
        if(minThanhTien == stk[i]->ThanhTien())
        {
            mtk.push_back(stk[i]);
        }
    }

    // Xuất thông tin các sách có thành tiền thấp nhất
    cout << "Xuat sach co thanh tien thap nhat: \n";
    for(int i = 0; i < mgk.size(); i++)
    {
        mgk[i]->Xuat();
    }
    for(int i = 0; i < mtk.size(); i++)
    {
        mtk[i]->Xuat();
    }

    // Xuất danh sách sách tìm được sau khi nhập nhà xuất bản
    vector<SGK*> nxb;
    nxb = SGK::TimSach(sgk);
    for(int i = 0; i < nxb.size(); i++)
    {
        nxb[i]->Xuat();
    }

    return 0;
}