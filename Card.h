#include <string.h>
#include <vector>
using namespace std;
enum Suit { CLUBS, DIAMONDS, HEARTS, SPADES };
enum Rank {
    ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT,
    NINE, TEN, JACK, QUEEN, KING
};

struct Deck;

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

    int find(const Deck& deck) const;

};

struct Deck {
    vector<Card> cards;

    Deck(int size);
    Deck();
    //swap at the two indexes
    void swap_cards(int card_1, int card_2);
    void shuffle();
    Deck subdeck(int l, int h) const;
    void add_card(const Card& c);
    Card remove_card();
    void print() const;
    Deck merge(const Deck& d) const;
};




