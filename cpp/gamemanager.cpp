#include <iostream>
#include "../headers/gamemanager.h"


g::GameManager::GameManager(){

	this->size = 0;
	this->n = 0;
	this->inGame = true;

	this->options[0] = "Check Piece";
	this->options[1] = "Move Piece"; 
	this->options[2] = "Check Board";
	this->options[3] = "End Turn";

	welcome();


}


int g::GameManager::getSize(){


	return this->size;
}


void g::GameManager::addPlayer(y::Player p){


	this->players[size] = &p;
	this->size++;
}


y::Player* g::GameManager::getPlayer(int n){

	return this->players[n];
}



std::string g::GameManager::getOption(int n){
	

	return this->options[n];

}


void g::GameManager::welcome(){


	std::cout << "Welcome to Chess." << std::endl;
    std::cout << std::endl;

}


int g::GameManager::getChoice(){



	return this->choice;
}


int g::GameManager::setChoice(int set){



	return this->choice = set;
}

bool g::GameManager::get_inGame(){


	return this->inGame;
}

bool g::GameManager::set_inGame(bool set){


	return this->inGame = set;
}

int g::GameManager::getN(){


	return this->n;
}


void g::GameManager::fillArrays(y::Player* p1, y::Player* p2, b::Board b){


 	int row = 0;
 	int col = 0;

	

	for(int i=0; i<b.getSize()*4; i++){

		if(i < b.getSize()*2){


			p1->insertAt(b.getSpace(row, col), i);
			col++;

			if(col == b.getSize()){

					col = 0;
					row = 1;

				}
		}

		else{

			if(i == (b.getSize()*2)){

 				row = 7;
 				col = 0;

 			}
 			
 			else if(i == (b.getSize()*3)){


 				row = 6;
 				col = 0;
 			}


 			p2->insertAt(b.getSpace(row, col), i-16);
 			col++;

		} 


}

}






void g::GameManager::runGame(b::Board board){ //add player sets and board

	int c;
	int index;
	bool confirm;
	int from;
	int to;
	//fillArrays(p1, p2, board);
	fillArrays(getPlayer(0), getPlayer(1), board);


	while(get_inGame()){

		if(getN() > 1){


			this->n = 0;
		}


		std::cout << "It is " << getPlayer(this->n)->getName() << "'s turn" << std::endl;
		std::cout << "What will you do?" << std::endl;

		for(int i=0; i<4; i++){

			std::cout << i+1 << ". " << getOption(i) << std::endl;
		}

		std::cin >> c;
		this->choice = setChoice(c);

		switch(getChoice()){

			case 1:

				std::cout << "Which piece?:" << std::endl;
				std::cout << std::endl;
				getPlayer(this->n)->printArr();

				std::cin >> index;

				if(index < getPlayer(this->n)->get_arrSize()){


					std::cout << std::endl;
					board.moveScan(getPlayer(this->n)->get(index-1));
					std::cout << std::endl;
					continue;
				}
				else{

					std::cout << std::endl;
					continue;
				}



				break;
			
			case 2:

				std::cout << "Which piece?: " << std::endl;
				std::cout << std::endl;
				getPlayer(this->n)->printArr();

				std::cin>>from;

				if(from < getPlayer(this->n)->get_arrSize()){

					std::cout << std::endl;
					std::cout << "To where?" << std::endl;
					//getPlayer(this->n)->get(from-1)->curr->print_pM();
					board.moveScan(getPlayer(this->n)->get(from-1));
					std::cin >>to;

					std::cout << "Confirm? (1 for yes)" << std::endl;
					std::cin >> confirm;

					if(confirm){

						board.swap(board.getSpace(getPlayer(this->n)->get(from-1)->getRow(), getPlayer(this->n)->get(from-1)->getCol()), board.getSpace(getPlayer(this->n)->get(from-1)->curr->pM[to-1], getPlayer(this->n)->get(from-1)->curr->pM[to]), getPlayer(this->n)->get(from-1)->curr->pM[to-1], getPlayer(this->n)->get(from-1)->curr->pM[to]);
						confirm = false;
						this->n++;

					} 
					else{

						continue;
					}

					


				}


			
				break;

			case 3:
			
				break;

			case 4:
				
				this->n++;
				break;			

		}


	}

}




