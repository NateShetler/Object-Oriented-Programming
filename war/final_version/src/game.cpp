#include "game.h"

//this is the play game function

//if worked on again in the future, this needs broken up
//into more functions. 
void Game::playGame(Deck d)
{
    d.makeDeck();
	d.shuffleDeck();

    //counter for if there is a tie
    int warcounter = 0;
    
    //this will be used when there is a tie between players
    int warCounter = 0, warCounter2 = 0;

    //will end loop if someone wins
    bool winner = false;

    //will tell program when to shuffle hands
    int shuffleCounter = 0;
    
    //creating the vectors for the players 'hand'
    std::vector <Card> player1;
    std::vector <Card> player2;

    //filling player1's 'hand' with cards
    for(int i = 0; i < d.deck.size() / 2; ++i)
    {
        player1.push_back(d.deck[i]);
    }

    //filling player2's 'hand' with cards
    for(int i = 26; i < d.deck.size(); ++i)
    {
        player2.push_back(d.deck[i]);
    }

    //this is the game loop
    while (winner == false)
    {
        //shuffle after awhile or game will be pretty much infinite
        if (shuffleCounter == 30)
        {
            //this is so the shuffle is truly random
            std::srand(time(0));

            //actual shuffle occurs
            std::random_shuffle(player1.begin(), player1.end());
            std::random_shuffle(player2.begin(), player2.end());
            //reset the counter
            shuffleCounter = 0;
        }
        //player one draws
        std::cout << "Player 1 draws a: ";
        std::cout << player1[0] << std::endl;

        //player 2 draws
        std::cout << "Player 2 draws a: ";
        std::cout << player2[0] << std::endl;

        //first part of the if statement is if a war has occured
        //second part is if no war has occured prior
        if(warCounter > 0)
        {

            if (player1[warCounter] > player2[warCounter])
            {
                std::cout << "Player 1 wins the round!" << std::endl;

                while (warCounter > 0)
               {
                    player1.push_back(player1[warCounter]);
                    player1.push_back(player2[warCounter]);
                    --warCounter;
                }
                player1.push_back(player1[warCounter]);
                player1.push_back(player2[warCounter]);  
            
            }
            else if (player2[warCounter] > player1[warCounter])
            {
                std::cout << "Player 2 wins the round!" << std::endl;

                while (warCounter > 0)
                {
                    player2.push_back(player1[warCounter]);
                    player2.push_back(player2[warCounter]);
                    --warCounter;
                }
                player2.push_back(player1[warCounter]);
                player2.push_back(player2[warCounter]);
                
            }
            else
            {
                std::cout << "There is a tie, that means war!" << std::endl;
                ++warCounter;
                ++warCounter2;
            }

            //this will go through and delete the cards at the beginning
            while (warCounter2 > 0)
            {
                player1.erase(player1.begin() + warCounter2);
                player2.erase(player2.begin() + warCounter2);
                --warCounter2;
            }
            warCounter2 = 0;

        }
        else if (warCounter == 0)
        {
            if(player1[0] > player2[0])
            {
                std::cout << "Player 1 wins the round!" << std::endl;
                //puts the cards won at bottom of player2's deck
                player1.push_back(player1[0]);
                player1.push_back(player2[0]);
            }
            else if (player2[0] > player1[0])
            {
                std::cout << "Player 2 wins the round!" << std::endl;
                //puts the cards won at bottom of player2's deck
                player2.push_back(player1[0]);
                player2.push_back(player2[0]);
            }
            else
            {
                std::cout << "There is a tie, that means war!" << std::endl;
                ++warCounter;
                ++warCounter2;
            }

            //this will erase the first element of the vectors (players deck)
            player1.erase(player1.begin());
            player2.erase(player2.begin());
        }

        //this will display the deck sizes for the players
        std::cout << "\n";
        std::cout << "Player 1 has: " << player1.size() << " cards." << std::endl;
        std::cout << "Player 2 has: " << player2.size() << " cards." << std::endl;
        std::cout << "\n";

        //winner check
        if((player1.size() == 52) || (player2.size() == 52) || (player1.size() == 0) || (player2.size() == 0))
        {
            winner = true;

            if(player1.size() > player2. size())
            {
                std::cout << "Congrats Player 1. You win!!" << std::endl;
            }
            else
            {
                std::cout << "Congrats Player 2. You win!!" << std::endl;
            }
        }

        //add one to shuffle counter
        ++shuffleCounter;
    }

}