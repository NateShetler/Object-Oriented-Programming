#include "deck.h"
#include <random>

//implementations of the deck functions

void Deck::makeDeck()
{
    const int SUITS = 4;
    const int RANKS = 13;

    //this will be used to set the cards in the deck
    unsigned char cardSet = 0;

    //loops for creating the deck
    for (int i = 0; i < SUITS; ++i)
	{
		for (int k = 0; k < RANKS; ++k)
		{
		    Card newCard{cardSet};
			deck.push_back(newCard);

            //add one to rank
            ++cardSet;
		}

        //this will shift the card information left by four so that 
        //adding one will add to the suit of the card 
        cardSet >>= 4;
        ++cardSet; 
        //this will shift right again allowing the rank to be modified
        //for the next iteration of the loop
        cardSet <<= 4;
	}

    //add joker cards into deck
    cardSet = 0b11000000;
    Card newJoker{cardSet};
    deck.push_back(newJoker);

    cardSet = 0b01000000;
    Card newJoker2{cardSet};
    deck.push_back(newJoker2);
		
}

void Deck::displayDeck()
{
    int n = 0;
    for (Card c : deck) 
    {
        std::cout << c << ", ";
        if (n == 3) {
            std::cout << '\n';
            n = 0;
        }
        else {
            ++n;
        }

    }
}

void Deck::shuffleDeck()
{
    //creating a random number
    std::random_device rng;
    std::minstd_rand ran(rng());

    //shuffling
    std::shuffle(deck.begin(), deck.end(), ran);
}