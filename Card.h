#include <string.h>

struct Card
{   
    //variables
    int suit, rank;
    //constructors
    Card();
    Card(int s, int r);

    //functions
    std::string get_string() const;


    bool equals(const Card& c2) const;
    bool is_greater(const Card& c2) const;

};




