#ifndef __DECK_H__
#define __DECK_H__

#include "Creature.h"
#include <vector>
#include <cstdlib>
#include <time.h>

const int DECK_MAX_SIZE = 20;
const string BLANKS = "|-                 -|";

struct Deck{
     private:
         vector<Card*> cards; 
         vector<Card*> draw_pile;
         vector<Card*> discard_pile;
         vector<Card*> hand;
         vector<Card*> lane;
     
     public:
          // Constructors
          Deck(){
               for (unsigned i = 0; i < DECK_MAX_SIZE; ++i){
                    this->cards.insert(this->cards.begin(), new Creature("Green Icy"));
               }
               for (unsigned i = 0; i < 3; ++i){
                    this->lane.insert(this->lane.begin(), new Creature());
               }
          }
          // Accessor Functions
          inline string get_lane_name(unsigned int i){ return this->lane[i]->get_name(); }
          inline int get_lane_attack(unsigned int i){ return this->lane[i]->perform_int("get_attack_power"); }
          inline int get_lane_shield(unsigned int i){ return this->lane[i]->perform_int("get_shield_power"); }
          inline string get_lane_flavor(unsigned int i){ return this->lane[i]->perform_str("get_flavor"); }
          
          
          // Replaces the card at index i with a new creature card
          void replace(unsigned int i, Card* card){
               delete this->cards[i];
               this->cards[i] = card;
          }
          
          // Puts all cards into the draw pile
          void init_draw_pile(){
               for (unsigned i = 0; i < DECK_MAX_SIZE; ++i){
                    this->draw_pile.insert(draw_pile.begin(), cards[i]);
               }
               this->randomize();
          }
          
          // All cards in the discard pile are placed back in the draw pile
          void all_to_draw_pile(){
               while (this->discard_pile.size() > 0){
                    this->draw_pile.insert(this->draw_pile.begin(), this->discard_pile.back());
                    this->discard_pile.pop_back();
               } 
               this->randomize();
          }
          
          void randomize(){
               vector<Card*> temp;
               srand(time(0));
               while(this->draw_pile.size() > 0){
                    int i = rand() % draw_pile.size();
                    temp.insert(temp.begin(), this->draw_pile[i]);
                    this->draw_pile.erase(this->draw_pile.begin() + i);
               }
               for (unsigned i = 0; i < temp.size(); ++i){
                    this->draw_pile.insert(this->draw_pile.begin(), temp[i]);
               }
          }
          
          // Draw 5 cards from the draw pile and place them in your hand
          // Places cards from discard pile into draw pile if there are a limited number of draw cards
          void draw(){
               if (this->draw_pile.size() < 5){
                    while(this->discard_pile.size() > 0){
                         this->draw_pile.insert(this->draw_pile.begin(), this->discard_pile.back());
                         this->discard_pile.erase(this->discard_pile.begin() + this->discard_pile.size() - 1);
                    }
               }
               for (unsigned i = 0; i < 5; ++i){
                    this->hand.insert(this->hand.begin(), this->draw_pile.back());
                    this->draw_pile.pop_back();
               }

          }
          
          // Adds a card from your hand to a lane
          // Returns true if successful, false otherwise
          bool add_to_lane(unsigned int hand_index, unsigned int lane_index){
               if (this->hand[hand_index]->get_name() == ""){
                    printf("\nERROR: Cannot place a card from your hand that does not exist\n");
                    return false;
               }
               
               // Playing a creature card
               if (this->hand[hand_index]->get_type() == "Creature"){
                    if (this->lane[lane_index]->get_name() != ""){ // Lane is not empty
                         return false;
                    }
                    else {
                         this->swap(&this->lane[lane_index], &this->hand[hand_index]);
                         return true;
                    }
               }
               // Playing a cube card
               else if (this->hand[hand_index]->get_type() == "Cube"){
                    int successful = this->evolve(this->lane[lane_index], this->hand[hand_index]);
                    if (successful){
                         this->discard_pile.insert(this->discard_pile.begin(), this->hand[hand_index]);
                         this->hand[hand_index] = new Creature();
			 return true;
                    }
		    return false;
               }
               else{
                    printf("\nERROR: Card type does not exist\n");
                    return false;
               }
               
          }
          
          // Removes a card from a lane, puts it into the discard pile, and resets its stats
          bool remove_from_lane(unsigned int lane_index){
               if (this->lane[lane_index]->get_name() == ""){
                    return false;
               }
               else{
                    this->lane[lane_index]->perform_void("set_attack_power", this->lane[lane_index]->perform_int("get_base_attack"), "");
                    this->lane[lane_index]->perform_void("set_shield_power", this->lane[lane_index]->perform_int("get_base_shield"), "");
                    this->discard_pile.insert(this->discard_pile.begin(), this->lane[lane_index]);
                    this->lane[lane_index] = new Creature();
                    return true;
               }
          }
          
          // Discard all the cards in your hand
          void discard_hand(){
               while(this->hand.size() > 0){
                    if (this->hand.back()->get_name() != ""){
                         this->discard_pile.insert(this->discard_pile.begin(), this->hand.back());
                    }
                    this->hand.erase(this->hand.begin() + this->hand.size() - 1);
               }
          }
          
          // Swaps the two pointer addresses to Creature
          void swap(Card** a, Card** b){
               Card* temp = *a;
               *a = *b;
               *b = temp;
          }
          
          // Replace the creature in the lane with its evolution, if possible
          // Returns 1 if successful, 0 otherwise
          int evolve(Card* creature, Card* evolver){
              // Evolver card needs to be the same flavor as the creature being considered
               if (evolver->perform_str("get_flavor") == creature->perform_str("get_flavor")){
                    unsigned int index = creature->perform_int("get_index");
                    switch (index){
                         case 1:
                              delete creature;
                              creature = new Creature("Green Scoop");
                              return 1;
                         case 2:
                              delete creature;
                              creature = new Creature("Green Cake");
                              return 1;
                         case 4:
                              delete creature;
                              creature = new Creature("Blue Scoop");
                              return 1;
                         case 5:
                              delete creature;
                              creature = new Creature("Blue Cake");
                              return 1;
                         case 7:
                              delete creature;
                              creature = new Creature("Red Scoop");
                              return 1;
                         case 8:
                              delete creature;
                              creature = new Creature("Red Cake");
                              return 1;
                         default:
                              printf("Creature cannot be evolved furthur.\n");
                              return 0;
                   }
              }
              return 0;
          }
          
          // Reduces the health of the creature being considered
          // When the creature has no health left, send it to the discard pile
          void damage(int damage_amount, unsigned int index){
               this->lane[index]->perform_void("lower_shield_power", damage_amount, "");
               if (this->lane[index]->perform_int("get_shield_power") == 0){
                    this->remove_from_lane(index);
               }
          }
          
          // Printing Functions
          string str_name(string label, unsigned int index){
               if (label == "lane"){
                    if (index < this->lane.size()){
                         return this->lane[index]->print_data(1);
                    }
                    else{
                         return BLANKS;
                    }
               }
               else if (label == "hand"){
                    if (index < this->hand.size()){
                         return this->hand[index]->print_data(1);
                    }
                    else{
                         return BLANKS;
                    }
               }
               else{
                    return "FIXME";     
               }
               
          }
          string str_flavor(string label, unsigned int index){
               if (label == "lane"){
                    if (index < this->lane.size()){
                         return this->lane[index]->print_data(2);
                    }
                    else{
                         return BLANKS;
                    }
               }
               else if (label == "hand"){
                    if (index < this->hand.size()){
                         return this->hand[index]->print_data(2);
                    }
                    else{
                         return BLANKS;
                    }
               }
               else{
                    return "FIXME";     
               }
          }
          string str_attack(string label, unsigned int index){
               if (label == "lane"){
                    if (index < this->lane.size()){
                         return this->lane[index]->print_data(4);
                    }
                    else {
                         return BLANKS;
                    }
               }
               else if (label == "hand"){
                    if (index < this->hand.size()){
                         return this->hand[index]->print_data(4);
                    }
                    else{
                         return BLANKS;
                    }
               }
               else{
                    return "FIXME - DECK::STR_ATTACK";     
               }
          }
          string str_shield(string label, unsigned int index){
               if (label == "lane"){
                    if (index < this->lane.size()){
                         return this->lane[index]->print_data(5);
                    }
                    else {
                         return BLANKS;
                    }
               }
               else if (label == "hand"){
                    if (index < this->hand.size()){
                         return this->hand[index]->print_data(5);
                    }
                    else{
                         return BLANKS;
                    }
               }
               else{
                    return "FIXME - DECK::STR_SHIELD";     
               }
          }
          void print(){
               for (unsigned i = 0; i < DECK_MAX_SIZE; ++i){
                    printf("Creature %d:\n", i+1);
                    cards[i]->perform_void("print_creature", 0, "");
                    printf("\n");
               }
          }
          void print_draw_pile(){
               for (unsigned i = 0; i < this->draw_pile.size(); ++i){
                    printf("Creature %d:\n", i+1);
                    draw_pile[i]->perform_void("print_creature", 0, "");
                    printf("\n");
               }
          }
          void print_hand(){
               for (unsigned i = 0; i < this->hand.size(); ++i){
                    printf("Creature %d:\n", i+1);
                    hand[i]->perform_void("print_creature", 0, "");
                    printf("\n");
               }
          }
          void print_lane(){
               for (unsigned i = 0; i < this->lane.size(); ++i){
                    printf("Creature %d:\n", i+1);
                    lane[i]->perform_void("print_creature", 0, "");
                    printf("\n");
               }
          }
          void print_discard_pile(){
               for (unsigned i = 0; i < this->discard_pile.size(); ++i){
                    printf("Creature %d:\n", i+1);
                    discard_pile[i]->perform_void("print_creature", 0, "");
                    printf("\n");
               }
          }
          
};




#endif
