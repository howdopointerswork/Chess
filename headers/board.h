#include <iostream>
#include <stdio.h>
#include "space.h"
#include "piece.h"


namespace b{

    class Board{

    	public:    

            Board(); //no-arg constructor - malloc here

            p::Piece* findPiece(int x, int y); //find piece on board by Space coordinate

            s::Space* getSpace(int x, int y);


        private:

        	int size;
        	
        	s::Space* spaces[8][8]; //board for holding spaces



        	Board insert(s::Space s, int col, int row); //overloaded constructor

        	int checkPieces();

        	int checkPieces_Colour(); //perhaps make this and above public


        	







  

    };

};