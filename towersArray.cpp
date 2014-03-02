/***************************************
 **Program: towersArray.cpp
 **Author: Lucy Wyman
 **Date: March 1, 2014
 **Description: Simple recursive Towers of Hanoi solution in which user inputs number of disks to be used, and the board is printed after each move.
 **Input: Number of disks
 **Output: Step by step solution to the puzzle for that number of disks.
 ******************************************/

#include<iostream>
#include<cmath>
#include<cstdlib>

using namespace std;

/***************************************
 **Function: buildBoard
 **Description: Initialize the game "board" for given number of disks--this happens in the form of a 2D-array where each disk number is in it's place, and the rest of the "spots" on the board are populated with 0s.  Consider each column to be a peg.  
 **Parameters: Dynamic array which represents the board, number of rows
 **Pre-conditions: User must have input valid int, and board must have initialized correctly.
 **Post-conditions: Board must contain one column of ints 1-x, where x is the number of rows, and be populated elsewhere by 0s.
 *****************************************/
void buildBoard(int array[][3], int rows);

/**************************************
 **Function: printArray
 **Description: Prints the current state of the board to the terminal so that user can follow solution step-by-step and visualize what's happening.
 **Parameters: Dynamic array which represents the board, number of rows.
 **Pre-conditions: Board must have been initialized correctly, and caller function must have run properly.
 **Post-conditions: 
 ***************************************/
void printArray(int array[][3], int rows);

/***************************************
 **Function: moveDisk
 **Description: Move "disk" (in form of an int representing the disk) from a to b within 2D array.
 **Parameters: Which disk is being moved, the 2D array representing the board, the column the disk is in (a), the column the disk is going to (b), the column which is not being used, and the number of rows.
 ***************************************/
void moveDisk(int disk, int b[][3], int from_column, int to_column, int rows);
/****************************************
 **Function: towers
 **Description: The meat of the program!  Calls move disk and print board functions recursively. 
 **Parameters: Which disk is being moved, board, from column, to column, spare column, and number of rows
 *****************************************/
void towers(int disks, int b[][3], int from_column, int spare, int to_column, int rows);

/****************************************
 **Function: checkInput
 **Description: Make sure user input is positive integer, and throw error if it's not.
 **Parameters: User input.
 **Pre-conditions: User must have input something.
 **Post-conditions: User must have input the input correct.
 ******************************************/
void checkInput(){
    cin.clear();
    cin.ignore(1000, '\n');
    cout<<"\033[1;31mSorry! You did not input a positive integer less than 100.  Please try again!\033[0m\n";
}

int main(){
    string run = "yes";
    int input = 1;
    int x;
    int rows;
    while (input == 1){
    while (run == "Yes" || run == "yes" || run == "Y" || run == "y"){
	cout<<"Please enter the number of disks: "<<endl;
	cin>>x;
	if (cin.fail() || x>100 || x<0){
		checkInput();
		break;
	}
	rows = x;
	int board[x][3];
	buildBoard(board, rows);
	printArray(board, rows);
	towers(x, board, 0, 1, 2, rows);
	cout<<"Would you like to play again?"<<endl;
	cin>>run;
    }
    if (run != "Yes" && run !="yes"){
    	break;
    }
    }
    return 0;
}

void buildBoard(int array[][3], int rows){
    for (int x = 0; x<rows; x++){
	array[x][0] = x+1;
	for (int y = 1; y<3; y++){
	    array[x][y] = 0;
	}
    } 
}
void printArray(int array[][3], int rows){
    for (int x = 0; x<rows; x++){
	for (int y = 0; y<3; y++){
	    cout<<array[x][y];
	}
	cout<<endl;
    }
    cout<<"-----------------------"<<endl;
} 

void moveDisk(int disk, int b[][3], int from_column, int to_column, int rows){
    int lowest;
    int i;
    for(i = rows-1; i>=0 && b[i][from_column]!=0; i--){
	disk = i;
    }
    for(i = rows-1; i>=0; i--){
	if (b[i][to_column]!=0){
	    ;
	}
	else{
	    lowest = i;
	    break;
	}    
    }
    b[lowest][to_column] = b[disk][from_column];
    b[disk][from_column] = 0;
}

void towers(int disks, int b[][3], int from_column, int spare, int to_column, int rows){
    if(disks!=0){
	towers(disks-1, b, from_column, to_column, spare, rows);
	cout<<"Moving disk "<<disks<<" from "<<from_column<<" to "<<to_column<<endl;
	moveDisk(disks-1, b, from_column, to_column, rows);	
	printArray(b, rows);
	towers(disks-1, b, spare, from_column, to_column, rows);
    }
}
