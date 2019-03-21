#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <string>
const int CHAR_NAME_SIZE = 15;

struct Character{
     private:
          // Data
          std::string name;
          int base_health;
          int base_AP;
          int current_health;
          int current_AP;
          int retreats;
     public:
          // Constructor
          Character(std::string name, int health){
               this->name = name;
               this->base_health = (health >= 0) ? health : 0;
               this->current_health = this->base_health;
               this->base_AP = 2;
               this->current_AP = 2;
               this->retreats = 1;
          }
          // Accessor
          inline bool has_health(){
               return (this->current_health > 0);
          }
          inline bool has_AP(){
               return (this->current_AP > 0);
          }
          inline bool has_retreats(){
               return (this->retreats > 0);
          }
          inline std::string get_name(){
               return this->name;
          }
          inline int get_current_health(){
               return this->current_health;
          }
          inline int get_current_AP(){
               return this->current_AP;
          }
          inline int get_retreats(){
               return this->retreats;
          }
          // Mutator
          void set_current_AP(int amount){
               this->current_AP = amount;
          }
          void set_retreats(int amount){
               this->retreats = amount;
          }
          
          void lose_health(int damage_amount){
               if (this->current_health - damage_amount > 0){
                    this->current_health = this->current_health - damage_amount;
               }
               else{
                    this->current_health = 0;
               }
          }
          void lose_AP(int AP_cost){
               if (this->current_AP - AP_cost > 0){
                    this->current_AP = this->current_AP - AP_cost;
               }
               else{
                    this->current_AP = 0;
               }
          }
          
          void lose_retreat(int retreat_cost){
               if (this->retreats - retreat_cost > 0){
                    this->retreats = this->retreats - retreat_cost;
               }
               else{
                    this->retreats = 0;
               }
          }
          // Printing
          std::string str_character_name(){
               std::string temp = this->name;
               int range = temp.size();
               for (unsigned i = 0; i < (CHAR_NAME_SIZE - range) / 2; ++i){
                    temp = " " + temp + " ";
               }
               if (temp.size() < CHAR_NAME_SIZE){
                    temp += " ";
               }
               return temp;
          }
          std::string str_character_health(){
               std::string temp = std::to_string(this->current_health);
               while (temp.length() < 3){
                    temp = "0" + temp;
               }
               return temp;
               
          }
};



#endif