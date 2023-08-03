//This code makes a game called Power 4 board game
//A win is to have an uninterrupted sequence of the same player symbol

#include <iostream>
#include "power4.h" //Find this header file in this repository  
using namespace std;


int main() {
    cout<<"POWER 4 BOARD GAME"<<endl;                                                       //
    cout<<"* Possible spots to play are marked by numbers  1 to 7 "<<endl;                  // **Introduction**
    cout<<"* This Game is played by two players."<<endl<<"Player '+' and Player 'O'"<<endl; //
    cout<<"Select a number to play or 'q' to quit the game"<<endl;                          //
    fill();                //The fill() function fills the empty grid with "_"(underscore) characters
    print();               // The print() function prints the grid to the console
    int round = 0;         //The round variable tracks the next player to play '+' or 'O'
    while(!end()) {        //The while loop will end if the grid is full (which is being tracked by end() function) or if one player wins
        char a;            //Variable 'a' takes the inputs
        char c;            //Variable 'c' takes the character of the player on each turn
        cout<<"It's the turn of player ";
        if(round%2 == 0) { //Player 'O' plays on even rounds
            c = 'O';
        }else {            //Player '+' plays on odd rounds
            c = '+';
        }
        cout<<"'"<<c<<"'"<<":"<<endl<<"> ";
        cin>>a;

        if(a == 'q' || a == 'q') {
            cout<<"Aborting the game...."<<endl;
            return 0;
        }

        if(play(a, c)) {   //We pass the input number and the playing character to the play function
            round--;       //If it returns true the input character must be false we then replay the round
        }
        print();            //Print the grid to see the progress
        if(checkVertical() || checkHorizontal() || checkRDiagonals() || checkLDiagonals()) { //check for wins in vertical, horizontal, and left&right diagonal directions 
            cout<<"Player '"<<c<<"' Wins!"<<endl; //A win is to have 4 resembling consecutive characters
            cout<<"The End"<<endl;
            return 0; //End the program if there is a win
        }
        round++; //If there is no win, play the next round.
    }
    cout<<"It's a draw"<<endl; //It ends with a draw if there is no win.
    cout<<"The End"<<endl;
    return 0; //
}
