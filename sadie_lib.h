#include"glglobal.h"
#include<cmath>

#ifndef SADIELIB_H
#define SADIELIB_H

////HEADER FILE FOR MY PERSONAL GRAPHICS LIBRARY

//mouse handler
void podrmo(int,int,int,int); // POlyline DRaw MOuse
/////button,state,x,y
//possible buttons: GLUT_LEFT_BUTTON,GLUT_RIGHT_BUTTON,GLUT_MIDDLE_BUTTON
//possible states: GLUT_UP,GLUT_DOWN

void pointclick(int,int,int,int);//makes point on click (obvi)
/////button,state,x,y
//point class for drawing

void qexit(unsigned char,int,int);//exit window with press of q
void drawRecCenter(int,int,int,int);//takes center x,center y,width,height
void newLine(int,int,int,int);
void randcolor();
void screensize(char*,int&,int&);

class point{
	public:
		point(double,double);
		point();
		void print();
		double x; 
		double y;
 };
 
void drawRec(point,point);

#endif
