#include "Robocop.h"

// Default constructor for Robocop class
Robocop::Robocop():Humanic(){
    Type=1;
    Strength=30;
    Hitpoints=40;
    Name="Robocop_"+ to_string(RobocopCount);
    RobocopCount++;
}
// Constructor with parameters for Robocop class
Robocop::Robocop(World* wrld,int x,int y,int newType, int newStrength, int newHit, string name)
:Humanic(wrld,x,y,newType=1,newStrength=30,newHit=40,name=("Robocop_"+ to_string(RobocopCount))){
    RobocopCount++; 
}
// Constructor with parameters for Robocop class
Robocop::Robocop(World* wrld,int x,int y)
:Humanic(wrld,x,y){
    Type=1;
    Strength=30;
    Hitpoints=40;
    Name="Robocop_"+ to_string(RobocopCount);
    RobocopCount++;    
}
// Returns the type of the robot as a string
string Robocop::getType(){
    return "robocop";
}

// Returns the strength of the robot as an integer
int Robocop::getStrength(){
    return Strength;
}
// Returns the hit points of the robot as an integer
int Robocop::getHitpoints(){
    return Hitpoints;
}
// Returns the name of the robot as a string
string Robocop::getName(){
    return Name;
}
// Sets the type of the robot to the given integer value
void Robocop::setType(int typ){
    Type=typ;
}
// Sets the strength of the robot to the given integer value
void Robocop::setStrength(int str){
    Strength=str;
}
// Sets the hit points of the robot to the given integer value
void Robocop::setHitpoints(int hit){
    Hitpoints=hit;
}

