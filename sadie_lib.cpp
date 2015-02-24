#include"glglobal.h"
#include<iostream>
#include<fstream>
#include<cmath>
#include<vector>
#include"sadielib.h"
using namespace std;

vector<point> list;
vector<point>::iterator li;
void podrmo(int button,int state,int x,int y){ //POlyline DRaw MOuse
	
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
		int height=glutGet(GLUT_WINDOW_HEIGHT);
		list.push_back(point(x,height-y));
		glClear(GL_COLOR_BUFFER_BIT);
		glBegin(GL_LINE_STRIP);
		glColor3f(1.0,1.0,1.0);
		for(li=list.begin();li!=list.end();li++){
						glVertex2i(li->x,li->y);
		}
		glEnd();
		glFlush();
	} else if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN){
			list.clear();
			glutPostRedisplay();
	}
}

void screensize(char* dino,int& W,int& H){
	ifstream ff;
	ff.open(dino);
	if(ff.fail()){
		cout << "Error in creating window\n";
		return;
	} 
	int lines,curline,x,y,xmax=0,ymax=0;
	ff >> lines;
	for(int i=0;i<lines;i++){
		ff >> curline;
		for(int j=0;j<curline;j++){
			ff >> x >> y;
			if(x>xmax){
				xmax=x;
			} if(y>ymax){
				ymax=y;
			}
		}
	}
	W=xmax+10;
	H=ymax+10;
	ff.close();
}

void pclick(unsigned char key,int x,int y){
	int height=glutGet(GLUT_WINDOW_HEIGHT);
	list.push_back(point(x,height-y));
	glClear(GL_COLOR_BUFFER_BIT);
	if(key=='c'){
		glBegin(GL_LINE_LOOP);
	} else{
		glBegin(GL_POINTS);
		glColor3f(1.0,1.0,1.0);
		for(li=list.begin();li!=list.end();li++){
				glVertex2i(li->x,li->y);
		}
		glEnd();
		glFlush();
	}
} 

void qexit(unsigned char key,int x,int y){
	if(key=='q'){
		exit(0);
	}
}

point::point(double b,double c){
	x=b;
	y=c;
}

void point::print(){
	cout << "(" << this->x << "," << this->y << ")\n";
}

point::point(){
	x=0.0;
	y=0.0;
}

const double PHI=370/599;
void drawRec(point a,point b){
	glBegin(GL_LINE_LOOP);
	glVertex2d(a.x,a.y);
	glVertex2d(a.x,b.y);
	glVertex2d(b.x,b.y);
	glVertex2d(b.x,a.y);
	glEnd();
}

void drawRecCenter(int x,int y,int w,int h){
	double halfw=w/2;
	double halfh=h/2;
	double x1=x-halfw;
	double y1=y+halfh;
	double x2=x-halfw;
	double y2=y-halfh;
	double x3=x+halfw;
	double y3=y-halfh;
	double x4=x+halfw;
	double y4=y+halfh;
	//glColor3f(0.8f,0.2f,0.8f);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2d(x1,y1);
	glVertex2d(x2,y2);
	glVertex2d(x3,y3);
	glVertex2d(x4,y4);
	glEnd();
}
void randcolor(){
	srand(time(0));
	GLfloat a=rand()%100/100;
	GLfloat b=rand()%100/100;
	GLfloat c=rand()%100/100;
	glColor3f(a,b,c);
}
void newLine(int x1,int y1,int x2,int y2){
	int height=glutGet(GLUT_WINDOW_HEIGHT);
	glVertex2i(x1,height-y1);
	glVertex2i(x2,height-y2);
}
