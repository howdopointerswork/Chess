#include <stdio.h>
#include <iostream>

namespace p{

    #pragma once

    class Piece{

        public:

            //int* pos; //global position


            //WILL NEED:

            //i = 0
            //j = 0 or 7
            //rank = 1

            //i = 0
            //j = 2 or 6
            //rank = 2

            //i = 0
            //j = 3 or 5
            //rank = 3

            //i = 0
            //j = 4
            //rank = 4

            //i = 0
            //j = 5
            //rank = 5

            //colour = 0

            //i = 1
            //rank = 0
            //colour = 0


            //and then i = 6 should reflect i =1
            //and 7 to 0

    
            //change to private and use getter
            bool colour; //colour, where 0 is white and 1 is black 
            //change to int maybe

            Piece(); //no-arg constructor

            Piece(bool colour, int rank, int x, int y); //overloaded constructor

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
        1 = rook
        2 = knight
        3 = bishop
        4 = queen
        5 = king
        */

       

        //make move function that returns a board space


    };

};