#include <iostream>
#include "../headers/board.h"


//boards start from the bottom left
b::Board::Board(){

	this->size = 8;

	int n = 1;
	


	for(int i=0; i<this->size; i++){

		


		for(int j=0; j<this->size; j++){




			this->spaces[i][j] = new s::Space(i,j); //static_cast<Space>(std::malloc(sizeof(Space)));
			//do left, right, etc. here

			//replace with actual piece classes, which will require inner if statements
			if(i == this->size - this->size){
				
				int* arr = static_cast<int*>(std::malloc(sizeof(int)*2));
				arr[0] = i;
				arr[1] = j;

				this->spaces[i][j]->curr = new p::Piece(0,n);
				this->spaces[i][j]->curr->setPosition(arr);
				
				n++;
				
				std::free(arr);

			}

			else if(i == (this->size - (this->size - 1))){
				
				int* arr = static_cast<int*>(std::malloc(sizeof(int)*2));
				arr[0] = i;
				arr[1] = j;
				
				n = 0;

				this->spaces[i][j]->curr = new p::Piece(0,n);
				
				std::free(arr);

			}

			else if(i == (this->size - 2)){

				int* arr = static_cast<int*>(std::malloc(sizeof(int)*2));
				arr[0] = i;
				arr[1] = j;

				this->spaces[i][j]->curr = new p::Piece(1,n);


				if(j == 7){

					n = 1;

				}

				std::free(arr);

			}

			else if(i == (this->size-1)){

				int* arr = static_cast<int*>(std::malloc(sizeof(int)*2));
				arr[0] = i;
				arr[1] = j;
				
				this->spaces[i][j]->curr = new p::Piece(1,n);
				n++;

				std::free(arr);

			}



					

			//this->spaces[i][j]->curr = NULL;

			//adjust pointers for each row

		}


	}

	


}


s::Space* b::Board::getSpace(int x, int y){


	return spaces[x][y];


}


p::Piece* b::Board::findPiece(int x, int y){


	return getSpace(x,y)->curr;

}