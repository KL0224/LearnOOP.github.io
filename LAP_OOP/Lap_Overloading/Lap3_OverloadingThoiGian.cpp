#include <iostream>
#include <string>

class ThoiGian
{
private:
	int iGio, iPhut, iGiay;
public:
	ThoiGian();
	ThoiGian(int, int, int);
	int TinhGiay();
	ThoiGian TinhLaiGio(int);
	friend ThoiGian operator+(ThoiGian, int);
	friend ThoiGian operator-(ThoiGian, int);
	friend ThoiGian operator+(ThoiGian, ThoiGian);
	friend ThoiGian operator-(ThoiGian, ThoiGian);
	void operator++();
	void operator--();
	friend bool operator==(ThoiGian, ThoiGian);
	friend bool operator!=(ThoiGian, ThoiGian);
	friend bool operator>=(ThoiGian, ThoiGian);
	friend bool operator<=(ThoiGian, ThoiGian);
	friend bool operator>(ThoiGian, ThoiGian);
	friend bool operator<(ThoiGian, ThoiGian);
	friend std::istream& operator>>(std::istream& is, ThoiGian&);
	friend std::ostream& operator<<(std::ostream& ou, ThoiGian);
};

ThoiGian::ThoiGian()
{
	this->iGio = 0;
	this->iPhut = 0;
	this->iGiay = 0;
}

ThoiGian::ThoiGian(int iGio, int iPhut, int iGiay)
{
	this->iGio = iGio;
	this->iPhut = iPhut;
	this->iGiay = iGiay;
}

int ThoiGian::TinhGiay()
{
	return this->iGio * 60 * 60 + this->iPhut * 60 + this->iGiay;
}

ThoiGian ThoiGian::TinhLaiGio(int t)
{
	this->iGio = t / 3600;
	this->iPhut = t % 3600 / 60;
	this->iGiay = t % 3600 % 60;

	return *this;
}

ThoiGian operator+(ThoiGian a, int t)
{
	ThoiGian b;
	b.TinhLaiGio(t);

	return a + b;
}

ThoiGian operator-(ThoiGian a, int t)
{
	ThoiGian b;
	b.TinhLaiGio(t);

	return a - b;
}

ThoiGian operator+(ThoiGian a, ThoiGian b)
{
	int giay = a.iGiay + b.iGiay;
	if (giay >= 60)
	{
		giay -= 60;
		b.iPhut++;
	}

	int phut = a.iPhut + b.iPhut;
	if (phut >= 60)
	{
		phut -= 60;
		b.iGio++;
	}

	int gio = a.iGio + b.iGio;
	if (gio >= 24)
	{
		gio -= 24;
	}

	return ThoiGian(gio, phut, giay);
}

ThoiGian operator-(ThoiGian a, ThoiGian b)
{
	int giay = a.iGiay - b.iGiay;
	if (giay < 0)
	{
		giay += 60;
		b.iPhut++;
	}

	int phut = a.iPhut - b.iPhut;
	if (phut < 0)
	{
		phut += 60;
		b.iGio++;
	}

	int gio = a.iGio - b.iGio;
	if (gio < 0)
	{
		gio += 24;
	}

	return ThoiGian(gio, phut, giay);
}

void ThoiGian::operator++()
{
	if (this->iGiay == 59)
	{
		this->iGiay = 0;
		this->iPhut++;
	}
	else
	{
		this->iGiay++;
	}

	if (this->iPhut == 60)
	{
		this->iPhut = 0;
		this->iGio++;
	}

	if (this->iGio == 24)
	{
		this->iGio = 0;
	}

}

void ThoiGian::operator--()
{
	if (this->iGiay == 0)
	{
		this->iGiay = 59;
		this->iPhut--;
	}
	else
	{
		this->iGiay--;
	}

	if (this->iGiay == -1)
	{
		this->iPhut = 59;
		this->iGio--;
	}

	if (this->iGio == -1)
	{
		this->iGio = 23;
	}
}

bool operator==(ThoiGian a, ThoiGian b)
{
	return (a.iGio == b.iGio) && (a.iPhut == b.iPhut) && (a.iGiay == b.iGiay);
}

bool operator!=(ThoiGian a, ThoiGian b)
{
	return !(a == b);
}

bool operator>(ThoiGian a, ThoiGian b)
{
	if (a != b)
	{
		if (a.iGio > b.iGio)
		{
			return true;
		}
		else if (a.iGio < b.iGio)
		{
			return false;
		}
		else
		{
			if (a.iPhut > b.iPhut)
			{
				return true;
			}
			else if(a.iPhut < b.iPhut)
			{
				return false;
			}
			else
			{
				if (a.iGiay > b.iGiay)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
	}

	return false;
}

bool operator>=(ThoiGian a, ThoiGian b)
{
	return a > b || a == b;
}

bool operator<(ThoiGian a, ThoiGian b)
{
	return !(a >= b);
}

bool operator<=(ThoiGian a, ThoiGian b)
{
	return a < b || a == b;
}

std::istream& operator>>(std::istream& is, ThoiGian& a)
{
	std::cout << "Nhap gio phut giay: ";
	is >> a.iGio >> a.iPhut >> a.iGiay;
	bool checkInput = true;
	while (checkInput)
	{
		if (a.iGio < 0 || a.iGio > 23)
		{
			std::cout << "Ban da nhap sai gio. Vui long nhap lai gio phut giay.\n";
			std::cout << "Nhap gio phut giay: ";
			is >> a.iGio >> a.iPhut >> a.iGiay;
		}
		if (a.iPhut < 0 || a.iPhut > 59)
		{
			std::cout << "Ban da nhap sai phut. Vui long nhap lai gio phut giay.\n";
			std::cout << "Nhap gio phut giay: ";
			is >> a.iGio >> a.iPhut >> a.iGiay;
		}
		if (a.iGiay < 0 || a.iGiay > 59)
		{
			std::cout << "Ban da nhap sai giay. Vui long nhap lai gio phut giay.\n";
			std::cout << "Nhap gio phut giay: ";
			is >> a.iGio >> a.iPhut >> a.iGiay;
		}
		if ((a.iGio >= 0 && a.iGio <= 23) && (a.iPhut >= 0 && a.iPhut <= 59) && (a.iGiay >= 0 && a.iGiay <= 59))
		{
			std::cout << "Ban nhap gio phut giay hop le.\n";
			checkInput = false;
		}
	}

	return is;
}

std::ostream& operator<<(std::ostream& os, ThoiGian a)
{
	std::string iGio = std::to_string(a.iGio);
	std::string iPhut = std::to_string(a.iPhut);
	std::string iGiay = std::to_string(a.iGiay);

	if (iGio.size() == 1)
	{
		iGio = '0' + iGio;
	}
	if (iPhut.size() == 1)
	{
		iPhut = '0' + iPhut;
	}
	if (iGiay.size() == 1)
	{
		iGiay = '0' + iGiay;
	}

	os << iGio << ":" << iPhut << ":" << iGiay << "\n";
	return os;
}

int main()
{
	// Khai báo 2 thời gian 
	ThoiGian a(23, 59, 59);
	std::cout << "Thoi gian a la: " << a;
	ThoiGian b;
	std::cin >> b;
	std::cout << "Thoi gian b la: " << b;

	// Phuong thuc tinh giay
	std::cout << "So giay cua thoi gian a la: " << a.TinhGiay() << "\n";

	// Phuong thuc tinh gio
	ThoiGian change;
	change.TinhLaiGio(30000);
	std::cout << "Thoi gian sau khi chuyen doi 30000 giay: " << change;

	// Phuong thuc + giay
	ThoiGian sum = a + 10000;
	std::cout << "Thoi gian a sau khi cong 10000 giay la: " << sum;

	// Phung thuc - giay 
	ThoiGian sub = a - 10000;
	std::cout << "Thoi gian a sau khi tru 10000 giay la: " << sub;
	
	// Phuong thuc + ThoiGian
	ThoiGian Sum = a + b;
	std::cout << "Thoi gian sau khi lay a cong b la: " << Sum;

	// Phuong thuc - ThoiGian
	ThoiGian Sub = a - b;
	std::cout << "Thoi gian sau khi lay a tru ba la: " << Sub;

	// Phuong thuc ++
	++a;
	std::cout << "Thoi gian sau khi a cong 1 giay la: " << a;

	//Phuong thuc --
	--b;
	std::cout << "Thoi gian sau khi b tru 1 giay la: " << b;

	//Phuong thuc a == c
	ThoiGian c(0, 0, 0);
	if (a == c)
	{
		std::cout << "Thoi gian thu nhat bang thoi gian thu hai.\n";
	}

	//Phuong thuc a != b
	if (a != b)
	{
		std::cout << "Thoi gian thu nhat khac thoi gian thu 2.\n";
	}

	// Phuong thuc b >= c
	if (b >= c)
	{
		std::cout << "Thoi gian thu nhat lon hon hoac bang thoi gian thu hai.\n";
	}

	// Phuong thuc b > c
	if (b > c)
	{
		std::cout << "Thoi gian thu nhat lon hon thoi gian thu hai.\n";
	}

	// Phuong thuc c <= d
	ThoiGian d(10, 20, 3);
	if (c <= d)
	{
		std::cout << "Thoi gian thu nhat nho hon hoac bang thoi gian thu hai.\n";
	}

	// Phuong thuc a < d
	if (a < d)
	{
		std::cout << "Thoi gian thu nhat nho hon thoi gian hai.\n";
	}

	return 0;
}