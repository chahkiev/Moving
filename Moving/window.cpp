//window.cpp
#include "window.h"
#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSlider>
#include <QSpinBox>
#include <QPushButton>
#include <QTextCodec>
Window::Window()
{
	codec = QTextCodec::codecForName("Windows-1251");
	this->setWindowTitle(codec->toUnicode("Дз3 часть2"));
	area = new Area(this);
	btn = new QPushButton(codec->toUnicode("Завершить"), this);
	QVBoxLayout *layout = new QVBoxLayout(this);
	layout->addWidget(area);
	layout->addWidget(btn);
	connect(btn, SIGNAL(clicked(bool)), this, SLOT(close()));
};
