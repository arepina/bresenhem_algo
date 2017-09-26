#include "Figure.h"
using namespace sem1;
using namespace std;

void sem1::Figure::create_line(int x1, int y1, int x2, int y2)
{
	this->x1 = x1;
	this->x2 = x2;
	this->y1 = y1;
	this->y2 = y2;
	figure_type = FigureType::Line;
}

void sem1::Figure::create_circle(int x1, int y1, int rad)
{
	this->x1 = x1;
	this->y1 = y1;
	this->rad_first = rad;
	this->rad_second = rad;
	figure_type = FigureType::Circle;
}

void sem1::Figure::create_ellipse(int x1, int y1, int rad_1, int rad_2)
{
	this->x1 = x1;
	this->y1 = y1;
	this->rad_first = rad_1;
	this->rad_second = rad_2;
	figure_type = FigureType::Ellipse;
}

void sem1::Figure::create_rect(int x1, int y1, int x2, int y2)
{
	this->x1 = x1;
	this->x2 = x2;
	this->y1 = y1;
	this->y2 = y2;
	figure_type = FigureType::Rect;
}

FigureType sem1::Figure::getFigureType()
{
	return figure_type;
}
