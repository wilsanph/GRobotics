#ifndef BASEROBOT_HPP_
#define BASEROBOT_HPP_

#include "Common.hpp"
#include "BaseGraphicsComponent.hpp"

class BaseGraphicsComponent;

class BaseRobot
{

public:
	BaseRobot();
	BaseRobot( double x, double y, double theta );
	void init();
	virtual void motionModel( double dt );
	void update( double dt );
	void render();

	// getters and setters
	double getX();
	double getY();
	double getSpeedX();
	double getSpeedY();
	double getTheta();
	BaseGraphicsComponent* getGraphicsComponent();

	void setX( double x );
	void setY( double y );
	void setSpeedX( double vx );
	void setSpeedY( double vy );
	void setTheta( double theta );


protected:
	BaseGraphicsComponent* m_graphicsComponent;
	double m_x;
	double m_y;
	double m_vx;
	double m_vy;
	double m_theta;	

};

#endif /* BASEROBOT_HPP_ */