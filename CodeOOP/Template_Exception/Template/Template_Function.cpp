// Template swap()
#include <iostream>
using namespace std;

template < typename T>
void Swap(T &x, T &y)
{
    T temp = x;
    x = y;
    y = temp;
}

int main()
{
    int x = 6;
    int y = 9;
    cout << "x = " << x << ", y = " << y << "\n";
    cout << "x and y after swap\n";
    Swap(x, y);
    cout << "x = " << x << ", y = " << y << "\n";
    return 0;
}