#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<limits>
using namespace std;

int loadbestscore(){
ifstream inFile("best_score.txt");
int bst=0;
if(inFile.is_open()){
inFile>>bst;
inFile.close();
}
return bst;
}

void updatebestscore(int att){
int currbest=loadbestscore();
if(currbest==0 || att<currbest){
ofstream outFile("best_score.txt");
if(outFile.is_open()){
outFile<<att;
outFile.close();
cout<<"New highest Score is: "<<att<<" attempts!"<<endl;
}
}
}

int playrnd(){
int low=1;
int up, difficulty;
cout<<"\nChoose your level of difficulty:"<<endl;
cout << "1) Easy   (1-30)" << endl;
cout << "2) Medium (1-100)" << endl;
cout << "3) Hard   (1-500)" << endl;
cout << "Enter your choice: ";
cin >> difficulty;
if(cin.fail()){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout<<"Invalid input entered....loading to medium level."<<endl;
    up=100;
}
if(difficulty==1){
    up=30;
}
else if(difficulty==2){
    up=100;
}
else if(difficulty==3){
    up=500;
}
else{
    cout<<"Invalid option selected....Directing you to medium level"<<endl;
    up=100;
}
int secnum=rand()%up+low;
int maxattempts=10;
int lastdist=-1; //to track warmer/colder

cout<<"\nThinking of a number that is in range of "<< low <<"  and  "<<up<<"!!"<<endl;
cout<<"You have "<<maxattempts<<" attempts left!!"<<endl;
int guess;
int attempts=0;
bool wonstats=false;
while(!wonstats && attempts<maxattempts){
    cout<<"\nAttempts:"<<(attempts+1)<<"/"<<maxattempts<<"\nEnter your guessing number:";
    cin>>guess;
    attempts++;
    if(cin.fail()){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout<<"Invalid input entered....Please enter a whole number."<<endl;
    attempts--;
    continue;
}
    if(guess<low || guess>up){
        cout<<"\nOops! your guess is out of range.Try again!!"<<endl;
        attempts--;
        continue;
    }
    int currdist=abs(secnum-guess);
    if(guess==secnum){
        cout<<"\nYou've correctly guessed the number!!You won in attempts:"<<attempts<<endl;
        wonstats=true;
    }
    else{
        if(guess<secnum){
            cout<<"Guess too low!!";
        }
        else{

                cout<<"Guess too high!!";
            }
            if(lastdist!=-1){
                if(currdist<lastdist){
                    cout<<"It is getting warmer!!"<<endl;
                }
                else{
                    cout<<"It is getting colder!!"<<endl;
                }

            }
            else{
                cout<<endl;
            }
            lastdist=currdist;
        }
    }

    if(!wonstats){
        cout<<"\nOops!! you're out of attempts. The secret number was:"<<secnum<<endl;
        return maxattempts+1;

    }
    return attempts;

}

int main(){
    srand(time(0));
    cout<<"\n~~~Welcome to Number Guessing Game~~~"<<endl;
    cout<<"Current best score :"<<loadbestscore()<<" attempts"<<endl;
    char playagain;
    do{
        int attempts=playrnd();
        updatebestscore(attempts);
        cout<<"\nYou want to play again?(y/n)"<<endl;
        cin>>playagain;

    }while(playagain=='y'||playagain=='Y');
    cout<<"\nThankyou<3"<<endl;
    return 0;

}

