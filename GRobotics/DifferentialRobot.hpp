#ifndef DIFFERENTIALROBOT_HPP_
#define DIFFERENTIALROBOT_HPP_

#include "BaseRobot.hpp"

class DifferentialRobot : public BaseRobot
{
public:

	DifferentialRobot();
	DifferentialRobot( double x, double y, double theta );
	
	// overwritten functions
	void init();
	void motionModel( double dt );

	double getWheelRadius();

	void setLinearVelocity( double v );
	void setAngularVelocity( double w );

	double getLinearVelocity();
	double getAngularVelocity();

private:
	double m_wheelRadius;
	double v;
	double w;

};


#endif