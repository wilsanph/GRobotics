

#include "BaseRobot.hpp"


BaseRobot::BaseRobot()
{
	this->m_x = 0;
	this->m_y = 0;
	this->m_vx = 1;
	this->m_vy = 0;
	this->m_theta = 0;
	this->init();
}

BaseRobot::BaseRobot( double x, double y, double theta )
{
	this->m_x = x;
	this->m_y = y;
	this->m_vx = 1;
	this->m_vy = 1;
	this->m_theta = theta;
	this->init();
}

void BaseRobot::init()
{
	this->m_graphicsComponent = new BaseGraphicsComponent( this );
	
}

void BaseRobot::motionModel( double dt )
{
	this->m_x += this->m_vx * dt;
	this->m_y += this->m_vy * dt;
	this->m_theta = std::atan2( this->m_vy, this->m_vx );
}

void BaseRobot::update( double dt )
{
	this->motionModel( dt );
}

void BaseRobot::render()
{
	this->m_graphicsComponent->render();
}

/******************************************************
* Getters and setters
*******************************************************/

double BaseRobot::getX()
{	
	return this->m_x;
}

double BaseRobot::getY()
{
	return this->m_y;
}

double BaseRobot::getSpeedX()
{
	return this->m_vx;
}

double BaseRobot::getSpeedY()
{
	return this->m_vy;
}

double BaseRobot::getTheta()
{
	return this->m_theta;
}

BaseGraphicsComponent* BaseRobot::getGraphicsComponent()
{
	return this->m_graphicsComponent;
}


void BaseRobot::setX( double x )
{
	this->m_x = x;
}

void BaseRobot::setY( double y )
{
	this->m_y = y;
}

void BaseRobot::setSpeedX( double vx )
{
	this->m_vx = vx;
}

void BaseRobot::setSpeedY( double vy )
{
	this->m_vy = vy;
}

void BaseRobot::setTheta( double theta )
{
	this->m_theta = theta;
}
