#include <iostream>
#include <cstring>
#include <vector>

class Tho
{
protected:
    int iSoCau;
    int iSoTieng;
    std::vector<std::vector<std::string>> str;
public:
    Tho() {}
    Tho(int iSoCau, int iSoTieng, const std::vector<std::vector<std::string>> &str) : iSoCau(iSoCau), iSoTieng(iSoTieng), str(str) {}
    int getSoCau()
    {
        return iSoCau;
    }
    std::string TachVan(const std::string &);
    friend void TimThoDaiNhat(std::vector<Tho*>);
    friend void KiemTraLuatTatCabaiTho(std::vector<Tho*>);
    virtual bool KiemTraGieoVan() = 0;
};

std::string Tho::TachVan(const std::string &str)
{
    std::string s;
    for(int j = 0; j < str.size(); j++)
        {
            if(str[j] == 'a' || str[j] == 'o' || str[j] == 'i' || str[j] == 'u' || str[j] == 'e')
            {
                 s = str.substr(j, str.size() - j);
                break;
            }
        }
    
    return s;
}

void TimThoDaiNhat(std::vector<Tho *> t)
{
    int tMax = t[0]->getSoCau();
    for(int i = 1; i < t.size(); i++)
    {
        if(t[i]->getSoCau() > tMax)
        {
            tMax = t[i]->getSoCau();
        }
    }

    for(int i = 0; i < t.size(); i++)
    {
        if(t[i]->getSoCau() == tMax)
        {
            std::cout << "Bai tho thu " << i + 1 << " la dai nhat.\n";
        }
    }
}

void KiemTraLuatTatCabaiTho(std::vector<Tho *> t)
{
    for(int i = 0; i < t.size(); i++)
    {
        if(t[i]->KiemTraGieoVan())
        {
            std::cout << "Bai tho thu " << i + 1 << " dung voi luat tho.\n";
        }
        else
        {
            std::cout << "Bai tho thu " << i + 1 << " khong dung voi luat tho.\n";
        }
    }
}

class LucBat : public Tho
{
public:
    LucBat() {}
    LucBat(int iSoCau, int iSoTieng, const std::vector<std::vector<std::string>> &str) : Tho(iSoCau, iSoTieng, str) {}
    bool KiemTraGieoVan() override;
};


bool LucBat::KiemTraGieoVan()
{
    std::vector<std::string> sVanLung;
    for(int i = 0; i < this->iSoCau; i++)
    {
        if(i % 2 == 0)
        {
            std::string s = this->TachVan(str[i][5]);
            sVanLung.push_back(s);
        }
        else
        {
            std::string s = this->TachVan(str[i][5]);
            sVanLung.push_back(s);

            std::string s1 = this->TachVan(str[i][7]);
            sVanLung.push_back(s1);
        }
    }

    for(int i = 0; i < sVanLung.size() - 2; i +=2)
    {
        if(i == 0)
        {
            if(sVanLung[i] != sVanLung[i + 1])
            return false;
        }
        else if(sVanLung[i] != sVanLung[i + 1] || sVanLung[i] != sVanLung[i + 2])
        {
            i++;
            return false;
        }
    }

    return true;
}

class SongThatLucBat : public Tho
{
private:
    std::vector<std::vector<std::string>> stlbThanh;
public:    
    SongThatLucBat() {}
    SongThatLucBat(int iSoCau, int iSoTieng, const std::vector<std::vector<std::string>> &str, const std::vector<std::vector<std::string>> &stlbThanh) 
    : Tho(iSoCau, iSoTieng, str), stlbThanh(stlbThanh) {}
    bool KiemTraGieoVan() override;
};

bool SongThatLucBat::KiemTraGieoVan()
{
    // Xét luật bằng trắc của cặp câu lục bát và song thất
    for(int i = 0; i < this->stlbThanh[0].size(); i++)
    {
        if((std::string)this->stlbThanh[0][i] != "bang")
        {
            return false;
        }
    }

    for(int i = 0; i < this->stlbThanh[1].size(); i++)
    {
        if(this->stlbThanh[1][i] != "trac")
        {
            return false;
        }
    }

    // Lấy vần lưng và vần liền
    std::vector<std::string> sVanLung;
    std::vector<std::string> sVanLien;
    for(int i = 0; i < this->iSoCau; i += 4)
    {
        // Lấy vần lưng
        std::string s = TachVan(this->str[i][6]); // Dòng 7
        std::string s1 = TachVan(this->str[i + 1][4]); // Dòng 7
        std::string s2 = TachVan(this->str[i + 2][5]); // Dòng 6
        std::string s3 = TachVan(this->str[i + 3][5]); // Dòng 8
        sVanLung.push_back(s);
        sVanLung.push_back(s1);
        sVanLung.push_back(s2);
        sVanLung.push_back(s3);

        // Lấy vần liền
        std::string s4 = TachVan(this->str[i + 1][6]);
        sVanLien.push_back(s4);
        sVanLien.push_back(s2);
    }

    //  Xét luật thơ theo xét vần lưng và phần liền
    for(int i = 0; i < sVanLung.size(); i += 2)
    {
        if(sVanLung[i].find(sVanLung[i + 1]) == std::string::npos && sVanLung[i + 1].find(sVanLung[i]) == std::string::npos)
        {
            return false;
        }
        if(i < sVanLien.size() && sVanLien[i].find(sVanLien[i + 1]) == std::string::npos && sVanLien[i + 1].find(sVanLien[i]) == std::string::npos)
        {
            return false;
        }
    }  

    return true;
}

class ThatNgonBatCu : public Tho
{
private: 
    std::vector<std::string> tnbcThanh;
public:
    ThatNgonBatCu() {}
    ThatNgonBatCu(int iSoCau, int iSoTieng, const std::vector<std::vector<std::string>> &str, const std::vector<std::string> &tnbcThanh) 
    : Tho(iSoCau, iSoTieng, str), tnbcThanh(tnbcThanh) {}
    bool KiemTraGieoVan() override;
};

bool ThatNgonBatCu::KiemTraGieoVan()
{
    for(int i = 1; i < tnbcThanh.size(); i++)
    {
        if(this->tnbcThanh[0] != this->tnbcThanh[i])
        {
            return false;
        }
    }

    return true;
}


int main()
{
    // Khởi tạo vector t để quan lý toàn bộ thơ
    std::vector<Tho *> t;

    // Khởi tạo thơ lục bát
    std::vector<std::vector<std::string>> sLucBat;
    // Khởi tạo từng dòng thơ
    std::vector<std::string> lbd1= { "tram","nam","trong","coi","nguoi","ta" }; 
    std::vector<std::string> lbd2= { "chu","tai", "chu","menh","kheo","la","ghet","nhau"}; 
    std::vector<std::string> lbd3= { "trai","qua","mot","cuoc","be","dau" };
    std::vector<std::string> lbd4= {"nhung","dieu","trong","thay","ma","dau","don","long"};
    // Truyền vào vector sLucBat
    sLucBat.push_back(lbd1);
    sLucBat.push_back(lbd2);
    sLucBat.push_back(lbd3);
    sLucBat.push_back(lbd4);
    // Khởi tạo đối tượng ThoLucBat
    Tho *lb = new LucBat(4, 28, sLucBat);

    // Khởi tạo thơ song thất lục bát
    std::vector<std::vector<std::string>> sSongThatLucBat;
    std::vector<std::vector<std::string>> stlb_Thanh; // Nơi chứa thanh của cặp câu song thất và lục bát
    // Khởi tạo từng dòng thơ
    std::vector<std::string> stlbd1 = {"ngoi", "dau", "cau", "nuoc", "trong", "nhu", "ngoc"};
    std::vector<std::string> stlbd2 = {"duong", "ben", "cau", "co", "moc", "con", "non"};
    std::vector<std::string> stlbd3 = {"dua", "chang", "long", "dac", "dac", "buon"};
    std::vector<std::string> stlbd4 = {"bo", "khon", "bang", "ngua", "thuy", "khon", "bang", "thuyen"};
    // Truyền vào vector sSongThatLucBat
    sSongThatLucBat.push_back(stlbd1);
    sSongThatLucBat.push_back(stlbd2);
    sSongThatLucBat.push_back(stlbd3);
    sSongThatLucBat.push_back(stlbd4);

    // Khởi tạo thanh của lục bát và thanh của song thất
    std::vector<std::string> lbThanh = {"bang", "bang"};
    std::vector<std::string> stThanh = {"trac", "trac"};
    stlb_Thanh.push_back(lbThanh);
    stlb_Thanh.push_back(stThanh);

    // Khởi tạo đối tượng SongThatLucBat
    Tho *stlb = new SongThatLucBat(4, 28, sSongThatLucBat, stlb_Thanh);

    // Khởi tạo thơ thất ngôn bát cú
    std::vector<std::vector<std::string>> sThatNgonBatCu;
    // Khởi tạo từng dòng thơ
    std::vector<std::string> tnbcd1 = {"buoc", "toi", "deo", "ngang", "bong", "xe", "ta"};
    std::vector<std::string> tnbcd2 = {"co", "cay", "chen", "la", "da", "chen", "hoa"};
    std::vector<std::string> tnbcd3 = {"lom", "khom", "duoi", "nui", "tieu" ,"vai", "chu"};
    std::vector<std::string> tnbcd4 = {"lac", "dac", "ben", "song", "cho", "may", "nha"};
    std::vector<std::string> tnbcd5 = {"nho", "nuoc", "dau", "long", "con", "quoc", "quoc"};
    std::vector<std::string> tnbcd6 = {"thuong", "nha", "moi", "mieng", "cai" ,"gia", "gia"};
    std::vector<std::string> tnbcd7 = {"dung", "chan", "dung", "lai", "troi", "non", "nuoc"};
    std::vector<std::string> tnbcd8 = {"mot", "manh", "tinh", "duyen", "ta", "voi", "ta"};
    // Truyền vào vector sSongThatLucBat
    sThatNgonBatCu.push_back(tnbcd1);
    sThatNgonBatCu.push_back(tnbcd2);
    sThatNgonBatCu.push_back(tnbcd3);
    sThatNgonBatCu.push_back(tnbcd4);
    sThatNgonBatCu.push_back(tnbcd5);
    sThatNgonBatCu.push_back(tnbcd6);
    sThatNgonBatCu.push_back(tnbcd7);

    // Khởi tạo thanh của từ cuối của các câu 1, 2, 4, 6, 8 trong bài thơ trên để xét luật thơ
    std::vector<std::string> tnbc_Thanh = {"bang", "bang", "bang", "bang", "bang"};

    // Khởi tạo đối tượng SongThatLucBat
    Tho *tnbc = new ThatNgonBatCu(7, 56, sThatNgonBatCu, tnbc_Thanh);

    // Đưa các tập thơ vào tập thơ t
    t.push_back(lb);
    t.push_back(stlb);
    t.push_back(tnbc);
    
    // Kiểm tra luật thơ
   KiemTraLuatTatCabaiTho(t);

    // Tìm thơ dài nhất trong 3 bài thơ trên
    TimThoDaiNhat(t);

    delete lb, stlb, tnbc;
    return 0;
}