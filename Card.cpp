#include <iostream>
#include "Card.h"
#include <vector>
#include <string>
#include "Deck.h"

using namespace std;

Card::Card() {
    suit = 0; rank = 0;
}

Card::Card(int s, int r) {
    suit = s; rank = r;
}


string Card::to_string() const
{
    vector<string> suit_strings = { "Clubs", "Diamonds", "Hearts", "Spades" };
    vector<string> rank_strings = { "", "Ace", "2", "3", "4", "5", "6", "7",
                                   "8", "9", "10", "Jack", "Queen", "King" };

    return rank_strings[rank] + " of " + suit_strings[suit];
}

bool Card::equals(const Card& c2) const
{
    return (rank == c2.rank && suit == c2.suit);
}

bool Card::is_greater(const Card& c2) const
{
    // first check the suits
    if (suit > c2.suit) return true;
    if (suit < c2.suit) return false;

    // if suits are equal, check ranks

    //first check if there are any aces

    if (rank == 1 || c2.rank == 1) {
        if (rank == c2.rank) return false;
        if (rank > c2.rank) return false;
        return true;
    }

    if (rank > c2.rank) return true;
    //if (rank < c2.rank) return false;

    // if ranks are equal too, 1st card is not greater than the 2nd
    return false;
}

// declare that Dec is a structure, without defining it
struct Deck;
int Card::find(const Deck& deck) const
{
    for (int i = 0; i < deck.cards.size(); i++) {
        if (deck.cards[i].equals(*this)) return i;
    }
    return -1;
}