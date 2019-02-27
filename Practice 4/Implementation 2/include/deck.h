#pragma once
#include "card.h"
#include <vector>
#include <algorithm>
#include <random>

//this is the deck class comprised of cards
struct Deck
{
    public:
        std::vector <Card> deck;
        void makeDeck();
        void displayDeck();
        void shuffleDeck();

};