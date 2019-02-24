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
        Rank rank;
        Suit suit; 
    
    public:
        Rank get_rank() const { return rank;}
        Suit get_suit() const { return suit;}
        
        Card(Rank r, Suit s)
            : rank(r), suit(s)
        {}
};

//this is for a joker card
struct jokerCard
{
    private:
        Color color;

    public:
        jokerCard(Color c)
            : color(c)
        {}

        Color get_color() const { return color;}


};

//this is the union between a standard card and joker card
union PlayingCardData
{
    PlayingCardData(Rank r, Suit s)
        : c(r, s)
    { }

    PlayingCardData(Color c)
        : jc(c)
    { }

    Card c;
    jokerCard jc;
};

//enum for card type
enum cardType
{
    standard,
    joker,
};

//playing card class
class PlayingCard
{
    public:
        PlayingCard(Rank r, Suit s)
            : tag(standard), data(r, s)
        { }

        PlayingCard(Color c)
            : tag(joker), data(c)
        { }

        bool is_standard() const { 
            return tag == standard;
        }

        bool is_joker() const { 
            return tag == joker;
        }

        Card get_as_standard() const {
            assert(is_standard());
            return data.c;
        }

        Rank get_rank() const {
            assert(is_standard());
            return data.c.get_rank();
        }

         Suit get_suit() const { 
            assert(is_standard());
            return data.c.get_suit();
        }

        jokerCard get_as_joker() const {
            assert(is_joker());
            return data.jc;
        }

        Color get_color() const { 
            assert(is_joker());
            return data.jc.get_color();
        }

    private:
        cardType tag;
        PlayingCardData data;
};


std::ostream& operator<<(std::ostream& os,Card c);
std::ostream& operator<<(std::ostream& os, PlayingCard c);
std::ostream& operator<<(std::ostream& os, jokerCard c);


