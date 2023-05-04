#include "Complex.h"
#include <string>


Complex::Complex() {
    real = 0; 
    imag = 0; 
}

Complex::Complex(double r, double i) { 
    real = r; 
    imag = i; 
}


Complex::Complex(double m, double t, Flag) {
    mag = m; theta = t;
    polar = true;
    calculate_cartesian();
}

double Complex::get_real() const
{
    return real;
}

double Complex::get_imag() const
{
    return imag;
}

void Complex::calculate_polar()
{
    mag = sqrt(real * real + imag * imag);
    theta = atan(imag / real);
    polar = true;
}

double Complex::get_mag()
{
    if (polar == false) calculate_polar();
    return mag;
}

double Complex::get_theta()
{
    if (polar == false) calculate_polar();
    return theta;
}

string Complex::str_cartesian()
{
    return to_string(get_real()) + " + " + to_string(get_imag()) + "i";
}

string Complex::str_polar()
{
    string theta = to_string(get_theta());
    string mag = to_string(get_mag());
    return mag + "e^" + theta + "i";
}

Complex Complex::operator + (const Complex& c)
{
    return Complex(real + c.real, imag + c.imag);
}

Complex Complex::operator - (const Complex& c) {
    return Complex(real - c.real, imag - c.imag);
}

Complex Complex::operator * (Complex& c)
{
    if (polar == false) calculate_polar();
    if (c.polar == false) c.calculate_polar();
    return Complex(mag * c.mag, theta + c.theta, POLAR);
}

Complex Complex::operator / (Complex& c)
{
    if (polar == false) calculate_polar();
    if (c.polar == false) c.calculate_polar();
    //should work according to khan academy - it is essentially the inverse of the above, so logically should work as well
    return Complex(mag/c.mag, theta - c.theta, POLAR);
}

void Complex::calculate_cartesian()
{
    assert(polar == true);
    real = mag * cos(theta);
    imag = mag * sin(theta);
}

ostream& operator<<(ostream& os, Complex const& v){
    os << v.get_real() <<  "+" << v.get_imag() << "i";
    return os;
}