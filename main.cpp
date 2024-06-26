#include <iostream>
#include <stdio.h>
//#include "headers/space.h"
//#include "headers/board.h"
#include "cpp/board.cpp"
#include "cpp/space.cpp"
#include "cpp/piece.cpp"
#include "cpp/player.cpp"



  //MAKE UNIT TESTS



int main(int argc, char* argv[]){
    //s::Space test(5,5);
    b::Board board;
    y::Player p1(0, "Player1");
    y::Player p2(1, "Player2");

 

    //b::Board* b = &board;

    /*pointers here - pass below and change 
    return type of functions to pointer*/

  
    //std::cout << test.getCol() << std::endl;

    //board.findPiece(0,4)->printInfo();

    std::cout << p1.getName() << std::endl;
    std::cout << "Number of pieces for " << p1.getName() << ": " << p1.pieceCount(board) << std::endl;
    std::cout << "Number of pieces for " << p2.getName() << ": " << p2.pieceCount(board) << std::endl;
    int* arr = board.getSpace(1,3)->right->getPosition();



 	std::cout << arr[0] << " " << arr[1] << std::endl;


 	//testing populate
 	//change accessibility of board to a function (returns the board and iterates)
 	for(int i=0; i<board.getSize(); i++){

 		for(int j=0; j<board.getSize(); j++){

 			std::cout << "Position " << i << "," << j << ": " << board.findPiece(i,j)->getRank() << std::endl;

 		}

 	}
 	


 	//std::cout << board.getSpace(0,3)->curr->printInfo() << std::endl;


    



    return 0;
}