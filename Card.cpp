#include <iostream>
#include "Card.h"
#include <vector>
#include <string>
#include <iostream>
 
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

    return rank_strings.at(rank) + " of " + suit_strings.at(suit);
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

Deck::Deck()
{
    vector<Card> temp(52);
    cards = temp;
    int i = 0;
    for (Suit suit = CLUBS; suit <= SPADES; suit = Suit(suit + 1)) {
        for (Rank rank = ACE; rank <= KING; rank = Rank(rank + 1)) {
            cards.at(i).suit = suit;
            cards.at(i).rank = rank;
            i++;
        }
    }
}

void Deck::print() const
{
    for (int i = 0; i < cards.size(); i++) {
        cout << cards.at(i).to_string() << endl;
    }
}

int random_between(const int upper, const int lower) {
    int random_int = rand();
    //filter out with modulus; upper-lower will give us within our 'range' (difference between upper to lower),
    //and then we can just increment it since it now 'fits' in between those uppwer and lower limits
    return int((random_int % (upper - lower))) + lower;
}

void Deck::swap_cards(int card_1, int card_2) {
    Card position_1 = cards[card_1];
    Card position_2 = cards[card_2];
    //swap positions
    cards[card_1] = position_2;
    cards[card_2] = position_1;
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

Deck::Deck(int size)
{
    vector<Card> temp(size);
    cards = temp;
}

//Deck merge(const Deck& d) const
Deck Deck::merge(const Deck& d) const
{
    // creates a new deck big enough for all the cards
    Deck result(cards.size() + d.cards.size());

    // use index i for place in first deck, j for place in other eck
    int i = 0;
    int j = 0;

    //check if the other decks won
    bool d_won = false;
    bool i_won = false;
    // k traverses the result deck
    for (int k = 0; k < result.cards.size(); k++) {
        // if this is empty, d wins, if d is empty, this wins;
        if (i == cards.size()) { 
            d_won = true;
            break;
        }
        if (j == d.cards.size()){
            i_won = true;
            break;
        }
        //make sure cards arent equal; if they are, just the first one and skip
        if (cards[i].equals(d.cards[j])) {
            result.cards[k] = cards[i];
            i++;
            continue;
        }
        // otherwise, compare the two cards on top
        if (d.cards[j].is_greater(cards[i])) {
            result.cards[k] = d.cards[j];
            j++;
        } else {
            //if not equal and not greater, then our card must be larger
            result.cards[k] = cards[i];
            i++;
        }
        // add winner to the new deck
    }
    //add on the rest if 'we' won or if the other deck won
    if (d_won) {
        //add ours
        for (int k = i; k < result.cards.size(); k++) {
            result.cards[k] = cards[i];
        }
    }
    if (i_won) {
        for (int k = j; k < result.cards.size(); k++) {
            result.cards[k] = cards[j];
        }
    }
    return result;
}
