#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

//regurgitate a line 
int main() {
string input;
cout << "Enter an expression" << endl;
getline(cin, input);
cout <<"input:" << input << " and it's size:" << input.length() << endl;
vector<char> infix = vector<char>(input.begin(), input.end());

cout <<"input:" << input << " and it's size:" << input.length() << endl;

//for (int i = 0; i < input.length(); i++)  {
    //treaverse the string
//    cout << "character going into infix:" << endl;
//    infix.assign(input.at(i), i);
//}

//cout << "infix size:" << infix.size() << endl;

 for (int i = 0; i < infix.size(); i++)  {
//     //treaverse the string
     cout << "cha:" << infix.at(i);
 }
// cout << endl;






return 0;
}