#include "Roomba.h"

Roomba::Roomba():Robot(){
    Type=2;
    Strength=3;
    Hitpoints=10;
    Name="Roomba_"+ to_string(RoombaCount);
    RoombaCount++;
}
Roomba::Roomba(World* wrld,int x,int y,int newType, int newStrength, int newHit, string name)
:Robot(wrld,x,y,newType=2,newStrength=3,newHit=10,name=("Roomba_"+ to_string(RoombaCount))){
    // Constructor that calls the Robot class constructor and sets default values for Roomba
    RoombaCount++; 
}
Roomba::Roomba(World* wrld,int x,int y)
:Robot(wrld,x,y){
    Type=2;
    Strength=3;
    Hitpoints=10;
    Name="Roomba_"+ to_string(RoombaCount);
    RoombaCount++;    
}

string Roomba::getType(){
    return "roomba";     // Returns the string "roomba"
}
// Return the damage value
int Roomba::getDamage(){
    int damage,damage2;
    damage = (rand() % Strength) + 1;   
    damage2= (rand() % Strength) + 1;   
    damage+=damage2;
    

    cout << getType() << " attacks for " << 
    damage << " points!" << endl;

    return damage;
}
int Roomba::getStrength(){
    return Strength;
}
int Roomba::getHitpoints(){
    return Hitpoints;
}
string Roomba::getName(){
    return Name;
}
void Roomba::setType(int typ){
    Type=typ;
}
void Roomba::setStrength(int str){
    Strength=str;
}
void Roomba::setHitpoints(int hit){
    Hitpoints=hit;
}


