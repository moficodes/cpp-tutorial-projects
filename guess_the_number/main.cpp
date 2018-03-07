#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    cout<<"Welcome to guess the number : "<<endl;
    int guess = rand()%1000+1;

    int choice = -1;

    int plays = 0;
    int point = 0;
    while(true){
        cout<<"What number am I thinking of : ";
        cin >> choice;
        plays++;

        if(choice > guess){
            cout<<"Lower"<<endl;
        }else if(choice < guess){
            cout<<"Higher"<<endl;
        }else {
            cout<<"Correct"<<endl;
            point = 10;
            break;
        }
        if(plays == 10){
            cout<<"You were too slow to guess"<<endl;
            break;
        }
    }

    point = point + (10-plays)*5;
    cout<<"Total Points : "<<point<<endl;
    cout<<"Thanks for playing"<<endl;
}