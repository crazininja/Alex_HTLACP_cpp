#include <iostream>
using namespace std;

struct Point {
	double x, y;
};

struct Rectangle {
	//this is the upper left corner
	Point corner;
	double width, height;
};

double findArea(Rectangle rect) {
	//returns the area
	return (rect.width * rect.height);
}

Point lowerRight(Rectangle rect) {
	// upper left
	//going by conventional graphics programming, we would count negative as up and positive as down...
	//but i don't think thats the intent here
	Point low_r = { rect.corner.x + rect.width, rect.corner.y - rect.height };
	return low_r;
}

int main(int argc, char** argv)
{

	double side1;
	double side2;
	double corner_x;
	double corner_y;
	cout << "Vertical length of rectangle:" << endl;
	cin >> side1;

	if (cin.good() == true) {
		cout << "Horizontal length of rectangle:" << endl;
		cin >> side2;
		if (cin.good() == true) {
			cout << "Corner x position:" << endl;
			cin >> corner_x;
			if (cin.good() == true) {
			cout << "Corner y position" << endl;
			cin >> corner_y;
				//in retrospect there wouldve been a much easier way to do this without so many indents... could either do while cin.good or set a condition to false if it fails one case
				if (cin.good() == true) {
					Point corner = { corner_x, corner_y };
					Rectangle rect = { corner, side1, side2 };
					cout << "Find area:" << findArea(rect) << endl;
					Point low_r = lowerRight(rect);
					cout << "Lower right:" << low_r.x << "," << low_r.y << endl;
					}
				}
			}
		}
	else {
		cout << "Bad input :( " << endl;
	}
}