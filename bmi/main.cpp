#include <iostream>
using namespace std;

int main()
{

  double height;
  double weight;
  double bmi;
  double feet;
  double inches;

  while(true){
    cout<<"BMI CALCULATOR\n=================================\n";
    cout<<"yout weight(lb) : ";
    cin>> weight ;
    cout<<"-----------------------------------\n";

    cout<<"Your height : "<<endl;
    cout<<"feet : ";
    cin>>feet;
    cout<<"inches : ";
    cin>>inches;

    height=(feet*12)+inches;

    if (height == 0) {
      cout <<"Height is 0. Please enter valid height.\n\n";
      continue;
    }

    if (weight == 0) {
      cout <<"Weight is 0. Please enter valid weight.\n\n";
      continue;
    }

    bmi=(weight*703)/(height*height);
    cout << "Your bmi : " << bmi<<endl;


    if(bmi<18.5){
      cout<<"Underweight BMI."<<endl;
    } else if(bmi < 25){
      cout<<"Normal BMI";
    } else if (bmi < 30){
      cout<<"Overweight BMI."<<endl;
    } else {
      cout<<"Obese BMI."<<endl;
    }
    
    cin.ignore();
    string choice;
    cout<<endl<<"Would you like to see another BMI : (y/n) : ";
    getline(cin, choice);
    if(choice[0] == 'N' ||choice[0] == 'n'){

      break;
    } else {
      cout<<"Choice is not No. Running again ...\n\n";
    }
  }
  //system(pause);
  return 0;


}
