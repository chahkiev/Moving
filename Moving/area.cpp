//area.cpp
#include "area.h"
#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSlider>
#include <QSpinBox>
#include <QPushButton>
#include <QTextCodec>
Area::Area(QWidget *parent) :QWidget(parent)
{
	setFixedSize(QSize(920, 400)); // фиксируем размер Холста
	quadrocircle = new QuadroCircle(160, 200, 100);  // создаем объект Линия
	oneellipse = new OneEllipse(440, 200, 100); // создаем объект Квадрат
	twoellipse = new TwoEllipse(760,200,100); // создаем объект Квадрат1
	alpha = 0;
}
void Area::showEvent(QShowEvent *)
{
	myTimer = startTimer(50);      // включаем таймер
}
void Area::paintEvent(QPaintEvent *)
{
	QPainter painter(this);    // создаем контент рисования на Холсте
	
	QFont font;
	font.setPixelSize(5);
	painter.setFont(font);// задаем красное Перо
	painter.setPen(Qt::red);
	quadrocircle->move(alpha*(-100), &painter);
	painter.setPen(Qt::yellow);
	oneellipse->move(alpha*(-2), &painter); 
	painter.setPen(Qt::green);
	twoellipse->move(alpha*(1.5), &painter);   
}
void Area::timerEvent(QTimerEvent *event)
{
	if (event->timerId() == myTimer) // если наш таймер
	{
		alpha = alpha + 0.2;
		update();        // обновить внешний вид
	}
	else
		QWidget::timerEvent(event);  // иначе передать далее
}
void Area::hideEvent(QHideEvent *)
{
	killTimer(myTimer);  // выключить таймер
}
Area::~Area()
{
	delete quadrocircle;
	delete oneellipse;
	delete twoellipse;
}
