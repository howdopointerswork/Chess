#include <stdio.h>
#include <iostream>

namespace p{

    #pragma once

    class Piece{

        public:

            //int* pos; //global position


            bool colour; //colour, where 0 is white and 1 is black 

            Piece(); //no-arg constructor

            Piece(bool colour, int rank); //overloaded constructor

            void setPosition(int* arr);

            void printInfo();

            int getRank();




        
        private:
        
            int movesP; //possible moves according to pos

            int rank;

            int x;

            int y;


            



            
        
        /*
        For rank:

        0 = pawn
        1 = bishop
        2 = knight
        3 = rook
        4 = queen
        5 = king
        */

       

        //make move function that returns a board space


    };

};