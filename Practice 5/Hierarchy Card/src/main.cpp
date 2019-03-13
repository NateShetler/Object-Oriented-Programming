#include "card.h"

int main(int argc, char*argv[])
{
    standardCard card1 = standardCard(ace, spades);
    jokerCard card2 = jokerCard(red);

    std::cout << card1 << '\n' << card2 << std::endl;

};
