#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ThucTheGame
{
protected:
    int iCapDo;
    double dSatThuong;
    string sHe;
public:
    ThucTheGame() {}
    ThucTheGame(int iCapDo) : iCapDo(iCapDo) {}
    double getSatThuong()
    {
        return dSatThuong;
    }
    virtual void Printf() = 0;
    string getHe()
    {
        return sHe;
    }
    void STTuongSinh()
    {
        dSatThuong += dSatThuong * 0.1;
    }
    friend void STTuongKhac(ThucTheGame* a, ThucTheGame *b)
    {
        a->dSatThuong += a->dSatThuong * 0.2;
        b->dSatThuong -= b->dSatThuong * 0.2;
    }
};

class NhanVat : public ThucTheGame
{
private:
    string sMonPhai;
public:
    NhanVat() {}
    NhanVat(int iCapDo, string sMonPhai) : ThucTheGame(iCapDo), sMonPhai(sMonPhai)
    {
        this->dSatThuong = iCapDo * 5;

        if(sMonPhai == "thienvuongbang" || sMonPhai == "thieulam")
        {
            sHe = "kim";
        }
        else if(sMonPhai == "ngudocgiao" || sMonPhai == "duongmon")
        {
            sHe = "moc";
        }
        else if(sMonPhai == "ngamy" || sMonPhai == "thuyyenmon")
        {
            sHe = "thuy";
        }
        else if(sMonPhai == "caibang" || sMonPhai == "thiennhangiao")
        {
            sHe = "hoa";
        }
        else
        {
            sHe = "tho";
        }
    }
    void Printf()
    {
        cout << "Nhan vat: " << "[ " << iCapDo << ", " << dSatThuong << ", " << sMonPhai << ", " << sHe << " ]\n";
    }

};

class QVTT : public ThucTheGame
{
public:
    QVTT() {}
    QVTT(int iCapDo, string sHe) : ThucTheGame(iCapDo)
    {
        this->dSatThuong = iCapDo * 3;
        this->sHe = sHe;
    }
    void Printf()
    {
        cout << "Quai vat thong thuong: " << "[" << iCapDo << ", " << dSatThuong << ", " << sHe << "]\n";
    }
};

class QVTL : public ThucTheGame
{
public: 
    QVTL() {}
    QVTL(int iCapDo, string sHe) : ThucTheGame(iCapDo)
    {
        this->dSatThuong = iCapDo * 7;
        this->sHe = sHe;
    }
    void Printf()
    {
        cout << "Quai vat thong linh: " << "[" << iCapDo << ", " << dSatThuong << ", " << sHe << "]\n";
    }
};

class VoLamTruyenKi 
{
private:
    vector<ThucTheGame*> ds;
public:
    VoLamTruyenKi() {}
    vector<ThucTheGame*> getDs()
    {
        return ds;
    }
    void NhapdsTTG()
    {
        int iCapDo;
        string sMonPhai;
        string sHe;

        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> iCapDo >> sMonPhai;
            ds.push_back(new NhanVat(iCapDo, sMonPhai));
        }

        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> iCapDo >> sHe;
            ds.push_back(new QVTT(iCapDo, sHe));
        }

        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> iCapDo >> sHe;
            ds.push_back(new QVTL(iCapDo, sHe));
        }
    }

    void XuatThucTheMucSTMax()
    {
        int stMax = ds[0]->getSatThuong();
        for(int i = 0; i < ds.size(); i++)
        {
            if(stMax < ds[i]->getSatThuong())
            {
                stMax = ds[i]->getSatThuong();
            }
        }
        
        cout << "Thuc the game co suc sat thuong cao nhat: ";
        for(int i = 0; i < ds.size(); i++)
        {
            if(ds[i]->getSatThuong() == stMax)
            {
                ds[i]->Printf();
            }
        }
    }

    void SoSanhSTTacDong(ThucTheGame* a, ThucTheGame* b)
    {
        
        if (a->getHe() == "hoa")
        {
            if (b->getHe() == "tho")
            {
                a->STTuongSinh();
            }
            else if(b->getHe() == "moc")
            {
                b->STTuongSinh();
            }
            else if(b->getHe() == "kim")
            {
                STTuongKhac(a, b);
            }
            else if(b->getHe() == "thuy")
            {
                STTuongKhac(b, a);
            }
        }
        else if (a->getHe() == "tho")
        {
            if (b->getHe() == "kim")
            {
                a->STTuongSinh();
            }
            else if(b->getHe() == "hoa")
            {
                b->STTuongSinh();
            }
            else if(b->getHe() == "thuy")
            {
                STTuongKhac(a, b);
            }
            else if(b->getHe() == "moc")
            {
                STTuongKhac(b, a);
            }
        } 
        else if (a->getHe() == "kim")
        {
            if (b->getHe() == "thuy")
            {
                a->STTuongSinh();
            }
            else if(b->getHe() == "tho")
            {
                b->STTuongSinh();
            }
            else if(b->getHe() == "moc")
            {
                STTuongKhac(a, b);
            }
            else if(b->getHe() == "hoa")
            {
                STTuongKhac(b, a);
            }
        }
        else if (a->getHe() == "thuy")
        {
            if (b->getHe() == "moc")
            {
                a->STTuongSinh();
            }
            else if(b->getHe() == "kim")
            {
                b->STTuongSinh();
            }
            else if(b->getHe() == "hoa")
            {
                STTuongKhac(a, b);
            }
            else if(b->getHe() == "tho")
            {
                STTuongKhac(b, a);
            }
        }
        else 
        {
            if (b->getHe() == "hoa")
            {
                a->STTuongSinh();
            }
            else if(b->getHe() == "thuy")
            {
                b->STTuongSinh();
            }
            else if(b->getHe() == "moc")
            {
                STTuongKhac(a, b);
            }
            else if(b->getHe() == "kim")
            {
                STTuongKhac(b, a);
            }
        }
    
        if(a->getSatThuong() > b->getSatThuong())
        {
            cout << "Sat thuong cua A len B lon hon sat thuong cua B len A.\n";
        }
        else if(a->getSatThuong() < b->getSatThuong())
        {
            cout << "Sat thuong cua A len B nho hon sat thuong cua B len A.\n";
        }
        else
        {
            cout << "Sat thuong cua A len B bang sat thuong cua B len A.\n";
        }

    }
};

int main()
{
    VoLamTruyenKi k;
    // 1
    k.NhapdsTTG();
    // 2
    k.XuatThucTheMucSTMax();
    // 3
    k.SoSanhSTTacDong(k.getDs()[1], k.getDs()[5]);

    return 0;
}