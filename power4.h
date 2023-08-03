#include <iostream>
using namespace std;
#ifndef _h
#define _h


int base[] = {5, 5, 5, 5, 5, 5, 5};           //This array will track how the grid is filling up 5 means bottom row 0 mean top row
char array[6][7];                             //This is the grid or board of the game

void fill() {                                 //This function fills the array grid with "_"(underscore characters)
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 7; j++) {
            if(i == 5) {
                
                array[i][j] = (char)(49+j);
            }else {
                array[i][j] = '_';
            }
        }
    }
}

bool end() {                                    //This function(end()) checks whether the grid if full by adding the elements of base.
    int k = 0;
    for(auto i : base) {
        k += i;
    }
    if(k == -7) {                               //If the elements of sum up to -7 there is no spot left to play and the function returns true to end the game...
        return true;
    }else {
        return false;                           //otherwise it continues
    }
}

bool play(char b, char c) {                     //This function receives the input number and the character of the player who entered it.
    int a = b - '0';                            //This line transforms the input 'b' character into a number(integer)
    a--;
    if(base[a] >= 0 && a < 7 && a >= 0) {       //If the following conditions are met....
        if(base[a] > 0) {
            array[base[a]-1][a] = array[base[a]][a];   //The displayed number will move to the upper row 
        }
        array[base[a]][a] = c;                         //We put the player character ('+' or 'O') in the previous place of the displayed number
        base[a]--;
        return false;
    }else {
        cout<<"Invalid input"<<endl;                   //We will return 'true' only if the input is not valid in order to replay the round
        return true;
    }
}

void print() {                                          //This function will print the game board to the console.
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 7; j++) {
            cout<<array[i][j]<<"    ";
        }
        cout<<endl;
    }
}

int countV(int row, int col, char c) {                  //This function will move to every valid box in every colum(vertically!)
    int k = 0;
    while(array[row][col] == c) {
        k++;
        row--;
    }
    return k;
}

int countH(int row, int col, char c) {                  //This function will move to every valid box in every row(Horizontally!)
    int k = 0;
    while(array[row][col] == c) {
        k++;
        col++;
    }
    return k;
}

int counterR(int row, int col, char c) {                //This function will move to every valid box in every every valid diagonal(from left to right!)
    int k = 0;
    while(row > -1 && col < 7 && array[row][col] == c) {
        k++;
        row--;
        col++;
    }
    if(k == 4) {
        return true;
    }else {
        return false;
    }
}

int counterL(int row, int col, char c) {                 //This function will move to every valid box in every every valid diagonal(from right to left!)
    int k = 0;
    while(row > -1 && col < 7 && array[row][col] == c) {
        k++;
        row--;
        col--;
    }
    if(k == 4) {
        return true;
    }else {
        return false;
    }
}

bool checkRDiagonal(int col) {                          //This function will analyze each left to right diagonal for every possible winning instance
    int row = 5;
    for(int i = 0; i < 3; i++) {
        if(array[row][col] == '+' || array[row][col] == 'O') {
            if(counterR(row, col, array[row][col])) {
                return true;
            }
        }
        row--;
        col++;
    }
    return false;
}

bool checkLDiagonal(int col) {                          //This function will analyze each right to left diagonal for every possible winning instance
    int row = 5;
    for(int i = 0; i < 3; i++) {
        if(array[row][col] == '+' || array[row][col] == 'O') {
            if(counterL(row, col, array[row][col])) {
                return true;
            }
        }
        row--;
        col--;
    }
    return false;
}

bool checkRDiagonals() {                        //This function will check for wins in left to right diagonals
    for(int i = 0; i < 4; i++) {
        int row = 5;
        int col = i;
        if(checkRDiagonal(col)) {
            return true;
        }
    }
    return false;
}

bool checkLDiagonals() {                        //This function will check for wins in right to left diagonals
    for(int i = 6; i >= 3; i--) {
        int row = 5;
        int col = i;
        if(checkLDiagonal(col)) {
            return true;
        }
    }
    return false;
}

bool checkVertical() {                      //This function will check for wins in columns of the grid
    for(int i = 0; i < 7; i++) {
        for(int j = 5; j >= 0; j--) {
            if(array[j][i] == '+' || array[j][i] == 'O') {
                int ans1 = countV(j, i, array[j][i]);
                if(ans1 == 4) {
                    return true;
                }
            }else {
                break;
            }
        }
    }
    return false;
}

bool checkHorizontal() {                    //This function will check for wins in rows of the grid
    for(int i = 5; i >= 0; i--) {
        for(int j = 0; j < 7; j++) {
            if(array[i][j] == '+' || array[i][j] == 'O') {
                int ans1 = countH(i, j, array[i][j]);
                if(ans1 == 4) {
                    return true;
                }
            }
        }
    }
    return false;
}



#endif
