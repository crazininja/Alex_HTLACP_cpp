#include <iostream>
#include <string>
using namespace std;

void wont_swap(char a, char b)
{
    cout << "a: " << a << "  b: " << b << endl;
    cout << "address of a: 0x" << hex << long((&a)) << endl;
    cout << "address of b: 0x" << hex << long((&b)) << endl;
    char temp = a;
    a = b;
    b = temp;
    cout << "a: " << a << "  b: " << b << endl;
}

void will_swap(char& a, char& b)
{
    cout << "a: " << a << "  b: " << b << endl;
    cout << "address of a: 0x" << hex << long(&a) << endl;
    cout << "address of b: 0x" << hex << long(&b) << endl;
    char temp = a;
    a = b;
    b = temp;
    cout << "a: " << a << "  b: " << b << endl;
}

int main()
{
    char x = 'x';
    char y = 'y';

    cout << "x: " << x << "  y: " << y << endl;
    cout << "address of x: 0x" << hex << long(&x) << endl;
    cout << "address of y: 0x" << hex << long(&y) << endl;
    cout << "Calling wont_swap..." << endl;
    wont_swap(x, y);
    cout << "x: " << x << "  y: " << y << endl;
    cout << "Calling will_swap..." << endl;
    will_swap(x, y);
    cout << "x: " << x << "  y: " << y << endl;

    return 0;
}