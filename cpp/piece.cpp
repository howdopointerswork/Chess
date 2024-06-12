#include <iostream>
#include "../headers/piece.h"


p::Piece::Piece(bool colour, int rank, int x, int y){
	
	this->colour = colour;

	this->rank = rank;

	this->x = x;

	this->y = y;
	

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