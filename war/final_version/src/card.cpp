#include "card.h"

//this is the implementation of the card ostream operator <<

std::ostream& operator<<(std::ostream& os,Card c)
{
    //switch statement for displaying the rank
    switch (static_cast<Rank>(c.cardData & 0xf))
	{
		case 0: os << "Ace of "; break;
        case 1: os << "2 of "; break;
        case 2: os << "3 of "; break;
        case 3: os << "4 of "; break;
        case 4: os << "5 of "; break;
        case 5: os << "6 of "; break;
        case 6: os << "7 of "; break;
        case 7: os << "8 of "; break;
        case 8: os << "9 of "; break;
        case 9: os << "10 of "; break;
        case 10: os << "Queen of "; break;
        case 11: os << "King of "; break;
        case 12: os << "Jack of "; break;
	
    }
    //switch statement displaying the suit
	switch (static_cast<Suit>(c.cardData >> 4))
	{
		case 0: os << "Hearts"; break;
        case 1: os << "Diamonds"; break;
        case 2: os << "Spades"; break;
        case 3: os << "Clubs"; break;
	}
    
    return os;
}

bool operator>(Card c1, Card c2)
{
    //This compares the rank of the two cards. Being a number
    //already makes the comparison less lines of code and
    //much faster than what I had in the last version. 
    return (static_cast<int>(c1.cardData & 0xf)) > (static_cast<int>(c2.cardData & 0xf));
}