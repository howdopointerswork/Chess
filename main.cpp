#include <iostream>
#include <stdio.h>
//#include "headers/space.h"
//#include "headers/board.h"
#include "cpp/board.cpp"
#include "cpp/space.cpp"
#include "cpp/piece.cpp"


int main(int argc, char* argv[]){
    s::Space test(5,5);
    b::Board board;

    //b::Board* b = &board;

    /*pointers here - pass below and change 
    return type of functions to pointer*/

    //make unit tests
    //std::cout << test.getCol() << std::endl;

    //board.findPiece(0,4)->printInfo();

    
    
    int* arr = board.getSpace(1,3)->right->getPosition();


    
 	std::cout << arr[0] << " " << arr[1] << std::endl;




    



    return 0;
}