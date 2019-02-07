//figura.cpp
#include <math.h>
#include "figura.h"
const double pi = 4.*atan(1.);

void Figura::move(float Alpha, QPainter *Painter)
{
	dx = halflen*cos(Alpha);
	dy = halflen*sin(Alpha);
	draw(Painter);   // необходим сложный полиморфизм!
	C = cos(Alpha);
	S = sin(Alpha);
	C1 = cos(Alpha+pi/2);
	S1 = sin(Alpha + pi / 2);
	Ugol = Alpha;
}
void QuadroCircle::draw(QPainter *Painter)
{
	//QRect rect(x - halflen, y - halflen, x + halflen, y + halflen);
	//Painter->drawLine(x + dx, y + dy, x - dx, y - dy);
	Painter->drawPie(x - halflen, y - halflen, 2 * halflen, 2 * halflen, Ugol * 16, 270 * 16);


	Painter->drawPie(x - halflen-0.25, y - halflen-0.25, 2 * halflen+0.5, 2 * halflen+0.5, Ugol * 16, 270 * 16);
	Painter->drawPie(x - halflen+0.25, y - halflen+0.25, 2 * halflen-0.5, 2 * halflen-0.5, Ugol * 16, 270 * 16);
	Painter->drawPie(x - halflen-0.375, y - halflen-0.375, 2 * halflen + 0.75, 2 * halflen + 0.75, Ugol * 16, 270 * 16);
	Painter->drawPie(x - halflen+0.375, y - halflen+0.375, 2 * halflen - 0.75, 2 * halflen - 0.75, Ugol * 16, 270 * 16);
	Painter->drawPie(x - halflen - 0.45, y - halflen - 0.45, 2 * halflen + 0.9, 2 * halflen + 0.9, Ugol * 16, 270 * 16);
	Painter->drawPie(x - halflen + 0.45, y - halflen + 0.45, 2 * halflen - 0.9, 2 * halflen - 0.9, Ugol * 16, 270 * 16);
	Painter->drawPie(x - halflen-0.5, y - halflen-0.5, 2 * halflen + 1, 2 * halflen + 1, Ugol * 16, 270 * 16);
	Painter->drawPie(x - halflen+0.5, y - halflen+0.5, 2 * halflen - 1, 2 * halflen - 1, Ugol * 16, 270 * 16);
	Painter->drawPie(x - halflen - 0.625, y - halflen - 0.625, 2 * halflen + 1.25, 2 * halflen + 1.25, Ugol * 16, 270 * 16);
	Painter->drawPie(x - halflen + 0.625, y - halflen + 0.625, 2 * halflen - 1.5, 2 * halflen - 1.5, Ugol * 16, 270 * 16);

	//Painter->drawPie(x - halflen-5, y - halflen-5, 2 * halflen + 10, 2 * halflen+10, Ugol * 16, 270 * 16);
	
	

	/*QPolygon poly;
	poly << QPoint(10, 10);
	poly << QPoint(10, 100);
	poly << QPoint(100, 100);

	//QPainter painter;
	//painter.drawPolygon(poly);  //  рисуем контур фигуры

	QPainterPath path;
	path.addPolygon(poly);

	QBrush brush;
	brush.setColor(Qt::yellow);
	//QBrush brush;
	brush.setColor(Qt::yellow);
	brush.setStyle(Qt::SolidPattern);

	Painter->fillPath(path, brush);*/
}

void OneEllipse::draw(QPainter *Painter)
{
	int  x0, y0;
	int xnach, ynach;
	bool flag;



	x0 = x + halflen;
	y0 = y;
	flag = true;


	while (flag)
	{
		x0 = x0 - 1;
		if ((((x0 - x)*C + (y0 - y)*S)*((x0 - x)*C + (y0 - y)*S) / halflen / halflen + 4 * (-(x0 - x)*S + (y0 - y)*C)*(-(x0 - x)*S + (y0 - y)*C) / halflen / halflen < 1.0001) &&
			(((x0 - x)*C + (y0 - y)*S)*((x0 - x)*C + (y0 - y)*S) / halflen / halflen + 4 * (-(x0 - x)*S + (y0 - y)*C)*(-(x0 - x)*S + (y0 - y)*C) / halflen / halflen >= 0))
		{
			flag = !flag;
			/*Painter->drawLine(x + dx, y + dy, x + dy, y - dx);
			Painter->drawLine(x + dy, y - dx, x - dx, y - dy);
			Painter->drawLine(x - dx, y - dy, x - dy, y + dx);
			Painter->drawLine(x - dy, y + dx, x + dx, y + dy);*/
			/*Painter->drawPoint(x0, y0);
			xnach = x0;
			ynach = y0;*/
			Painter->drawPoint(x0, y0);
		}
	}


	x0 = x + halflen + 1;
	y0 = y;

	while (float(y0) >= (float(y - halflen)))
	{
		while (float(x0) >= float(x))
		{
			x0 = x0 - 1;
			if ((((x0 - x)*C + (y0 - y)*S)*((x0 - x)*C + (y0 - y)*S) / halflen / halflen + 4 * (-(x0 - x)*S + (y0 - y)*C)*(-(x0 - x)*S + (y0 - y)*C) / halflen / halflen < 1.0) &&
				(((x0 - x)*C + (y0 - y)*S)*((x0 - x)*C + (y0 - y)*S) / halflen / halflen + 4 * (-(x0 - x)*S + (y0 - y)*C)*(-(x0 - x)*S + (y0 - y)*C) / halflen / halflen > 0.9))
			{
				//Painter->drawLine(x + dy, y - dx, x - dx, y - dy);
				//Painter->drawLine(x - dx, y - dy, x - dy, y + dx);
				//Painter->drawLine(x - dy, y + dx, x + dx, y + dy);
				//Image.Canvas.Lineto(round(x), round(y))
				/*Painter->drawLine(xnach, ynach, x0, y0);
				xnach = x0;
				ynach = y0;*/
				Painter->drawPoint(x0, y0);
			}

		}
		y0 = y0 - 1;
		x0 = x + halflen + 1;

	}




	x0 = x + 1;
	y0 = y - halflen;

	while (float(y0) <= float(y))
	{
		while (float(x0) >= float(x - halflen))
		{
			x0 = x0 - 1;
			if ((((x0 - x)*C + (y0 - y)*S)*((x0 - x)*C + (y0 - y)*S) / halflen / halflen + 4 * (-(x0 - x)*S + (y0 - y)*C)*(-(x0 - x)*S + (y0 - y)*C) / halflen / halflen < 1.0) &&
				(((x0 - x)*C + (y0 - y)*S)*((x0 - x)*C + (y0 - y)*S) / halflen / halflen + 4 * (-(x0 - x)*S + (y0 - y)*C)*(-(x0 - x)*S + (y0 - y)*C) / halflen / halflen > 0.9))
			{
				//then Image.Canvas.Lineto(round(x), round(y));
				/*Painter->drawLine(xnach, ynach, x0, y0);
				xnach = x0;
				ynach = y0;*/
				Painter->drawPoint(x0, y0);
			}
		}
		y0 = y0 + 1;
		x0 = x + 1;

	}



	x0 = x - halflen - 1;
	y0 = y;

	while (float(y0) <= float(y + halflen))
	{
		while (float(x0) <= float(x))
		{
			x0 = x0 + 1;
			if ((((x0 - x)*C + (y0 - y)*S)*((x0 - x)*C + (y0 - y)*S) / halflen / halflen + 4 * (-(x0 - x)*S + (y0 - y)*C)*(-(x0 - x)*S + (y0 - y)*C) / halflen / halflen < 1.0) &&
				(((x0 - x)*C + (y0 - y)*S)*((x0 - x)*C + (y0 - y)*S) / halflen / halflen + 4 * (-(x0 - x)*S + (y0 - y)*C)*(-(x0 - x)*S + (y0 - y)*C) / halflen / halflen > 0.9))
			{
				//Image.Canvas.Lineto(round(x), round(y));
				/*Painter->drawLine(xnach, ynach, x0, y0);
				xnach = x0;
				ynach = y0;*/
				Painter->drawPoint(x0, y0);
			}
		}
		y0 = y0 + 1;
		x0 = x - halflen - 1;
	}



	x0 = x - 1;
	y0 = y + halflen;

	while (float(y0) >= float(y))
	{
		while (float(x0) <= float(x + halflen))
		{
			x0 = x0 + 1;
			if ((((x0 - x)*C + (y0 - y)*S)*((x0 - x)*C + (y0 - y)*S) / halflen / halflen + 4 * (-(x0 - x)*S + (y0 - y)*C)*(-(x0 - x)*S + (y0 - y)*C) / halflen / halflen < 1.0) &&
				(((x0 - x)*C + (y0 - y)*S)*((x0 - x)*C + (y0 - y)*S) / halflen / halflen + 4 * (-(x0 - x)*S + (y0 - y)*C)*(-(x0 - x)*S + (y0 - y)*C) / halflen / halflen > 0.9))
			{
				//then Image.Canvas.Lineto(round(x), round(y));
				/*Painter->drawLine(xnach, ynach, x0, y0);
				xnach = x0;
				ynach = y0;*/
				Painter->drawPoint(x0, y0);
			}
		}
		y0 = y0 - 1;
		x0 = x - 1;
	}

	
}

void TwoEllipse::draw(QPainter *Painter)
{
	int  x0, y0;
	int xnach, ynach;
	bool flag;

	/////////////////////первый эллипс
	x0 = x + halflen;
	y0 = y;
	flag = true;



	while (flag)
	{
		x0 = x0 - 1;
		if ((((x0 - x)*C + (y0 - y)*S)*((x0 - x)*C + (y0 - y)*S) / halflen / halflen + 4 * (-(x0 - x)*S + (y0 - y)*C)*(-(x0 - x)*S + (y0 - y)*C) / halflen / halflen < 1.0001) &&
			(((x0 - x)*C + (y0 - y)*S)*((x0 - x)*C + (y0 - y)*S) / halflen / halflen + 4 * (-(x0 - x)*S + (y0 - y)*C)*(-(x0 - x)*S + (y0 - y)*C) / halflen / halflen >= 0))
		{
			flag = !flag;
			/*Painter->drawLine(x + dx, y + dy, x + dy, y - dx);
			Painter->drawLine(x + dy, y - dx, x - dx, y - dy);
			Painter->drawLine(x - dx, y - dy, x - dy, y + dx);
			Painter->drawLine(x - dy, y + dx, x + dx, y + dy);*/
			/*Painter->drawPoint(x0, y0);
			xnach = x0;
			ynach = y0;*/
			Painter->drawPoint(x0, y0);
		}
	}


	x0 = x + halflen + 1;
	y0 = y;

	while (float(y0) >= (float(y - halflen)))
	{
		while (float(x0) >= float(x))
		{
			x0 = x0 - 1;
			if ((((x0 - x)*C + (y0 - y)*S)*((x0 - x)*C + (y0 - y)*S) / halflen / halflen + 4 * (-(x0 - x)*S + (y0 - y)*C)*(-(x0 - x)*S + (y0 - y)*C) / halflen / halflen < 1.0) &&
				(((x0 - x)*C + (y0 - y)*S)*((x0 - x)*C + (y0 - y)*S) / halflen / halflen + 4 * (-(x0 - x)*S + (y0 - y)*C)*(-(x0 - x)*S + (y0 - y)*C) / halflen / halflen > 0.9))
			{
				//Painter->drawLine(x + dy, y - dx, x - dx, y - dy);
				//Painter->drawLine(x - dx, y - dy, x - dy, y + dx);
				//Painter->drawLine(x - dy, y + dx, x + dx, y + dy);
				//Image.Canvas.Lineto(round(x), round(y))
				/*Painter->drawLine(xnach, ynach, x0, y0);
				xnach = x0;
				ynach = y0;*/
				Painter->drawPoint(x0, y0);
			}

		}
		y0 = y0 - 1;
		x0 = x + halflen + 1;

	}




	x0 = x + 1;
	y0 = y - halflen;

	while (float(y0) <= float(y))
	{
		while (float(x0) >= float(x - halflen))
		{
			x0 = x0 - 1;
			if ((((x0 - x)*C + (y0 - y)*S)*((x0 - x)*C + (y0 - y)*S) / halflen / halflen + 4 * (-(x0 - x)*S + (y0 - y)*C)*(-(x0 - x)*S + (y0 - y)*C) / halflen / halflen < 1.0) &&
				(((x0 - x)*C + (y0 - y)*S)*((x0 - x)*C + (y0 - y)*S) / halflen / halflen + 4 * (-(x0 - x)*S + (y0 - y)*C)*(-(x0 - x)*S + (y0 - y)*C) / halflen / halflen > 0.9))
			{
				//then Image.Canvas.Lineto(round(x), round(y));
				/*Painter->drawLine(xnach, ynach, x0, y0);
				xnach = x0;
				ynach = y0;*/
				Painter->drawPoint(x0, y0);
			}
		}
		y0 = y0 + 1;
		x0 = x + 1;

	}



	x0 = x - halflen - 1;
	y0 = y;

	while (float(y0) <= float(y + halflen))
	{
		while (float(x0) <= float(x))
		{
			x0 = x0 + 1;
			if ((((x0 - x)*C + (y0 - y)*S)*((x0 - x)*C + (y0 - y)*S) / halflen / halflen + 4 * (-(x0 - x)*S + (y0 - y)*C)*(-(x0 - x)*S + (y0 - y)*C) / halflen / halflen < 1.0) &&
				(((x0 - x)*C + (y0 - y)*S)*((x0 - x)*C + (y0 - y)*S) / halflen / halflen + 4 * (-(x0 - x)*S + (y0 - y)*C)*(-(x0 - x)*S + (y0 - y)*C) / halflen / halflen > 0.9))
			{
				//Image.Canvas.Lineto(round(x), round(y));
				/*Painter->drawLine(xnach, ynach, x0, y0);
				xnach = x0;
				ynach = y0;*/
				Painter->drawPoint(x0, y0);
			}
		}
		y0 = y0 + 1;
		x0 = x - halflen - 1;
	}



	x0 = x - 1;
	y0 = y + halflen;

	while (float(y0) >= float(y))
	{
		while (float(x0) <= float(x + halflen))
		{
			x0 = x0 + 1;
			if ((((x0 - x)*C + (y0 - y)*S)*((x0 - x)*C + (y0 - y)*S) / halflen / halflen + 4 * (-(x0 - x)*S + (y0 - y)*C)*(-(x0 - x)*S + (y0 - y)*C) / halflen / halflen < 1.0) &&
				(((x0 - x)*C + (y0 - y)*S)*((x0 - x)*C + (y0 - y)*S) / halflen / halflen + 4 * (-(x0 - x)*S + (y0 - y)*C)*(-(x0 - x)*S + (y0 - y)*C) / halflen / halflen > 0.9))
			{
				//then Image.Canvas.Lineto(round(x), round(y));
				/*Painter->drawLine(xnach, ynach, x0, y0);
				xnach = x0;
				ynach = y0;*/
				Painter->drawPoint(x0, y0);
			}
		}
		y0 = y0 - 1;
		x0 = x - 1;
	}


	

	/////////////////////второй эллипс
	x0 = x + halflen;
	y0 = y;
	flag = true;


	while (flag)
	{
		x0 = x0 - 1;
		if ((((x0 - x)*C1 + (y0 - y)*S1)*((x0 - x)*C1 + (y0 - y)*S1) / halflen / halflen + 4 * (-(x0 - x)*S1 + (y0 - y)*C1)*(-(x0 - x)*S1 + (y0 - y)*C1) / halflen / halflen < 1.0001) &&
			(((x0 - x)*C1 + (y0 - y)*S1)*((x0 - x)*C1 + (y0 - y)*S1) / halflen / halflen + 4 * (-(x0 - x)*S1 + (y0 - y)*C1)*(-(x0 - x)*S1 + (y0 - y)*C1) / halflen / halflen >= 0))
		{
			flag = !flag;
			/*Painter->drawLine(x + dx, y + dy, x + dy, y - dx);
			Painter->drawLine(x + dy, y - dx, x - dx, y - dy);
			Painter->drawLine(x - dx, y - dy, x - dy, y + dx);
			Painter->drawLine(x - dy, y + dx, x + dx, y + dy);*/
			/*Painter->drawPoint(x0, y0);
			xnach = x0;
			ynach = y0;*/
			Painter->drawPoint(x0, y0);
		}
	}


	x0 = x + halflen + 1;
	y0 = y;

	while (float(y0) >= (float(y - halflen)))
	{
		while (float(x0) >= float(x))
		{
			x0 = x0 - 1;
			if ((((x0 - x)*C1 + (y0 - y)*S1)*((x0 - x)*C1 + (y0 - y)*S1) / halflen / halflen + 4 * (-(x0 - x)*S1 + (y0 - y)*C1)*(-(x0 - x)*S1 + (y0 - y)*C1) / halflen / halflen < 1.0) &&
				(((x0 - x)*C1 + (y0 - y)*S1)*((x0 - x)*C1 + (y0 - y)*S1) / halflen / halflen + 4 * (-(x0 - x)*S1 + (y0 - y)*C1)*(-(x0 - x)*S1 + (y0 - y)*C1) / halflen / halflen > 0.9))
			{
				//Painter->drawLine(x + dy, y - dx, x - dx, y - dy);
				//Painter->drawLine(x - dx, y - dy, x - dy, y + dx);
				//Painter->drawLine(x - dy, y + dx, x + dx, y + dy);
				//Image.Canvas.Lineto(round(x), round(y))
				/*Painter->drawLine(xnach, ynach, x0, y0);
				xnach = x0;
				ynach = y0;*/
				Painter->drawPoint(x0, y0);
			}

		}
		y0 = y0 - 1;
		x0 = x + halflen + 1;

	}




	x0 = x + 1;
	y0 = y - halflen;

	while (float(y0) <= float(y))
	{
		while (float(x0) >= float(x - halflen))
		{
			x0 = x0 - 1;
			if ((((x0 - x)*C1 + (y0 - y)*S1)*((x0 - x)*C1 + (y0 - y)*S1) / halflen / halflen + 4 * (-(x0 - x)*S1 + (y0 - y)*C1)*(-(x0 - x)*S1 + (y0 - y)*C1) / halflen / halflen < 1.0) &&
				(((x0 - x)*C1 + (y0 - y)*S1)*((x0 - x)*C1 + (y0 - y)*S1) / halflen / halflen + 4 * (-(x0 - x)*S1 + (y0 - y)*C1)*(-(x0 - x)*S1 + (y0 - y)*C1) / halflen / halflen > 0.9))
			{
				//then Image.Canvas.Lineto(round(x), round(y));
				/*Painter->drawLine(xnach, ynach, x0, y0);
				xnach = x0;
				ynach = y0;*/
				Painter->drawPoint(x0, y0);
			}
		}
		y0 = y0 + 1;
		x0 = x + 1;

	}



	x0 = x - halflen - 1;
	y0 = y;

	while (float(y0) <= float(y + halflen))
	{
		while (float(x0) <= float(x))
		{
			x0 = x0 + 1;
			if ((((x0 - x)*C1 + (y0 - y)*S1)*((x0 - x)*C1 + (y0 - y)*S1) / halflen / halflen + 4 * (-(x0 - x)*S1 + (y0 - y)*C1)*(-(x0 - x)*S1 + (y0 - y)*C1) / halflen / halflen < 1.0) &&
				(((x0 - x)*C1 + (y0 - y)*S1)*((x0 - x)*C1 + (y0 - y)*S1) / halflen / halflen + 4 * (-(x0 - x)*S1 + (y0 - y)*C1)*(-(x0 - x)*S1 + (y0 - y)*C1) / halflen / halflen > 0.9))
			{
				//Image.Canvas.Lineto(round(x), round(y));
				/*Painter->drawLine(xnach, ynach, x0, y0);
				xnach = x0;
				ynach = y0;*/
				Painter->drawPoint(x0, y0);
			}
		}
		y0 = y0 + 1;
		x0 = x - halflen - 1;
	}



	x0 = x - 1;
	y0 = y + halflen;

	while (float(y0) >= float(y))
	{
		while (float(x0) <= float(x + halflen))
		{
			x0 = x0 + 1;
			if ((((x0 - x)*C1 + (y0 - y)*S1)*((x0 - x)*C1 + (y0 - y)*S1) / halflen / halflen + 4 * (-(x0 - x)*S1 + (y0 - y)*C1)*(-(x0 - x)*S1 + (y0 - y)*C1) / halflen / halflen < 1.0) &&
				(((x0 - x)*C1 + (y0 - y)*S1)*((x0 - x)*C1 + (y0 - y)*S1) / halflen / halflen + 4 * (-(x0 - x)*S1 + (y0 - y)*C1)*(-(x0 - x)*S1 + (y0 - y)*C1) / halflen / halflen > 0.9))
			{
				//then Image.Canvas.Lineto(round(x), round(y));
				/*Painter->drawLine(xnach, ynach, x0, y0);
				xnach = x0;
				ynach = y0;*/
				Painter->drawPoint(x0, y0);
			}
		}
		y0 = y0 - 1;
		x0 = x - 1;
	}



	

}
