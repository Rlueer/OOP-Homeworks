#include "Bulldozer.h"

// Constructor 1: initializes Bulldozer object with default values
Bulldozer::Bulldozer():Robot(){
    Type=3;
    Strength=50;
    Hitpoints=200;
    Name="Bulldozer_"+ to_string(BulldozerCount);
    BulldozerCount++;
}
// Constructor 2: initializes Bulldozer object with specific values
Bulldozer::Bulldozer(World* wrld,int x,int y,int newType, int newStrength, int newHit, string name)
:Robot(wrld,x,y,newType=3,newStrength=50,newHit=200,name=("Bulldozer_"+ to_string(BulldozerCount))){
    BulldozerCount++; 
    //This constructor can be removed because the robot type is fixed.
}
// Constructor 3: initializes Bulldozer object with default values and assigns a location in the world
Bulldozer::Bulldozer(World* wrld,int x,int y)
:Robot(wrld,x,y){
    Type=3;
    Strength=50;
    Hitpoints=200;
    Name="Bulldozer_"+ to_string(BulldozerCount);
    BulldozerCount++;    //BU 2. constructor KALDIRILABİLİR ROBOTUN ÇEŞİDİ BELLİ ÇÜNKÜ
}
// Returns the type of the Bulldozer object as a string
string Bulldozer::getType(){
    return "bulldozer";
}
// Returns the strength of the Bulldozer object
int Bulldozer::getStrength(){
    return Strength;
}
// Returns the hitpoints of the Bulldozer object
int Bulldozer::getHitpoints(){
    return Hitpoints;
}

// Returns the name of the Bulldozer object as a string
string Bulldozer::getName(){
    return Name;
}

// Sets the type of the Bulldozer object
void Bulldozer::setType(int typ){
    Type=typ;
}

// Sets the strength of the Bulldozer object
void Bulldozer::setStrength(int str){
    Strength=str;
}

// Sets the hitpoints of the Bulldozer object
void Bulldozer::setHitpoints(int hit){
    Hitpoints=hit;
}
