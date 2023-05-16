#include "Robot.h"

Robot::Robot(){
    // Default constructor initializes all member variables to default values
    Name="none";
    Type=-1;
    Strength=0;
    Hitpoints=0;
    world=NULL;
    x=0;
    y=0;
    moved=false;
    fighted=false;
    a=0;
    b=0;
}
Robot::Robot(World* wrld,int x,int y,int newType, int newStrength, int newHit, string name){
    // Constructor to create a robot with given properties and place it in the world at given coordinates
    // Sets member variables to given values and sets the robot in the world grid

    this->Type=newType;
    this->Strength=newStrength;
    this->Hitpoints=newHit;
    this->Name=name;

    this->world=wrld;
    this->x=x;
    this->y=y;
    moved=false;
    fighted=false;
    a=0;
    b=0;
    wrld->setAt(x,y,this);
    

}
Robot::Robot(World* wrld,int x,int y){
     // Constructor to create a robot and place it in the world at given coordinates
    // Sets member variables to default values and sets the robot in the world grid
    this->world=wrld;
    this->x=x;
    this->y=y;
    moved=false;
    fighted=false;
    a=0;
    b=0;
    wrld->setAt(x,y,this);
    
}
Robot::~Robot(){}// Destructor to clean up memory of the object

int Robot::getDamage(){
    // Function to calculate damage done by the robot in an attack
    // Returns a random value between 1 and the robot's strength value
    int damage;
    damage = (rand() % Strength) + 1;
    cout << getType() << " attacks for " <<
    damage << " points!" << endl;
    return damage;
}

string Robot::getType(){
    // Function to return the name of the robot type based on the type number
    // Returns a string value of the robot type name
    
    switch (Type){
    case 0: return "optimusprime";
    case 1: return "robocop";
    case 2: return "roomba";
    case 3: return "bulldozer";
    }
    return "unknown";
}

int Robot::getStrength(){   // Returns an integer value of the robot strength
    return Strength;
}
int Robot::getHitpoints(){  // Returns an integer value of the robot hitpoints  
    return Hitpoints;
}
string Robot::getName(){    // Returns a string value of the robot name
    return Name;
}
void Robot::setType(int typ){   // Sets the type value to the given integer value
    Type=typ;
}
void Robot::setStrength(int str){   // Sets the strength value to the given integer value
    Strength=str;   
}
void Robot::setHitpoints(int hit){  // Sets the hitpoints value to the given integer value
    Hitpoints=hit;
}
// Function to print a message describing a hit by the attacker robot on the victim robot
    // Takes in references to the attacker and victim robots,
void Robot::hit_message(Robot& attacker,Robot& victim,int damage,int new_hitpoint){
    cout<< attacker.getName()<<"("<<attacker.getHitpoints()<<") hits "<<
    victim.getName()<<"("<<victim.getHitpoints()<<") with "<<damage<<"\n";

    cout<< "The new hitpoints of "<<victim.getName()<<" is "<<new_hitpoint<<"\n";

}

int Robot::fight_loop(Robot& attacker,Robot& victim){

while(1){    // loop indefinitely until one of the robots is dead
    // Attacker calculates and inflicts damage to the victim
    int d_r = attacker.getDamage();
    int v_newh=victim.getHitpoints()-d_r;
    if(v_newh<=0)v_newh=0;
    hit_message(attacker,victim,d_r,v_newh);   //print hit_message(see hit_message for details)
    victim.setHitpoints(v_newh);
    // Check if the victim is still alive
    if(victim.getHitpoints()<=0){
        cout<<victim.getName()<<" is dead\n";
        attacker.fighted=true;
        victim.fighted=true;
        return 1;   // if return 1 victim is dead 
    }
    // Victim calculates and inflicts damage to the attacker
    int d_s = victim.getDamage();
    int a_newh=attacker.getHitpoints()-d_s;
    if(a_newh<=0)a_newh=0;
    hit_message(victim,attacker,d_s,a_newh);    //print hit_message(see hit_message for details)
    attacker.setHitpoints(a_newh);

    // Check if the attacker is still alive
    if(attacker.getHitpoints()<=0){
        cout<<attacker.getName()<<" is dead\n";
        attacker.fighted=true;
        victim.fighted=true;
        return 0;   // if return 0 attacker is dead 
    }

}
}
void Robot::move(){

    while(fighted==false){

    int dir= rand()%4;  // Randomly select a direction (0 = up, 1 = right, 2 = down, 3 = left)

    if(dir==0){ // If the selected direction is up
        if((y>0)&& (world->getAt(x,y-1)==NULL)){        // If the cell above is empty and within bounds
        // Move the robot to the cell above
            world->setAt(x,y-1,world->getAt(x,y));
            world->setAt(x,y,NULL);
            y--;
        }
        else if((y>0)&& (world->getAt(x,y-1)!=NULL)){       // If the cell above is not empty and within bounds
            int a=fight_loop(*world->getAt(x,y),*world->getAt(x,y-1));  // Call the fight_loop function to start a fight
            if(a==1){   //victim dead
                // Delete the victim and move the robot to the cell above
                delete(world->grid[x][y-1]);
                world->setAt(x,y-1,world->getAt(x,y));
                world->setAt(x,y,NULL);
                y--;    
                fighted=true;    // Set the fighted flag to true to indicate that a fight occurred
                return ;  // Return  to indicate that the robot has moved and a fight has occurred
            }
            else if(a==0){//attacker dead
                delete(world->grid[x][y]);
                world->setAt(x,y,NULL);
                fighted=true;   // Set the fighted flag to true to indicate that a fight occurred
                return ;  // Return  to indicate that the robot has moved and a fight has occurred
        
            }
        }   
    }
    else if(dir==1){
        if((y<WORLDSIZE-1)&& (world->getAt(x,y+1))==NULL){ // If the cell above is empty and within bounds
        // Move the robot to the cell above
            world->setAt(x,y+1,world->getAt(x,y));
            world->setAt(x,y,NULL);
            y++;
        }
        else if((y<WORLDSIZE-1)&& (world->getAt(x,y+1))!=NULL){  
            int a=fight_loop(*world->getAt(x,y),*world->getAt(x,y+1));
            if(a==1){//victim dead
                // Delete the victim and move the robot to the cell above
                delete(world->grid[x][y+1]);
                world->setAt(x,y+1,world->getAt(x,y));
                world->setAt(x,y,NULL);
                y++;
                fighted=true;   // Set the fighted flag to true to indicate that a fight occurred
                return ;    // Return  to indicate that the robot has moved and a fight has occurred
            }
            else if(a==0){//attacker dead
                delete(world->grid[x][y]);
                world->setAt(x,y,NULL);
                fighted=true;   // Set the fighted flag to true to indicate that a fight occurred
                return ;    // Return  to indicate that the robot has moved and a fight has occurred
            }
        }  
    }
    else if(dir==2){
        if((x>0) && (world->getAt(x-1,y)==NULL)){   // If the cell above is empty and within bounds
        // Move the robot to the cell above
            world->setAt(x-1,y,world->getAt(x,y));
            world->setAt(x,y,NULL);
            x--;
        }
        else if((x>0) && (world->getAt(x-1,y)!=NULL)){  
            int a=fight_loop(*world->getAt(x,y),*world->getAt(x-1,y));
            if(a==1){//victim dead
                // Delete the victim and move the robot to the cell above
                delete(world->grid[x-1][y]);
                world->setAt(x-1,y,world->getAt(x,y));
                world->setAt(x,y,NULL);
                x--;
                fighted=true;   // Set the fighted flag to true to indicate that a fight occurred
                return ;    // Return  to indicate that the robot has moved and a fight has occurred
            }
            else if(a==0){//attacker dead
                delete(world->grid[x][y]);
                world->setAt(x,y,NULL);
                fighted=true;
                return ;    // Return  to indicate that the robot has moved and a fight has occurred
            }
        }  
    }
    else if(dir==3){
        if((x<WORLDSIZE-1)&& (world->getAt(x+1,y)==NULL)){ // If the cell above is empty and within bounds
        // Move the robot to the cell above
            world->setAt(x+1,y,world->getAt(x,y));
            world->setAt(x,y,NULL);
            x++;
        }
        else if((x<WORLDSIZE-1)&& (world->getAt(x+1,y)!=NULL)){   
            int a=fight_loop(*world->getAt(x,y),*world->getAt(x+1,y));
            if(a==1){//victim dead
                // Delete the victim and move the robot to the cell above
                delete(world->grid[x+1][y]);
                world->setAt(x+1,y,world->getAt(x,y));
                world->setAt(x,y,NULL);
                x++;
                fighted=true;   // Set the fighted flag to true to indicate that a fight occurred
                return ;    // Return  to indicate that the robot has moved and a fight has occurred
            }
            else if(a==0){//attacker dead
                delete(world->grid[x][y]);
                world->setAt(x,y,NULL);
                fighted=true;   // Set the fighted flag to true to indicate that a fight occurred
                return ;    // Return  to indicate that the robot has moved and a fight has occurred
            }
        }  
    }


    }
}
