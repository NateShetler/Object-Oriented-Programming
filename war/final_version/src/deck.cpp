#include "deck.h"

//implementations of the deck functions

void Deck::makeDeck()
{
    const int SUITS = 4;
    const int RANKS = 13;
    Suit suit[SUITS] = {hearts, diamonds, spades, clubs};
    Rank rank[RANKS] = {ace, two, three, four, five, six, 
    seven, eight, nine, ten, queen, king, jack};

	for (int i = 0; i < RANKS; ++i)
	{
		for (int k = 0; k < SUITS; ++k)
		{
		    Card newCard{suit[k], rank[i]};
			deck.push_back(newCard);
		}
	}
		
}

void Deck::displayDeck()
{
    for (int i = 0; i < deck.size(); ++i)
    {
        std::cout << deck[i] << std::endl;
    }
}

void Deck::shuffleDeck()
{
    //this is so the shuffle is truly random
    std::srand(time(0));
    
    std::random_shuffle(deck.begin(), deck.end());
}