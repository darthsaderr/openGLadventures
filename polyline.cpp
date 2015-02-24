#include "glglobal.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "sadielib.h"
#include "polyline.h"
using namespace std;

//////////////////////////////POLYLINE CLASS IMPLEMENTATION////////////
polyLine::polyLine(){
	linenum=0;
	picture.clear();
}

polyLine::polyLine(segment a){
	linenum=1;
	picture.push_back(a);
}

void polyLine::newseg(segment a){
	picture.push_back(a);
}

void polyLine::draw(char* filename){
	ifstream fin;
	fin.open(filename);
	if(fin.fail()){
		cout << "Unable to open file.\n";
	}
	int points,x,y,lines;
	segment S;
	fin >> lines;
	for(int i=0;i<lines;i++){
		fin >> points;
		for(int j=0;j<points;j++){
			fin >> x >> y;
			S.newpoint(point(x,y));
		} 
		this->newseg(S);
		S.clear();
	}
	vector<point>::iterator spi;
	glBegin(GL_LINE_STRIP);
	for(int k=0;k<lines;k++){
		picture[k].draw();
		//picture[k].print();
	}
	glEnd();
	glFlush();
	fin.close();
}
////////////////////////SEGMENT CLASS IMPLEMENTATION/////////////////
segment::segment(){}

segment::segment(int x,int y){
	seg.push_back(point(x,y));
}

void segment::newpoint(point a){
	seg.push_back(a);
}
