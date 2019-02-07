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
	setFixedSize(QSize(920, 400)); // ��������� ������ ������
	quadrocircle = new QuadroCircle(160, 200, 100);  // ������� ������ �����
	oneellipse = new OneEllipse(440, 200, 100); // ������� ������ �������
	twoellipse = new TwoEllipse(760,200,100); // ������� ������ �������1
	alpha = 0;
}
void Area::showEvent(QShowEvent *)
{
	myTimer = startTimer(50);      // �������� ������
}
void Area::paintEvent(QPaintEvent *)
{
	QPainter painter(this);    // ������� ������� ��������� �� ������
	
	QFont font;
	font.setPixelSize(5);
	painter.setFont(font);// ������ ������� ����
	painter.setPen(Qt::red);
	quadrocircle->move(alpha*(-100), &painter);
	painter.setPen(Qt::yellow);
	oneellipse->move(alpha*(-2), &painter); 
	painter.setPen(Qt::green);
	twoellipse->move(alpha*(1.5), &painter);   
}
void Area::timerEvent(QTimerEvent *event)
{
	if (event->timerId() == myTimer) // ���� ��� ������
	{
		alpha = alpha + 0.2;
		update();        // �������� ������� ���
	}
	else
		QWidget::timerEvent(event);  // ����� �������� �����
}
void Area::hideEvent(QHideEvent *)
{
	killTimer(myTimer);  // ��������� ������
}
Area::~Area()
{
	delete quadrocircle;
	delete oneellipse;
	delete twoellipse;
}
