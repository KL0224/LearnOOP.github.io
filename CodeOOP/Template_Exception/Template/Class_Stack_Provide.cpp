#include <iostream>
using namespace std;

template <class T, int M> class Stack
{
private:
    static const int max = M;
    T contents[max];
    int current;
public:
    Stack();
    ~Stack();
    void push(const T&);
    void pop(T&);
    bool isEmpty() const;
    bool isFull() const;
};

template <class T, int I> 
Stack<T, I>::Stack()
{
    this->current = 0;
}

template <class T, int M>
Stack<T, M>::~Stack() {}

template <class T, int I>
void Stack<T, I>::push(const T& i)
{
    if(this->current < this->max)
    {
        this->contents[this->current++] = i;
    }
}

template <class T, int I>
void Stack<T, I>::pop(T& i)
{
    if(this->current > 0)
    {
        i = this->contents[--this->current];
    }
}

template <class T, int I>
bool Stack<T, I>::isEmpty() const
{
    return this->current == 0;
}

template <class T, int I>
bool Stack<T, I>::isFull() const
{
    return (this->current == this->max);
}


int main()
{
    int x = 5;
    char c = 'a';
    Stack<int, 5> s;
    Stack<char, 10> t;
    s.push(x);
    t.push(c);

    int y;
    s.pop(y);
    cout << y << endl;

    char d;
    t.pop(d);
    cout << d << "\n";

    return 0;
}