# Food-Fight!
A food-based trading card game

## How to Play
+ Food-Fight! is a turn-based, two-player game.
+ The object of the game is to bring the opponent's cleanliness meter (health) to 0.
+ Players start the game with a deck of 20 cards and draw 5 cards at the beginning of their turn.
+ Each turn, a player may do one of the following:
    + Play a card (detailed discussion below)
    + Retreat a creature
+ A player is only able to make a move if they have enough AP (action points)
+ At the end of turn, the player discards all the unused cards in their hand. Any "Food Creature" cards in play will perform their action at this time.
+ The last player standing wins!

## Food Creatures
+ Food Creatures are one type of playable card.
+ Food Creatures may be played on any of the player's 3 lanes if that lane is empty.
+ At the end of a player's turn, their Food Creatures will attempt to inflict damage on the opponent.
+ Food Creatures can only inflict direct damage to the opponent if there are no opposing Food Creatures in their lane; otherwise, the opposing Food Creatures take the damage.
+ Food Creatures will fight back if directly attacked by opposing Food Creatures. 

## Condiments
+ Condiments are another type of playable card.
+ Condiments permanently upgrade Food Creature cards, making them stronger.

## Flavors
+ There are currently 3 flavors (types) of cards in the game: Cherry, Minty, and Berry.
    + CHERRY is strong against Minty but weak against Berry.
    + MINTY is strong against Berry but weak against Cherry.
    + BERRY is strong against Cherry but weak against Minty.  

## Compiling and Running the Program
+ Note: Currently only supported on Linux
+ To compile, use the following command: `make`
+ To run the program: `./food_fight.out`
