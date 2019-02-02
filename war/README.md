For this implementation of war I created a card, deck, and game class. 

The card class is comprised of two enums. One of the enums is for the rank of the card (two, three, ... ace), 
and the other is for the suit of the card (Diamonds, Spades, Hearts, Clubs). I overloaded the << operator so one can use cout with 
the card class. I also overloaded the comparison operator > so one can compare two cards to see who has the greater rank.
  
  
The deck class is comprised of 52 card objects. There are various functions in the deck class such as makeDeck, shuffleDeck, and displayDeck.

  -makeDeck will create a vector of Cards. shuffleDeck will shuffle the created deck. displayDeck will display the deck. displayDeck won't really be used in the program though, it was mostly for testing. 
  
The game class is comprised of a deck and two players. It only has one function which is called playGame. The players 
are each a vector comprised of 26 cards. Essentially they are a half deck. The game class also does all of the game logic. It compares 
cards to see who wins the round or says that war has occured if there is a tie. It also puts the cards that the winner of the round won 
to the bottom of the winners deck. The game will keep playing until one player has all 52 cards or one player has 0 cards 
(Basically the same thing).

The only things in main are a deck object and a game object and then a call to the playGame function. 
