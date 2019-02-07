//window.h
#pragma once
#ifndef window_h
#define window_h
#include <QtGui>
#include <iostream>
#include "area.h"
class Window : public QWidget
{
protected:
	QTextCodec *codec;
	Area * area;         // ������� ����������� �������
	QPushButton * btn;
public:
	Window();
};
#endif
