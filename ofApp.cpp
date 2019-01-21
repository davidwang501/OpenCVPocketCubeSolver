#include "ofApp.h"
#include "Solver.h"
using namespace cv;
using namespace ofxCv;

//--------------------------------------------------------------
void ofApp::setup(){
    cam.initGrabber(433,300);
    
    font.load("/Users/david/Downloads/of_v0.10.0_osx_release/apps/myApps/finalProject2/bin/data/tnr.ttf",22);
    
    for(int i=0;i<24;i++){
        std::vector<int> blank;
        blank.push_back(255);
        blank.push_back(255);
        blank.push_back(255);
        faces.push_back(blank);
    }
    face=0;
    
    tempFace="";
    instructions="";
    
}

//--------------------------------------------------------------
void ofApp::update(){
    cam.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255,255,255);
    
    //draw instructions
    int counter = 0;
    int lineNumber = 0;
    std::string line = "";
    for(int i=0;i<instructions.size();i++){
        if(counter == 12){
            font.drawString(line,580,400+lineNumber*35);
            //ofDrawBitmapString(line,650,400+lineNumber*20);
            lineNumber++;
            line="";
            counter=0;
        }
        if(instructions[i]==' '){
            counter++;
            line+=instructions[i];
        }else{
            line+=instructions[i];
        }
    }
    font.drawString(line,580,400+lineNumber*35);
    //ofDrawBitmapString(line,650,400+lineNumber*20);

    
    //draw cam
    ofSetColor(255,255,255);
    cam.draw(575,15);
    
    drawColors();
    drawGrid();
    
    
    
    
}

void ofApp::drawGrid(){
    ofSetColor(0,0,0);
    ofSetLineWidth(5);
    
    //two long vertical
    ofDrawLine(207,30,207,738);
    ofDrawLine(384,30,384,738);
    
    //two long horizontal
    ofDrawLine(30,207,561,207);
    ofDrawLine(30,384,561,384);
    
    //short horizontals
    ofDrawLine(207,30,384,30);
    ofDrawLine(207,561,384,561);
    ofDrawLine(207,738,384,738);
    
    //short verticals
    ofDrawLine(30,207,30,384);
    ofDrawLine(561,207,561,384);
    
    // vertical middle lines
    ofDrawLine(295.5,30,295.5,738);
    ofDrawLine(118.5,207,118.5,384);
    ofDrawLine(472.5,207,472.5,384);
    
    //horizontal middle lines
    ofDrawLine(30,295.5,561,295.5);
    ofDrawLine(207,118.5,384,118.5);
    ofDrawLine(207,472.5,384,472.5);
    ofDrawLine(207,649.5,384,649.5);
    
    //squares in camera
    ofNoFill();
    ofSetLineWidth(2);
    ofDrawRectangle(735,100, 35, 35);
    ofDrawRectangle(735,180, 35, 35);
    ofDrawRectangle(835,100, 35, 35);
    ofDrawRectangle(835,180, 35, 35);
    
    
}

void ofApp::drawColors(){
    
    ofFill();
    //face 1
    ofSetColor(faces[0][0], faces[0][1], faces[0][2]);
    ofDrawRectangle(207,30, 88.5, 88.5);
    
    //face 2
    ofSetColor(faces[1][0], faces[1][1], faces[1][2]);
    ofDrawRectangle(295.5,30, 88.5, 88.5);
    
    //face 3
    ofSetColor(faces[2][0], faces[2][1], faces[2][2]);
    ofDrawRectangle(207,118.5, 88.5, 88.5);
    
    //face 4
    ofSetColor(faces[3][0], faces[3][1], faces[3][2]);
    ofDrawRectangle(295.5,118.5, 88.5, 88.5);
    
    //face 5
    ofSetColor(faces[4][0], faces[4][1], faces[4][2]);
    ofDrawRectangle(207,207, 88.5, 88.5);
    
    //face 6
    ofSetColor(faces[5][0], faces[5][1], faces[5][2]);
    ofDrawRectangle(295.5,207, 88.5, 88.5);
    
    //face 7
    ofSetColor(faces[6][0], faces[6][1], faces[6][2]);
    ofDrawRectangle(207,295.5, 88.5, 88.5);
    
    //face 8
    ofSetColor(faces[7][0], faces[7][1], faces[7][2]);
    ofDrawRectangle(295.5,295.5, 88.5, 88.5);
    
    //face 9
    ofSetColor(faces[8][0], faces[8][1], faces[8][2]);
    ofDrawRectangle(207,384, 88.5, 88.5);
    
    //face 10
    ofSetColor(faces[9][0], faces[9][1], faces[9][2]);
    ofDrawRectangle(295.5,384, 88.5, 88.5);
    
    //face 11
    ofSetColor(faces[10][0], faces[10][1], faces[10][2]);
    ofDrawRectangle(207,472.5, 88.5, 88.5);
    
    //face 12
    ofSetColor(faces[11][0], faces[11][1], faces[11][2]);
    ofDrawRectangle(295.5,472.5, 88.5, 88.5);
    
    //face 13
    ofSetColor(faces[12][0], faces[12][1], faces[12][2]);
    ofDrawRectangle(207,561, 88.5, 88.5);
    
    //face 14
    ofSetColor(faces[13][0], faces[13][1], faces[13][2]);
    ofDrawRectangle(295.5,561, 88.5, 88.5);
    
    //face 15
    ofSetColor(faces[14][0], faces[14][1], faces[14][2]);
    ofDrawRectangle(207,649.5, 88.5, 88.5);
    
    //face 16
    ofSetColor(faces[15][0], faces[15][1], faces[15][2]);
    ofDrawRectangle(295.5,649.5, 88.5, 88.5);

    //face 17
    ofSetColor(faces[16][0], faces[16][1], faces[16][2]);
    ofDrawRectangle(30,207, 88.5, 88.5);
    
    //face 18
    ofSetColor(faces[17][0], faces[17][1], faces[17][2]);
    ofDrawRectangle(118.5,207, 88.5, 88.5);
    
    //face 19
    ofSetColor(faces[18][0], faces[18][1], faces[18][2]);
    ofDrawRectangle(30,295.5, 88.5, 88.5);
    
    //face 20
    ofSetColor(faces[19][0], faces[19][1], faces[19][2]);
    ofDrawRectangle(118.5,295.5, 88.5, 88.5);
    
    //face 21
    ofSetColor(faces[20][0], faces[20][1], faces[20][2]);
    ofDrawRectangle(384,207, 88.5, 88.5);
    
    //face 22
    ofSetColor(faces[21][0], faces[21][1], faces[21][2]);
    ofDrawRectangle(472.5,207, 88.5, 88.5);
    
    //face 23
    ofSetColor(faces[22][0], faces[22][1], faces[22][2]);
    ofDrawRectangle(384,295.5, 88.5, 88.5);
    
    //face 24
    ofSetColor(faces[23][0], faces[23][1], faces[23][2]);
    ofDrawRectangle(472.5,295.5, 88.5, 88.5);
    
    ofNoFill();
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key==' '){
        std::cout<<"scramble: "<<scramble<<std::endl;
        tempFace="";
        
        ofImage uleft;
        uleft.grabScreen(735,100,32,32);
        uleft.save("uleft.png");
        
        ofImage dleft;
        dleft.grabScreen(735,180,32,32);
        dleft.save("dleft.png");
        
        ofImage uright;
        uright.grabScreen(835,100,32,32);
        uright.save("uright.png");
        
        ofImage dright;
        dright.grabScreen(835,180,32,32);
        dright.save("dright.png");
        
        //load in 4 squares of the face
        uleft.load("/Users/david/Downloads/of_v0.10.0_osx_release/apps/myApps/finalProject2/bin/data/uleft.png");
        uright.load("/Users/david/Downloads/of_v0.10.0_osx_release/apps/myApps/finalProject2/bin/data/uright.png");
        dleft.load("/Users/david/Downloads/of_v0.10.0_osx_release/apps/myApps/finalProject2/bin/data/dleft.png");
        dright.load("/Users/david/Downloads/of_v0.10.0_osx_release/apps/myApps/finalProject2/bin/data/dright.png");
        
        //upper left rgb values
        Mat ul = toCv(uleft);
        
        Vec3b buf1 = ul.at<Vec3b>(15,15);
        
        uchar rul = buf1.val[0];
        int rulval = rul;
        
        uchar gul = buf1.val[1];
        int gulval = gul;
        
        uchar bul = buf1.val[2];
        int bulval = bul;
        
        //std::cout<<rulval<<","<<gulval<<","<<bulval<<std::endl;
        
        //upper right rgb values
        Mat ur = toCv(uright);
        Vec3b buf2 = ur.at<Vec3b>(15,15);
        
        uchar rur = buf2.val[0];
        int rurval = rur;
        
        uchar gur = buf2.val[1];
        int gurval = gur;
        
        uchar bur = buf2.val[2];
        int burval = bur;
        
        //std::cout<<rurval<<","<<gurval<<","<<burval<<std::endl;
        
        // down left rgb values
        Mat dl = toCv(dleft);
        Vec3b buf3 = dl.at<Vec3b>(15,15);
        
        uchar rdl = buf3.val[0];
        int rdlval = rdl;
        
        uchar gdl = buf3.val[1];
        int gdlval = gdl;
        
        uchar bdl = buf3.val[2];
        int bdlval = bdl;
        
        //std::cout<<rdlval<<","<<gdlval<<","<<bdlval<<std::endl;
        
        // down right rgb values
        Mat dr = toCv(dright);
        Vec3b buf4 = dr.at<Vec3b>(15,15);
        
        uchar rdr = buf4.val[0];
        int rdrval = rdr;
        
        uchar gdr = buf4.val[1];
        int gdrval = gdr;
        
        uchar bdr = buf4.val[2];
        int bdrval = bdr;
        
        //std::cout<<rdrval<<","<<gdrval<<","<<bdrval<<std::endl;
        
        //add colors to temporary face
        tempFace+=getColor2(rulval,gulval,bulval);
        tempFace+=getColor2(rurval,gurval,burval);
        tempFace+=getColor2(rdlval,gdlval,bdlval);
        tempFace+=getColor2(rdrval,gdrval,bdrval);
        
        // for testing
//        std::cout<<"tempFace: "<<tempFace<<std::endl;
//        std::cout<<getColor2(rulval,gulval,bulval)<<std::endl;
//        std::cout<<getColor2(rurval,gurval,burval)<<std::endl;
//        std::cout<<getColor2(rdlval,gdlval,bdlval)<<std::endl;
//        std::cout<<getColor2(rdrval,gdrval,bdrval)<<std::endl;
        
        updateFaces(getColor2(rulval,gulval,bulval));
        face++;
        updateFaces(getColor2(rurval,gurval,burval));
        face++;
        updateFaces(getColor2(rdlval,gdlval,bdlval));
        face++;
        updateFaces(getColor2(rdrval,gdrval,bdrval));
        face-=3;
        
        
        // for testing
//        std::cout<<"*************"<<std::endl;
//        std::cout<<"scramble: "<<scramble<<std::endl;
//        std::cout<<"*************"<<std::endl;
        
        
//        scramble+=getColor(rulval,gulval,bulval);
//        scramble+=getColor(rurval,gurval,burval);
//        scramble+=getColor(rdlval,gdlval,bdlval);
//        scramble+=getColor(rdrval,gdrval,bdrval);
//        
//        
//        std::cout<<getColor(rulval,gulval,bulval)<<std::endl;
//        std::cout<<getColor(rurval,gurval,burval)<<std::endl;
//        std::cout<<getColor(rdlval,gdlval,bdlval)<<std::endl;
//        std::cout<<getColor(rdrval,gdrval,bdrval)<<std::endl;
//        std::cout<<"*************"<<std::endl;
//        std::cout<<"scramble: "<<scramble<<std::endl;
//        std::cout<<"*************"<<std::endl;
        
    }
    //makes temporary face permanent, goes to next face
    if(key=='n'){
        face+=4;
        scramble+=tempFace;
    }
    //done inputting all faces, print out sovling algorithm
    if(key=='d'){
        scramble+=tempFace;
        Solver s (scramble);
        s.initalizeCube();
        s.firstLayer();
        instructions=s.secondLayer();
    }
    // restart game
    if(key=='r'){
        
        //reset all values
        for(int i=0;i<24;i++){
            faces[i][0]=255;
            faces[i][1]=255;
            faces[i][2]=255;
        }
        
        face=0;
        tempFace="";
        instructions="";
        scramble="";
        
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}

// original get color method, didn't work too well
std::string ofApp::getColor(int r, int g, int b){
    
    if(r<100){
        if(g<100){
            return "b";
        }else{
            return "g";
        }
    }
    if(r>210){
        if((g>60 && g<130)&& (b>20 && b<180)){
            return "o";
        }
    }
    
    if(g>20 && g<85){
        if(b<110 && (r>120 && r<170)){
            return "r";
        }
    }
    
    if(b<145 && (r>115 && r<210) && (g>130&& g<175)){
        return "y";
    }
    
    return "w";

}

// method that returns the color of a square piece
std::string ofApp::getColor2(int r, int g, int b){
    
    //calculate lowest Euclidian distance from red, green, blue, yellow, orange, white
    std::string color =" ";
    int lowest = 100000;
    
    
    //rgb values are computed by dozens of runs, trial and error
    //red
    int r2 = 168;
    int g2 = 32;
    int b2 = 31;
    
    if(sqrt((r-r2)*(r-r2)+(g-g2)*(g-g2)+(b-b2)*(b-b2))<lowest){
        lowest = sqrt((r-r2)*(r-r2)+(g-g2)*(g-g2)+(b-b2)*(b-b2));
        color="r";
    }
    
    //orange
    r2 = 241;
    g2 = 73;
    b2 = 67;
    
    if(sqrt((r-r2)*(r-r2)+(g-g2)*(g-g2)+(b-b2)*(b-b2))<lowest){
        lowest = sqrt((r-r2)*(r-r2)+(g-g2)*(g-g2)+(b-b2)*(b-b2));
        color="o";
    }
    
    //blue
    r2 = 26;
    g2 = 29;
    b2 = 110;
    
    if(sqrt((r-r2)*(r-r2)+(g-g2)*(g-g2)+(b-b2)*(b-b2))<lowest){
        lowest = sqrt((r-r2)*(r-r2)+(g-g2)*(g-g2)+(b-b2)*(b-b2));
        color="b";
    }
    
    //green
    r2 = 69;
    g2 = 141;
    b2 = 79;
    
    if(sqrt((r-r2)*(r-r2)+(g-g2)*(g-g2)+(b-b2)*(b-b2))<lowest){
        lowest = sqrt((r-r2)*(r-r2)+(g-g2)*(g-g2)+(b-b2)*(b-b2));
        color="g";
    }
    
    //white
    r2 = 162;
    g2 = 163;
    b2 = 164;
    
    if(sqrt((r-r2)*(r-r2)+(g-g2)*(g-g2)+(b-b2)*(b-b2))<lowest){
        lowest = sqrt((r-r2)*(r-r2)+(g-g2)*(g-g2)+(b-b2)*(b-b2));
        color="w";
    }
    
    //yellow
    r2 = 153;
    g2 = 157;
    b2 = 37;
    
    if(sqrt((r-r2)*(r-r2)+(g-g2)*(g-g2)+(b-b2)*(b-b2))<lowest){
        lowest = sqrt((r-r2)*(r-r2)+(g-g2)*(g-g2)+(b-b2)*(b-b2));
        color="y";
    }
    
    return color;
    
}

//updates color of color vector with corresponding rgb values
void ofApp :: updateFaces(std::string color){
    
    if(color=="r"){
        faces[face][0]=255;
        faces[face][1]=0;
        faces[face][2]=0;
    }else if(color=="g"){
        faces[face][0]=0;
        faces[face][1]=128;
        faces[face][2]=0;
    }else if(color=="b"){
        faces[face][0]=0;
        faces[face][1]=0;
        faces[face][2]=255;
    }else if(color=="o"){
        faces[face][0]=255;
        faces[face][1]=165;
        faces[face][2]=0;
    }else if(color=="y"){
        faces[face][0]=255;
        faces[face][1]=255;
        faces[face][2]=0;
    }else{
        faces[face][0]=255;
        faces[face][1]=255;
        faces[face][2]=255;
    }
    
}


