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
			this->spaces[i][j]->curr = new p::Piece(-1,-1,i,j);
	



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



int b::Board::colourCheck(p::Piece* p){


	return p->colour;

}



void b::Board::moveScan(s::Space* s){
//needs to be condensed/optimized
	int inc;
	int start; //if white: 0. if black: 7
	int opp;

	if(s->curr->colour == 0){

		inc = 1;
		start = 0;
		opp = 1;

	}
	else{

		inc = -1;
		start = getSize()-1;
		opp = 0;
	}

//back and front??
//left and right should swap


//make 

	if(s->curr->getRank() >= 0){

		switch(s->curr->getRank()){

			case 0:

				std::cout << "Pawn" << std::endl;
		
				if(s->curr->colour == 0){
					if((s->getRow() < getSize()-1) && moveCheck(s, s->front) != s->curr->colour){

						s->front->addSelf(s->curr);
						std::cout << "x: " << s->front->getRow() << ", y: " << s->front->getCol() << std::endl;

						if(moveCheck(s->front, s->front->front) != s->curr->colour && s->getRow() == 1 && s->curr->moveDouble){

							s->front->front->addSelf(s->curr);
							std::cout << "x: " << s->front->front->getRow() << ", y: " << s->front->front->getCol() << std::endl;
						}

					}

					if(s->getRow() < getSize()-1){

						if(s->getCol() > 0){

							if(moveCheck(s, s->front->left) == opp){

								s->front->left->addSelf(s->curr);
								std::cout << "x: " << s->front->left->getRow() << ", y: " << s->front->left->getCol() << std::endl;
							}

						}

						//front left as well
						if(s->getCol() < getSize()-1){

							if(s->getCol() < getSize()-1){

								if(moveCheck(s, s->front->right) == opp){

									s->front->right->addSelf(s->curr);
									std::cout << "x: " << s->front->right->getRow() << ", y: " << s->front->right->getCol() << std::endl;
								}
							}

					}






			}

		}

		else if(s->curr->colour == 1){


			if(s->getRow() > 0 && moveCheck(s, s->back) != s->curr->colour){

				s->back->addSelf(s->curr);
				std::cout << "x: " << s->back->getRow() << ", y: " << s->back->getCol() << std::endl;

				if(moveCheck(s->back, s->back->back) != s->curr->colour && s->getRow() > 1 && s->curr->moveDouble){

					s->back->back->addSelf(s->curr);
					std::cout << "x: " << s->back->back->getRow() << ", y: " << s->back->back->getCol() << std::endl;
				}

			}

			if(s->getRow() > 0){

				if(s->getCol() > 0){

					if(moveCheck(s, s->back->left) == opp){

						s->back->left->addSelf(s->curr);
						std::cout << "x: " << s->back->left->getRow() << ", y: " << s->back->left->getCol() << std::endl;
					}

				}

				//front left as well
				if(s->getCol() > 0){

					if(s->getCol() < getSize()-1){

						if(moveCheck(s, s->back->right) == opp){

							s->back->right->addSelf(s->curr);
							std::cout << "x: " << s->back->right->getRow() << ", y: " << s->back->right->getCol() << std::endl;
						}
					}

			}

		}
		

	}









			if(s->curr->moveCount == 0){

				std::cout << "Cannot move" << std::endl;
			}	
			break;



			
			
			case 1:
			
				std::cout << "Rook" << std::endl;

				s::Space* tmp;
				tmp = s;

	

				while(tmp->curr->colour != opp && tmp->getRow() < getSize()-1){
					//check for white pieces in the way

					if(moveCheck(tmp, tmp->front) != s->curr->colour){

						//addShift(tmp, tmp->front, s->curr);
						tmp->front->addSelf(s->curr);
						tmp = tmp->front;
						std::cout << tmp->getRow() << ", " << tmp->getCol() << std::endl;
						
					}
					else{

						break;
					}					

				}

				tmp = s;


				//white should be > 0
				//black should be < 7

				while(tmp->curr->colour != opp && tmp->getRow() > 0){
					//check for white pieces in the way

					if(moveCheck(tmp, tmp->back) != s->curr->colour){
			

						//addShift(tmp, tmp->back, s->curr);
						tmp->back->addSelf(s->curr);
						tmp = tmp->back;
						std::cout << tmp->getRow() << ", " << tmp->getCol() << std::endl;


					}
					else{

						break;
					}

					
										

				}

				tmp = s;





				while(tmp->curr->colour != opp && tmp->getCol() > 0){
					//check for white pieces in the way
					if(moveCheck(tmp, tmp->left) != s->curr->colour){
						//addShift(tmp, tmp->left, s->curr);
						tmp->left->addSelf(s->curr);
						tmp = tmp->left;
						std::cout << tmp->getRow() << ", " << tmp->getCol() << std::endl;
					}
					else{

						break;
					}					

				}


				tmp = s;
				

				while(tmp->curr->colour != opp && tmp->getCol() < getSize()-1){
					//check for white pieces in the way

					if(moveCheck(tmp, tmp->right) != s->curr->colour){

						
						//addShift(tmp, tmp->right, s->curr);
						tmp->right->addSelf(s->curr);
						tmp = tmp->right;
						std::cout << tmp->getRow() << ", " << tmp->getCol() << std::endl;

					}
					else{
						break;
					}


				}


				delete[] tmp;

				if(s->curr->moveCount == 0){

					std::cout << "Cannot move" << std::endl;
				}	

				break;


			case 2:

				std::cout << "Knight" << std::endl;

				//how the fuck do i do this

				//down down left
				//down down right
				//up up left
				//up up right
				//left left up
				//left left down
				//right right up
				//right right down


				//no loop as one movement
				//but can go over others

				//can do a for loop however



				if(s->getRow() > 1 && s->getCol() > 0){

					if(moveCheck(s, s->back->back->left) != s->curr->colour){

						s->back->back->left->addSelf(s->curr);
						std::cout << s->back->back->left->getRow() << ", " << s->back->back->left->getCol() << std::endl;
					}

				}

				if(s->getRow() > 1 && s->getCol() < getSize()-1){

					if(moveCheck(s, s->back->back->right) != s->curr->colour){

						s->back->back->right->addSelf(s->curr);
						std::cout << s->back->back->right->getRow() << ", " << s->back->back->right->getCol() << std::endl;
					}
				}


				if(s->getRow() < getSize()-2 && s->getCol() > 0){
					std::cout << "Here" << std::endl;
					if(moveCheck(s, s->front->front->left) != s->curr->colour){

						s->front->front->left->addSelf(s->curr);
						std::cout << s->front->front->left->getRow() << ", " << s->front->front->left->getCol() << std::endl;

					}
				}

				if(s->getRow() < getSize()-2 && s->getCol() < getSize()-1){

					if(moveCheck(s, s->front->front->right) != s->curr->colour){

						s->front->front->right->addSelf(s->curr);
						std::cout << s->front->front->right->getRow() << ", " << s->front->front->right->getCol() << std::endl;
					}
				}

				if(s->getCol() > 1 && s->getRow() < getSize()-1){

					if(moveCheck(s, s->left->left->front) != s->curr->colour){

						s->left->left->front->addSelf(s->curr);
						std::cout << s->left->left->front->getRow() << ", " << s->left->left->front->getCol() << std::endl;
					}
				}

				if(s->getCol() > 1 && s->getRow() > 0){


					if(moveCheck(s, s->left->left->back) != s->curr->colour){


						s->left->left->back->addSelf(s->curr);
						std::cout << s->left->left->back->getRow() << ", " << s->left->left->back->getCol() << std::endl;
					}
				}

				if(s->getCol() < getSize()-2 && s->getRow() > 0){

					if(moveCheck(s, s->right->right->back) != s->curr->colour){

						s->right->right->back->addSelf(s->curr);
						std::cout << s->right->right->back->getRow() << ", " << s->right->right->back->getCol() << std::endl;
					}
				}

				if(s->getCol() < getSize()-2 && s->getRow() < getSize()-1){

					if(moveCheck(s, s->right->right->front) != s->curr->colour){

						s->right->right->front->addSelf(s->curr);
						std::cout << s->right->right->front->getRow() << ", " << s->right->right->front->getCol() << std::endl;
					}
				}




				break;

			case 3:
					
				std::cout << "Bishop" << std::endl;


				s::Space* tmp2;
				tmp2 = s;

		


				while(tmp2->curr->colour != opp && ((tmp2->getRow() < getSize()-1 && tmp2->getCol() > 0))){

					if(moveCheck(tmp2, tmp2->front->left) != s->curr->colour){


						
						//addShift(tmp2, tmp2->front->left, s->curr);
						tmp2->front->left->addSelf(s->curr);
						tmp2 = tmp2->front->left;
						std::cout << tmp2->getRow() << ", " << tmp2->getCol() << std::endl;

					}
					else{

						break;
					}

				}

				tmp2 = s;

				while(tmp2->curr->colour != opp && (tmp2->getRow() < getSize()-1 && tmp2->getCol() < getSize()-1)){

					if(moveCheck(tmp2, tmp2->front->right) != s->curr->colour){

						
						//addShift(tmp2, tmp->front->right, s->curr);
						tmp2->front->right->addSelf(s->curr);
						tmp2 = tmp2->front->right;
						std::cout << tmp2->getRow() << ", " << tmp2->getCol() << std::endl;

					}
					else{

						break;
					}



				}

				tmp2 = s;



				while(tmp2->curr->colour != opp && (tmp2->getRow() > 0 && tmp2->getCol() > 0)){
					
					if(moveCheck(tmp2, tmp2->back->left) != s->curr->colour){

						
						//addShift(tmp2, tmp2->back->left, s->curr);
						tmp2->back->left->addSelf(s->curr);
						tmp2 = tmp2->back->left;
						std::cout << tmp2->getRow() << ", " << tmp2->getCol() << std::endl;

					}
					else{
						break;
					}

				}

				tmp2 = s;



				while(tmp2->curr->colour != opp && (tmp2->getRow() > 0 && tmp2->getCol() < getSize()-1)){

					if(moveCheck(tmp2, tmp2->back->right) != s->curr->colour){

						
						//addShift(tmp2, tmp2->back->right, s->curr);
						tmp2->back->right->addSelf(s->curr);
						tmp2 = tmp2->back->right;
						std::cout << tmp2->getRow() << ", " << tmp2->getCol() << std::endl;

					}
					else{

						break;
					}

				}

				delete[] tmp2;

				if(s->curr->moveCount == 0){

					std::cout << "Cannot move" << std::endl;
				}	


				break;


			case 4:

				std::cout << "Queen" << std::endl;

				s::Space* tmp3;
				tmp3 = s;



				if(tmp3->curr->colour == 0){

					opp = 1;


				}

				else{

					opp = 0;
				}

				while(tmp3->curr->colour != opp && tmp3->getRow() < getSize()-1){
					//check for white pieces in the way

					if(moveCheck(tmp3, tmp3->front) != s->curr->colour){

						//addShift(tmp3, tmp3->front, s->curr);
						tmp3->front->addSelf(s->curr);
						tmp3 = tmp3->front;
						std::cout << tmp3->getRow() << ", " << tmp3->getCol() << std::endl;
						
					}
					else{

						break;
					}					

				}

				tmp3 = s;


				while(tmp3->curr->colour != opp && tmp3->getRow() > 0){
					//check for white pieces in the way
					if(moveCheck(tmp3, tmp3->back) != s->curr->colour){

						
						//addShift(tmp3, tmp3->back, s->curr);
						tmp3->back->addSelf(s->curr);
						tmp3 = tmp3->back;
						std::cout << tmp3->getRow() << ", " << tmp3->getCol() << std::endl;
						
					}
					else{

						break;
					}

					
										

				}


				tmp3 = s;


				while(tmp3->curr->colour != opp && tmp3->getCol() > 0){
					//check for white pieces in the way
					if(moveCheck(tmp3, tmp3->left) != s->curr->colour){

						//addShift(tmp3, tmp3->left, s->curr);
						tmp3->left->addSelf(s->curr);
						tmp3 = tmp3->left;
						std::cout << tmp3->getRow() << ", " << tmp3->getCol() << std::endl;
						
					}
					else{

						break;
					}					

				}


				tmp3 = s;

				while(tmp3->curr->colour != opp && tmp3->getCol() < getSize()-1){
					//check for white pieces in the way

					if(moveCheck(tmp3, tmp3->right) != s->curr->colour){

						
						//addShift(tmp3, tmp3->right, s->curr);
						tmp3->right->addSelf(s->curr);
						tmp3 = tmp3->right;
						std::cout << tmp3->getRow() << ", " << tmp3->getCol() << std::endl;
						
					}
					else{

						break;
					}


				}

				while(tmp3->curr->colour != opp && (tmp3->getRow() < getSize()-1 && tmp3->getCol() > 0)){

					if(moveCheck(tmp3, tmp3->front->left) != s->curr->colour){


						
						//addShift(tmp3, tmp3->front->left, s->curr);
						tmp3->front->left->addSelf(s->curr);
						tmp3 = tmp3->front->left;
						std::cout << tmp3->getRow() << ", " << tmp3->getCol() << std::endl;

					}
					else{

						break;
					}

				}

				tmp3 = s;

				while(tmp3->curr->colour != opp && (tmp3->getRow() < getSize()-1 && tmp3->getCol() < getSize()-1)){

					if(moveCheck(tmp3, tmp3->front->right) != s->curr->colour){

						//addShift(tmp3, tmp3->front->right, s->curr);
						tmp3->front->right->addSelf(s->curr);
						tmp3 = tmp3->front->right;
						std::cout << tmp3->getRow() << ", " << tmp3->getCol() << std::endl;

					}
					else{

						break;
					}



				}

				tmp3 = s;



				while(tmp3->curr->colour != opp && (tmp3->getRow() > 0 && tmp3->getCol() > 0)){
					
					if(moveCheck(tmp3, tmp3->back->left) != s->curr->colour){

						//addShift(tmp3, tmp3->back->left, s->curr);
						tmp3->back->left->addSelf(s->curr);
						tmp3 = tmp3->back->left;
						std::cout << tmp3->getRow() << ", " << tmp3->getCol() << std::endl;

					}
					else{
						break;
					}

				}

				tmp3 = s;



				while(tmp3->curr->colour != opp && (tmp3->getRow() > 0 && tmp3->getCol() < getSize()-1)){

					if(moveCheck(tmp3, tmp3->back->right) != s->curr->colour){

						//addShift(tmp3, tmp3->back->right, s->curr);
						tmp3->back->right->addSelf(s->curr);
						tmp3 = tmp3->back->right;
						std::cout << tmp3->getRow() << ", " << tmp3->getCol() << std::endl;

					}
					else{

						break;
					}

				}

				delete[] tmp3;

				if(s->curr->moveCount == 0){

					std::cout << "Cannot move" << std::endl;
				}	


				break;



			case 5:
				

				std::cout << "King" << std::endl;

	

				if(s->getRow() < getSize()-1){

					if(moveCheck(s, s->front) != s->curr->colour){

						s->front->addSelf(s->curr);
						std::cout << s->front->getRow() << ", " << s->front->getCol() << std::endl;

					}
				}

				if(s->getRow() > 0){

					if(moveCheck(s, s->back) != s->curr->colour){

						s->back->addSelf(s->curr);
						std::cout << s->back->getRow() << ", " << s->back->getCol() << std::endl;
					}

				}


				if(s->getCol() > 0){

					if(moveCheck(s, s->left) != s->curr->colour){

						s->left->addSelf(s->curr);
						std::cout << s->left->getRow() << ", " << s->left->getCol() << std::endl;
					}
				}

				if(s->getCol() < getSize()-1){

					if(moveCheck(s, s->right) != s->curr->colour){

						s->right->addSelf(s->curr);
						std::cout << s->right->getRow() << ", " << s->right->getCol() << std::endl;
					}
				}

				//diagonals

				if(s->getRow() < getSize()-1 && s->getCol() > 0){

					if(moveCheck(s, s->front->left) != s->curr->colour){

						s->front->left->addSelf(s->curr);
						std::cout << s->front->left->getRow() << ", " << s->front->left->getCol() << std::endl;
					}
				}

				if(s->getRow() < getSize()-1 && s->getCol() < getSize()-1){


					if(moveCheck(s, s->front->right) != s->curr->colour){

						s->front->right->addSelf(s->curr);
						std::cout << s->front->right->getRow() << ", " << s->front->right->getCol() << std::endl;
					}
				} 

				if(s->getRow() > 0 && s->getCol() > 0){

					if(moveCheck(s, s->back->left) != s->curr->colour){

						s->back->left->addSelf(s->curr);
						std::cout << s->back->left->getRow() << ", " << s->back->left->getCol() << std::endl;
					}

				if(s->getRow() > 0 && s->getCol() < getSize()-1){

					if(moveCheck(s, s->back->right) != s->curr->colour){


						s->back->right->addSelf(s->curr);
						std::cout << s->back->right->getRow() << ", " << s->back->right->getCol() << std::endl;
					}
				}	
				}


				if(s->curr->moveCount == 0){

					std::cout << "Cannot move" << std::endl;
				}	



				break;
			}
		}



}		
	
		



//work on this next
void b::Board::swap(s::Space* p1, s::Space* p2, int i, int j){

	//Swap works, but we need to update in game manager

	std::cout << "Before:" << std::endl;
	

	std::cout << "p1 address: " << p1 << " p1 row: " << p1->getRow() << " p1 col: " << p1->getCol() << " p1 rank: " << p1->curr->getRank() << std::endl;
	std::cout << "p2 address: " << p2 << " p2 row: " << p2->getRow() << " p2 col: " << p2->getCol()  << " p2 rank: " << p2->curr->getRank() << std::endl;


	s::Space* tmp = p1;
	tmp->setRow(p1->getRow());
	tmp->setCol(p1->getCol());
	p1 = p2;
	p1->setRow(p2->getRow());
	p1->setCol(p2->getCol());
	p2 = tmp;
	p2->setRow(tmp->getRow());
	p2->setCol(tmp->getCol());



	std::cout << "After:" << std::endl;

	std::cout << "p1 address: " << p1 << " p1 row: " << p1->getRow() << " p1 col: " << p1->getCol()  << " p1 rank: " << p1->curr->getRank() << std::endl;
	std::cout << "p2 address: " << p2 << " p2 row: " << p2->getRow() << " p2 col: " << p2->getCol()  << " p2 rank: " << p2->curr->getRank() << std::endl;

/*
	if(p1->curr->colour != p2->curr->colour && p2->curr->getRank() >= 0){

		delete[] this->spaces[i][j];
		this->spaces[i][j] = new s::Space(i,j); 
		this->spaces[i][j]->curr = new p::Piece(-1,-1,i,j);
		swap(p1, p2, i, j);
		std::cout << "Ate piece" << std::endl;

	}
	else if(p1->curr->colour != p2->curr->colour){

		std::cout << "Hello" << std::endl;
		s::Space* tmp;
		int x;
		int y;

		tmp = p1;
		//tmp->setRow(p1->getRow());
		//tmp->setCol(p1->getCol());



		p1 = p2;
		//p1->setRow(p2->getRow());
		//p1->setCol(p2->getCol());



		p2 = tmp;
		//p2->setRow(tmp->getRow());
		//p2->setCol(p2->getCol());

	//add removal of enemy pieces here.
	//check if swapped piece (coming from origin) has opposite colour
	//if so, change the eaten piece to a blank



		delete[] tmp;
		}*/

	std::cout << "Swapped: " << p1->getRow() << "," << p1->getCol() << std::endl;
	std::cout << "Swapped: " << p2->getRow() << "," << p2->getCol() << std::endl; 


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

		/*if(i == (arrSize/2)){


			currCol = -1;

		}*/
		
		if(i == arrSize-16){

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


int b::Board::moveCheck(s::Space* current, s::Space* check){


	//code
	//0 is back
	//1 is front
	//2 is left
	//3 is right
	//diagonal 


	if(current->curr->colour != check->curr->colour || check->curr->getRank() < 0){

		if(check->curr->getRank() < 0){

			//std::cout << "Empty space" << std::endl;
			return check->curr->colour;
		}

		else{

			std::cout << "Enemy piece" << std::endl;
			return check->curr->colour;
		}

		
	}

	return current->curr->colour;

}



//Work on these arrays so that we can make the switch case for each piece
//more efficient
//There must be some way that we can shift values and make one loop instead of four while's




void b::Board::addShift(s::Space* from, s::Space* to, p::Piece* src ){



	to->addSelf(src);
	from = to;
	std::cout << "x: " << to->getRow() << ", y: " << to->getCol() << std::endl;
	
						


}

int b::Board::boundCheck(s::Space* s){

	if((s->getRow() < getSize()-1 && s->curr->colour == 0) || (s->getRow() < getSize()-1 && s->curr->colour == 1)){

		return 1;
	}

	if(s->getRow() > 0){

		return 2;
	}


	return 0;
}


p::Piece* b::Board::getPiece(int index){


	return this->chessSet[index];
}


