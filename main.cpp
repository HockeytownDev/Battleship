#include <iostream>
#include <cmath>
#include <stdio.h>
#include <cstdlib>
#include <ctype.h>

using namespace std;

// check if a certain position on the board is occupied by a human ship. 1 indicates health ship, 2 indicated sunk portion of ship
string checkPos(int x, int y, int human[][6])
{
    string str = "";
    if(human[x][y] == 1)
        str = "O";
    else if(human[x][y] == 2)
        str = "X";
    else
        str = " ";

    return str;
}

// print the human's or computer's side of the board. This will show if the ships placed are hit
void printBoard(int human[][6], int computer[][6])
{
    cout << "\n";
    cout << "   ___ ___ ___ ___ ___ ___ " << endl;
    cout << "  |   |   |   |   |   |   |" << endl;
    cout << "5 | " << checkPos(0, 5, human) << " | " << checkPos(1, 5, human) <<" | " << checkPos(2, 5, human) << " | " << checkPos(3, 5, human) << " | " << checkPos(4, 5, human) << " | " <<  checkPos(5, 5, human) << " |" << endl;
    cout << "  |___|___|___|___|___|___|" << endl;
    cout << "  |   |   |   |   |   |   |" << endl;
    cout << "4 | " <<  checkPos(0, 4, human) << " | " << checkPos(1, 4, human) << " | " << checkPos(2, 4, human) << " | " << checkPos(3, 4, human) << " | " << checkPos(4, 4, human) << " | " << checkPos(5, 4, human) << " |" << endl;
    cout << "  |___|___|___|___|___|___|" << endl;
    cout << "  |   |   |   |   |   |   |" << endl;
    cout << "3 | " << checkPos(0, 3, human) << " | " <<  checkPos(1, 3, human) << " | " << checkPos(2, 3, human) << " | " <<  checkPos(3, 3, human) << " | " << checkPos(4, 3, human) << " | " <<  checkPos(5, 3, human) << " |" << endl;
    cout << "  |___|___|___|___|___|___|" << endl;
    cout << "  |   |   |   |   |   |   |" << endl;
    cout << "2 | " <<  checkPos(0, 2, human) << " | " << checkPos(1, 2, human) << " | " <<  checkPos(2, 2, human) << " | " << checkPos(3, 2, human) << " | " <<  checkPos(4, 2, human) << " | " << checkPos(5, 2, human) << " |" << endl;
    cout << "  |___|___|___|___|___|___|" << endl;
    cout << "  |   |   |   |   |   |   |" << endl;
    cout << "1 | " << checkPos(0, 1, human) << " | " <<  checkPos(1, 1, human) << " | " << checkPos(2, 1, human) << " | " << checkPos(3, 1, human) << " | " << checkPos(4, 1, human) << " | " <<  checkPos(5, 1, human) << " |" << endl;
    cout << "  |___|___|___|___|___|___|" << endl;
    cout << "  |   |   |   |   |   |   |" << endl;
    cout << "0 | " << checkPos(0, 0, human) << " | " << checkPos(1, 0, human) << " | " <<  checkPos(2, 0, human) << " | " << checkPos(3, 0, human) << " | " <<  checkPos(4, 0, human) << " | " << checkPos(5, 0, human) << " |" << endl;
    cout << "  |___|___|___|___|___|___|" << endl;
    cout << "    0   1   2   3   4   5   \n" << endl;
}

void initializePieces(int human[][6], int computer[][6])
{
    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 6; j++)
        {
            human[i][j] = 0;
            computer[i][j] = 0;
        }
}

/**
*** Checks thats the back of the ship is adjacent to the front and is not in diagonal
**/
bool check_valid(int fx, int fy, int bx, int by) {
  bool valid = false;
  if ((bx == fx+1 && by == fy) || (bx == fx-1 && by == fy)) {
    valid = true;
  }
  if ((by == fy+1 && bx == fx) || (by == fy-1 && bx == fx)) {
    valid = true;
  }
  return valid;
}

void playGame(int human[][6], int computer[][6])
{
    //Variables to keep track of the ships/ Progress of the game
    int human_front_x1 = -1, human_front_y1 = -1;
    int human_back_x1 = -1, human_back_y1 = -1;
    int human_front_x2 = -1, human_front_y2 = -1;
    int human_back_x2 = -1, human_back_y2 = -1;
    int computer_front_x1 = -1, computer_front_y1 = -1;
    int computer_back_x1 = -1, computer_back_y1 = -1;
    int computer_front_x2 = -1, computer_front_y2 = -1;
    int computer_back_x2 = -1, computer_back_y2 = -1;
    bool computer_ship1_front_live = true, computer_ship1_back_live = true;
    bool computer_ship2_front_live = true, computer_ship2_back_live = true;
    bool human_ship1_front_live = true, human_ship1_back_live = true;
    bool human_ship2_front_live = true, human_ship2_back_live = true;

    //Input for the front of ship 1
    while(true){
          cout << "Please enter the coordinates of the front of first ship (example 1 3): ";
          cin >> human_front_x1 >> human_front_y1;

          if(human_front_x1 >= 0 && human_front_x1 <=5 && human_front_y1 >= 0 && human_front_y1 <=5){
            break;
          } else {
            cout << "\nCoordinates must be between 0 and 5." << endl;
          }
    }

    //Update the value of the front of ship 1
    human[human_front_x1][human_front_y1] = 1;

    //Input for the back of ship 1
    while(true){
          cout << "\nPlease enter the coordinates of the back of first ship (example 1 3): ";
          cin >> human_back_x1 >> human_back_y1;
          if(human_back_x1 >= 0 && human_back_x1 <=5 && human_back_y1 >= 0 && human_back_y1 <=5){
            if(human_front_x1 == human_back_x1 && human_front_y1 == human_back_y1){
              cout << "\nFront and back coordinates cannot be the same! Please re-enter." << endl;
            } else {
              if(check_valid(human_front_x1, human_front_y1, human_back_x1, human_back_y1)){
                break;
              } else {
                cout << "\nShip cannot be diagonal and length of ship cannot be more than 2. Re-enter.";
              }
            }
          } else {
            cout << "\nCoordinates must be between 0 and 5." << endl;
          }
    }

    //Updates the value of the back of ship 1 and prints the board
    human[human_back_x1][human_back_y1] = 1;
    cout << "\nCurrent board: \n";
    printBoard(human, computer);

    //Input for the front of ship 2
    while(true){
          cout << "\nPlease enter the coordinates of the front of second ship (example 1 3): ";
          cin >> human_front_x2 >> human_front_y2;

          if(human_front_x2 >= 0 && human_front_x2 <=5 && human_front_y2 >= 0 && human_front_y2 <=5){
            if(human[human_front_x2][human_front_y2] == 1){
              cout << "\nShips cannot be on top of each other! Re-enter." << endl;
            } else {
              break;
            }
          } else {
            cout << "\nCoordinates must be between 0 and 5." << endl;
          }
    }

    //Updates the value for the front of ship 2
    human[human_front_x2][human_front_y2] = 1;

    //Input for the back of ship 2
    while(true){
          cout << "\nPlease enter the coordinates of the back of second ship (example 1 3): ";
          cin >> human_back_x2 >> human_back_y2;

          if(human_back_x2 >= 0 && human_back_x2 <=5 && human_back_y2 >= 0 && human_back_y2 <=5){
            if(human[human_back_x2][human_back_y2] == 1){
              cout << "\nShips cannot be on top of each other! Please re-enter." << endl;
            } else {
              if(check_valid(human_front_x2, human_front_y2, human_back_x2, human_back_y2)){
                break;
              } else {
                cout << "\nShip cannot be diagonal and length of ship cannot be more than 2. Re-enter.\n";
              }
            }
          } else {
            cout << "\nCoordinates must be between 0 and 5." << endl;
          }
    }

    //Updates the back of ship 2 and prints the current board
    human[human_back_x2][human_back_y2] = 1;
    cout << "\nCurrent board: \n";
    printBoard(human, computer);

    //Random generator for the front of the computers ship
    while(true){
      computer_front_x1 = rand() % 6;
      computer_front_y1 = rand() % 6;

      //Check if position is already taken
      if(human[computer_front_x1][computer_front_y1] != 1 && computer[computer_front_x1][computer_front_y1] != 1){
        break;
      }
    }

    //Choose the back position for the computer's ship 1 so that it is adjacent to the front position and not diagonal
    if(computer_front_x1 < 5 && human[computer_front_x1+1][computer_front_y1] != 1 && computer[computer_front_x1+1][computer_front_y1] != 1){
        computer_back_x1 = computer_front_x1+1;
        computer_back_y1 = computer_front_y1;
    } else if(computer_front_x1 == 5 && human[computer_front_x1-1][computer_front_y1] != 1 && computer[computer_front_x1-1][computer_front_y1] != 1 ){
        computer_back_x1 = computer_front_x1-1;
        computer_back_y1 = computer_front_y1;;
    } else if(computer_front_y1 < 5 && human[computer_front_x1][computer_front_y1+1] != 1 && computer[computer_front_x1][computer_front_y1+1] != 1){
        computer_back_x1 = computer_front_x1;
        computer_back_y1 = computer_front_y1+1;
    } else if(computer_front_y1 == 5 && human[computer_front_x1][computer_front_y1-1] != 1 && computer[computer_front_x1][computer_front_y1-1] != 1 ){
        computer_back_x1 = computer_front_x1-1;
        computer_back_y1 = computer_front_y1;
    }

    //Set the values of the positions of the computer ship to 1
    computer[computer_front_x1][computer_front_y1] = 1;
    computer[computer_back_x1][computer_back_y1] = 1;

    //Random generator for ship 2
    while(true){
      computer_front_x2 = rand() % 6;
      computer_front_y2 = rand() % 6;

      //Check if the position is already taken
      if(human[computer_front_x2][computer_front_y2] != 1 && computer[computer_front_x2][computer_front_y2] != 1){
        break;
      }
    }

    //Choose the back position for the computer's ship 2 so that it is adjacent to the front position and not diagonal
    if(computer_front_x2 < 5 && human[computer_front_x2+1][computer_front_y2] != 1 && computer[computer_front_x2+1][computer_front_y2] != 1){
        computer_back_x2 = computer_front_x2+1;
        computer_back_y2 = computer_front_y2;
    } else if(computer_front_x2 == 5 && human[computer_front_x2-1][computer_front_y2] != 1 && computer[computer_front_x2-1][computer_front_y2] != 1 ){
        computer_back_x2 = computer_front_x2-1;
        computer_back_y2 = computer_front_y2;
    } else if(computer_front_y2 < 5 && human[computer_front_x2][computer_front_y2+1] != 1 && computer[computer_front_x2][computer_front_y2+1] != 1){
        computer_back_x2 = computer_front_x2;
        computer_back_y2 = computer_front_y2+1;
    } else if(computer_front_y2 == 5 && human[computer_front_x2][computer_front_y2-1] != 1 && computer[computer_front_x2][computer_front_y2-1] != 1 ){
        computer_back_x2 = computer_front_x2-1;
        computer_back_y2 = computer_front_y2;
    }

    //Sets the value of the computers ship to 1
    computer[computer_front_x2][computer_front_y2] = 1;
    computer[computer_back_x2][computer_back_y2] = 1;

    cout << "\nComputer has placed its ships!" << endl;

    //Loop to get the attack positions
    while(true){
      int attack_x = -1, attack_y = -1;
      while(true){
        cout << "\nPlease enter the coordinates of your attack (example 1 3): ";
        cin >> attack_x >> attack_y;

        if(attack_x >= 0 && attack_x <=5 && attack_y >= 0 && attack_y <=5){
          break;
        } else {
          cout << "\nCoordinates must be between 0 and 5." << endl;
        }
      }

       //Check if the attack positions hit the computer
      if (computer_ship1_front_live && attack_x == computer_front_x1 && attack_y == computer_front_y1) {
        computer[computer_front_x1][computer_front_y1] = 2;
        cout << "\nHIT!" << endl;
        computer_ship1_front_live = false;
      } else if (computer_ship1_back_live && attack_x == computer_back_x1 && attack_y == computer_back_y1) {
        computer[computer_back_x1][computer_back_y1] = 2;
        cout << "\nHIT!" << endl;
        computer_ship1_back_live = false;
      } else if (computer_ship2_front_live && attack_x == computer_front_x2 && attack_y == computer_front_y2) {
        computer[computer_front_x2][computer_front_y2] = 2;
        cout << "\nHIT!" << endl;
        computer_ship2_front_live = false;
      } else if (computer_ship2_back_live && attack_x == computer_back_x2 && attack_y == computer_back_y2) {
        computer[computer_back_x2][computer_back_y2] = 2;
        cout << "\nHIT!" << endl;
        computer_ship2_back_live = false;
      } else {
        cout << "\nMISS!" << endl;
      }

      //Check if the computers ships have been sunk
      if(!computer_ship1_front_live && !computer_ship1_back_live && !computer_ship2_front_live && !computer_ship2_back_live) {
        cout << "\nComputer's board: \n";
        printBoard(computer, human);
        cout << "\nYou Won the battle!" << endl;
        break;
      }


        //Randomly generate the computers attack
      int computer_attack_x = rand() % 6;
      int computer_attack_y = rand() % 6;

      //Check if the random attack positions hit the ships
      if (human_ship1_front_live && computer_attack_x == human_front_x1 && computer_attack_y == human_front_y1) {
        human[human_front_x1][human_front_y1] = 2;
        cout << "\nYour ship has been hit!" << endl;
        human_ship1_front_live = false;
        cout << "\nYour Board: \n";
        printBoard(human, computer);
      } else if (human_ship1_back_live && computer_attack_x == human_back_x1 && computer_attack_y == human_back_y1) {
        human[human_back_x1][human_back_y1] = 2;
        cout << "\nYour ship has been hit!" << endl;
        human_ship1_back_live = false;
        cout << "\nYour Board: \n";
        printBoard(human, computer);
      } else if (human_ship2_front_live && computer_attack_x == human_front_x2 && computer_attack_y == human_front_y2) {
        human[human_front_x2][human_front_y2] = 2;
        cout << "\nYour ship has been hit!" << endl;
        human_ship2_front_live = false;
        cout << "\nYour Board: \n";
        printBoard(human, computer);
      } else if (human_ship2_back_live && computer_attack_x == human_back_x2 && computer_attack_y == human_back_y2) {
        human[human_back_x2][human_back_y2] = 2;
        cout << "\nYour ship has been hit!" << endl;
        human_ship2_back_live = false;
        cout << "\nYour Board: \n";
        printBoard(human, computer);
      } else {
        cout << "\nComputer missed!" << endl;
      }

      //Check if all of the players ships have sunk
      if(!human_ship1_front_live && !human_ship1_back_live && !human_ship2_front_live && !human_ship2_back_live) {
        cout << "\nYour Board: \n";
        printBoard(human, computer);
        cout << "\nYou Lost the battle! Better luck next time!" << endl;
        break;
      }

    }
}

int main()
{
	cout << "Welcome to Modified battleship!" << endl << endl;
	cout << "Player, please place your first ship of length 2!" << endl << endl;
    int human[6][6];
    int computer[6][6];
    initializePieces(human, computer);
    playGame(human, computer);
    return 0;
}
