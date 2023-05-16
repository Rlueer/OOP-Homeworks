#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>

#include "World.h"
#include "Robot.h"
#include "Humanic.h"
#include "Bulldozer.h"
#include "Optimusprime.h"
#include "Robocop.h"
#include "Roomba.h"

// Define initial robot counts
const int INITIALOPTIMUSPRIME = 5;
const int INITIALROBOCOP = 5;
const int INITIALROOMBA = 5;
const int INITIALBULLDOZER = 5;

// Forward declarations of classes used in the code 
class World;
class Robot;
class Humanic;
class Optimusprime;
class Robocop;
class Roomba;
class Bulldozer;

// Static variables to keep track of the number of instances of each robot type
int Optimusprime::OptimusprimeCount=0;
int Robocop::RobocopCount=0;  
int Roomba::RoombaCount=0;
int Bulldozer::BulldozerCount=0;


int main()
{
    string s;
    srand(time(NULL));
    World w;
    
    // Create initial instances of Optimusprime robots
    int optimusprime_count =0;
    while(optimusprime_count<INITIALOPTIMUSPRIME){
        int x = rand()% WORLDSIZE;
        int y = rand()% WORLDSIZE;
        if(w.getAt(x,y)==NULL){
            optimusprime_count++;
            Optimusprime* a1= new Optimusprime(&w,x,y);// Create a new Optimusprime robot instance at the given position
        }
    }
    // Create initial instances of Robocop robots
    int robocop_count =0;
    while(robocop_count<INITIALROBOCOP){
        int x = rand()% WORLDSIZE;
        int y = rand()% WORLDSIZE;
        if(w.getAt(x,y)==NULL){
            robocop_count++;
            Robocop* a2= new Robocop(&w,x,y);// Create a new Robocop robot instance at the given position
        }
    }
    // Create initial instances of Roomba robots
    int roomba_count =0;
    while(roomba_count<INITIALROOMBA){
        int x = rand()% WORLDSIZE;
        int y = rand()% WORLDSIZE;
        if(w.getAt(x,y)==NULL){
            roomba_count++;
            Roomba* a1= new Roomba(&w,x,y);// Create a new Roomba robot instance at the given position
        }
    }
    // Create initial instances of Bulldozer robots
    int bulldozer_count =0;
    while(bulldozer_count<INITIALBULLDOZER){
        int x = rand()% WORLDSIZE;
        int y = rand()% WORLDSIZE;
        if(w.getAt(x,y)==NULL){
            bulldozer_count++;
            Bulldozer* a2= new Bulldozer(&w,x,y);// Create a new Bulldozer robot instance at the given position
        }
    }

    // Main simulation loop
    while(true){
        //w.Display();    // Display the current state of the world
        w.SimulateOneStep();    // Simulate one step of the world
        cout<<endl<<"Press enter for next step"<<endl;
        getline(cin,s); // Wait for user input before continuing to the next step
    }


    return 0;
}