#include <iostream>
// lets user use input output operation
#include <vector>
// lets access to vector functionlities
#include <cstdlib>
// lets access system, rand
#include <ctime>
// lets access to time

using namespace std;
// standard c++ namespace (access to cout, cin, endl, vector)

// c++ function
// returntype functionname (parameters)

//function prototype
// below are the functions that will be defined later.

void clearMap(vector<vector<int> >&);
// function return type : void, name : clearMap,
// parameter : vector<vector<int> > (thats a vector of a vector)

void move(vector<vector<int> >&, const int&, const int&, const int&, const int&);
// return type : void, name : move,
// parameter: vector<vector<int> >, int, int, int, int (5 total)
void printMap(const vector<vector<int> >&, const bool&);
// return type : void, name : printMap,
//parameter: vector<vector<int> >, bool)


int main(){// code execution begins here
  srand(time(NULL));
  //seed the time with NULL to get a better random number generation
  //computer is not good at generation random number
  //this helps it make more unpredictable (not 100% random still)
  int grid;
  //size of grid
  cout<<"Welcome to the game of findme"<<endl;
  cout<<"What size grid do you want to play in : ";
  cin>>grid;//take user input


  vector<vector<int> > map(grid, vector<int> (grid));// create a 2d vector of width = grid and height = grid


  // set the player pos x to 0
  // set the player pos y to 0
  int playerPosX = 0;
  int playerPosY = 0;

  //randomly set the comp position away from player
  int computerPosX = rand()%(grid/2)+(grid/2);
  int computerPosY = rand()%(grid/2)+(grid/2);

  bool show = true;//if true computer postion will be shown

  map[playerPosX][playerPosY]=1;//set the value of user position in map to 1
  map[computerPosX][computerPosY]=3;//set the value of computer position to 3
  //1 and 3 are chosen in random. these are just flags to differentiate
  // by default the vectors value is 0
  // so i used that for empty state


  printMap(map, show);//before the game starts show the map with user and computer

  cout<<"The computer will try to hide in the grid of "<<grid<<"*"<<grid<<" tile"<<endl;

  int turns = 0;//before the game started number of turn is 0
  while(true){

    char choice;// player input
    cout<<"Enter q-quit a-left, d-right, w-up, s-down : ";//user manual
    cin>>choice;// enter choice
    if(choice == 'q')break;
    turns++;
    if(turns%5 == 0){
      show = true; // every five turn make computer visible
    }else{
      show = false; // if not keep the computer hidden
    }
    switch (choice) {// the user can choose one of 4 ways to move
      //based on their choice switch to different actions
      case 'a':
        playerPosY = (playerPosY + grid - 1)%grid;//move left with wrap around
        break;
      case 'd':
        playerPosY = (playerPosY + grid + 1)%grid;//move right with wrap around
        break;
      case 'w':
        playerPosX = (playerPosX + grid - 1)%grid;//move up with wrap around
        break;
      case 's':
        playerPosX = (playerPosX + grid + 1)%grid;//move down with wrap around
        break;
    }

    int compMove = rand()%4+1;// random number between 1-4

    switch (compMove) {//based on the random number move computer
      case 1:
        computerPosY = (computerPosY + grid - 1)%grid;
        break;
      case 2:
        computerPosY = (computerPosY + grid + 1)%grid;
        break;
      case 3:
        computerPosX = (computerPosX + grid - 1)%grid;
        break;
      case 4:
        computerPosX = (computerPosX + grid + 1)%grid;
        break;
    }

    move(map, playerPosX, playerPosY, computerPosX, computerPosY);
    //call move function to move player and computer

    if(playerPosX == computerPosX && playerPosY == computerPosY){
      clearMap(map);
      map[playerPosX][playerPosY] = 2;
      // 2 is flag chosen for computer found
      show = false;
      // dont show computer
      printMap(map, show);
      // print the end map
      cout<<"Your found me "<<endl;

      break;
      //game over
    }
    printMap(map, show);
  }

}

void clearMap(vector<vector<int> > &map){
  for(int i = 0; i<map.size(); i++){
    for(int j = 0; j<map[0].size(); j++){
      // traverse the 2d vectors
      // set each value to 0
      map[i][j]=0;
    }
  }
}

void move(vector<vector<int> > &map, int const &playerPosX, int const& playerPosY, int const &computerPosX, int const &computerPosY){
  clearMap(map);
  // clear the map first
  map[playerPosX][playerPosY]=1;
  // player pos to 1
  map[computerPosX][computerPosY]=3;
  // comp position to 3
}

void printMap(vector<vector<int> > const &map, bool const &show){
  system("clear");
  // clear the screen
  //basically push everything up
  // so it looks like cleared
  for(int i = 0; i<map.size(); i++){
    for(int j = 0; j<map[0].size(); j++){
      // if postion is 0 print -
      if(map[i][j]==0){
        cout<<"- ";// emplty locaiton
      }else if(map[i][j]==1){//player marker
        //if 1 then print x
        cout<<"x ";
      }else if(map[i][j] == 2){//capture marker
        //if 2 then print *
        cout<<"* ";
      }else{
        if(show){
          // if show print +
          cout<<"+ ";//computer marker
        }else{
          //else show like empty
          cout<<"- ";
        }
      }

    }
    cout<<endl;
  }
  cout<<endl;
}
