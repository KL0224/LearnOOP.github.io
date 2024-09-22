#include <iostream>
#include <cstring>
using namespace std;

class Nguoi
{
public: enum LOAI{NGUOI, SV, CN};
protected:
    char* cHoTen;
    int iNamSinh;
public:
    LOAI pl;
    Nguoi(char* ht, int ns) : iNamSinh(ns), pl(NGUOI)
    {
        cHoTen = strdup(ht);
    }
    ~Nguoi()
    {
        delete[] cHoTen;
    }
    void An() const
    {
        cout << cHoTen << " an 1 ngay 70k.\n";
    }
    void Xuat() const
    {
        cout << "Nguoi, ho ten: " << cHoTen << " sinh nam: " << iNamSinh << "\n";
    }
};

class SinhVien: public Nguoi
{
protected:
    char* cMaSo;
public:
    SinhVien(char* ht, char* ms, int ns) : Nguoi(ht, ns)
    {
        cMaSo = strdup(ms);
        pl = SV;
    }
    ~SinhVien()
    {
        delete[] cMaSo;
    }
    void Xuat() const
    {
        cout << "Sinh vien, ten: " << cHoTen << " ma so: " << cMaSo << "\n";
    }
};

class CongNhan : public Nguoi
{
protected: 
    double dMucLuong;
public:
    CongNhan(char *ht, double ml, int ns) : Nguoi(ht, ns), dMucLuong(ml)
    {
        pl = CN;
    }
    void Xuat() const
    {
        cout << "Cong nhan, ten: " << cHoTen << " muc luong: " << dMucLuong << "\n";
    }
};

void XuatDs(int n, Nguoi* an[])
{
    for(int i = 0; i < n; i++)
    {
        switch(an[i]->pl)
        {
            case Nguoi::SV:
                ((SinhVien*)an[i])->Xuat();
                break;
            case Nguoi::CN:
                ((CongNhan*)an[i])->Xuat();
                break;
            default:
                an[i]->Xuat();
                break;
        }
    }
}

const int N = 4;
int main()
{
    Nguoi * an[N];
    an[0] = new SinhVien("Pham Anh Kiet", "23520816", 2005);
    an[1] = new SinhVien("Phan Thi Kim Loan", "001", 2006);
    an[2] = new CongNhan("Nguyen Hong Thuy", 1000, 2005);
    an[3] = new Nguoi("Hung Long", 2004);
    XuatDs(4, an);
    return 0;
}