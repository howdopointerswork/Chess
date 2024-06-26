#include <iostream>
#include "../headers/player.h"


y::Player::Player(bool colour, std::string name){
	
	this->colour = colour;

	this->name = name;




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