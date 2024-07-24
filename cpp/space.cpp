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

bool s::Space::update(bool tf){


	this->occupied = tf;

	return tf;

}



void s::Space::addSelf(p::Piece* p){



	p->moveCount++;
	p->pM[p->moveCount-1] = this->getRow();
	p->moveCount++;
	p->pM[p->moveCount-1] = this->getCol();



}


void s::Space::setRow(int n){


	this->row = n;
}

void s::Space::setCol(int n){


	this->row = n;
}