#include <iostream>
#include <stdio.h>

#include "cpp/board.cpp"
#include "cpp/space.cpp"
#include "cpp/piece.cpp"
#include "cpp/player.cpp"
#include "cpp/gamemanager.cpp"



  //MAKE UNIT TESTS



int main(int argc, char* argv[]){
    //s::Space test(5,5);
   	g::GameManager gm;
    b::Board board;
    y::Player p1(0, "Player1");
    y::Player p2(1, "Player2");

    int n = 0;
    int choice;


    //put in gm
    bool inGame = true;




    //put in constructor
    gm.addPlayer(p1);
    gm.addPlayer(p2);

    //make part of gm


    //make a gm function
    
 	//gm.runGame(); 

 	int row = 0;
 	int col = 0;

 	gm.runGame(board);


 	/*for(int i=0; i<board.getSize()*4; i++){


 		if(i < board.getSize()*2){


 			p1.insertAt(board.getSpace(row, col), i);
 			col++;


 			if(col == board.getSize()){

 				col = 0;
 				row = 1;

 			}

 		}

 		else{



 			if(i == (board.getSize()*2)){

 				row = 7;
 				col = 0;

 			}
 			else if(i == (board.getSize()*3)){


 				row = 6;
 				col = 0;
 			}


 			p2.insertAt(board.getSpace(row, col), i-16);
 			col++;




 		}



 	}*/




 	//re-populate chess sets for respective players
 	//then work on piece selection for viewing moves and such
 	//offer to select a move from available ones or choose another piece
 	//for choosing another piece, we just loop what we did 
 	//if choose, we commit the swap and print appropriately






 
 

    //b::Board* b = &board;

    /*pointers here - pass below and change 
    return type of functions to pointer*/

  
    //std::cout << test.getCol() << std::endl;

    //board.findPiece(0,4)->printInfo();

    /*std::cout << p1.getName() << std::endl;
    std::cout << "Number of pieces for " << p1.getName() << ": " << p1.pieceCount(board) << std::endl;
    std::cout << "Number of pieces for " << p2.getName() << ": " << p2.pieceCount(board) << std::endl;
    int* arr = board.getSpace(1,3)->right->getPosition();*/



 //	std::cout << arr[0] << " " << arr[1] << std::endl;

 	//board.swap(board.getSpace(0,1), board.getSpace(1,0));

 	//board.moveScan(board.getSpace(1,0));

 	//board.getSpace(1,0)->curr->print_pM();

 	//board.swap(board.getSpace(6,4), board.getSpace(7,0));
 	//board.swap(board.getSpace(5,3), board.getSpace(6,4));
 	//put piece in the way of rook at 2,0: board.swap(board.getSpace(1,3), board.getSpace(3,0));
 	/*board.swap(board.getSpace(5,4), board.getSpace(7,0));
 	board.moveScan(board.getSpace(5,4));*/
 	//board.getSpace(6,4)->curr->print_pM();

 	//test queen


 	//testing populate
 	//change accessibility of board to a function (returns the board and iterates)
 	/*for(int i=0; i<board.getSize(); i++){

 		for(int j=0; j<board.getSize(); j++){

 	
 			//board.moveScan(board.findPiece(i,j)->getRank());
 			std::cout << "x: " << board.getSpace(i,j)->getPosition()[0] << ", y: " << board.getSpace(i,j)->getPosition()[1] << std::endl;
 			std::cout << "rank: " << board.getSpace(i,j)->curr->getRank() << std::endl;
 		}

 	}*/
 	


 	//std::cout << board.getSpace(0,3)->curr->printInfo() << std::endl;


    



    return 0;
}