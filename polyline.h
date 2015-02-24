#include"glglobal.h"
#include"sadielib.h"
#include<vector>

#ifndef POLYLINE_H
#define POLYLINE_H


class segment{
	friend class polyLine;
	public:
		segment();
		segment(int,int);
		void newpoint(point);
		void clear();
		void print();
		void draw();
	protected:
		std::vector<point> seg;
};

class polyLine{
	public:
		polyLine();
		polyLine(segment);
		void newseg(segment);
		void draw(char*);
	private:
		int linenum;
		std::vector<segment> picture;
};

#endif
