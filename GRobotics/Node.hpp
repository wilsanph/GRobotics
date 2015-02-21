#ifndef NODE_HPP_
#define NODE_HPP_

#include "Common.hpp"

class Node
{
public:
	Node();
	virtual void render();
	void update( double dt );
	Point basePoint;
	double baseAngle;
	void setBasePoint( double x, double y );
	void setBaseAngle( double angle );
protected:
	RGBColor color;
};

#endif