#include "card.h"

//this is the implementation of the card ostream operator <<

std::ostream& operator<<(std::ostream& os,Card c)
{
    //switch statement for displaying the rank
    switch (c.get_rank())
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
	switch (c.get_suit())
	{
		case 0: os << "Hearts"; break;
        case 1: os << "Diamonds"; break;
        case 2: os << "Spades"; break;
        case 3: os << "Clubs"; break;
	}
    
    return os;
}

//displays a PlayingCard
std::ostream& operator<<(std::ostream& os, PlayingCard c)
{
    if (c.is_standard())
    {
        return os << c.get_as_standard();
    }
    else
    {
        return os << c.get_as_joker();
    }
    
}

//display a joker card
std::ostream& operator<<(std::ostream& os, jokerCard c)
{
    switch(c.get_color())
    {
        case 0: os << "Red Joker"; break;
        case 1: os << "Black Joker"; break;
    }

    return os;
}
