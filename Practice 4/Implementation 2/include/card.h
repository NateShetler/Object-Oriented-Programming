#pragma once
#include <iostream>
#include <cassert>

//enums for suit and rank
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

//enum for joker color
enum Color
{
    red,
    black,
};

//this is for a standard card
struct Card
{
    private:
        unsigned char cardData; 
    
    public:
        unsigned char get_cardData(){ return cardData;}
        
        Card(unsigned char c)
            : cardData(c)
        {}
};

std::ostream& operator<<(std::ostream& os,Card c);