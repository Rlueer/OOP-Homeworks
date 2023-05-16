#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include "World.h"

class World;

using namespace std;

class Robot{
    friend class World; // Making the World class a friend of Robot class
    protected:      // Protected properties of the Robot class   
        int Type;
        int Strength;
        int Hitpoints;
        string Name;
        World* world;
        int x,y;
        bool moved;
        bool fighted;
        int a,b;
    public:
        // Public methods of the Robot class
        Robot();    // Constructors and destructor
        ~Robot();
        Robot(World* wrld,int x,int y,int newType, int newStrength, int newHit, string name);
        Robot(World* wrld,int x,int y);
        
        virtual int getDamage();
        void move(); //move functions for robots
        int fight_loop(Robot& attacker,Robot& victim);  //starts fight loop between two Robot object
        void hit_message(Robot& attacker,Robot& victim,int damage,int new_hitpoint);    //prints damages,hitpoints

        //GETTERS
        virtual string getType();   
        virtual int getStrength();  
        virtual int getHitpoints();
        string getName();
        //SETTERS
        virtual void setType(int typ);  
        virtual void setStrength(int str);  
        virtual void setHitpoints(int hit);
        
};


#endif