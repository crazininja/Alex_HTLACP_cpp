#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int rand_within(const int upper, const int lower){
    int random_int = rand();
    //filter out with modulus; upper-lower will give us within our 'range' (difference between upper to lower),
    //and then we can just increment it since it now 'fits' in between those uppwer and lower limits
    return int((random_int % (upper-lower)))+lower;
}


int main(int argc, char **argv)
{
    cout << "Some random integers in between 3 and 6:" << endl;
    //generate 15 random integers between 3 and 6
    for (int i = 0; i < 15; i++) {
        cout << rand_within(6,3) << endl;
    }
    

}