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

void will_swap_with_pointers(int* a, int* b)
{
    cout << "a: " << *a << "  b: " << *b << endl;
    cout << "address of a: " << a << endl;
    cout << "address of b: " << b << endl;
    int temp = *a;
    *a = *b;
    *b = temp;
    cout << "a: " << *a << "  b: " << *b << endl;
}

int main()
{
    int one = 1;
    int two = 2;
    int* a = &one;
    int* b = &two;
    will_swap_with_pointers(a, b);
    cout << "a has been swapped to: " << a << " and is now:" << *a << endl;
    cout << "b has been swapped to: " << b << " and is now:" << *b << endl;
    return 0;
}