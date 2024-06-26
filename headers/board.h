#include <iostream>
#include <stdio.h>
#include "space.h"
#include "piece.h"

#pragma once

namespace b{

    class Board{

    	public:    

            Board(); //no-arg constructor - malloc here

            p::Piece* findPiece(int x, int y); //find piece on board by Space coordinate

            s::Space* getSpace(int x, int y);

            void moveScan(int rank);

            int getSize();







        private:

        	int size;
        	
        	s::Space* spaces[8][8]; //board for holding spaces

            p::Piece* chessSet[32];

            //move function here

            //others here

            void makeSpaces(int n);

            void connectSpaces();

            void makeChessSet();

            void populate();

        







  

    };

};