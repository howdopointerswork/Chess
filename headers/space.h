#include <iostream>
#include <stdio.h>
#include "../headers/piece.h" //add cpp here later

#pragma once 

namespace s{


    class Space{

        public:

            Space* front; //Space in front of this one

            Space* back; //Space behind this one

            Space* left; //Space left of this one

            Space* right; //Space right of this one

            p::Piece* curr;

            
            
            Space(int row, int col); //constructor

            int getRow() const;

            int getCol() const;

            int* getPosition();

            bool update(bool tf);






        private:


            int pos[2];

            int row;

            int col;

            bool occupied; //whether space is occupied




            


    };



};