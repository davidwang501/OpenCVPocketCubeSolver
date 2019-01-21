//
//  Solver.h
//  finalProject2
//
//  Created by David Wang on 12/10/18.
//
//

#ifndef __finalProject__Solver__
#define __finalProject__Solver__

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

#endif /* defined(__finalProject__Solver__) */

class Solver{
    
public:
    
    //constructor
    Solver(std::string cube);
    
    //number of cubie in solved cube regardless of orientation
    std::vector<int> position;
    
    // orientation of cube
    std::vector<int> rotation;
    
    std::string moveList = "";
    
    std::vector<std::string> diffMoves {"T", "F", "R", "T'", "F'", "R'"};
    
    std::string inputCube;
    
    void initalizeCube();
    
    void firstLayer();
    
    std::string secondLayer();
    
    void rotateFaces(std::vector<std::string> moves);
    
    std::vector<std::string> tryMoves(int depth);
    
    int findCubie(int cubie);
    
    std::string getColor(std::string file){
        
        
    }
};
