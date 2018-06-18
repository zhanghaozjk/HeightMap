#pragma once
class Color
{
public:
	Color();
	Color(short r, short g, short b);
	void setColor(short r, short g, short b);
	~Color();
	short r;
	short g;
	short b;
};

