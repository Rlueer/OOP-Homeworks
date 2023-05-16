#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include "Robot.h"

const int WORLDSIZE = 10;

class Robot;
class Humanic;
class Optimusprime;
class Robocop;
class Roomba;
class Bulldozer;


using namespace std;

// This is the class definition for the World class.
class World{
    // These are friend classes that have access to the private members of the World class.
    friend class Robot;
    friend class Humanic;
    friend class Optimusprime;
    friend class Robocop;
    friend class Roomba;
    friend class Bulldozer;
    public:
        // This is the default constructor for the World class.
        World();
        ~World();
        // This function returns a pointer to the robot at the specified grid location.
        Robot* getAt(int x,int y);
        // This function sets the robot at the specified grid location.
        void setAt(int x,int y, Robot* org);
        // This function displays the current state of the grid.
        void Display();
        // This function simulates one step of the game.
        void SimulateOneStep();
    
    private:
    // This is the grid that represents the world.
        Robot* grid[WORLDSIZE][WORLDSIZE];
};



#endif