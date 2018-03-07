#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<string> readFile(string fileName){
    string line;
    ifstream myfile (fileName);
    vector<string> lines;
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            lines.push_back(line);
        }
        myfile.close();
    }

    else cout << "Unable to open file";

    return lines;
}

void printList(vector<string> list){
    for(int i = 0; i<list.size(); i++){
        cout<<i<<" : "<<list[i]<<endl;
    }
}

void printVector(vector<char> word){
    for(int i = 0; i<word.size(); i++){
        cout<<word[i]<<" ";
    }
    cout<<endl;
}

bool isComplete(vector<char> word){//['m', 'a', 'l', 'e']
    for(int i = 0; i<word.size(); i++){
        if(word[i]=='-'){
            return false;
        }
    }
    return true;
}

void hangman(vector<string> words){
    int size = words.size();
    int guess = rand()%size;
    string word = words[guess];
//    cout<<"Word is : "<<word<<endl;

    vector<char> hiddenWord;

    for(int i = 0; i<word.length();i++){
        hiddenWord.push_back('-');
    }

    int mistake = 0;
    int totalChances = 8;

    bool usedAlphabet[26] = {false};//[false,false,....,false]

    while(true){
        printVector(hiddenWord);

        char letter;

        cout<<"Guess a letter : ";
        cin >> letter;



        if(usedAlphabet[letter-'a']){
            cout<<"Already guessed "<<letter<<" Please guess something else"<<endl;
            continue;
        }
        //users guess of a-z
        //i want to convert to 0-25
        //user guess a-a = 0
        //user guess z-a = 25
        usedAlphabet[letter-'a']=true;



        bool found = false;
        for(int i = 0; i<word.length(); i++){
            if(word[i]==letter){
                hiddenWord[i]=letter;
                found = true;
            }
        }

        if(!found){
            mistake++;
            cout<<"You have "<<totalChances-mistake<<" lives left"<<endl;
        }
        if(totalChances-mistake == 0){
            cout<<"You have used up all you chances"<<endl;
            cout<<"The correct word was : "<<word<<endl;
            break;
        }

        if(isComplete(hiddenWord)){
            cout<<"Congrats you got it"<<endl;
            cout<<word<<endl;
            break;
        }
    }
}

int main() {
    srand(time(0));
    string fileName = "resources/words.txt";

    vector<string> words = readFile(fileName);

    cout<<"Welcome to hangman "<<endl<<endl;

    while(true){
        hangman(words);
        char choice;
        cout<<"Do you want to continue (y/n) : ";
        cin>>choice;
        if(choice == 'n'){
            break;
        }
        cout<<"====================================="<<endl<<endl;
    }


    return 0;
}
