#include "World.h"

World::World()
{
    int i,j;
    for(i=0;i<WORLDSIZE;i++){   // Initialize grid with NULL pointers
        for(j=0;j<WORLDSIZE;j++){
            grid[i][j]=NULL;
        }
    }
}
World::~World(){    // Destructor to deallocate memory of objects in the grid
    int i,j;
    for(i=0;i<WORLDSIZE;i++){
        for(j=0;j<WORLDSIZE;j++){
            if(grid[i][j]!=NULL) delete (grid[i][j]);   // Check for non-null pointers and delete objects
        }
    }
}
Robot* World::getAt(int x,int y){   // Get the Robot object at the given (x,y) position
    if((x>=0) && (x<WORLDSIZE) && (y>=0) && (y<WORLDSIZE))
        return grid[x][y];  // Return the Robot object at the (x,y) position
    return NULL;
}
void World::setAt(int x ,int y,Robot* org){ // Set the Robot object at the given (x,y) position
    if((x>=0) && (x<WORLDSIZE) && (y>=0) && (y<WORLDSIZE))  // Check if given (x,y) position is within the grid bounds
        grid[x][y]=org;
}
void World::Display(){  // Display the current state of the grid
    int i,j;
    cout<<endl<<endl;
    for(j=0;j<WORLDSIZE;j++){
        for(i=0;i<WORLDSIZE;i++){
            if(grid[i][j]==NULL)    // If the (i,j) position has a NULL pointer, display a "."
                cout<<".";
            else if(grid[i][j]->getType()=="optimusprime")
                cout<<"O";
            else if(grid[i][j]->getType()=="robocop")
                cout<<"C";
            else if(grid[i][j]->getType()=="roomba")
                cout<<"R";
            else if(grid[i][j]->getType()=="bulldozer")
                cout<<"B";

        }
        cout<<endl;
    }
}

void World::SimulateOneStep(){  // Simulate one step of the game
    int i,j;
    for(i=0;i<WORLDSIZE;i++)
        for(j=0;j<WORLDSIZE;j++){
            if(grid[i][j]!=NULL) grid[i][j]->moved=false;
            if(grid[i][j]!=NULL) grid[i][j]->fighted=false;

        }
    // Move all Optimus Primes
    for(i=0;i<WORLDSIZE;i++){
        for(j=0;j<WORLDSIZE;j++){
            if((grid[i][j]!=NULL) && (grid[i][j]->getType()=="optimusprime"))
            {    
                if(grid[i][j]->moved==false){
                    grid[i][j]->moved=true;
                    grid[i][j]->move();
                }
            }
        }
    }
    // Move all Robocops
    for(i=0;i<WORLDSIZE;i++){
        for(j=0;j<WORLDSIZE;j++){
            if((grid[i][j]!=NULL) && (grid[i][j]->getType()=="robocop"))
            {
                if(grid[i][j]->moved==false){
                    grid[i][j]->moved=true;
                    grid[i][j]->move();
            
                }
            }   
        }
    }
    // Move all Roombas
    for(i=0;i<WORLDSIZE;i++){
        for(j=0;j<WORLDSIZE;j++){
            if((grid[i][j]!=NULL) && (grid[i][j]->getType()=="roomba"))
            {
                if(grid[i][j]->moved==false){
                    grid[i][j]->moved=true;
                    grid[i][j]->move();
                }
            }
        }
    }
    // Move all Bulldozers
    for(i=0;i<WORLDSIZE;i++){
        for(j=0;j<WORLDSIZE;j++){
            if((grid[i][j]!=NULL) && (grid[i][j]->getType()=="bulldozer"))
            {
                if(grid[i][j]->moved==false){
                    grid[i][j]->moved=true;
                    grid[i][j]->move();
                }
            }
        }
    }
     // Check if the game has ended
    int last=0;
    for(int i=0;i<WORLDSIZE;i++){   // HERE CHECKING FOR ARE THERE ONLY ONE
        for(int j=0;j<WORLDSIZE;j++){
            if(grid[i][j]!=NULL){
                last++;
            }
        }
    }
    if(last==1){
        cout<<"Game ended\n";
        exit(0);
    }

}
