#include "Card.h"
#include <vector>

using namespace std;

struct Deck {
    vector<Card> cards;

    Deck(int n);
};

Deck::Deck(int size)
{
    vector<Card> temp(size);
    cards = temp;
}