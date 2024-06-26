#include <iostream>
#include "../headers/board.h"



b::Board::Board(){ 
//constructor
//boards start from the bottom left

	


	this->size = 8; //set size for nested loops

	makeSpaces(1); //initialize spaces in spaces array

	connectSpaces(); //set pointers for each space

	makeChessSet();

	populate();

	


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
			this->spaces[i][j]->curr = new p::Piece(0,-1,i,j);
	



			}
	

			//this->spaces[i][j]->curr = NULL;

			//adjust pointers for each row

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



void b::Board::makeChessSet(){

	bool currCol = 0;

	int currRank = 1;

	int arrSize = this->size * 4;

	int posX = 0;

	int posY = 0;

	int inc = 1;


	//rows will be i at 0 and j 0-7
	//and i at 1 and j at 0-7


	for(int i = 0; i < arrSize; i++){

		//make pieces here

		//

		if(posY == 8){

			posY = 0;

			//match posx with previous value and change it and then break

			switch(posX){

				case 0:

					posX = 1;
					break;
				
				case 1:
				
					posX = 6;
					inc *= -1;
					break;

				case 6:	

					posX = 7;
					currRank = 1;	
					break;
				}

		}

		if(i == (arrSize/2)){


			currCol = 1;

		}


		chessSet[i] = new p::Piece(currCol, currRank, posX, posY);
		//std::cout << posX << "," << posY << ": " << chessSet[i]->getRank() << std::endl;

		posY++;

		if(posX == 0 || posX == 7){

			currRank += inc;

			if(currRank == 6){

				currRank = 3;
				inc *= -1;
			}

		}
		else{


			currRank = 0;
		}




		//first 8 will be
		//0 = rook
		//1 = knight
		//2 = bishop
		//3 = queen
		//4 = king
		//5 = bishop
		//6 = knight
		//7 = rook
		//8-15 = pawn
		//16-23 = black set
		//24-31 = black pawns
		 

		 //0, 7,  is rook






	}

	

}




void b::Board::populate(){

	int ind = 0;

	for(int i=0; i < this->size; i++){

		for(int j=0; j < this->size; j++){


			if(i == 0 || i == 1 || i == 6 || i == 7){

				spaces[i][j]->curr = chessSet[ind];
				ind++;

				}
			
			




		}

	}

}	


