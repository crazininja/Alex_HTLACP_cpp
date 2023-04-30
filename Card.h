#include <string.h>
enum Suit { CLUBS, DIAMONDS, HEARTS, SPADES };
enum Rank {
    ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT,
    NINE, TEN, JACK, QUEEN, KING
};

struct Card
{   

    //variables
    int suit, rank;
    //constructors
    Card();
    Card(int s, int r);

    //functions
    std::string to_string() const;


    bool equals(const Card& c2) const;
    bool is_greater(const Card& c2) const;

};




