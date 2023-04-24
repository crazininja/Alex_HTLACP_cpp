#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>

using namespace std;

int rand_within(const int upper, const int lower){
    int random_int = rand();
    //filter out with modulus; upper-lower will give us within our 'range' (difference between upper to lower),
    //and then we can just increment it since it now 'fits' in between those uppwer and lower limits
    return int((random_int % (upper-lower)))+lower;
}


int main(int argc, char **argv)
{
    cout << "Some 10 random integers in between 1 to 10:" << endl;
    //generate 15 random integers between 3 and 6
    vector<int> random_nums(10,0);
    for (int i = 0; i < 10; i++) {
        random_nums[i] = rand_within(10,1);
    }

    for (int j = 0; j < random_nums.size(); j++) {
        cout << random_nums[j] << endl;
    }
    

}