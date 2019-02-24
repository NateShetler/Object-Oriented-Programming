#include "deck.h"
#include <random>

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
            PlayingCard newCard(rank[i], suit[k]);
			deck.push_back(newCard);
		}
	}
	
    //add the joker cards in 
    deck.push_back(PlayingCard{red});
    deck.push_back(PlayingCard{black});
}

void Deck::displayDeck()
{
    int n = 0;
    for (PlayingCard c : deck) 
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