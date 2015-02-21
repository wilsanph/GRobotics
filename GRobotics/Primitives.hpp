#ifndef PRIMITIVES_HPP_
#define PRIMITIVES_HPP_

#include "Node.hpp"

#define CIRCLE_STEPS 20

namespace gPrimitives
{

	class Circle : public Node
	{
	public:
		Circle();
		Circle( double cx, double cy, double radius, RGBColor color );
		void render();

		double getCx();
		double getCy();
		double getRadius();

		void setCx( double cx );
		void setCy( double cy );
		void setRadius( double radius );

	private:
		double m_cx;
		double m_cy;
		double m_radius;
	};

	class Quad : public Node
	{
	public:
		Quad();
		Quad( double p1x, double p1y,
			  double p2x, double p2y,
			  double p3x, double p3y,
			  double p4x, double p4y,
			  RGBColor color);

		void render();

		Point getP1();
		Point getP2();
		Point getP3();
		Point getP4();

		void setP1( double p1x, double p1y );
		void setP2( double p2x, double p2y );
		void setP3( double p3x, double p3y );
		void setP4( double p4x, double p4y );
	private:
		Point p1;
		Point p2;
		Point p3;
		Point p4;
	};

}

#endif