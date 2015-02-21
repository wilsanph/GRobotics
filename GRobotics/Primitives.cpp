#include "Primitives.hpp"


gPrimitives::Circle::Circle()
{
	this->basePoint = Point();
	this->baseAngle = 0;
	this->m_cx = 0;
	this->m_cy = 0;
	this->m_radius = 0.1;
	this->color = RGBColor();
}

gPrimitives::Circle::Circle( double cx, double cy, double radius, RGBColor color )
{
	this->basePoint = Point( cx, cy );
	this->baseAngle = 0;
	this->m_cx = cx;
	this->m_cy = cy;
	this->m_radius = radius;
	this->color = color;
}

void gPrimitives::Circle::render()
{
	glColor3f( this->color.red, this->color.green, this->color.blue );
	glBegin( GL_POLYGON );

	for ( int i = 0; i < CIRCLE_STEPS; i++ )
	{
		float theta = 2.0f * 3.1415926f * float( i ) / float( CIRCLE_STEPS );//get the current angle

		float x = this->m_radius * cosf( theta );//calculate the x component
		float y = this->m_radius * sinf( theta );//calculate the y component
		x += this->m_cx + this->basePoint.x;
		y += this->m_cy + this->basePoint.y;

		glVertex2f( x, y );//output vertex
	}

	glEnd();
}

double gPrimitives::Circle::getCx()
{
	return this->m_cx;
}

double gPrimitives::Circle::getCy()
{
	return this->m_cy;
}

double gPrimitives::Circle::getRadius()
{
	return this->m_radius;
}

void gPrimitives::Circle::setCx( double cx )
{
	this->m_cx = cx;
}

void gPrimitives::Circle::setCy( double cy )
{
	this->m_cy = cy;
}

void gPrimitives::Circle::setRadius( double radius )
{
	this->m_radius = radius;
}



gPrimitives::Quad::Quad()
{
	this->basePoint = Point();
	this->baseAngle = 0;

	this->p1 = Point();
	this->p2 = Point();
	this->p3 = Point();
	this->p4 = Point();

	this->color = RGBColor();
}

gPrimitives::Quad::Quad(
	double p1x, double p1y,
	double p2x, double p2y,
	double p3x, double p3y,
	double p4x, double p4y,
	RGBColor color )
{
	this->basePoint = Point();
	this->baseAngle = 0;

	this->p1 = Point( p1x, p1y );
	this->p2 = Point( p2x, p2y );
	this->p3 = Point( p3x, p3y );
	this->p4 = Point( p4x, p4y );
	this->color = color;
}


void gPrimitives::Quad::render()
{
	glColor3f( this->color.red, this->color.green, this->color.blue );
	glBegin( GL_QUADS );

	Point p1t, p2t, p3t, p4t;
	p1t = this->p1.rotate( this->baseAngle );
	p1t = p1t.translate( this->basePoint.x, this->basePoint.y );
	p2t = this->p2.rotate( this->baseAngle );
	p2t = p2t.translate( this->basePoint.x, this->basePoint.y );
	p3t = this->p3.rotate( this->baseAngle );
	p3t = p3t.translate( this->basePoint.x, this->basePoint.y );
	p4t = this->p4.rotate( this->baseAngle );
	p4t = p4t.translate( this->basePoint.x, this->basePoint.y );

	glVertex2f( p1t.x, p1t.y );
	glVertex2f( p2t.x, p2t.y );
	glVertex2f( p3t.x, p3t.y );
	glVertex2f( p4t.x, p4t.y );

	glEnd();
}

Point gPrimitives::Quad::getP1()
{
	return Point( this->p1.x, this->p1.y );
}

Point gPrimitives::Quad::getP2()
{
	return Point( this->p2.x, this->p2.y );
}

Point gPrimitives::Quad::getP3()
{
	return Point( this->p3.x, this->p3.y );
}

Point gPrimitives::Quad::getP4()
{
	return Point( this->p4.x, this->p4.y );
}

void gPrimitives::Quad::setP1( double p1x, double p1y )
{
	this->p1.x = p1x;
	this->p1.y = p1y;
}

void gPrimitives::Quad::setP2( double p2x, double p2y )
{
	this->p2.x = p2x;
	this->p2.y = p2y;
}

void gPrimitives::Quad::setP3( double p3x, double p3y )
{
	this->p3.x = p3x;
	this->p3.y = p3y;
}

void gPrimitives::Quad::setP4( double p4x, double p4y )
{
	this->p4.x = p4x;
	this->p4.y = p4y;
}