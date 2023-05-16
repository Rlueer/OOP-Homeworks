#ifndef HUMANIC_H
#define HUMANIC_H

#include <iostream>
#include "Robot.h"


using namespace std;

// Humanic class inherits from the Robot class
class Humanic : public Robot {
    friend class World;
    public:
        // Constructors
        Humanic();
        Humanic(World* wrld,int x,int y,int newType, int newStrength, int newHit, string name);
        Humanic(World* wrld,int x,int y);

        // Overridden virtual functions from Robot class
        virtual int getDamage();
        virtual string getType();
        virtual int getStrength();  
        virtual int getHitpoints();
        virtual string getName();
        
        //SETTERS   
        virtual void setType(int typ);  
        virtual void setStrength(int str);  
        virtual void setHitpoints(int hit);
};


#endif