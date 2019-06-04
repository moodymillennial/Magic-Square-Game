///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Joshua Stromberg
// Input: User enters 9 numbers, each separated by a space, then at the end if it's not magic Y or N
// Output: A text file with printed screen user sees, if the square is magic, a confirmation if the square
//         is magic or not, the input of the user placed in a square, and a confirmation of whether
//         the user entered a valid amount of numbers.
// Processes: Through a while loop, the process may repeat based on if it's magic or not, if it's magic
//            the loop doesn't repeat. Switch case determines if entry is valid myfileopen() function for
//            writing to text file.
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
 
 
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>
using namespace std;
 
const int MAX_SIZE = 3;
int magicSquare[MAX_SIZE][MAX_SIZE];
 
int main(){
    char tryAgain = 'Y';
    while (tryAgain == 'Y')
    {
        ofstream myfile;
         
        // ***********************************************************
        // ***********************************************************
        // here is where the text file gets opened and you should place where you want it!
         
        myfile.open("/Users/Josh/Desktop/magicSquare.txt");
    // int dimension measures the dimension of our square (3x3)
    int dimension;
    // bool will trigger whether the square is magic or not
    bool isMagic = true;
     
    cout << "Please enter the numbers 1-9 for the order of row 1, then row 2, etc. of the matrix." << endl;
         
    myfile << "Please enter the numbers 1-9 for the order of row 1, then row 2, etc. of the matrix." << endl;
     
         
    // get input and store as a variable
    string input;
     
    getline(cin, input);
         
        // record input by user in text file
     
    myfile << input << endl;
     
    int TotalNumberCount = 0;
     
    // sorting through user input to get rid of spaces
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == ' ')
        {
            TotalNumberCount++;
        }
    }
     
    // check if the user inputted enough values to form a square
    // for 3x3 square
    switch (TotalNumberCount)
    {
             
        case 8:
            dimension = 3;
            break;
             
        default:
            cout << "Not a square or too large" << endl;
            myfile << "Not a square or too large" << endl;
            return 0;
             
    }
     
    //store the input in the magic square array
    stringstream getInt(input);
    int thisNumber;
    for (int row = 0; row < dimension; row++)
    {
        for (int col = 0; col < dimension; col++)
        {
            getInt >> thisNumber;
            magicSquare[row][col] = thisNumber;
        }
    }
     
     
     
    // compare all resorts for first sum
    int firstSum = 0;
    for (int j = 0; j < dimension; j++)
    {
        firstSum += magicSquare[0][j];
    }
     
    // this is our RowSum() function
    for (int i = 0; i < dimension; i++)
    {
        int sum = 0;
        for (int j = 0; j < dimension; j++)
        {
            sum += magicSquare[i][j];
        }
        if (sum != firstSum)
        {
            isMagic = false;
        }
    }
     
    // this is our ColSum() function
    for (int i = 0; i < dimension; i++)
    {
        int sum = 0;
        for (int j = 0; j < dimension; j++)
        {
            sum += magicSquare[j][i];
        }
        if (sum != firstSum)
        {
            isMagic = false;
        }
    }
     
    // this is the DiagSum() function
    int Diag1Sum = 0;
    for (int i = 0; i < dimension; i++)
    {
        Diag1Sum += magicSquare[i][i];
    }
    int Diag2Sum = 0;
    for (int i = 0; i < dimension; i++)
    {
        Diag2Sum += magicSquare[dimension - 1 - i][i];
    }
    if (Diag1Sum != firstSum || Diag2Sum != firstSum)
    {
        isMagic = false;
    }
     
    // here is where our square will be displayed
    for (int row = 0; row < dimension; row++)
    {
        for (int col = 0; col < dimension; col++)
        {
            cout << magicSquare[row][col] << " ";
        }
        cout << endl;
    }
    // same loop for displaying the square but just to display it
        // in the text file
    for (int row = 0; row < dimension; row++)
    {
        for (int col = 0; col < dimension; col++)
        {
            myfile << magicSquare[row][col] << " ";
        }
        myfile << endl;
    }
     
        // if the square is magic, we record in text and display the following message
    if (isMagic)
    {
        cout << "Congratulations! The square you entered is magic." << endl;
        myfile << "Congratulations! The square you entered is magic." << endl;
        myfile.close();
        return 0;
    }
        // if the square isn't magic, give the user option to restart
        // and alert them that the square isnt magic
    else
    {
        cout << "Sorry, the square you entered is NOT magic." << endl;
        cout << "Try again? Y or N" << endl;
        myfile << "Sorry, the square you entered is NOT magic." << endl;
        myfile << "Try again? Y or N" << endl;
        cin  >> tryAgain;
        myfile << tryAgain;
        // if user doesn't want to restart program ends
        if (tryAgain == 'N')
        {
            myfile.close();
            break;
        }
        // if they want to restart this is where the program reloops
        else
        {
            getline(cin, input);
            continue;
        }
    }
    }
}
