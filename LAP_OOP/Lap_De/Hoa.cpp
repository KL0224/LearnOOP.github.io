#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ThanhPhan
{
protected:
    string sMauChu;
    string sMauNen;
public:
    ThanhPhan() {}
    ThanhPhan(string sMauChu, string sMauNen) : sMauChu(sMauChu), sMauNen(sMauNen) {}
    string getMauChu()
    {
        return sMauChu;
    }
    string getMauNen()
    {
        return sMauNen;
    }
};

class Label : public ThanhPhan
{
public:
    Label() {}
    Label(string sMauChu, string sMauNen) : ThanhPhan(sMauChu, sMauNen) {}
};

class Button : public ThanhPhan
{
public:
    Button() {}
    Button(string sMauChu, string sMauNen) : ThanhPhan(sMauChu, sMauNen) {}
};

class Website
{
private:
    string sTenWebsite;
    vector<ThanhPhan*> ds;
public:
    Website() {}
    Website(string sTenWebsite) :  sTenWebsite(sTenWebsite) {};
    vector<ThanhPhan*> getDs()
    {
        return ds;
    }
    void NhapDsThanhPhan();
    bool KiemTraPhoiMauDonSac(const vector<string>&);
    bool KiemTraPhoiMauBoTucTrucTiep(const vector<string>&);
    bool KiemTraPhoiMauTuongDong(const vector<string>&);
};

void Website::NhapDsThanhPhan()
{
    string sMauChu;
    string sMauNen;

    int n;
    cout << "Nhap so luong doi tuong Label trong danh sach: ";
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cout << "Nhap doi tuong Label thu " << i + 1 << " :\n";
        cout << "Mau chu: ";
        cin >> sMauChu;
        cout << "Mau nen: ";
        cin >> sMauNen;
        ds.push_back(new Label(sMauChu, sMauNen));
    }

    int m;
    cout << "Nhap so luong doi tuong Button trong danh sach: ";
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        cout << "Nhap doi tuong Button thu " << i + 1 << " :\n";
        cout << "Mau chu: ";
        cin >> sMauChu;
        cout << "Mau nen: ";
        cin >> sMauNen;
        ds.push_back(new Button(sMauChu, sMauNen));
    }
}

bool Website::KiemTraPhoiMauDonSac(const vector<string>& color)
{
    for(int i = 1; i < color.size(); i++)
    {
        if(color[0] != color[i])
        {
            return false;
        }
    }

    return true;
}

// Bộ màu đối xứng : red - cyan, orange - occean, yellow - blue, spring_green - violet, green - magenta, turquois - raspberry
bool Website::KiemTraPhoiMauBoTucTrucTiep(const vector<string>& color)
{
    // Bảng trạng thái màu xuất hiện theo thứa tự: red, orange, yellow, spring_green, green, tuaquoise, cyan, ocean, blue, violet, magenta, raspberry.
    int tt[12] = {0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0};

    for(int i = 0; i < color.size(); i++)
    {
        if(color[i] == "red") tt[0] = 1;
        else if(color[i] == "orange") tt[1] = 1;
        else if(color[i] == "yellow") tt[2] = 1;
        else if(color[i] == "spring_green") tt[3] = 1;
        else if(color[i] == "green") tt[4] = 1;
        else if(color[i] == "tuaquosie") tt[5] = 1;
        else if(color[i] == "cyan") tt[6] = 1;
        else if(color[i] == "ocean") tt[7] = 1;
        else if(color[i] == "blue") tt[8] = 1;
        else if(color[i] == "violet") tt[9] = 1;
        else if(color[i] == "magenta") tt[10] = 1;
        else if(color[i] == "raspberry") tt[11] = 1;
    }

    for(int i = 0; i < 6; i++)
    {
        if(tt[i] + tt[6 + i] == 2)
        {
            return true;
        }
    }

    return false;
}

// Bộ 3 màu: red - orange - yellow, orange - yellow - spring_green,...
bool Website::KiemTraPhoiMauTuongDong(const vector<string>& color)
{
    // Bảng trạng thái màu xuất hiện theo thứa tự: red, orange, yellow, spring_green, green, tuaquoise, cyan, ocean, blue, violet, magenta, raspberry.
     int tt[12] = {0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0};

    for(int i = 0; i < color.size(); i++)
    {
        if(color[i] == "red") tt[0] = 1;
        else if(color[i] == "orange") tt[1] = 1;
        else if(color[i] == "yellow") tt[2] = 1;
        else if(color[i] == "spring_green") tt[3] = 1;
        else if(color[i] == "green") tt[4] = 1;
        else if(color[i] == "tuaquosie") tt[5] = 1;
        else if(color[i] == "cyan") tt[6] = 1;
        else if(color[i] == "ocean") tt[7] = 1;
        else if(color[i] == "blue") tt[8] = 1;
        else if(color[i] == "violet") tt[9] = 1;
        else if(color[i] == "magenta") tt[10] = 1;
        else if(color[i] == "raspberry") tt[11] = 1;
    }

    for(int i = 0; i < 10; i++)
    {
        if(tt[i] + tt[i + 1] + tt[i + 2] == 3)
        {
            return true;
        }
    }

    return false;
}


int main()
{   
    // Yêu cầu 3.1
    Website k("DoHoa");
    k.NhapDsThanhPhan();

    // Yêu cầu 3.2
    if(k.KiemTraPhoiMauBoTucTrucTiep({k.getDs()[0]->getMauChu(), k.getDs()[0]->getMauNen()}))
    {
        cout << "Thanh phan dau trong danh sach phu hop voi cach phoi mau bo tuc truc tiep.\n";
    }
    else
    {
        cout << "Thanh phan dau trong danh sach khong phu hop voi cach phoi mau bo tuc truc tiep.\n";
    }

    // Yêu cầu 3.3
    vector<string> fullMauNen;
    for(int i = 0; i < k.getDs().size(); i++)
    {
        fullMauNen.push_back(k.getDs()[i]->getMauNen());
    }
    if(k.KiemTraPhoiMauDonSac(fullMauNen))
    {
        cout << "Mau nen cua tat ca thanh phan phu hop voi cach phoi mau don sac.\n";
    }
    if(k.KiemTraPhoiMauBoTucTrucTiep(fullMauNen))
    {
        cout << "Mau nen cua tat ca thanh phan phu hop voi cach phoi mau bo tuc truc tiep.\n";
    }
    if(k.KiemTraPhoiMauTuongDong(fullMauNen))
    {
        cout << "Mau nen cua tat ca thanh phan phu hop voi cach phoi mau tuong dong.\n";
    }
    if(!(k.KiemTraPhoiMauDonSac(fullMauNen) || k.KiemTraPhoiMauBoTucTrucTiep(fullMauNen) || k.KiemTraPhoiMauTuongDong(fullMauNen)))
    {
        cout << "Mau nen cua tat ca thanh phan khong phu hop voi cach phoi mau  nao.\n";
    }

    return 0;
}

