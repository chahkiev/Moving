//area.h
#pragma once
#include "figura.h"
#ifndef area_h
#define area_h
#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSlider>
#include <QSpinBox>
#include <QPushButton>
#include <QTextCodec>
class Area : public QWidget
{
	int myTimer; // идентификатор таймера
	float alpha; // угол поворота
public:
	Area(QWidget *parent = 0);
	~Area();
	QuadroCircle *quadrocircle;
	OneEllipse *oneellipse;
	TwoEllipse *twoellipse;

protected:
	//	обработчики событий
	void paintEvent(QPaintEvent *event);
	void timerEvent(QTimerEvent *event);
	void showEvent(QShowEvent *event);
	void hideEvent(QHideEvent *event);
};
#endif

