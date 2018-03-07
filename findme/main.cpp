#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
//random comment

using namespace std;

void clearMap(vector<vector<int> >&);
void move(vector<vector<int> >&, const int&, const int&, const int&, const int&);
void printMap(const vector<vector<int> >&, const bool&);


int main(){
  srand(time(NULL));
  int grid;
  cout<<"Welcome to the game of findme"<<endl;
  cout<<"What size grid do you want to play in : ";
  cin>>grid;


  vector<vector<int> > map(grid, vector<int> (grid));

  int playerPosX = 0;
  int playerPosY = 0;

  int computerPosX = rand()%(grid/2)+(grid/2);
  int computerPosY = rand()%(grid/2)+(grid/2);

  bool show = true;

  map[playerPosX][playerPosY]=1;
  map[computerPosX][computerPosY]=3;
  printMap(map, show);

  cout<<"The computer will try to hide in the grid of "<<grid<<"*"<<grid<<" tile"<<endl;

  int turns = 0;
  while(true){

    char choice;
    cout<<"Enter q-quit a-left, d-right, w-up, s-down : ";
    cin>>choice;
    if(choice == 'q')break;
    turns++;
    if(turns%5 == 0){
      show = true;
    }else{
      show = false;
    }
    switch (choice) {
      case 'a':
        playerPosY = (playerPosY + grid - 1)%grid;
        break;
      case 'd':
        playerPosY = (playerPosY + grid + 1)%grid;
        break;
      case 'w':
        playerPosX = (playerPosX + grid - 1)%grid;
        break;
      case 's':
        playerPosX = (playerPosX + grid + 1)%grid;
        break;
    }

    int compMove = rand()%4+1;

    switch (compMove) {
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

    if(playerPosX == computerPosX && playerPosY == computerPosY){
      clearMap(map);
      map[playerPosX][playerPosY] = 2;
      show = false;
      printMap(map, show);
      cout<<"Your found me "<<endl;
      break;
    }
    printMap(map, show);
  }

}

void clearMap(vector<vector<int> > &map){
  for(int i = 0; i<map.size(); i++){
    for(int j = 0; j<map[0].size(); j++){
      map[i][j]=0;
    }
  }
}

void move(vector<vector<int> > &map, int const &playerPosX, int const& playerPosY, int const &computerPosX, int const &computerPosY){
  clearMap(map);
  map[playerPosX][playerPosY]=1;
  map[computerPosX][computerPosY]=3;
}

void printMap(vector<vector<int> > const &map, bool const &show){
  system("clear");
  for(int i = 0; i<map.size(); i++){
    for(int j = 0; j<map[0].size(); j++){
      if(map[i][j]==0){
        cout<<"- ";// emplty locaitons
      }else if(map[i][j]==1){//player marker
        cout<<"x ";
      }else if(map[i][j] == 2){//capture marker
        cout<<"* ";
      }else{
        if(show){
          cout<<"+ ";//computer marker
        }else{
          cout<<"- ";
        }
      }

    }
    cout<<endl;
  }
  cout<<endl;
}
