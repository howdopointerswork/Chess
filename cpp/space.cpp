#include "../headers/space.h"
#include <iostream>

s::Space::Space(int row, int col){

	this->row = row;

	this->col = col;

	this->pos[0] = this->row;

	this->pos[1] = this->col;

	this->occupied = 0;

};

int s::Space::getRow() const{

    return this->pos[0];

}

int s::Space::getCol() const{

    return this->pos[1];

}


int* s::Space::getPosition(){


	return pos;

}