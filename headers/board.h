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

            void moveScan(s::Space* s);

            int colourCheck(p::Piece* p);

            void swap(s::Space* p1, s::Space* p2, int i, int j);

            int getSize();

            p::Piece* getPiece(int index);

            p::Piece* chessSet[32];






        private:

        	int size;
        	
        	s::Space* spaces[8][8]; //board for holding spaces

           

            //move function here

            //others here

            void makeSpaces(int n);

            void connectSpaces();

            void makeChessSet();

            void populate();

            int moveCheck(s::Space* current, s::Space* check);

            void addShift(s::Space* from, s::Space* to, p::Piece* src);

            int boundCheck(s::Space* s);








  

    };

};