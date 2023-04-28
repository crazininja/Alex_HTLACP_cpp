#include <iostream>
#include "Card.h"
#include <vector>
using namespace std;


void print_deck(const vector<Card>& deck)
{
    for (int i = 0; i < deck.size(); i++) {
        cout << deck[i].to_string() << endl;
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
    cout << l << ", " << h;
    if (h < l) {return -1;}

    int m = (l + h) / 2;

    if (deck[m].equals(card)) { return m; }
    
    if (deck[m].is_greater(card)) {
        return bin_search(card, deck, l, m - 1);
    }
    else {
        return bin_search(card, deck, m + 1, h);
    }
}

vector<Card> build_deck() {
    vector<Card> deck(52);

    
    int i = 0;
    for (int suit = 0; suit <= 3; suit++) {
        for (int rank = 1; rank <= 13; rank++) {
            deck[i].suit = suit;
            deck[i].rank = rank;
            i++;
        }
    }
    return deck;
}

int main() {
    Card card(1, 11);
    Card card1(2, 11);
    Card card2(1, 11);

    Card ace(1, 1);
    Card deuce(1, 2);

    if (ace.is_greater(deuce)) {
        cout << ace.to_string() << "is greater than" << deuce.to_string() << endl;
    }

    if (card1.is_greater(card2)) {
        cout << card1.to_string() << " is greater than " << card2.to_string();
        cout << endl;
    }
    //vector<Card> deck(52);

    
    //int i = 0;
    //for (int suit = 0; suit <= 3; suit++) {
    //    for (int rank = 1; rank <= 13; rank++) {
    //        deck[i].suit = suit;
     //       deck[i].rank = rank;
    //        i++;
    //}

    vector<Card> deck = build_deck();
    int indx = find_card(deck[17], deck);
    cout << "Your card was found at index " << indx << "." << endl;

   

    indx = bin_search(deck[23], deck, 0, 51);
    cout << "Card found at index " << indx << endl;

    return 0;
}


