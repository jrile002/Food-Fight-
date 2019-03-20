#ifndef __MENU_H__
#define __MENU_H__

#include <iostream>

const string TITLE_1 = "    ______                     __           ______    _              __     __ ";
const string TITLE_2 = "   / ____/  ____   ____   ____/ /          / ____/   (_)   ____ _   / /_   / /_";
const string TITLE_3 = "  / /_     / __ \\ / __ \\ / __  /          / /_      / /   / __ `/  / __ \\ / __/";
const string TITLE_4 = " / __/    / /_/ // /_/ // /_/ /          / __/     / /   / /_/ /  / / / // /_  ";
const string TITLE_5 = "/_/       \\____/ \\____/ \\__,_/          /_/       /_/    \\__, /  /_/ /_/ \\__/  ";
const string TITLE_6 = "                                                        /____/                 ";

const string BATTLE_1 = "___  ____ ___ ___ _    ____ ";
const string BATTLE_2 = "|__] |__|  |   |  |    |___ ";
const string BATTLE_3 = "|__] |  |  |   |  |___ |___ ";

const string CUSTOMIZE_1 = "____ _  _ ____ ___ ____ _  _ _ ___  ____    ___  ____ ____ _  _";
const string CUSTOMIZE_2 = "|    |  | [__   |  |  | |\\/| |   /  |___    |  \\ |___ |    |_/ ";
const string CUSTOMIZE_3 = "|___ |__| ___]  |  |__| |  | |  /__ |___    |__/ |___ |___ | \\_";

const string EXIT_1 = " ___       ___";    
const string EXIT_2 = "|__  \\_/ |  | ";     
const string EXIT_3 = "|___ / \\ |  | ";    

const unsigned char NUM_MENU_SPACES = 50;

#define GRAY_HIGHLIGHT "\x1b[47m"
#define NORMAL "\x1b[0m" 

class Menu{
     private:
     string menu_spaces;

     public:
          Menu(){
               for (unsigned char i = 0; i < NUM_MENU_SPACES; ++i){
                    this->menu_spaces += " ";
               }
          }
          
          // Print the menu
          void print(){
               printf("%s%s\n", this->menu_spaces.c_str(), TITLE_1.c_str());
               printf("%s%s\n", this->menu_spaces.c_str(), TITLE_2.c_str());
               printf("%s%s\n", this->menu_spaces.c_str(), TITLE_3.c_str());
               printf("%s%s\n", this->menu_spaces.c_str(), TITLE_4.c_str());
               printf("%s%s\n", this->menu_spaces.c_str(), TITLE_5.c_str());
               printf("%s%s\n\n\n", this->menu_spaces.c_str(), TITLE_6.c_str());
          }
          // Select and play a game mode
          
          int select_mode(){
               const unsigned char NUM_MODES = 3;
               string input;
               string color;
               unsigned char highlight = 0;
               
               do{
                    system("tput reset");
                    this->print();
                    
                    if (input == "8"){
                         highlight = highlight == 0 ? NUM_MODES - 1 : highlight - 1;
                    }
                    else if (input == "2"){ 
                         highlight = highlight < NUM_MODES - 1 ? highlight + 1 : 0;
                    }
                    
                    // Highlight the current mode being selected
                    if (highlight == 0){color = GRAY_HIGHLIGHT;}
                    else {color = NORMAL;}
                    printf("%s%s%s%s\n", this->menu_spaces.c_str(), color.c_str(), BATTLE_1.c_str(), NORMAL);
                    printf("%s%s%s%s\n", this->menu_spaces.c_str(), color.c_str(), BATTLE_2.c_str(), NORMAL);
                    printf("%s%s%s%s\n", this->menu_spaces.c_str(), color.c_str(), BATTLE_3.c_str(), NORMAL);
                    printf("\n");
                    
                    if (highlight == 1){color = GRAY_HIGHLIGHT;}
                    else {color = NORMAL;}
                    printf("%s%s%s%s\n", this->menu_spaces.c_str(), color.c_str(), CUSTOMIZE_1.c_str(), NORMAL);
                    printf("%s%s%s%s\n", this->menu_spaces.c_str(), color.c_str(), CUSTOMIZE_2.c_str(), NORMAL);
                    printf("%s%s%s%s\n", this->menu_spaces.c_str(), color.c_str(), CUSTOMIZE_3.c_str(), NORMAL);
                    printf("\n");
                    
                    if (highlight == 2){color = GRAY_HIGHLIGHT;}
                    else {color = NORMAL;}
                    printf("%s%s%s%s\n", this->menu_spaces.c_str(), color.c_str(), EXIT_1.c_str(), NORMAL);
                    printf("%s%s%s%s\n", this->menu_spaces.c_str(), color.c_str(), EXIT_2.c_str(), NORMAL);
                    printf("%s%s%s%s\n", this->menu_spaces.c_str(), color.c_str(), EXIT_3.c_str(), NORMAL);
                    printf("\n");

                    getline(cin, input);
               }while (input.size() > 0);
               
               return highlight;
          }
};





#endif