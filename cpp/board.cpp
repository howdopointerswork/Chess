#include <iostream>
#include "../headers/board.h"


//boards start from the bottom left
b::Board::Board(){

	this->size = 8;

	int n = 1;
	
//make board initialize function
//make set board function (pointers)
//make pieces and populate function	

	for(int i=0; i<this->size; i++){
		

		for(int j=0; j<this->size; j++){


			this->spaces[i][j] = new s::Space(i,j); 

			//replace with actual piece classes, which will require inner if statements
			if(i == this->size - this->size){
				

				//make chess set array
				//and allocate / populate
				//then assign curr to addresses of each 
				//according to ifs
				//make temp for board?

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


	for(int i=0; i<this->size; i++){


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


s::Space* b::Board::getSpace(int x, int y){


	return spaces[x][y];


}


p::Piece* b::Board::findPiece(int x, int y){


	return getSpace(x,y)->curr;

}



void b::makeSpaces(){


	return;

}



void b::connectSpaces(){


	return;
}



void b::populate(){


	return;
}