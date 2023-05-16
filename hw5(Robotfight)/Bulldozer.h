#ifndef BULLDOZER_H
#define BULLDOZER_H

#include <iostream>
#include "Robot.h"
#include "World.h"

using namespace std;

class Bulldozer : public Robot {
    friend class World;
    public:
        // Static variable to keep track of the number of instances of Bulldozer class
        static int BulldozerCount;
        // Constructors
        Bulldozer();
        Bulldozer(World* wrld,int x,int y,int newType, int newStrength, int newHit, string name);
        Bulldozer(World* wrld,int x,int y);

        // Getter functions for the Bulldozer properties
        string getType();
        int getStrength();  
        int getHitpoints();
        string getName();
        // Setter functions for the Bulldozer properties
        void setType(int typ);  
        void setStrength(int str);  
        void setHitpoints(int hit);

};

#endif