#pragma once
#include <iostream>
#include <vector>

using namespace std;

struct Card {
	unsigned short suit;
	unsigned short dignity;
};

class CardsSet {
private:
	vector<Card> cards;
	unsigned int size;
public:
	CardsSet() : size(0) {vector<Card> vec;
	cards = vec;
	};
	CardsSet(const int siz) : size(siz) { vector<Card> vec(siz);
	cards = vec;
	}
	CardsSet(const CardsSet& other) : size(other.size) {
		for (int i = 0; i < other.size; ++i) {
			cards[i] = other.cards[i];
		}
	}

};