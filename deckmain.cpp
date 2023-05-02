#include <iostream>
#include "Card.h"
#include <vector>
using namespace std;


int main() {
	Deck deck = Deck();
	deck.print();
	deck.shuffle();
	//deck.print();
	//Deck hand1 = deck.subdeck(0, 4);
	//Deck hand2 = deck.subdeck(5, 9);
	//Deck pack = deck.subdeck(10, 51);
	return 0;
}