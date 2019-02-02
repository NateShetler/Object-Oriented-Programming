#include "card.h"

//this is the implementation of the card ostream operator <<

std::ostream& operator<<(std::ostream& os,Card c)
{
    switch (c.rank)
	{
		case ace: os << "Ace of "; break;
        case two: os << "2 of "; break;
        case three: os << "3 of "; break;
        case four: os << "4 of "; break;
        case five: os << "5 of "; break;
        case six: os << "6 of "; break;
        case seven: os << "7 of "; break;
        case eight: os << "8 of "; break;
        case nine: os << "9 of "; break;
        case ten: os << "10 of "; break;
        case queen: os << "Queen of "; break;
        case king: os << "King of "; break;
        case jack: os << "Jack of "; break;
	
    }
	switch (c.suit)
	{
		case hearts: os << "Hearts"; break;
        case diamonds: os << "Diamonds"; break;
        case spades: os << "Spades"; break;
        case clubs: os << "Clubs"; break;
	}
    
    return os;
}

bool operator>(Card c1, Card c2)
{
    //values for comparison
    int value1 = 0, value2 = 0;

    switch (c1.rank)
	{
        case two: value1 = 1; break;
        case three: value1 = 2; break;
        case four: value1 = 3; break;
        case five: value1 = 4; break;
        case six: value1 = 5; break;
        case seven: value1 = 6; break;
        case eight: value1 = 7; break;
        case nine: value1 = 8; break;
        case ten: value1 = 9; break;
        case queen: value1 = 10; break;
        case king: value1 = 11; break;
        case jack: value1 = 12; break;
        case ace: value1 = 13; break;
	
    }

    switch (c2.rank)
	{
        case two: value2 = 1; break;
        case three: value2 = 2; break;
        case four: value2 = 3; break;
        case five: value2 = 4; break;
        case six: value2 = 5; break;
        case seven: value2 = 6; break;
        case eight: value2 = 7; break;
        case nine: value2 = 8; break;
        case ten: value2 = 9; break;
        case queen: value2 = 10; break;
        case king: value2 = 11; break;
        case jack: value2 = 12; break;
        case ace: value2 = 13; break;
	
    }

    return value1 > value2;
}