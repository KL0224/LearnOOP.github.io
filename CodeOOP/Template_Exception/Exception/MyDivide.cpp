#include <iostream>
#include <exception>
using namespace std;

double MyDivide(double numerator, double denominator)
{
    if(denominator == 0.0)
    {
        throw invalid_argument("The denominator cannot be 0.");
    }
    else
    {
        return numerator / denominator;
    }
}

int main()
{
    int x;
    int y;
    double result;
    
    do
    {
        cout << "Nhap 2 so x va y: ";
        cin >> x >> y;

        try
        {
            result = MyDivide(x, y);
            cout << "x/y = " << result << endl; 
        }
        catch(invalid_argument& e)
        {
            cout << e.what() << '\n';
        };
    } while (1);
    return 0;
}