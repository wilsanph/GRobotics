#include "Node.hpp"

Node::Node()
{
	this->basePoint = Point( 0, 0 );
	this->baseAngle = 0;
}

void Node::render()
{

}

void Node::update( double dt )
{

}

void Node::setBasePoint( double x, double y )
{
	this->basePoint.x = x;
	this->basePoint.y = y;
}

void Node::setBaseAngle( double angle )
{
	this->baseAngle = angle;
}