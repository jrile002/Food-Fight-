//Database:

//Contains all available cards that you can put in your deck.

#ifndef __DATABASE_H__
#define __DATABASE_H__

#include "Creature.h"
#include "Deck.h"
#include <vector>

struct Database{
     private:
          vector<Card*> cards;
     public:
          // Initializes database with standard cards for a deck
          Database(){
               this->cards.insert(this->cards.begin(), new Creature("Green Icy"));
               this->cards.insert(this->cards.begin(), new Creature("Blue Icy"));
               this->cards.insert(this->cards.begin(), new Creature("Red Icy"));
               this->cards.insert(this->cards.begin(), new Cube("Minty Cube"));
               this->cards.insert(this->cards.begin(), new Cube("Berry Cube"));
               this->cards.insert(this->cards.begin(), new Cube("Cherry Cube"));
          }

          // If deck size < 20, adds the card to the deck
          // Returns 1 for success, 0 for failure
          int add_to_deck(Card* card, Deck* deck){
               
          }
          
          // Arranges database according to index
          void index_order(){
               
          }
          
          // Arranges database in alphabetical order
          void alphabetical_order(){
               
          }
          
          // Arranges database by flavor
          // Order from highest to lowest: Cherry, Berry, Minty, Lemony, Chocolately
          void flavor_order(){
               
          }
          
          
          
}





#endif

