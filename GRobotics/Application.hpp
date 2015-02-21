#ifndef APPLICATION_HPP_
#define APPLICATION_HPP_

#pragma once

#include "Common.hpp"
#include "World.hpp"

class Application
{

public:
	static Application* instance;
	Application();
	Application( double realToGLRatio );
	void init();
	void update( double dt );
	void render();

	double width();
	double height();
	double realToGLRatio();

	double metersToGLlength( double length );
	double getXGLPosition( double xReal );
	double getYGLPosition( double yReal );

private:
	double m_width;
	double m_height;	
	double m_realToGLRatio;
	World* m_world;

};


#endif /* APPLICATION_HPP_ */