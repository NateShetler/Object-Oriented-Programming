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

//this is for the different types of cards
enum cardType
{
    standard,
    joker,
};

//this will be the parent class to all cards
struct Card
{
    private:
        cardType Type;
    public:
        Card(cardType t)
            : Type(t)
        {}

        //returns what type of card it is 
        cardType get_type() const {return Type;}
};

//this is for a standard card
//it is a child of Card
struct standardCard : Card
{
    private:
        Rank rank;
        Suit suit; 
    
    public:
        Rank get_rank() const { return rank;}
        Suit get_suit() const { return suit;}
        
        standardCard(Rank r, Suit s)
            : Card(standard), rank(r), suit(s)
        {}
};

//this is for a joker card
//it is a child of Card
struct jokerCard : Card
{
    private:
        Color color;

    public:
        jokerCard(Color c)
            : Card(joker), color(c)
        {}

        Color get_color() const { return color;}


};



std::ostream& operator<<(std::ostream& os, Card c);
std::ostream& operator<<(std::ostream& os, standardCard c);
std::ostream& operator<<(std::ostream& os, jokerCard c);


