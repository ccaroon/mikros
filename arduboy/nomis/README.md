nomis
=====

## Description
A simple memory game similar to Simon(tm).

## Instructions
The game starts at level one by showing one of the 6 buttons on the screen
and playing an associated tone. Your job is to repeat the button press.

At each level a new button is added to the sequence. So by level 5 the Arduboy
will display a sequence of five buttons and play their associated tones and
you'll have to repeat the sequence of 5.

There's currently no penalty for getting it wrong. You get as many tries as you
like.

You advance levels by successfully repeating the sequence that the Arduboy plays.

How far can you get??

## Download
[From GitHub](https://github.com/ccaroon/arduino/tree/master/arduboy/nomis)

## Installation
### Arduino IDE
1. Make a folder named nomis in your Sketchbook folder.
2. Copy files nomis.h and nomis.cpp into the nomis folder.
3. Copy file main.ino into the nomis folder and rename it to nomis.ino.

### Platformio
1. platformio run --target upload

## Development
Nomis was developed with [Platformio](http://platformio.org)

-----

## Work In Progress

### Iteration 0 -- Done!
There's nothing to play. It just runs thru a demo of the various pieces.

### Iteration 1 <--- We Are Here (Jun 16, 2016)
* The game is playable. Might be some bugs. Pretty bare bones.

### Iteration N (Coming Soon)
* Instructions
* Better graphics
    - Game Logo
    - Success/Fail screens
    - Dev Logo
* Menu for...
    - Settings
        - Sound Only
        - Visual Only
        - Both
    - Modes
        - Additive (default)
        - Random
* Scores?
* Pause between levels for user input
    - Continue or Quit
