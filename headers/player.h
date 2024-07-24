#include <iostream>
#include "board.h"
#include "space.h"
#include "piece.h"

#pragma once

namespace y{
	
	class Player{

		public:

			Player(bool colour, std::string name);

			bool getColour();

			std::string getName();			

			int pieceCount(b::Board b);

			void insertAt(s::Space* s, int index);

			int get_arrSize();

			void printArr();

			s::Space* get(int n);


			//int* positions = new int[];
			//for positions, make dynamic array
			//add each piece position of space to array
			//make function for printing, possibly use squares
			//size of array should be equal to pieceCount


						

		
		private:

			std::string name;

			bool colour;	

			s::Space* arr[16];

			int arrSize;





	};


};