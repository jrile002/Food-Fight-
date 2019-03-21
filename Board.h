#ifndef __BOARD_H__
#define __BOARD_H__

#include <string>
#include "Character.h"
#include "Deck.h"

const std::string CMD_MESSAGE = "Choose from the following commands:\n   1)\"r [#]\" to retreat creature from lane [#]\n   2)\"p [#1] [#2]\" to play card [#1] on lane [#2]\n   3) \"e\" to end your turn\n     Command: ";
const std::string HAND_HEADER = "#-------------------#     #-------------------#     #-------------------#     #-------------------#     #-------------------#";
const std::string HAND_BUFFER = "|-------------------|     |-------------------|     |-------------------|     |-------------------|     |-------------------|";
const std::string HAND_FOOTER = "#------Hand 01------#     #------Hand 02------#     #------Hand 03------#     #------Hand 04------#     #------Hand 05------#";
const std::string LANE_SPACES = "                          "; 
const std::string LANE_HEADER = LANE_SPACES + "#-------------------#     #-------------------#     #-------------------#";
const std::string LANE_BUFFER = LANE_SPACES + "|-------------------|     |-------------------|     |-------------------|";
const std::string LANE_FOOTER = LANE_SPACES + "#------Lane 01------#     #------Lane 02------#     #------Lane 03------#";
const std::string SPACES = "     ";

#define GOLD "\x1b[43m"

struct Board{
     private:
          Character* p1;
          Character* p2;
          Deck* deck_p1;
          Deck* deck_p2;
          unsigned int turn_count;
          
          // Prints player statistics and cards in player's hand
          void print_hand(Character* player, Deck* deck){
               // For printing the player's name, health, and AP
               std::string stats, hand_name, hand_flavor, hand_attack, hand_shield;
               stats = "   " + player->str_character_name() + "   " + SPACES;
               stats += "Health: " + player->str_character_health() + "          " + SPACES;
               stats += "AP: " + std::to_string(player->get_current_AP());
               // For printing cards in player's hand
               for (unsigned i = 0; i < 5; ++i){
                    hand_name += deck->str_name("hand",i);
                    hand_flavor += deck->str_flavor("hand",i);
                    hand_attack += deck->str_attack("hand",i);
                    hand_shield += deck->str_shield("hand",i);
                    if (i < 4){
                         hand_name += "     ";
                         hand_flavor += "     ";
                         hand_attack += "     ";
                         hand_shield += "     ";
                    }
               }
               printf("%s\n%s\n%s\n", stats.c_str(), HAND_HEADER.c_str(), hand_name.c_str());
               printf("%s\n%s\n%s\n", hand_flavor.c_str(), HAND_BUFFER.c_str(), hand_attack.c_str());
               printf("%s\n%s\n%s\n\n", hand_shield.c_str(), HAND_BUFFER.c_str(), HAND_FOOTER.c_str());
          }
          
          // Prints cards in player's lane
          void print_lane(Deck* deck){
               std::string lane_name = LANE_SPACES;
               std::string lane_flavor = LANE_SPACES;
               std::string lane_attack = LANE_SPACES;
               std::string lane_shield = LANE_SPACES;
               
               for (unsigned i = 0; i < 3; ++i){
                    lane_name += deck->str_name("lane",i);
                    lane_flavor += deck->str_flavor("lane",i);
                    lane_attack += deck->str_attack("lane",i);
                    lane_shield += deck->str_shield("lane",i);
                    if (i < 2){
                         lane_name += "     ";
                         lane_flavor += "     ";
                         lane_attack += "     ";
                         lane_shield += "     ";
                    }
               }
               
               printf("%s\n%s\n%s\n", LANE_HEADER.c_str(), lane_name.c_str(), lane_flavor.c_str());
               printf("%s\n%s\n%s\n", LANE_BUFFER.c_str(), lane_attack.c_str(), lane_shield.c_str());
               printf("%s\n%s\n\n", LANE_BUFFER.c_str(), LANE_FOOTER.c_str());
          }
          
     
     public:
          // Constructor
          Board(Character* p1, Character* p2, Deck* deck_p1, Deck* deck_p2){
               this->p1 = p1;
               this->p2 = p2;
               this->deck_p1 = deck_p1;
               this->deck_p2 = deck_p2;
               turn_count = 0;
          }
          
          // Returns true if either character has no health
          bool is_game_over(){
               return !(this->p1->has_health() && this->p2->has_health());
          }
          
          // When the game is over, return name of the winner (otherwise returns "Tie")
          std::string get_winner(){
               this->print_board();
               if (!(this->p1->has_health()) && !(this->p2->has_health())){ 
                    return "Tie";
               }
               else if (this->p1->has_health()){
                    return this->p1->get_name();
               }
               else {
                    return this->p2->get_name();
               }
          }
          
          // Checks if number parsed from user is a valid lane
          bool is_valid_lane(char number){
               for (char i = '1'; i <= '3'; ++i){
                    if (i == number){
                         return true;
                    }
               }
               return false;
          }
          
          // Checks if number parsed from user corresponds to a valid hand card
          bool is_valid_card(char number){
               for (char i = '1'; i <= '5'; ++i){
                    if (i == number){
                         return true;
                    }
               }
               return false;
          }
          
          // Retreats a creature from a lane, if possible
          void retreat_card(Character* player, Deck* deck, int number){
               if (player->get_retreats() > 0){
                    bool is_able = deck->remove_from_lane(number - 1);
                    if (is_able){
                         player->set_retreats(player->get_retreats() - 1);
                    }
                    else {
                         printf("Lane %d is already empty\n", number);
                    }
               }
               else {
                    printf("You cannot retreat a creature this turn\n");
               }
          }
          
          // Plays a card from your hand onto a lane
          void play_card(Character* player, Deck * deck, int card_number, int lane_number){
               if (player->get_current_AP() > 0){
                    bool is_able = deck->add_to_lane(card_number - 1, lane_number - 1);
                    if (is_able){
                         player->set_current_AP(player->get_current_AP() - 1);
                    }
                    else{
                         printf("\nCannot play that card on lane %d.\n", lane_number);
                    }
               }
               else{
                    printf("\nYou do not have any AP left.\n");
               }
          }
          
          // Executes turn actions for the player whose turn it is
          void play_turn(){
               if (turn_count % 2 == 0){
                    play_turn_helper(p1, deck_p1);
               }
               else {
                    play_turn_helper(p2, deck_p2);
               }
               turn_count += 1;
          }
          
          // Resets AP and number of retreat
          // Draw 5 cards from the draw pile to your deck
          // Do various things with your AP and retreat amount
          // Attack, if possible
          // Discard the cards in your hand
          void play_turn_helper(Character* player, Deck* deck){
               std::string command;
               player->set_retreats(1);
               player->set_current_AP(2);
               
               deck->draw();

               // Get user commands to retreat or play a card
               while (command != "e"){
                    // Clears screen
                    system("tput reset");
                    if (command.size() > 2 && command.size() < 6){
                         // Handle retreat
                         if (command[0] == 'r'){
                              if (command.size() == 3 && command[1] == ' ' && this->is_valid_lane(command[2])){
                                   this->retreat_card(player, deck, command[2] - '0');
                              }
                              else{
                                   printf("\n----Command Unrecognized----\n");
                              }
                         }
                         // Handle playing the card
                         else if (command[0] == 'p'){
                              if (command.size() == 5 && command[1] == ' ' && this->is_valid_card(command[2]) && command[3] == ' ' && this->is_valid_lane(command[4])){
                                   this->play_card(player, deck, command[2] - '0', command[4] - '0');
                              }
                              else {
                                   printf("\n----Command Unrecoginzed----\n");
                              }
                         }
                         else {
                              printf("\n----Command Unrecoginzed----\n");
                         }
                    }
                    else if (command != ""){
                         printf("\n----Command Unrecognized----\n");
                    }
                    this->print_board();
                    printf("\n" GOLD "%s\'s" RESET " Turn:\n", player->get_name().c_str());
                    printf("%s", CMD_MESSAGE.c_str());
                    getline(cin, command);
               }
               
               // Attack Phase
               if (player == this->p1){
                    attack(p1, p2, deck_p1, deck_p2);
               }
               else{
                    attack(p2, p1, deck_p2, deck_p1);
               }
               
               // Put cards in your hand in discard pile
               deck->discard_hand();
               
          }
          
          // Attack the opposing lanes/character, if possible
          // Defeated cards are sent to the discard pile
          void attack(Character* attacker, Character* defender, Deck* deck_attack, Deck* deck_defend){
               int attacker_damage = 0;
               int defender_damage = 0; 
                // Attack opponent and deal damage
               for (unsigned i = 0; i < 3; ++i){
                    // Only considers current player's populated lanes
                    if (deck_attack->get_lane_name(i) != ""){
                         // Attack opposing creature if opponent's lane is populated
                         if (deck_defend->get_lane_name(i) != ""){
                              attacker_damage = deck_attack->get_lane_attack(i) * get_damage_multiplier(deck_attack->get_lane_flavor(i), deck_defend->get_lane_flavor(i)); 
                              defender_damage = deck_defend->get_lane_attack(i) * get_damage_multiplier(deck_defend->get_lane_flavor(i), deck_attack->get_lane_flavor(i));
                              deck_attack->damage(defender_damage, i);
                              deck_defend->damage(attacker_damage, i);
                         }
                         // Otherwise, attack the opponent's character
                         else{
                              // Handle player damage
                              attacker_damage = deck_attack->get_lane_attack(i);
                              defender->lose_health(attacker_damage);
               
                         }
                    }
                    
               }
          }
          
          void play_match(){
               this->deck_p1->init_draw_pile();
               this->deck_p2->init_draw_pile();
               
               // FIXME: If decks contain same cards in same order, they will be played in same order. 
               // FIXME: Update random function
               this->deck_p2->randomize();
               
               while (!this->is_game_over()){
                    // Clears screen
                    //system("tput reset");
                    this->play_turn();
               }
               std::string winner = this->get_winner();
               if (winner == "Tie"){
                    printf("\n\nMatch ended in a tie!\n\n");
               }
               else{
                    printf("\n\n%s wins!\n\n", winner.c_str());
               }
               
          }
          // Prints the board layout
          void print_board(){
               
               // Prints cards in P1's hand
               print_hand(this->p1, this->deck_p1);
               
               // Prints cards in P1's lane
               print_lane(this->deck_p1);
               
               // Prints cards in P2's lane
               print_lane(this->deck_p2);
               
               // Prints cards in P2's hand
               print_hand(this->p2, this->deck_p2);
                        
          }
          
};



#endif