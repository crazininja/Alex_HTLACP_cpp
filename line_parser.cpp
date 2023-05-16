#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
using namespace std;

//regurgitate a line 
int main() {
string input;
cout << "Enter an expression" << endl;
getline(cin, input);
cout <<"input:" << input << " and it's size:" << input.length() << endl;
vector<char> infix = vector<char>();


//for (int i = 0; i < input.length(); i++)  {
    //treaverse the string
//    cout << "character going into infix:" << endl;
//    infix.assign(input.at(i), i);
//}

//cout << "infix size:" << infix.size() << endl;

 for (int i = 0; i < input.size(); i++)  {
    cout << "pushing back:"<< input[i] << endl;
    infix.push_back(input[i]);
 }

 for (int i = 0; i < infix.size(); i++)  {
    cout << infix[i];
 }







return 0;
}