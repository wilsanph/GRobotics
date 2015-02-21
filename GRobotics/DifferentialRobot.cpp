

#include "DifferentialRobot.hpp"


DifferentialRobot::DifferentialRobot()
	: BaseRobot()
{
	BaseRobot();
	this->v = 1;
	this->w = 1;
}

DifferentialRobot::DifferentialRobot( double x, double y, double theta )
	: BaseRobot( x, y, theta )
{
	BaseRobot( x, y, theta );
	this->v = 2;
	this->w = 0.5;
}

void DifferentialRobot::init()
{
	this->m_wheelRadius = 0.05;
	//this->m_graphicsComponent;
}

void DifferentialRobot::motionModel( double dt )
{
	// TODO: Modify this approximate model by the real derived one
	double dTheta = this->w * dt;
	double dx = ( this->v / this->w ) * ( std::sin( this->m_theta ) - std::sin( this->m_theta - dTheta ) );
	double dy = ( this->v / this->w ) * ( -std::cos( this->m_theta ) + std::cos( this->m_theta - dTheta ) );
	this->m_x += dx;
	this->m_y += dy;
	this->m_theta += dTheta;
}


double DifferentialRobot::getWheelRadius()
{
	return this->m_wheelRadius;
}


void DifferentialRobot::setLinearVelocity( double v )
{
	this->v = v;
}

void DifferentialRobot::setAngularVelocity( double w )
{
	this->w = w;
}

double DifferentialRobot::getLinearVelocity()
{
	return this->v;
}

double DifferentialRobot::getAngularVelocity()
{
	return this->w;
}