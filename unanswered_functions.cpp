#include <iostream>
using namespace std;
int add_two(int a, int b){
    return a+b;
}
void add_three(int a, int b, int c) {
   cout << a+b+c << endl;
}
int main(int argc, char **argv){

int hour, minute;
char colon;

hour = 11;
minute = 59;
colon = ':';
//and int and void function
//this wil result in error; add three returns void -> nothing, which cout cannot process
//you cannot assign a variable to a void function because of this either

//cout << "Add 1 + 2 "<< add_two(1,2) << "Add 1 + 2 3" << add_three(1,2,3) << endl;
cout << "1+2=" << add_two(1,2) << endl;
cout << "Using the function outside of a output statement:" << endl;
add_three(1,2,3);

}