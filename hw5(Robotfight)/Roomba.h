#ifndef ROOMBA_H
#define ROOMBA_H

#include <iostream>
#include "Robot.h"
#include "World.h"

using namespace std;

class Roomba : public Robot {
    friend class World;
    public:
        static int RoombaCount;
        Roomba();
        Roomba(World* wrld,int x,int y,int newType, int newStrength, int newHit, string name);
        Roomba(World* wrld,int x,int y);
        int getDamage();
        string getType();
        int getStrength(); 
        int getHitpoints();
        string getName();
        //SETTERS
        void setType(int typ);  
        void setStrength(int str);  
        void setHitpoints(int hit);

};

#endif