#include <iostream>
using namespace std;

void wont_swap(int a, int b)
{
    cout << "a: " << a << "  b: " << b << endl;
    cout << "address of a: " << &a << endl;
    cout << "address of b: " << &b << endl;
    int temp = a;
    a = b;
    b = temp;
    cout << "a: " << a << "  b: " << b << endl;
}

void will_swap(int& a, int& b)
{
    cout << "a: " << a << "  b: " << b << endl;
    cout << "address of a: " << &a << endl;
    cout << "address of b: " << &b << endl;
    int temp = a;
    a = b;
    b = temp;
    cout << "a: " << a << "  b: " << b << endl;
}

int main()
{
    int x = 7;
    int y = 11;

    cout << "x: " << x << "  y: " << y << endl;
    cout << "address of x: " << &x << endl;
    cout << "address of y: " << &y << endl;
    cout << "Calling wont_swap..." << endl;
    wont_swap(x, y);
    cout << "x: " << x << "  y: " << y << endl;
    cout << "Calling will_swap..." << endl;
    will_swap(x, y);
    cout << "x: " << x << "  y: " << y << endl;

    return 0;
}