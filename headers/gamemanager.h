#include <iostream>
#include "player.h"
#include "board.h"



namespace g{
	
	class GameManager{

		public:


			

			GameManager();

			void addPlayer(y::Player p);

			int getSize();

			y::Player* getPlayer(int n);

			std::string getOption(int n);

			int getChoice();

			int setChoice(int set);

			void runGame(b::Board board);

			bool get_inGame();

			bool set_inGame(bool set);

			int getN();

			void fillArrays(y::Player* p1, y::Player* p2, b::Board b);









		private:	


			y::Player* players[2];

			int size;

			std::string options[4];

			bool inGame;

			int choice;

			int n;



			void welcome();


	};


};