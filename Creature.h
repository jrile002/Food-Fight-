#ifndef __CREATURE_H__
#define __CREATURE_H__

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

const int CREAT_NAME_SIZE = 17;
const string HEADER = "#-------------------#";
const string FILLER = "|-------------------|";
const double SUPER_EFF = 1.5;
const double IN_EFF = 0.5;
// Flavor colors:  Cherry(Red), Berry(Blue), Minty(Green), Lemony(Yellow), Chocolatey(Brown) 
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define BLUE    "\x1b[34m"
// Attack and Shield Colors
#define L_RED   "\x1b[91m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

class Card{ //
     private:
          string name;
          string type;
     public:
          // Constructor
          Card(){
               this->name = "";
               this->type = "";
          }
          // Accessors
          inline string get_name(){return this->name;}
          inline string get_type(){return this->type;}
          
          // Mutators
          void set_name(string new_name){this->name = new_name;}
          void set_type(string new_type){this->type = new_type;}
          
          virtual int perform_int(string id) = 0; // For executing int functions
          virtual string perform_str(string id){return "";} // For executing string functions
          virtual void perform_void(string id, int x, string y){}
          // Printing
          virtual string print_data(unsigned int data_number){return "";}

};

// Food character cards
class Creature: public Card{

     private:
          // Stats
          int base_attack = 0;
          int base_shield = 0;
          string flavor = "";
          unsigned int ability = 0; // FIXME: Contains index to ability list
          unsigned int index = 0; // FIXME: Contains index of evolution list
          // Variable Stats 
          int attack_power = 0;
          int shield_power = 0;
     public:
          // Constructor
          Creature(){
               this->set_type("Creature");
               this->base_attack = 0;
               this->base_shield = 0;
               this->flavor = "";
               this->ability = 0;
               this->index = 0;
               this->attack_power = this->base_attack;
               this->shield_power = this->base_shield;
          }
          Creature(string id){
               if (id == "Green Icy"){
                    this->set_name(id);
                    this->set_type("Creature");
                    this->base_attack = 3;
                    this->base_shield = 5;
                    this->flavor = "Minty";
                    this->ability = 0;
                    this->index = 1;
                    this->attack_power = this->base_attack;
                    this->shield_power = this->base_shield;
               }
               else if (id == "Green Scoop"){
                    this->set_name(id);
                    this->set_type("Creature");
                    this->base_attack = 6;
                    this->base_shield = 10;
                    this->flavor = "Minty";
                    this->ability = 0;
                    this->index = 2;
                    this->attack_power = this->base_attack;
                    this->shield_power = this->base_shield;
               }
               else if (id == "Green Cake"){
                    this->set_name(id);
                    this->set_type("Creature");
                    this->base_attack = 9;
                    this->base_shield = 15;
                    this->flavor = "Minty";
                    this->ability = 0;
                    this->index = 3;
                    this->attack_power = this->base_attack;
                    this->shield_power = this->base_shield;
               }
               else if (id == "Blue Icy"){
                    this->set_name(id);
                    this->set_type("Creature");
                    this->base_attack = 3;
                    this->base_shield = 5;
                    this->flavor = "Berry";
                    this->ability = 0;
                    this->index = 4;
                    this->attack_power = this->base_attack;
                    this->shield_power = this->base_shield;
               }
               else if (id == "Blue Scoop"){
                    this->set_name(id);
                    this->set_type("Creature");
                    this->base_attack = 6;
                    this->base_shield = 10;
                    this->flavor = "Berry";
                    this->ability = 0;
                    this->index = 5;
                    this->attack_power = this->base_attack;
                    this->shield_power = this->base_shield;
               }
               else if (id == "Blue Cake"){
                    this->set_name(id);
                    this->set_type("Creature");
                    this->base_attack = 9;
                    this->base_shield = 15;
                    this->flavor = "Berry";
                    this->ability = 0;
                    this->index = 6;
                    this->attack_power = this->base_attack;
                    this->shield_power = this->base_shield;
               }
               else if (id == "Red Icy"){
                    this->set_name(id);
                    this->set_type("Creature");
                    this->base_attack = 3;
                    this->base_shield = 5;
                    this->flavor = "Cherry";
                    this->ability = 0;
                    this->index = 7;
                    this->attack_power = this->base_attack;
                    this->shield_power = this->base_shield;
               }
               else if (id == "Red Scoop"){
                    this->set_name(id);
                    this->set_type("Creature");
                    this->base_attack = 6;
                    this->base_shield = 10;
                    this->flavor = "Cherry";
                    this->ability = 0;
                    this->index = 8;
                    this->attack_power = this->base_attack;
                    this->shield_power = this->base_shield;
               }
               else if (id == "Red Cake"){
                    this->set_name(id);
                    this->set_type("Creature");
                    this->base_attack = 9;
                    this->base_shield = 15;
                    this->flavor = "Cherry";
                    this->ability = 0;
                    this->index = 9;
                    this->attack_power = this->base_attack;
                    this->shield_power = this->base_shield;
               }
               else{
                    this->set_type("Creature");
                    this->base_attack = 0;
                    this->base_shield = 0;
                    this->flavor = "";
                    this->ability = 0;
                    this->index = 0;
                    this->attack_power = this->base_attack;
                    this->shield_power = this->base_shield;
               }
          }
          
          // Public Accessor Functions
          inline string get_flavor(){ return this->flavor; }
          inline int get_base_attack(){ return this->base_attack; }
          inline int get_base_shield(){ return this->base_shield; }
          inline int get_index() { return this->index; }
          inline int get_attack_power(){ return this->attack_power; }
          inline int get_shield_power(){ return this->shield_power; }
          // Public Mutator Functions
          inline void set_flavor(string flavor){ this->flavor = flavor; }
          inline void set_base_attack(int amount){ this->base_attack = amount; }
          inline void set_base_shield(int amount){ this->base_shield = amount; }
          inline void set_attack_power(int amount){ this->attack_power = amount; }
          inline void set_shield_power(int amount){ this->shield_power = amount; }
          
          void lower_attack_power(int amount){
               if (this->attack_power - amount > 0){
                    this->attack_power -= amount;
               }
               else {
                    this->attack_power = 0;
               }
          }
          
          void lower_shield_power(int amount){
               if (this->shield_power - amount > 0){
                    this->shield_power -= amount;
               }
               else {
                    this->shield_power = 0;
               }
          }
          // Print Function
          void print_creature(){
               printf("name: %s\nflavor: %s\nattack power: %d\nshield power: %d\n", this->get_name().c_str(), this->get_flavor().c_str(), this->get_attack_power(), this->get_shield_power());
          }
          
          string str_name(){
               string temp = this->get_name();
               int range = temp.size();
               for (unsigned i = 0; i < (CREAT_NAME_SIZE - range) / 2; ++i){
                    temp = " " + temp + " ";
               }
               if (temp.size() < CREAT_NAME_SIZE){
                    temp += " ";
               }
               return temp;
          }
          
          string str_flavor(){
               string color;
               string temp = this->flavor;
               if (temp == "Minty") { color = GREEN; }
               else if (temp == "Berry") { color = BLUE; }
               else if (temp == "Cherry") { color = RED; }
               
               int range = temp.size();
               for (unsigned i = 0; i < (CREAT_NAME_SIZE - range) / 2; ++i){
                    temp = " " + temp + " ";
               }
               if (temp.size() < CREAT_NAME_SIZE){
                    temp += " ";
               }
               return color + temp + RESET;
          }
          
          string str_attack(){
               string temp = "Atk: " + to_string(this->attack_power);
               int range = temp.size();
               for (unsigned i = 0; i < (CREAT_NAME_SIZE - range) / 2; ++i){
                    temp = " " + temp + " ";
               }
               if (temp.size() < CREAT_NAME_SIZE){
                    temp += " ";
               }
               return L_RED + temp + RESET;
          }
          
          string str_shield(){
               string temp = "Shld: " + to_string(this->shield_power);
               int range = temp.size();
               for (unsigned i = 0; i < (CREAT_NAME_SIZE - range) / 2; ++i){
                    temp = " " + temp + " ";
               }
               if (temp.size() < CREAT_NAME_SIZE){
                    temp += " ";
               }
               return CYAN + temp + RESET;
          }
          // Virtual function implementations
          int perform_int(string id){
               if (id == "get_base_attack"){ return this->get_base_attack(); }
               else if (id == "get_base_shield"){ return this->get_base_shield(); }
               else if (id == "get_attack_power"){ return this->get_attack_power(); }
               else if (id == "get_shield_power"){ return this->get_shield_power(); }
               else if (id == "get_index") { return this->get_index(); }
               else { return 0; }
          } 
          string perform_str(string id){
               if (id == "get_flavor"){ return this->get_flavor();}
               else if (id == "str_name") {return this->str_name(); }
               else if (id == "str_flavor") {return this->str_flavor(); }
               else if (id == "str_attack") {return this->str_attack(); }
               else if (id == "str_shield") {return this->str_shield(); }
               else { return ""; }
          }
          void perform_void(string id, int x, string y){
               if (id == "set_flavor") { this->set_flavor(y); }
               else if (id == "set_base_attack") { this->set_base_attack(x); }
               else if (id == "set_base_shield") { this->set_base_shield(x); }
               else if (id == "set_attack_power") { this->set_attack_power(x); }
               else if (id == "set_shield_power") { this->set_shield_power(x); }
               else if (id == "lower_attack_power") { this->lower_attack_power(x); }
               else if (id == "lower_shield_power") { this->lower_shield_power(x); }
               else if (id == "print_creature") {this->print_creature();}
          }
          string print_data(unsigned int data_number){
               switch (data_number){
                    case 0:
                         return HEADER;
                    case 1:
                         if (this->get_name().size() > 0){
                              return "|-" + str_name() + "-|";
                         }
                         else {
                              return FILLER;
                         }
                    case 2:
                         if (this->get_name().size() > 0){
                              return "|-" + str_flavor() + "-|";
                         }
                         else {
                              return FILLER;
                         }
                    case 3: 
                         return FILLER;
                    case 4:
                         if (this->get_name().size() > 0){
                              return "|-" + str_attack() + "-|";
                         }
                         else {
                              return FILLER;
                         }
                    case 5:
                         if (this->get_name().size() > 0){
                              return "|-" + str_shield() + "-|";
                         }
                         else {
                              return FILLER;
                         }
                    case 6:
                         return FILLER;
                    default:
                         printf("\n\nERROR - Data number exceeds limit\n\n");
                         exit(1);
               }
          }
     
};

// Evolution cards
class Cube: public Card{
     private:
          string flavor = "";
     public:
          // Constructors
          Cube(){
               this->flavor = "";
               this->set_type("Cube");
          }
          Cube(string id){
               if (id == "Minty Cube"){
                    this->set_name(id);
                    this->flavor = "Minty";
                    this->set_type("Cube");
               }
               else if (id == "Berry Cube"){
                    this->set_name(id);
                    this->flavor = "Berry";
                    this->set_type("Cube");
               }
               else if (id == "Cherry Cube"){
                    this->set_name(id);
                    this->flavor = "Cherry";
                    this->set_type("Cube");
               }
               else {
                    this->flavor = "";
                    this->set_type("Cube");
               }
          }
          // Accessors
          inline string get_flavor(){ return this->flavor; } 
          
          // For Printing
          string str_name(){
               string temp = this->get_name();
               int range = temp.size();
               for (unsigned i = 0; i < (CREAT_NAME_SIZE - range) / 2; ++i){
                    temp = " " + temp + " ";
               }
               if (temp.size() < CREAT_NAME_SIZE){
                    temp += " ";
               }
               return temp;
          }
          string str_flavor(){
               string color;
               string temp = this->flavor;
               if (temp == "Minty") { color = GREEN; }
               else if (temp == "Berry") { color = BLUE; }
               else if (temp == "Cherry") { color = RED; }
               
               int range = temp.size();
               for (unsigned i = 0; i < (CREAT_NAME_SIZE - range) / 2; ++i){
                    temp = " " + temp + " ";
               }
               if (temp.size() < CREAT_NAME_SIZE){
                    temp += " ";
               }
               return color + temp + RESET;
          }
          // FIXME
          int perform_int(string id){
               return 0;
          }
          string perform_str(string id){
               if (id == "get_flavor"){ return this->get_flavor();}
               else if (id == "str_name") {return this->str_name(); }
               else if (id == "str_flavor") {return this->str_flavor(); }
               else { return ""; }
               
          }
          // FIXME
          void perform_void(string id, int x, string y){
               
          }
          // Printing
          string print_data(unsigned int data_number){
               switch (data_number){
                    case 0:
                         return HEADER;
                    case 1:
                         return "|-" + str_name() + "-|";
                    case 2:
                         return "|-" + str_flavor() + "-|";
                    case 3: 
                         return FILLER;
                    case 4:
                         return FILLER;
                    case 5:
                         return FILLER;
                    case 6:
                         return FILLER;
                    default:
                         return "ERROR";
               }
          }
};


double get_damage_multiplier(string user_flavor, string opp_flavor){
     if (user_flavor == "Minty"){
          if (opp_flavor == "Minty"){
               return 1;
          }
          else if (opp_flavor == "Cherry"){
               return IN_EFF;
          }
          else if (opp_flavor == "Berry"){
               return SUPER_EFF;
          }
          else {
               return 0;
          }
     }
     else if (user_flavor == "Cherry"){
          if (opp_flavor == "Minty"){
               return SUPER_EFF;
          }
          else if (opp_flavor == "Cherry"){
               return 1;
          }
          else if (opp_flavor == "Berry"){
               return IN_EFF;
          }
          else {
               return 0;
          }
     }
     else if (user_flavor == "Berry"){
          if (opp_flavor == "Minty"){
               return IN_EFF;
          }
          else if (opp_flavor == "Cherry"){
               return SUPER_EFF;
          }
          else if (opp_flavor == "Berry"){
               return 1;
          }
          else {
               return 0;
          }
     }
     else {
          return 0;
     }
}





#endif