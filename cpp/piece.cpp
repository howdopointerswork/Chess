#include <iostream>
#include "../headers/piece.h"


p::Piece::Piece(int colour, int rank, int x, int y){
	
	this->colour = colour;

	this->rank = rank;

	this->x = x;

	this->y = y;

	this-> pM = new int[moveCount];
	

}


void p::Piece::setPosition(int* arr){

	//this->pos = arr;
	this->x = arr[0];
	this->y = arr[1];

}


void p::Piece::printInfo(){


	std::cout << "Position: " << this->x << "," << this->y << std::endl;
	std::cout << "Rank: " << this->getRank() << std::endl;

}



int p::Piece::getRank(){


	return this->rank;

}



void p::Piece::set_moveCount(int toSet){


	this->moveCount = toSet;
}

void p::Piece::print_pM(){

	if(moveCount == 0){

		std::cout << "Cannot move" << std::endl;
		return;
	}

	for(int i=0; i<moveCount; i+=2){

		std::cout << "x: " << pM[i] << ", y: " << pM[i+1] << std::endl;

	}




}


