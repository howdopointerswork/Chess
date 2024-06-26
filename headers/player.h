#include <iostream>
#include "board.h"
#include "space.h"
#include "piece.h"


namespace y{
	
	class Player{

		public:

			Player(bool colour, std::string name);

			bool getColour();

			std::string getName();			

			int pieceCount(b::Board b);

			

		
		private:

			std::string name;


			bool colour; 	





	};


};