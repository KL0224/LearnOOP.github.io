#include <bits/stdc++.h>
using namespace std;

class String
{
    char* p;
public:
    String(char*);
    String(const String&);
    ~String();
    String& operator = (const String&);
    char& operator [](int);
    friend ostream& operator<<(ostream&, String);
};

String::String(char* s = "")
{
    p = strdup(s);
}

String::String(const String& s)
{
    p = strdup(s.p);
}

String::~String()
{
    cout << "delete" << (void*)p << "\n";  delete[] p;
}

String& String::operator=(const String& s)
{
    if(this != &s)
    {
        delete[] p;
        p = strdup(s.p);
    }

    return *this;
}

char& String::operator[](int i)
{
    return p[i];
}

ostream& operator<<(ostream& os, String a)
{
    os << a.p;
}

int main()
{
    String a("Nguyen Van A");
    String b = a;
    String aa = "Le van AA";
    cout << a[3] << endl;
    cout << "aa = " << aa << " "; cout << "\n";
    aa = a;
    cout << "aa = " << aa << " "; cout << "\n";
    return 0;
}