#include <iostream>

class Matrix
{
private:
    float **M;
    int row, col;
public:
    Matrix(int, int);
    ~Matrix();
    float& operator() (int, int);
};

Matrix::Matrix(int r, int c)
{
    M = new float* [r];
    for(int i = 0; i < r; i++)
    {
        M[i] = new float[c];
    }

    row = r;
    col = c;
}

Matrix::~Matrix()
{
    for(int i = 0; i < col; i++)
    {
        delete[] M[i];
    }

    delete[] M;
}

float& Matrix::operator() (int i, int j)
{
    return M[i][j];
}

int main()
{
    std::cout<< "Cho ma tran 2x3.\n";
    Matrix a(2, 3);
    int i, j;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j <3; j++)
        {
            std::cin>>a(i,j);
        }
    }
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            std::cout<<a(i,j)<<" ";
        }
        std::cout << std::endl;
    }

    return 0;
}