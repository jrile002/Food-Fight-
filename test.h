#ifndef __TEST_H__
#define __TEST_H__

#include "Creature.h"
#include "Board.h"
#include "Menu.h"

void creature_test();
void creature_test1();
void creature_test2();
void creature_test3();
void creature_test4();
void creature_test5();

void card_test();
void card_test1();
void card_test2();

void character_test();
void character_test1();
void character_test2();
void character_test3();
void character_test4();
void character_test5();

void deck_test();
void deck_test1();
void deck_test2();
void deck_test3();
void deck_test4();
void deck_test5();
void deck_test6();

void board_test();
void board_test1();
void board_test2();
void board_test3();
void board_test4();
void board_test5();

void cube_test();
void cube_test1();
void cube_test2();

void menu_test();
void menu_test1();
void menu_test2();

void gameplay_test();

// /////////////////////////////////////////////////
// Card Test Functions
void card_test(){
     card_test1();
     card_test2();
}

void card_test1(){
     printf("--Beginning Card Test 1: Card* c;\n");
     Card* c;
     printf("--Card Test 1 Finished\n\n");
}

void card_test2(){
     printf("--Beginning Card Test 2: Card* c = new Creature();\n");
     Card* c = new Creature();
     printf("--Card Test 2 Finished\n\n");
}

/////////////////////////////////////////////////
// Creature Test Functions
void creature_test(){
     creature_test1();
     creature_test2();
     creature_test3();
     creature_test4();
     creature_test5();
}

void creature_test1(){
     printf("--Beginning Creature Test 1: Creature()\n");
     Card *a = new Creature();
     for (unsigned i = 0; i < 7; ++i){
          printf("%s\n", a->print_data(i).c_str());
     }
     printf("--Test 1 completed\n\n");
}

void creature_test2(){
     printf("--Beginning Creature Test 2: Creature a(\"Green Icy\");\n");
     Card *a = new Creature("Green Icy");
     for (unsigned i = 0; i < 7; ++i){
          printf("%s\n", a->print_data(i).c_str());
     }
     printf("--Test 2 completed\n\n");
}

void creature_test3(){
     printf("--Beginning Creature Test 3: Creature a(\"Unreal Icy\");\n");
     Creature a("Unreal Icy");
     for (unsigned i = 0; i < 7; ++i){
          printf("%s\n", a.print_data(i).c_str());
     }
     printf("--Test 3 completed\n\n");
}

void creature_test4(){
     printf("--Beginning Creature Test 4: Lowering Shield\n");
     Creature a("Green Icy");
     a.print_creature();
     
     int damage_amount = 3;
     a.lower_shield_power(damage_amount);
     printf("Received %d damage\n", damage_amount);
     a.print_creature();
     
     a.lower_shield_power(damage_amount);
     printf("Received %d damage\n", damage_amount);
     a.print_creature();

     printf("--Test 4 completed\n\n");
}

void creature_test5(){
     printf("--Beginning Creature Test 5: Lowering Attack\n");
     Creature a("Green Icy");
     a.print_creature();
     
     int damage_amount = 2;
     a.lower_attack_power(damage_amount);
     printf("Lowered attack by %d\n", damage_amount);
     a.print_creature();
     
     a.lower_attack_power(damage_amount);
     printf("Lowered attack by %d\n", damage_amount);
     a.print_creature();

     printf("--Test 5 completed\n\n");
}
// /////////////////////////////////////////////////
// Character Test Functions
void character_test(){
     character_test1();
     character_test2();
     character_test3();
     character_test4();
}

void character_test1(){
     printf("--Beginning Character Test 1: Constructor\n");
     Character p1("Player 1", 100);
     Character p2("Player 2", 80);
     Character p3("Player 3", -10);
     printf("p1\'s name is %s and health is %d\n", p1.get_name().c_str(), p1.get_current_health());
     printf("p2\'s name is %s and health is %d\n", p2.get_name().c_str(), p2.get_current_health());
     printf("p3\'s name is %s and health is %d\n", p3.get_name().c_str(), p3.get_current_health());
     printf("--Character Test 1 Completed\n\n");
     
}

void character_test2(){
     printf("--Beginning Character Test 2: lose health + Has health\n");
     Character p1("Player 1", 100);
     Character p2("Player 2", 80);
     printf("%s\'s starting health is: %d HP\n" , p1.get_name().c_str(), p1.get_current_health());
     printf("%s\'s starting health is: %d HP\n\n" , p2.get_name().c_str(), p2.get_current_health());
     int damage_amount = 50;
     while(p1.has_health()){
          printf("%s loses %d HP\n" , p1.get_name().c_str(), damage_amount);
          p1.lose_health(damage_amount);
          printf("%s\'s current health is: %d HP\n" , p1.get_name().c_str(), p1.get_current_health());
     }
     printf("\n");
     while(p2.has_health()){
          printf("%s loses %d HP\n" , p2.get_name().c_str(), damage_amount);
          p2.lose_health(damage_amount);
          printf("%s\'s current health is: %d HP\n" , p2.get_name().c_str(), p2.get_current_health());
     }
     printf("\n");
     printf("%s\'s ending health is: %d HP\n" , p1.get_name().c_str(), p1.get_current_health());
     printf("%s\'s ending health is: %d HP\n" , p2.get_name().c_str(), p2.get_current_health());
     
     printf("--Character Test 2 Completed\n\n");
     
}

void character_test3(){
     printf("--Beginning Character Test 3: lose AP\n");
     Character p1("Player 3", 10);
     printf("%s\'s starting AP is: %d AP\n" , p1.get_name().c_str(), p1.get_current_AP());
     int damage_amount = 1;

     while(p1.has_AP()){
          printf("%s loses %d AP\n" , p1.get_name().c_str(), damage_amount);
          p1.lose_AP(damage_amount);
          printf("%s\'s current AP is: %d\n" , p1.get_name().c_str(), p1.get_current_AP());
     }
     printf("\n");
     printf("%s\'s ending AP is: %d\n" , p1.get_name().c_str(), p1.get_current_AP());

     printf("--Character Test 3 Completed\n\n");
     
}

void character_test4(){
     printf("--Beginning Character Test 4: lose retreat\n");
     Character p1("Player 4", 10);
     printf("%s\'s available retreats is: %d\n" , p1.get_name().c_str(), p1.get_retreats());
     int damage_amount = 2;

     while(p1.has_retreats()){
          printf("%s loses %d retreat\n" , p1.get_name().c_str(), damage_amount);
          p1.lose_retreat(damage_amount);
          printf("%s\'s current retreats is: %d\n" , p1.get_name().c_str(), p1.get_retreats());
     }
     printf("\n");
     printf("%s\'s ending retreats is: %d\n" , p1.get_name().c_str(), p1.get_retreats());
     
     printf("--Character Test 4 Completed\n\n");
     
}
// /////////////////////////////////////////////////
// Deck Test Functions

void deck_test(){
     deck_test1();
     deck_test2();
     deck_test3();
     deck_test4();
     deck_test5();
     deck_test6();
}

void deck_test1(){
     printf("--Beginning Deck Test 1: Constructor\n");
     Deck deck;
     string input;
     deck.print();
     printf("Press enter to continue: "); getline(cin, input); printf("\n");
     printf("--Deck Test 1 Completed\n\n");
}

void deck_test2(){
     printf("--Beginning Deck Test 2: Replace() \n");
     Deck deck;
     string input;
     for (unsigned i = 0; i < DECK_MAX_SIZE; ++i){
          if (i % 2 == 0){
               deck.replace(i, new Creature("Red Icy"));
          }
     }
     printf("Press enter to continue: "); getline(cin, input); printf("\n");
     deck.print();
     printf("--Deck Test 2 Completed\n\n");
}

void deck_test3(){
     printf("--Beginning Deck Test 3: Init_Draw_Pile() and Randomize()\n");
     Deck deck;
     string input;
     for (unsigned i = 0; i < DECK_MAX_SIZE; ++i){
          if (i % 2 == 0){
               deck.replace(i, new Creature("Red Icy"));
          }
     }
     printf("Press enter to continue: "); getline(cin, input); printf("\n");
     deck.init_draw_pile();
     deck.print_draw_pile();
     printf("--Deck Test 3 Completed\n\n");
}

void deck_test4(){
     printf("--Beginning Deck Test 4: Draw()\n");
     Deck deck;
     string input;
     for (unsigned i = 0; i < DECK_MAX_SIZE; ++i){
          if (i % 2 == 0){
               deck.replace(i, new Creature("Red Icy"));
          }
     }
     printf("Press enter to continue: "); getline(cin, input); printf("\n");
     deck.init_draw_pile();
     deck.draw();
     printf("Printing Draw Pile\n");
     deck.print_draw_pile();
     printf("Press enter to continue: "); getline(cin, input); printf("\n");
     printf("Printing Hand\n");
     deck.print_hand();
     printf("--Deck Test 4 Completed\n\n");
}

void deck_test5(){
     printf("--Beginning Deck Test 5: Add_To_Lane() and Swap()\n");
     Deck deck;
     string input;
     for (unsigned i = 0; i < DECK_MAX_SIZE; ++i){
          if (i % 2 == 0){
               deck.replace(i, new Creature("Red Icy"));
          }
     }
     deck.init_draw_pile();
     deck.draw();
     printf("Printing Hand\n");
     deck.print_hand();
     printf("Printing Lane\n");
     deck.print_lane();
     printf("\nAdding Creature 0 to Lane 0\n");deck.add_to_lane(0, 0);
     printf("Adding Creature 1 to Lane 1\n");deck.add_to_lane(1, 1);
     printf("Adding Creature 2 to Lane 2\n\n");deck.add_to_lane(2, 2);
     printf("Press enter to continue: "); getline(cin, input); printf("\n");
     
     printf("Printing Hand\n");
     deck.print_hand();
     printf("Printing Lane\n");
     deck.print_lane();
     printf("Press enter to continue: "); getline(cin, input); printf("\n");
     
     printf("\nAdding Creature 3 to Lane 0\n");deck.add_to_lane(3, 0);
     printf("Adding Creature 4 to Lane 1\n");deck.add_to_lane(4, 1);
     printf("Adding Creature 0 to Lane 2\n\n");deck.add_to_lane(1, 2);
     
     printf("Printing Hand\n");
     deck.print_hand();
     printf("Printing Lane\n");
     deck.print_lane();
     printf("Printing Discard\n");
     deck.print_discard_pile();
     
     printf("Press enter to continue: "); getline(cin, input); printf("\n");
     printf("--Deck Test 5 Completed\n\n");
}

void deck_test6(){
     printf("--Beginning Deck Test 6: Remove_From_Lane()\n");
     Deck deck;
     string input;
     deck.init_draw_pile();
     deck.draw();
     
     printf("\nAdding Creature 0 to Lane 0\n");deck.add_to_lane(0, 0);
     printf("Adding Creature 1 to Lane 1\n");deck.add_to_lane(1, 1);
     printf("Adding Creature 2 to Lane 2\n\n");deck.add_to_lane(2, 2);
     printf("Press enter to continue: "); getline(cin, input); printf("\n");
     
     printf("Printing Hand\n");
     deck.print_hand();
     printf("Press enter to continue: "); getline(cin, input); printf("\n");
     printf("Printing Lane\n");
     deck.print_lane();
     printf("Press enter to continue: "); getline(cin, input); printf("\n");
     printf("Printing Discard\n");
     deck.print_discard_pile();
     printf("Press enter to continue: "); getline(cin, input); printf("\n");
     
     printf("\nRemoving Creature from Lane 0\n");deck.remove_from_lane(0);
     printf("Removing Creature from Lane 2\n");deck.remove_from_lane(2);
     printf("Removing Creature from Lane 0\n\n");deck.remove_from_lane(0);
     printf("Press enter to continue: "); getline(cin, input); printf("\n");
     
     printf("Printing Hand\n");
     deck.print_hand();
     printf("Press enter to continue: "); getline(cin, input); printf("\n");
     printf("Printing Lane\n");
     deck.print_lane();
     printf("Press enter to continue: "); getline(cin, input); printf("\n");
     printf("Printing Discard\n");
     deck.print_discard_pile();
     printf("Press enter to continue: "); getline(cin, input); printf("\n");
     
     printf("--Deck Test 6 Completed\n\n");
}
///////////////////////////////////////////////
// Board Test Functions

void board_test(){
     board_test1();
     board_test2();
     board_test3();
     board_test4();
     board_test5();
}

void board_test1(){
     printf("--Beginning Board Test 1: Print_Board()\n");
     Character c1("Player 1", 100);
     Character c2("Player 2", 100);
     Deck d1;
     Deck d2;
     Board b(&c1, &c2, &d1, &d2);
     b.print_board();
     printf("--Board Test 1 Completed\n\n");
}

void board_test2(){
     printf("--Beginning Board Test 2: Print_Board()\n");
     Character c1("Mira", 10);
     Character c2("Henry", 5);
     Deck d1;
     Deck d2;
     d1.init_draw_pile();
     d1.draw();
     d2.init_draw_pile();
     d2.draw();
     Board b(&c1, &c2, &d1, &d2);
     b.print_board();
     printf("--Board Test 2 Completed\n\n");
}

void board_test3(){
     printf("--Beginning Board Test 3: One Play Turn()\n");
     Character c1("Player 1", 100);
     Character c2("Player 2", 100);
     Deck d1;
     Deck d2;
     d1.init_draw_pile();
     d2.init_draw_pile();
     Board b(&c1, &c2, &d1, &d2);
     b.play_turn();
     printf("--Board Test 3 Completed\n\n");
}

void board_test4(){
     printf("--Beginning Board Test 4: Two Play Turn()\n");
     Character c1("Player 1", 100);
     Character c2("Player 2", 100);
     Deck d1;
     Deck d2;
     d1.init_draw_pile();
     d2.init_draw_pile();
     Board b(&c1, &c2, &d1, &d2);
     b.play_turn();
     b.play_turn();
     printf("--Board Test 4 Completed\n\n");
}

void board_test5(){
     printf("--Beginning Board Test 4: Two Play Turn()\n");
     Character c1("Player 1", 100);
     Character c2("Player 2", 100);
     Deck d1;
     Deck d2;
     d1.init_draw_pile();
     d2.init_draw_pile();
     Board b(&c1, &c2, &d1, &d2);
     for (unsigned i = 0; i < 3; ++i){
          b.play_turn();
     }
     printf("--Board Test 4 Completed\n\n");
}

///////////////////////////////////////////////
// Cube Test Functions
void cube_test(){
     cube_test1();
     cube_test2();
}

void cube_test1(){
     string input;
     printf("--Beginning Cube Test 1: Cube cube;\n");
     Cube cube;
     for (unsigned i = 0; i < 7; ++i){
          printf("%s\n", cube.print_data(i).c_str());
     }
     printf("--Cube Test 1 Completed\n\n");
     printf("Press enter to continue: "); getline(cin, input); printf("\n");
}

void cube_test2(){
     string input;
     printf("--Beginning Cube Test 2: Cube c1(\"Minty Cube\");\n");
     Cube c1("Minty Cube");
     for (unsigned i = 0; i < 7; ++i){
          printf("%s\n", c1.print_data(i).c_str());
     }
     printf("--Cube Test 2 Completed\n\n");
     printf("Press enter to continue: "); getline(cin, input); printf("\n");
}

///////////////////////////////////////////////
// Menu Test Functions
void menu_test(){
     menu_test1();
     menu_test2();
}

void menu_test1(){
     Menu menu;
     menu.print();
}

void menu_test2(){
     Menu menu;
     menu.print();
     menu.select_mode();
}

// Basic game
void gameplay_test1(){
     Character c1("Player 1", 50);
     Character c2("Player 2", 50);
     Deck d1;
     Deck d2;
     for (unsigned i = 0; i < DECK_MAX_SIZE; ++i){
          if (i % 2 == 0){
               d1.replace(i, new Creature("Red Icy"));
          }
     }
     Board b(&c1, &c2, &d1, &d2);
     b.play_match();
}

// Basic game with evolution cards
void gameplay_test2(){
     Character c1("Joshua", 50);
     Character c2("Opponent", 50);
     Deck d1;
     Deck d2;
     for (unsigned i = 0; i < DECK_MAX_SIZE; ++i){
          if (i % 2 == 0){
               d1.replace(i, new Cube("Minty Cube"));
          }
     }
     Board b(&c1, &c2, &d1, &d2);
     b.play_match();
}

// Basic menu options + game with 3 standard creatures with corresponding evolution cards
void gameplay_test3(){
     Menu menu;
     Character c1("Player 1", 50);
     Character c2("Player 2", 50);
     Deck d1;
     Deck d2;
     for (unsigned i = 0; i < DECK_MAX_SIZE; ++i){
          if (i < 12){
               if (i % 3 == 0){
                    d1.replace(i, new Creature("Blue Icy"));
                    d2.replace(i, new Creature("Blue Icy"));
               }
               else if (i % 3 == 1){
                    d1.replace(i, new Creature("Red Icy"));
                    d2.replace(i, new Creature("Red Icy"));
               }
          }
          else {
               if (i % 3 == 0){
                    d1.replace(i, new Cube("Minty Cube"));
                    d2.replace(i, new Cube("Minty Cube"));
               }
               else if (i % 3 == 1){
                    d1.replace(i, new Cube("Berry Cube"));
                    d2.replace(i, new Cube("Berry Cube"));
               }
               else {
                    d1.replace(i, new Cube("Cherry Cube"));
                    d2.replace(i, new Cube("Cherry Cube"));
               }
          }
     }
     Board b(&c1, &c2, &d1, &d2);
     switch(menu.select_mode()){
          case 0:
              b.play_match();
              break;
          case 1:
               printf("\n\n FIXME - Incorporate deck customization\n\n");
               break;
          case 2:
               return;
          default:
               printf("\n\nERROR - Mode selected doesn't exist\n\n");
               break;
     }
}

#endif