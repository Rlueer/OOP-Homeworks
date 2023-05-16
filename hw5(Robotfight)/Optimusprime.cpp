#include "Optimusprime.h"


// Default constructor for Optimusprime class
Optimusprime::Optimusprime():Humanic(){
    Type=0;
    Strength=100;
    Hitpoints=100;
    Name="Optimusprime_"+ to_string(OptimusprimeCount);
    OptimusprimeCount++;
}
// Constructor with parameters for Optimusprime class
Optimusprime::Optimusprime(World* wrld,int x,int y,int newType, int newStrength, int newHit, string name)
:Humanic(wrld,x,y,newType=0,newStrength=100,newHit=100,name=("Optimusprime_"+ to_string(OptimusprimeCount))){
    OptimusprimeCount++;   
}
// Constructor with parameters for Optimusprime class
Optimusprime::Optimusprime(World* wrld,int x,int y)
:Humanic(wrld,x,y){
    Type=0;
    Strength=100;
    Hitpoints=100;
    Name="Optimusprime_"+ to_string(OptimusprimeCount);
    OptimusprimeCount++;    
}
// Returns the type of the robot as a string
string Optimusprime::getType(){
    return "optimusprime";
}
// Calculates the damage of the robot and returns it as an integer
int Optimusprime::getDamage(){
    int damage;
    damage = (rand() % Strength) + 1;
    if((rand()%10)==0){
        damage+=50;     //NUKE ATTACK 
    }  
    if((rand()%100)<15){
        damage*=2;  //STRONG ATTACK
    }

    cout << getType() << " attacks for " <<
    damage << " points!" << endl;
    return damage;
}
// Returns the strength of the robot as an integer
int Optimusprime::getStrength(){
    return Strength;
}
// Returns the hit points of the robot as an integer
int Optimusprime::getHitpoints(){
    return Hitpoints;
}
// Returns the name of the robot as a string
string Optimusprime::getName(){
    return Name;
}
// Sets the type of the robot to the given integer value
void Optimusprime::setType(int typ){
    Type=typ;
}
// Sets the strength of the robot to the given integer value
void Optimusprime::setStrength(int str){
    Strength=str;
}
// Sets the hit points of the robot to the given integer value
void Optimusprime::setHitpoints(int hit){
    Hitpoints=hit;
}


