#pragma once
#include <iostream>
//make sure to remove above line before submitting

//this is the defintion of the card

enum Suit
{
    hearts,
    diamonds,
    spades,
    clubs,
};

enum Rank
{
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    queen,
    king,
    jack,
    ace,
    
};

struct Card
{
    Suit suit;
    Rank rank;

};


std::ostream& operator<<(std::ostream& os,Card c);

bool operator>(Card c1,Card c2);

