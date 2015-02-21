#ifndef COMMON_HPP_
#define COMMON_HPP_

#pragma once

#include "math.h"
#include "glfw3.h"
#include <vector>

#endif /* COMMON_HPP_ */


class Point
{
public:

	Point()
	{
		this->x = 0;
		this->y = 0;
	}

	Point( double x, double y )
	{
		this->x = x;
		this->y = y;
	}

	Point translate( double x, double y )
	{
		return Point( this->x + x, this->y + y );
	}

	Point rotate( double angle )
	{
		return Point(
			this->x * std::cos( angle ) - this->y * std::sin( angle ),
			this->x * std::sin( angle ) + this->y * std::cos( angle ) );
	}

	double x;
	double y;
};


class RGBColor
{

public:
	RGBColor()
	{
		this->red = 0;
		this->green = 0;
		this->blue = 0;
	}
	RGBColor( double red, double green, double blue )
	{
		this->red = red;
		this->green = green;
		this->blue = blue;
	}
	double red;
	double green;
	double blue;

};