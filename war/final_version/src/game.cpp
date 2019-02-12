#include "game.h"

//this is the play game function

void Game::playGame(Deck d)
{
    //creating and shuffling the deck
    d.makeDeck();
	d.shuffleDeck();

    //counter for if there is a tie
    int warcounter = 0;
    
    //bool for telling if a war has occured
    bool warBool = false;

    //will end loop if someone wins
    bool winner = false;

    //will tell program when to shuffle hands
    int shuffleCounter = 0;
    
    //creating the vectors for the players 'hand'
    std::vector<Card> player1;
    std::vector<Card> player2;

    //this is a vector for the cards played in a war situation
    std::vector <Card> warVec;

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
            //creating a random number
            std::random_device rng;
            std::minstd_rand ran(rng());

            //actual shuffle occurs
            std::shuffle(player1.begin(), player1.end(), ran);
            std::shuffle(player2.begin(), player2.end(), ran);
            //reset the counter
            shuffleCounter = 0;
        }
        //player one draws
        std::cout << "Player 1 draws a: ";
        std::cout << player1[0] << std::endl;

        //player 2 draws
        std::cout << "Player 2 draws a: ";
        std::cout << player2[0] << std::endl;

        
        //these if statements are for determining the winner of the round (or tie)
        if(player1[0] > player2[0])
        {
            std::cout << "Player 1 wins the round!" << std::endl;
            //puts the cards won at bottom of player2's deck
            player1.push_back(player1[0]);
            player1.push_back(player2[0]);

            //this will insert the war cards if there is any
            if (warBool == true)
            {
                player1.insert(player1.end(), warVec.begin(), warVec.end());
                warVec.clear();  
            }
            warBool = false;
        }
        else if (player2[0] > player1[0])
        {
            std::cout << "Player 2 wins the round!" << std::endl;
            //puts the cards won at bottom of player2's deck
            player2.push_back(player1[0]);
            player2.push_back(player2[0]);

            //this will insert the war cards if there is any
            if (warBool == true)
            {
                player2.insert(player2.end(), warVec.begin(), warVec.end());
                warVec.clear();
            }

            warBool = false;
        }
        else
        {
            std::cout << "There is a tie, that means war!" << std::endl;
            warVec.push_back(player1[0]);
            warVec.push_back(player2[0]);
            warBool = true;
        }

        //this will erase the first element of the vectors (players deck)
        //(these are the cards they just played)
        player1.erase(player1.begin());
        player2.erase(player2.begin());
        

        //this will display the deck sizes for the players
        std::cout << "\n";
        std::cout << "Player 1 has: " << player1.size() << " cards." << std::endl;
        std::cout << "Player 2 has: " << player2.size() << " cards." << std::endl;
        std::cout << "\n";

        //winner check
        if((player1.size() >= 52) || (player2.size() >= 52) || (player1.size() == 0) || (player2.size() == 0))
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