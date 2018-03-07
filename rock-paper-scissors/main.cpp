//
//  main.cpp
//  c-plus-plus
//
//  Created by Mofizur Rahman on 2/16/18.
//  Copyright © 2018 Mofizur Rahman. All rights reserved.
//

//  whatever the fuck i want
//


//  insert, to utilize, to bring with, to make a part of
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;



//return type = string
//name = processChoice
//paremeter = int choice
string processChoice(int choice){
    if(choice == 0){
        return "Rock";
    } else if(choice == 1){
        return "Paper";
    } else if(choice == 2){
        return "Scissor";
    } else{
        return "never reach this";
    }
}
//[55(0), 91(1), 61(2), 1004(3)] 32bit*3 96 bit / 32 = 3

// will retrun the index of the largers element in the array
int mostChosen(int *arr){//(int[] arr)
    int max = -1;
    int index = -1;
    for(int i =0; i<sizeof(arr)/sizeof(arr[0]); i++){
        if(arr[i]>max){
            max = arr[i];
            index = i;
        }
    }
    return index;
}
//3 parts to a function

//1: return type
//2: name of the function
//3: parameters

//return_type function_name(parameters){}
int main() {
    // seed the random number generator with time 0 1970 jan 1
    srand((unsigned)time(0));
    
    // rock paper scissor
    // rock breaks scissor
    // scissor cuts paper
    // paper covers rock
    

    // computer will randomly choose something but wont tell you
    // you will make your choice ( either by 0,1,2 or we can do some cool stuff
    // read rock paper or scissor
    
    // we will check who won
    // then will tell the user either they won or they lost
    
    // rock = 0; paper = 1; scissor = 2
    // 0 -> 1%3; 1 -> 2%3; 2 -> 3%3; 0 -> 1; 1 -> 2 ; 2 -> 0
    
    
    // 1. continuous play ** -done
    // 2. betting mechanism
    // 3. what our winning ratio -done
    // 4. what is out most common choice -done
    // 5. what is computers most common choice -done
    // 6. what choice won the most games # -done
    // 7. what choice lost the most games # -done
    
    // variable that stores number of game player
    int gameCount = 0;
    // variable that stores number of game won
    int winCount = 0;
    // variable that stores number of game lost
    int loseCount = 0;
    // variable that stores number of game tied
    int tieCount = 0;
    
    
    // array that keeps track of each input chosen by computer
    int compChoices[3] = {0,0,0};//[0,0,0]
    // array that keeps track of each input chosen by user
    int userChoices[3] = {0,0,0};//[2,1,1]
    
    // array that keeps track of the winning choice of the current game
    int winningChoice[3] = {0,0,0};
    

    // loop that will run indefinetely (wont stop until we stop it)
    while(true){
        cout<<"Enter choice negative number (eg:-1, -2) to quit the game\n";
        
        // randomly select a choice for the user (either 0 , 1 or 2)
        int compMove = rand()%3; //0,1,2
        int choice;
        cout<<"Select a choice \n\t(0) for rock, \n\t(1) for paper, \n\t(2) for scissors : ";
        
        // take user input
        cin>> choice;
        
        // game ending condition
        if(choice < 0){
            break;
        }
        
        // if a choice is > 2 do nothing that roung bring back to beginning
        if(choice > 2){
            cout<<"Please keep your choices between 0,1 and 2"<<endl;
            continue;
        }
        
        // increment comp choice
        compChoices[compMove]++;
        // increment user choice
        userChoices[choice]++;
        
        // one game played
        gameCount++;
        
        if(choice == compMove){
            cout<<"Game Tied"<<endl;
            // one tie happened
            tieCount++;
        } else if((choice - compMove + 3) %3 == 1){
            cout<<"Player Wins"<<endl;
            // one winning happened
            winCount++;
            // we know one winning choice
            winningChoice[choice]++;
        } else{
            cout<<"Computer Wins"<<endl;
            //one loosing happened
            loseCount++;
            //we know one loosing choice
            // so we know the opposite has won
            winningChoice[compMove]++;
        }
        
        cout<<"======================"<<endl;
        
//        cout<<"Computer chose "<<processChoice(compMove)<<" User chose "<<processChoice(choice)<<endl;
    }
    
    
    // game is completed
    cout<<"game ended\n"<<endl;
    cout<<"Total games : "<<gameCount<<endl;

    
    if(gameCount>0){
        cout<<"Player won : "<<winCount<<endl;
        cout<<"Player lose : "<<loseCount<<endl;
        cout<<"Tied : "<<tieCount<<endl;
        cout<<"Win ratio : "<<(double)winCount/gameCount<<endl;
        for(int i = 0; i<3; i++){
            cout<<processChoice(i)<<" chosen : "<<compChoices[i]<<" by computer"<<
            " and "<<userChoices[i]<<" By the user"<<endl;
        }
        cout<<"Users most chose : "<< processChoice(mostChosen(userChoices))<<endl;
        cout<<"Computer most chose : "<< processChoice(mostChosen(compChoices))<<endl;
        
        if(winCount>0 || loseCount>0){
            cout<<"Most winning choice : "<< processChoice(mostChosen(winningChoice))<<endl;
            
            cout<<"Most loosing choice : " <<processChoice((mostChosen(winningChoice)-1+3)%3)<<endl;
        }
        //mostChosen(winningChoice)
        //3 -> 2, 1 -> 0, 2 -> 1
        // mobile application
    }

    return 0;
}


