#include <iostream>
using namespace std;

template <class T> class Stack
{
private:
    static const int max = 10;
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

template <class T> 
Stack<T>::Stack()
{
    this->current = 0;
}

template <class T>
Stack<T>::~Stack() {}

template <class T>
void Stack<T>::push(const T& i)
{
    if(this->current < this->max)
    {
        this->contents[this->current++] = i;
    }
}

template <class T>
void Stack<T>::pop(T& i)
{
    if(this->current > 0)
    {
        i = this->contents[--this->current];
    }
}

template <class T>
bool Stack<T>::isEmpty() const
{
    return this->current == 0;
}

template <class T>
bool Stack<T>::isFull() const
{
    return (this->current == this->max);
}


int main()
{
    int x = 5;
    char c = 'a';
    Stack<int> s;
    Stack<char> t;
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