#include <iostream>
using namespace std;

class A
{
    int x;

public:
    A()
    {
        x = 0;
    }

    A &inc1()
    {
        x++;
        return *this;
    }
    A inc2()
    {
        x++;
        return *this;
    }
    void print()
    {
        cout << x << endl;
    }
};

int main()
{
    A a, b;
    a.inc1().inc1().inc1().print();
    a.print();
    b.inc2().inc2().inc2().print();
    b.print();

    return 0;
}