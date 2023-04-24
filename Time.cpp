#include <iostream>
#include "Time.h"
using namespace std;

Time::Time(int h, int m, double s) {
    hour = h;
    minute = m;
    second = s;
}

Time::Time(double secs) {
    hour = (int(secs) / 3600);
    minute = (int(secs) / 60 - 60 * (int(secs) / 3600));
    second = (secs - 60 * (int(secs) / 60));
}

void Time::increment(double s) {
    hour += (int(s) / 3600);
    minute += (int(s) / 60 - 60 * (int(s) / 3600));
    second += (s - 60 * (int(s) / 60));
}

void Time::print() const {
    cout << hour << ":" << minute << ":" << second << endl;
}

bool Time::after(const Time& time2) const {
    if (hour > time2.hour) return true;
    if (hour < time2.hour) return false;
  
    if (minute > time2.minute) return true;
    if (minute < time2.minute) return false;

    return (second > time2.second);
}

Time Time::add(const Time& t2) const {
	return Time(convert_to_seconds() + t2.convert_to_seconds());
}

double Time::convert_to_seconds() const {
    return ((hour * 60) + minute) * 60 + second;
}