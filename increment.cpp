#include <iostream>
#include <cmath>
using namespace std;
struct Time {
    int hour, minute;
    double second;
    //Time = {hour, minute, second}
};

Time increment(const Time& time, double secs) {
    //use floor division here - e.g. 3613//3600 = 1 for an hour
    Time newtime = {time.hour+ int(secs)/3600, 
    time.minute + int(secs)/60-(int(secs)/3600)*60, 
    time.second + secs-(int(secs)/60)*60};
    return(newtime);

}


int main(int argc, char **argv)
{
    Time time = {0, 0, 0.0};
    //increase to 1 hour, 58 mintes, and 23 seconds
    //this is 7103 seconds
    Time after_time = increment(time, 7103.0);
    cout << after_time.hour << ":" << after_time.minute << ":" << after_time.second << endl;

}