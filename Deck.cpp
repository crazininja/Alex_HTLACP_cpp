#include <iostream>
#include "Card.h"
#include <vector>
using namespace std;

Deck::Deck()
{
    vector<Card> temp(52);
    cards = temp;
    int i = 0;
    for (Suit suit = CLUBS; suit <= SPADES; suit = Suit(suit + 1)) {
        for (Rank rank = ACE; rank <= KING; rank = Rank(rank + 1)) {
            cards[i].suit = suit;
            cards[i].rank = rank;
            i++;
        }
    }
}

void Deck::print() const
{
    for (int i = 0; i < cards.size(); i++) {
        cout << cards[i].to_string() << endl;
    }
}

int random_between(const int upper, const int lower) {
    int random_int = rand();
    //filter out with modulus; upper-lower will give us within our 'range' (difference between upper to lower),
    //and then we can just increment it since it now 'fits' in between those uppwer and lower limits
    return int((random_int % (upper - lower))) + lower;
}

void Deck::shuffle()
{
    for (int i = 0; i < cards.size(); i++) {
        int rand_card = random_between(0, cards.size() - 1);
        swap_cards(i, rand_card);
    }
}

Deck Deck::subdeck(int l, int h) const
{
    Deck sub(h - l + 1);

    for (int i = 0; i < sub.cards.size(); i++) {
        sub.cards[i] = cards[l + i];
    }
    return sub;
}

void Deck::add_card(const Card& c)
{
    cards.push_back(c);
}

Card Deck::remove_card()
{
    Card card = cards[cards.size() - 1];
    cards.pop_back();
    return card;
}