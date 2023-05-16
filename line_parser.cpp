#include <string>
#include <iostream>
#include <sstream>
using namespace std;

//regurgitate a line 
int main() {
string input;
cout << "Enter a line!" << endl;
getline(cin, input);
cout << input << endl;
return 0;
}