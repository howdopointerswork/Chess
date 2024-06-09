#include <iostream>
#include "../headers/piece.h"


p::Piece::Piece(bool colour, int rank){
	
	this->colour = colour;

	this->rank = rank;
	

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