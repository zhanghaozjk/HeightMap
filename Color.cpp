#include "Color.h"

Color::Color()
{
	this->r = 0;
	this->g = 0;
	this->b = 0;
}

Color::Color(short r, short g, short b)
{
	this->r = r;
	this->g = g;
	this->b = b;
}

void Color::setColor(short r, short g, short b)
{
	this->r = r;
	this->g = g;
	this->b = b;
}

Color::~Color()
{
}
