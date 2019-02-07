//figura.h
#pragma once
#ifndef figura_h
#define figura_h
#include <QtGui>
class Figura
{
protected:
	int x, y, halflen, dx, dy, r;
	float C, S,C1,S1,Ugol;
	virtual void draw(QPainter *Painter) = 0;
public:
	Figura(int X, int Y, int Halflen) :
		x(X), y(Y), halflen(Halflen) {}
	void move(float Alpha, QPainter *Painter);
};

class QuadroCircle :public Figura
{
protected:
	void draw(QPainter *Painter);
public:
	QuadroCircle(int x, int y, int halflen) :Figura(x, y, halflen) {}
};
class OneEllipse :public Figura
{
protected:
	void draw(QPainter *Painter);
public:
	OneEllipse(int x, int y, int halflen) :Figura(x, y, halflen) {}
};

class TwoEllipse :public Figura
{
protected:
	void draw(QPainter *Painter);
public:
	TwoEllipse(int x, int y, int halflen) :Figura(x, y, halflen) {}
};
#endif

