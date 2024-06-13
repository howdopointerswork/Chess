#include <iostream>
#include "../headers/board.h"



b::Board::Board(){ 
//constructor
//boards start from the bottom left

	


	this->size = 8; //set size for nested loops

	makeSpaces(1); //initialize spaces in spaces array

	connectSpaces(); //set pointers for each space

	


}


s::Space* b::Board::getSpace(int x, int y){ 
//returns a space at index x, y of spaces array

	return spaces[x][y];


}


p::Piece* b::Board::findPiece(int x, int y){
//returns the pointer piece at the specified space

	return getSpace(x,y)->curr;

}



void b::Board::makeSpaces(int n){


	for(int i=0; i<this->size; i++){
		

		for(int j=0; j<this->size; j++){


			this->spaces[i][j] = new s::Space(i,j); 

			//replace with actual piece classes, which will require inner if statements
			if(i == 0){
				

				//replace each of the lines like below with
				//pieces in chessSet

				this->spaces[i][j]->curr = new p::Piece(0,n, i, j);
				
				n++;
				

			}

			else if(i == (this->size - (this->size - 1))){
				
				n = 0;

				this->spaces[i][j]->curr = new p::Piece(0,n, i, j);
				

			}

			else if(i == (this->size - 2)){


				this->spaces[i][j]->curr = new p::Piece(1, n, i, j);


				if(j == 7){

					n = 1;

				}


			}

			else if(i == (this->size-1)){

				
				this->spaces[i][j]->curr = new p::Piece(1,n, i, j);
				n++;


			}



					

			//this->spaces[i][j]->curr = NULL;

			//adjust pointers for each row

		}


	}

}



void b::Board::connectSpaces(){


	for(int i=0; i<size; i++){


		for(int j=0; j<this->size; j++){


			if(i < 7){
				
				this->spaces[i][j]->front = this->spaces[i+1][j];

			}
			else{

				this->spaces[i][j]->front = nullptr;

			}


			if(i > 0){


				this->spaces[i][j]->back = this->spaces[i-1][j];

			}
			else{



				this->spaces[i][j]->back = nullptr;
			}

			if(j > 0){



				this->spaces[i][j]->left = this->spaces[i][j-1];

			}

			else{


				this->spaces[i][j]->left = nullptr;

			}

			if(j < 7){


				this->spaces[i][j]->right = this->spaces[i][j+1];

			}

			else{


				this->spaces[i][j]->right = nullptr;

			}




			



		}


	}
}



void b::Board::moveScan(int rank){


	switch(rank){

		case 0:

			std::cout << "Pawn" << std::endl;
			break;
		
		case 1:
		
			std::cout << "Rook" << std::endl;
			break;

		case 2:

			std::cout << "Knight" << std::endl;
			break;

		case 3:
				
			std::cout << "Bishop" << std::endl;
			break;

		case 4:

			std::cout << "Queen" << std::endl;
			break;

		case 5:
			

			std::cout << "King" << std::endl;
			break;
		}
	}



int b::Board::getSize(){


	return this->size;

}



void b::Board::populate(){

	bool currCol = 0;

	int currRank = 0;

	int arrSize = this->size * 4;


	for(int i = 0; i < arrSize; i++){

		//make pieces here

		//

		if(i == (arrSize/2)){


			currCol = 1;

		}
		//else


		//if(i == 0 || i == 7)






	}

	

}
