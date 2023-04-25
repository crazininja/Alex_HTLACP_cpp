#include <iostream>
#include "Card.h"
#include <vector>
using namespace std;


void print_deck(const vector<Card>& deck)
{
    for (int i = 0; i < deck.size(); i++) {
        cout << deck[i].get_string() << endl;
    }
}


int find_card(const Card& card, const vector<Card>& deck)
{
    for (int i = 0; i < deck.size(); i++) {
        if (deck[i].equals(card)) return i;
    }
    return -1;
}

int bin_search(const Card& card, const vector<Card>& deck, int l, int h) {
    int m = (l + h) / 2;

    if (deck[m].equals(card)) { return m; }

    if (deck[m].is_greater(card)) {
        return bin_search(card, deck, l, m - 1);
    }
    else {
        return bin_search(card, deck, m + 1, h);
    }
}

int main() {


    return 0;
}

