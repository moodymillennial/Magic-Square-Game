#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;
 
int squareArray[3][3];
bool isMagic;
 
int main(){
    int dimension;
     
    cout << "Enter numbers into the magic square "
    << "and push enter when you're done.\n";
     
    string input;
     
    getline(cin, input);
     
    int TotalNumberCount = 0;
     
    // I'm assuming all user input is correct
    // Parsing user input is kind of a pain
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == ' ')
        {
            TotalNumberCount++;
        }
    }
     
    // Check if the user inputted enough values to form a square.
    switch (TotalNumberCount){
        case 0:
            dimension = 1;
            break;
        case 3:
            dimension = 2;
            break;
        case 8:
            dimension = 3;
            break;
        default:
            cout << "Not a square or too large" << endl;
            return 0;
    }
     
    // Store all the variables in SquareArray
    stringstream getInt(input);
    int thisNumber;
    for (int row = 0; row < dimension; row++)
    {
        for (int col = 0; col < dimension; col++)
        {
            getInt >> thisNumber;
            squareArray[row][col] = thisNumber;
        }
    }
}
 
bool isMagic
    {
        int firstSum = 0;
        for (int j = 0; j < dimension; j++)
        {
            firstSum += squareArray[0][j];
        }
        cout << "Row Check:\n";
        for (int i = 0; i < dimension; i++)
        {
            int sum = 0;
            for (int j = 0; j < dimension; j++)
            {
                sum += squareArray[i][j];
            }
            cout << "Row " << i << " sum: " << sum << endl;
            if (sum != firstSum)
            {
                isMagic = false;
            }
        }
         
        cout << "Column Check:\n";
        for (int i = 0; i < dimension; i++)
        {
            int sum = 0;
            for (int j = 0; j < dimension; j++)
            {
                sum += squareArray[j][i];
            }
            cout << "Column " << i << " sum: " << sum << endl;
            if (sum != firstSum)
            {
                isMagic = false;
            }
        }
         
         
        cout << "Diagonal Check:\n";
         
        cout << "Diagonal #0 sum: ";
        int Diag1Sum = 0;
        for (int i = 0; i < dimension; i++)
        {
            Diag1Sum += squareArray[i][i];
        }
        cout << Diag1Sum << endl;
         
        cout << "Diagonal #1 sum: ";
        int Diag2Sum = 0;
        for (int i = 0; i < dimension; i++)
        {
            Diag2Sum += squareArray[dimension - 1 - i][i];
        }
        cout << Diag2Sum << endl;
        if (Diag1Sum != firstSum || Diag2Sum != firstSum)
        {
            isMagic = false;
        }
         
    }
}
 
}
