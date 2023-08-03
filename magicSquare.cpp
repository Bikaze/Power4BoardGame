//A C++ program to check if a matrix is a Magic Square or not.

#include <iostream>
#include <vector>
using namespace std;

bool isMagicSquare(std::vector<std::vector<int>>& matrix){
    int n = matrix.size();

    //Calculate the sum of the first row (targetSum).
    int targetSum = 0;
    for(int j = 0; j < n; j++){
        targetSum += matrix[0][j];
    }

    //Calculate the sum of other rows.
    for(int i = 1; i < n; i++){
        int rowSum = 0;
      for(int j = 0; j < n; j++){
        rowSum += matrix[i][j];
      }
      if (rowSum != targetSum){
            return false;
      }
    }

    //Calculate the sum of columns.
    for(int j = 0; j < n; j++){
        int colSum = 0;
        for(int i = 0; i < n; i++){
            colSum += matrix[i][j];
        }
        if (colSum != targetSum){
            return false;
        }
    }

    //Calculate the sum of the main diagonal.
    int mainDiaSum = 0;
    for(int i = 0; i < n; i++){
        mainDiaSum += matrix[i][i];
        }
    if (mainDiaSum != targetSum){
        return false;
        }

    //Calculate the sum of the second diagonal.
    int secDiaSum = 0;
    for(int i = 0; i < n; i++){
        secDiaSum += matrix[i][n - i - 1];
        }
    if (secDiaSum != targetSum){
        return false;
        }
    return true;
}

int main(){

    //Ask user to enter the size of the matrix.
    int n;
    cout<<"Enter the size of the matrix (n x n):" ;
    cin>>n;

    //Create the vector and add its elements.
    vector<vector<int>> matrix(n, vector<int>(n));

    cout<<"Enter the elements of the vector: "<<endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>matrix[i][j];
        }
    }

    //Check if the entered matrix is a magic square.
    if(isMagicSquare(matrix)){
        cout<<"The matrix is a Magic Square!"<<endl;
        }
    else {
        cout<<"The matrix is not a Magic Square."<<endl;
        }

    return 0;
}
