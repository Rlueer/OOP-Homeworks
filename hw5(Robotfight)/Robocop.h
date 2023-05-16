#ifndef ROBOCOP_H
#define ROBOCOP_H

#include <iostream>
#include "Robot.h"
#include "World.h"
#include "Humanic.h"

using namespace std;

class Robocop : public Humanic {
    friend class World;
    public:
        static int RobocopCount;// static variable to count the number of instances of the 
        Robocop();  // default constructor
        Robocop(World* wrld,int x,int y,int newType, int newStrength, int newHit, string name);
        Robocop(World* wrld,int x,int y);

        string getType();   // method to get the type of the robot
        int getStrength();      // method to get the strength of the robot
        int getHitpoints(); // method to get the hit points of the robot
        string getName();   // method to get the name of the robot
        //SETTERS
        void setType(int typ);  // method to set the type of the robot
        void setStrength(int str);  // method to set the strength of the robot
        void setHitpoints(int hit); // method to set the hit points of the robot

};

#endif