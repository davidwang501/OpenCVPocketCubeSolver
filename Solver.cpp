//
//  Solver.cpp
//  finalProject2
//
//  Created by David Wang on 12/10/18.
//
//

#include "Solver.h"
Solver::Solver(std::string cube):inputCube(cube), position(8), rotation(8){};

// initalizes input string cube`

void Solver :: initalizeCube(){
    
    // string to char vector
    // from stackoverflow.com/questions/8263926/how-to-copy-stdstring-into-stdvectorchar
    
    std::vector<char> input(inputCube.begin(),inputCube.end());
    
    
    std::vector<std::vector<char>> cubies;
    
    std::vector<char> temp1 {input[0], input[16], input[14]};
    cubies.push_back(temp1);
    
    std::vector<char> temp2 {input[1], input[15], input[21]};
    cubies.push_back(temp2);
    
    std::vector<char> temp3 {input[2], input[4], input[17]};
    cubies.push_back(temp3);
    
    std::vector<char> temp4 {input[3], input[20], input[5]};
    cubies.push_back(temp4);
    
    std::vector<char> temp5 {input[10], input[12], input[18]};
    cubies.push_back(temp5);
    
    std::vector<char> temp6 {input[11], input[23], input[13]};
    cubies.push_back(temp6);
    
    std::vector<char> temp7 {input[8], input[19], input[6]};
    cubies.push_back(temp7);
    
    std::vector<char> temp8 {input[9], input[7], input[22]};
    cubies.push_back(temp8);
    
    
    //all possible orientations for correct cubie placements
    //3 possible orientations for each of the 8 cubies
    std::vector<std::vector<char>> cubieOrientations{
        {'y', 'r', 'b'}, {'r', 'b', 'y'}, {'b', 'y', 'r'},
        {'y', 'b', 'o'}, {'b', 'o', 'y'}, {'o', 'y', 'b'},
        {'y', 'g', 'r'}, {'g', 'r', 'y'}, {'r', 'y', 'g'},
        {'y', 'o', 'g'}, {'o', 'g', 'y'}, {'g', 'y', 'o'},
        {'w', 'b', 'r'}, {'b', 'r', 'w'}, {'r', 'w', 'b'},
        {'w', 'o', 'b'}, {'o', 'b', 'w'}, {'b', 'w', 'o'},
        {'w', 'r', 'g'}, {'r', 'g', 'w'}, {'g', 'w', 'r'},
        {'w', 'g', 'o'}, {'g', 'o', 'w'}, {'o', 'w', 'g'}
    };
    
    
    for(int i=0;i<8;i++){
        int index = 0;
        while(true){
            if(cubies[i]==cubieOrientations[index]){
                break;
            }
            index++;
        }
        position[i] = index/3;
        rotation[i] = index%3;
        
    }
    
}


// unfinished dfs solution
//std::vector<std::string> Solver :: tryMoves(int depth){
//    std::vector<std::string> answer {"NA"};
//    std::vector<int> startPos(8);
//    std::vector<int> startRot(8);
//    startPos=position;
//    startRot=rotation;
//
//    std::string sits ="";
//    for(int s=0;s<depth;++s){
//        sits+="5";
//    }
//
//    for(long i=0; i<= std::stol(sits,nullptr,6);++i){
//        position=startPos;
//        rotation=startRot;
//        std::string moveString = std::to_string(i);
//        std::vector<std::string> moves (moveString.length());
//        std::cout<<moveString<<std::endl;
//        for(int d=0;d<moveString.length();++d){
//            std::string temp = moveString.substr(d,d+1);
//            //std::cout<<temp<<std::endl;
//            int index = std::stoi(temp);
//
//            std::string move = diffMoves[index];
//            moves[d]= move;
//        }
//        rotateFaces(moves);
//        int correctCount=0;
//
//        for(int number=0;number<8;++number){
//            if(position[i]==number&&rotation[number]==0){
//                correctCount++;
//            }
//        }
//        if(correctCount==8){
//            answer=moves;
//            break;
//        }
//
//    }
//    position=startPos;
//    rotation=startRot;
//    return answer;
//
//}




// move cubies 5,6,7 to correct positions and orientations to solve first layer (white on bottom)
void Solver :: firstLayer(){
    // move cubie 6 to correct position
    if (!(position[6] == 6)){
        int sixpos = findCubie(6);
        //if it's on the bottom
        if (sixpos > 3){
            
            std::vector<std::string> move {"R","R"};
            //Now it must be on the top
            rotateFaces(move);
            sixpos = findCubie(6);
        }
        //rotate into correct top position
        while (position[2] != 6){
            std::vector<std::string> move {"T"};
            rotateFaces(move);
        }
        
        //bring down to bottom
        std::vector<std::string> down {"F'"};
        rotateFaces(down);
    }
    
    
    //move cubie 7 to correct position
    if (!(position[7] == 7)){
        //if cubie 7 is in bottom back right
        if (position[5] == 7){
            std::vector<std::string> right {"R"};
            rotateFaces(right);
            
        }else {
            //must be on top
            //rotate top until it is above the correct bottom layer position
            while (position[3] != 7){
                std::vector<std::string> top {"T"};
                rotateFaces(top);
            }
            //flip it down to the correct bottom layer position
            std::vector<std::string> down {"R'"};
            rotateFaces(down);
        }
    }
    
    
    
    //move cubie 5 to correct position
    if (position[5] != 5){
        //Must be on top, so rotate top into top front left, then slide down and back
        while (position[3] != 5){
            std::vector<std::string> top {"T"};
            rotateFaces(top);
            
        }
        //slide down and back
        std::vector<std::string> slide {"F", "R'", "F'"};
        rotateFaces(slide);
    }
    
    
    // rotate cubies 5,7,6 to correct orientations
    
    while (rotation[5] != 0 || position[5] != 5){
        std::vector<std::string> move {"F", "R", "F'", "T'"};
        rotateFaces(move);
    }
    
    while (rotation[7] != 0 || position[7] != 7){
        std::vector<std::string> move {"R", "T", "R'", "T'"};
        rotateFaces(move);
    }
    
    while (rotation[6] != 0 || position[6] != 6){
        std::vector<std::string> move {"F", "T", "F'", "T'"};
        rotateFaces(move);
    }
    
    moveList+="First Layer Done ";
}

// move cubies 0-3 to correct positions and orientations to solve top/final layer

std::string Solver:: secondLayer(){
    // move cubie 1 to correct position
    while (position[1] != 1){
        std::vector<std::string> top {"T"};
        rotateFaces(top);
    }
    // orient remaining top cubies (0,2,3)
    // cubies are all in incorrect positions
    if (position[0] != 0 && position[2] != 2 && position[3] != 3){
        while (position[0] != 0){
            std::vector<std::string> alg {"T", "T", "R", "T'", "R'", "F", "R'", "F'", "R", "T'"};
            rotateFaces(alg);
        }
    }
    // swap the two corners
    else if (position[0] != 0 && position[3] != 3){
        std::vector<std::string> alg {"F", "R", "T", "R'", "T'", "F'", "T"};
        rotateFaces(alg);
    }
    // swap the left half
    else if (position[0] != 0 && position[2] != 2){
        std::vector<std::string> alg {"T'", "R", "T'", "R'", "T'", "F'", "T", "F", "T"};
        rotateFaces(alg);
    }
    // swap the front half
    else if (position[2] != 2 && position[3] != 3) {
        std::vector<std::string> alg {"R", "T'", "R'", "T'", "F'", "T", "F"};
        rotateFaces(alg);
    }
    
    // orient all top layer cubies now that they are in the correct position
    std::vector<std::string> top {"T"};
    rotateFaces(top);
    
    for (int x = 0; x < 4; x++){
        int thisCubie;
        if (x == 2){
            thisCubie = 3;
        }
        else if (x == 3) {
            thisCubie = 2;
        }
        else {
            thisCubie = x;
        }
        
        while (!(rotation[1] == 0 && position[1] == thisCubie)){
            std::vector<std::string> alg {"R", "T", "F'", "T'"};
            rotateFaces(alg);
        }
        std::vector<std::string> reverseTop {"T'"};
        rotateFaces(reverseTop);
    }
    
    //turn top to match bottom
    while (position[0] != 0){
        rotateFaces(top);
    }
    
    //print steps
    std::cout<<moveList<<std::endl;
    return moveList;
    
}


void Solver :: rotateFaces(std::vector<std::string> moves){
    for(int i=0;i<moves.size();i++){
        
        std::string s = moves[i];
        
        if(s=="F"){
            std::vector<int> tempCubiesPos{position[0], position[1], position[6], position[2], position[4], position[5], position[7], position[3]};
            std::vector<int> tempCubiesRot{rotation[0], rotation[1], (rotation[6]+1) % 3, (rotation[2]+2) % 3, rotation[4], rotation[5], (rotation[7]+2) % 3, (rotation[3]+1) % 3};
            
            
            position=tempCubiesPos;
            rotation=tempCubiesRot;
            moveList+="F ";
            
        }else if(s=="R"){
            
            std::vector<int> tempCubiesPos{position[0], position[3], position[2], position[7], position[4], position[1], position[6], position[5]};
            std::vector<int> tempCubiesRot{rotation[0], (rotation[3]+2) % 3, rotation[2], (rotation[7]+1) % 3, rotation[4], (rotation[1]+1) % 3, rotation[6], (rotation[5]+2) % 3};
            position=tempCubiesPos;
            rotation=tempCubiesRot;
            moveList+="R ";
            
        }else if(s=="T"){
            
            std::vector<int> tempCubiesPos{position[2], position[0], position[3], position[1], position[4], position[5], position[6], position[7]};
            std::vector<int> tempCubiesRot{rotation[2], rotation[0], rotation[3], rotation[1], rotation[4], rotation[5], rotation[6], rotation[7]};
            position=tempCubiesPos;
            rotation=tempCubiesRot;
            moveList+="T ";
            
        }else if(s=="F'"){
            
            std::vector<int> tempCubiesPos{position[0], position[1], position[3], position[7], position[4], position[5], position[2], position[6]};
            std::vector<int> tempCubiesRot{rotation[0], rotation[1], (rotation[3]+1) % 3, (rotation[7]+2) % 3, rotation[4], rotation[5], (rotation[2]+2) % 3, (rotation[6]+1) % 3};
            position=tempCubiesPos;
            rotation=tempCubiesRot;
            moveList+="F' ";
            
        }else if(s=="R'"){
            
            std::vector<int> tempCubiesPos{position[0], position[5], position[2], position[1], position[4], position[7], position[6], position[3]};
            std::vector<int> tempCubiesRot{rotation[0], (rotation[5]+2) % 3, rotation[2], (rotation[1]+1) % 3, rotation[4], (rotation[7]+1) % 3, rotation[6], (rotation[3]+2) % 3};
            position=tempCubiesPos;
            rotation=tempCubiesRot;
            moveList+="R' ";
            
        }else if(s=="T'"){
            
            std::vector<int> tempCubiesPos{position[1], position[3], position[0], position[2], position[4], position[5], position[6], position[7]};
            std::vector<int> tempCubiesRot{rotation[1], rotation[3], rotation[0], rotation[2], rotation[4], rotation[5], rotation[6], rotation[7]};
            position=tempCubiesPos;
            rotation=tempCubiesRot;
            moveList+="T' ";
            
        }else{
            break;
        }
        
    }
    
}

// returns position of given cubie
int Solver :: findCubie(int cubie){
    
    int i = 0;
    
    while(true){
        if(position[i]==cubie){
            break;
        }
        i++;
    }
    return i;
    
}