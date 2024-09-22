#include <iostream>
using namespace std;
class SOFITEL
{
protected:
    int iSoDem;
    double dPhiDichVu;
public:
    SOFITEL() {}
    SOFITEL(int iSoDem, double dPhiDichVu) : iSoDem(iSoDem), dPhiDichVu(dPhiDichVu) {}
    SOFITEL(int iSoDem) : iSoDem(iSoDem) {}
    virtual double DoanhThuPhong() = 0;
};

class Deluxe : public SOFITEL
{
public:
    Deluxe() {}
    Deluxe(int iSoDem, double dPhiDichVu) : SOFITEL(iSoDem, dPhiDichVu) {};
    double DoanhThuPhong()
    {
        return iSoDem * 750000 + dPhiDichVu + dPhiDichVu;
    }
};

class Premium : public SOFITEL
{
public:
    Premium() {}
    Premium(int iSoDem, double dPhiDichVu) : SOFITEL(iSoDem, dPhiDichVu) {}
    double DoanhThuPhong()
    {
        return iSoDem * 500000 + dPhiDichVu;
    }
};

class Business : public SOFITEL
{
public:
    Business() {}
    Business(int iSoDem) : SOFITEL(iSoDem) {}
    double DoanhThuPhong()
    {
        return iSoDem * 300000;
    }
};

int main()
{
    // Phòng Deluxe
    Deluxe a(3, 100000);
    Deluxe b(10, 1000000);
    double sDeluxe = a.DoanhThuPhong() + b.DoanhThuPhong();

    // Phòng Premium
    Premium c(2, 300000);
    Premium d(5, 2000000);
    double sPremium = c.DoanhThuPhong() + d.DoanhThuPhong();


    // Phòng e
    Business e(7);
    double sBusiness = e.DoanhThuPhong();

    if(sBusiness > sDeluxe && sBusiness > sPremium)
    {
        cout << "Loai phong Business co danh thu cao nhat.\n";
    }
    else if(sDeluxe > sBusiness && sDeluxe > sPremium)
    {
        cout << "Loai phong Deluxe co doanh thu cao nhat.\n";
    }
    else
    {
        cout << "Loai phong Premium co doanh thu cao nhat.\n";
    }

    return 0;
}