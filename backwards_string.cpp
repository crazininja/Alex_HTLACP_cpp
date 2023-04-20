#include <string>
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{

	int index;
	string input;
	cout << "Enter a word to be said backwards!" << endl;
	cin >> input;
	if (cin.good() == true) {
		index = input.length() - 1;
		//get to the start of input
		while ((index) > -1) {
				//just cout - if there's a newlinw character it should place a newline in the console because ocut is constant
			cout << input[index];
			index--;
		}
	}
	else {
		cout << "Bad input :( " << endl;
	}
}