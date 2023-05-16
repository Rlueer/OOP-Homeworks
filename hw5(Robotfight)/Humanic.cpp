#include "Humanic.h"

// Implementation of default constructor for Humanic class
Humanic::Humanic():Robot(){

}
// Implementation of constructor with parameters for Humanic class
Humanic::Humanic(World* wrld,int x,int y,int newType, int newStrength, int newHit, string name)
:Robot(wrld,x,y,newType,newStrength,newHit,name){

}
// Implementation of constructor with parameters for Humanic class
Humanic::Humanic(World* wrld,int x,int y)
:Robot(wrld,x,y){

}

// Implementation of getDamage() function for Humanic class
int Humanic::getDamage(){
    int damage;
    damage = (rand() % Strength) + 1;   
    if((rand()%10)==0){
        damage+=50;     //NUKE ATTACK 
    }

    cout << getType() << " attacks for " <<
    damage << " points!" << endl;
    return damage;
}
// Implementation of getType() function for Humanic class
string Humanic::getType(){
    
    switch (Type){
    case 0: return "optimusprime";
    case 1: return "robocop";
    }
    return "unknown";
}
// Implementation of getStrength() function for Humanic class
int Humanic::getStrength(){
    return Strength;
}
// Implementation of getHitpoints() function for Humanic class
int Humanic::getHitpoints(){
    return Hitpoints;
}
// Implementation of getName() function for Humanic class
string Humanic::getName(){
    return Name;
}
// Implementation of setType() function for Humanic class
void Humanic::setType(int typ){
    Type=typ;
}
// Implementation of setStrength() function for Humanic class
void Humanic::setStrength(int str){
    Strength=str;
}
// Implementation of setHitpoints() function for Humanic class
void Humanic::setHitpoints(int hit){
    Hitpoints=hit;
}


