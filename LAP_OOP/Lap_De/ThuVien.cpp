#include <iostream>
#include <vector>
using namespace std;

class Sach
{
protected:
    int maSach;
    string tenSach;
    string nhaXuatBan;
    int soLuong;
    float donGia;
public:
    Sach() {}
    Sach(int maSach, string tenSach, string nhaXuatBan, int soLuong, float donGia) :
        maSach(maSach), tenSach(tenSach), nhaXuatBan(nhaXuatBan), soLuong(soLuong), donGia(donGia) {}
    string getTenSach()
    {
        return tenSach;
    }
    string getNhaXuatBan()
    {
        return nhaXuatBan;
    }
    void Printf()
    {
        // Thông tin có dạng: [mã sách, tên sách, nhà xuất bản, số lượng, đơn giá]
        cout << "[ " << maSach << ", " << tenSach << ", " << nhaXuatBan << ", " << soLuong << ", " << donGia << " ]\n";
    }
    virtual float ThanhTien() = 0;
};

class SGK : public Sach
{
    bool tinhTrang;
public:
    SGK() {}
    SGK(int maSach, string tenSach, string nhaXuatBan, int soLuong, float donGia, bool tinhTrang) : 
        Sach(maSach, tenSach, nhaXuatBan, soLuong, donGia), tinhTrang(tinhTrang) {}
    float ThanhTien()
    {
        if(tinhTrang) return soLuong * donGia;
        return soLuong * donGia * 0.5;
    } 
};

class STK : public Sach
{
    float thue;
public:
    STK() {}
    STK(int maSach, string tenSach, string nhaXuatBan, int soLuong, float donGia, float thue) : 
        Sach(maSach, tenSach, nhaXuatBan, soLuong, donGia), thue(thue) {}
    float ThanhTien()
    {
        return soLuong * donGia + thue;
    }
};

class ThuVien
{
private:
    string tenThuVien;
    vector<Sach*> ds;
public:
    ThuVien() {}
    ThuVien(string ten) : tenThuVien(ten) {}

    // Giải quyết câu 3.1
    void NhapDsSach()
    {
        int maSach;
        string tenSach;
        string nhaXuatBan;
        int soLuong;
        float donGia;
        bool tinhTrang;
        float thue;
        int n;
        cout << "Nhap so luong sach giao khoa: ";
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            // Nhap sach theo template: ma sach, ten sach, nha xuat ban, so luong, don gia, tinh trang.
            cin >> maSach >> tenSach >> nhaXuatBan >> soLuong >> donGia >> tinhTrang;
            ds.push_back(new SGK(maSach, tenSach, nhaXuatBan, soLuong, donGia, tinhTrang));
        }

        cout << "Nhap so luong sach tham khao: ";
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            // Nhap sach theo template: ma sach, ten sach, nha xuat ban, so luong, don gia, thue.
            cin >> maSach >> tenSach >> nhaXuatBan >> soLuong >> donGia >> thue;
            ds.push_back(new STK(maSach, tenSach, nhaXuatBan, soLuong, donGia, thue));
        }
    }

    void XuatDsSach()
    {
        for(int i = 0; i < ds.size(); i++)
        {
            ds[i]->Printf();
        }
    }

    // Giải quyết câu 3.2
    void TinhThanhTien()
    {
        for(int i = 0; i < ds.size(); i++)
        {
            cout << "Thanh tien ma thu vien phai tra cho sach " << ds[i]->getTenSach() << " la: " << ds[i]->ThanhTien() << endl;
        }
    }

    void InsachCoTTMin()
    {
        int minSach = ds[0]->ThanhTien();
        for(int i = 1; i < ds.size(); i++)
        {
            if(ds[i]->ThanhTien() < minSach) minSach = ds[i]->ThanhTien();
        }
        
        cout << "Sach co thanh tien nho nhat:\n";
        for(int i = 0; i < ds.size(); i++)
        {
            if(ds[i]->ThanhTien() == minSach) ds[i]->Printf();
        }
    }

    // Giải quyết câu 3.3
    void TimSGK_theoNXB(string nxb);
    {
        cout << "Sach giao khoa co nha xuat ban la: " << nxb << ".\n";
        for(int i = 0; i < ds.size(); i++)
        {
            if(ds[i]->getNhaXuatBan() == nxb)
            {
                ds[i]->Printf();
            }
        }
    }
};

int main()
{
    ThuVien x("UIT");
    // 3.1
    x.NhapDsSach();
    x.XuatDsSach();
    // 3.2
    x.TinhThanhTien();
    x.InsachCoTTMin();
    // 3.3
    cout << "Nhap ten nha xuat ban: ";
    string nxb;
    cin >> nxb;
    x.TimSGK_theoNXB(nxb);
    return 0;
}

