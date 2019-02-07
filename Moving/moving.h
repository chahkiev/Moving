#ifndef MOVING_H
#define MOVING_H

#include <QtWidgets/QMainWindow>
#include "ui_moving.h"

class Moving : public QMainWindow
{
	Q_OBJECT

public:
	Moving(QWidget *parent = 0);
	~Moving();

private:
	Ui::MovingClass ui;
};

#endif // MOVING_H
