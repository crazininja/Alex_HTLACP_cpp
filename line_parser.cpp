#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <set>
using namespace std;

//regurgitate a line 
int main() {
string input;
cout << "Enter an expression" << endl;
getline(cin, input);
vector<char> postfix = vector<char>();
set<char> valids = set<char>({'(',')','0','1','2','3','4','5','6','7','8','9','+','-','/','*'});
 for (int i = 0; i < input.size(); i++)  {
    //count will return a 1 or 0
    if (valids.count(input[i])) {
        postfix.push_back(input[i]);
    }
 }

 for (int i = 0; i < postfix.size(); i++)  {
    cout << postfix[i];
 }







return 0;
}