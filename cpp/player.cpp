#include <iostream>
#include "../headers/player.h"


y::Player::Player(bool colour, std::string name){
	
	this->colour = colour;

	this->name = name;

	this->arrSize = 0;




}



bool y::Player::getColour(){


	return this->colour;
}


std::string y::Player::getName(){

	return this->name;

}


int y::Player::pieceCount(b::Board b){

	int counter = 0;

	for(int i=0; i<b.getSize(); i++){

		for(int j=0; j<b.getSize(); j++){


			if(b.findPiece(i,j)->colour == this->getColour() && b.findPiece(i,j)->getRank() >= 0){

				counter++;
			}

		}

	}

	return counter;

}


void y::Player::insertAt(s::Space* s, int index){


	this->arr[index] = s;
	this->arrSize++;

}


int y::Player::get_arrSize(){


	return this->arrSize;
}

void y::Player::printArr(){



	for(int i=0; i<this->arrSize; i++){

		std::cout << i+1 << ". " << arr[i]->curr->getRank() << ", " << arr[i]->curr->colour << " at: " << arr[i]->getRow() << ", " << arr[i]->getCol() << std::endl;
	}
	std::cout << std::endl;
}


s::Space * y::Player::get(int n){


	return this->arr[n];
}

