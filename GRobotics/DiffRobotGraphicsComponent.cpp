#include "DiffRobotGraphicsComponent.hpp"
#include "Application.hpp"

DiffRobotGraphicsComponent::DiffRobotGraphicsComponent( DifferentialRobot* parent )	
{
	this->m_parent = parent;
	gPrimitives::Circle* tCircle = new gPrimitives::Circle(
		Application::instance->getXGLPosition( parent->getX() ),
		Application::instance->getYGLPosition( parent->getY() ),
		Application::instance->metersToGLlength( 1 ),
		RGBColor( 1.0, 0.0, 0.0 ) );
	this->m_renderables.push_back( tCircle );

	double wheelRadius = 1;
	double wheelWidth = 0.5;

	gPrimitives::Quad* tQuad1 = new gPrimitives::Quad(
		Application::instance->getXGLPosition( 0 - wheelRadius ),
		Application::instance->getYGLPosition( -1 ),
		Application::instance->getXGLPosition( 0 + wheelRadius ),
		Application::instance->getYGLPosition( -1 ),
		Application::instance->getXGLPosition( 0 + wheelRadius ),
		Application::instance->getYGLPosition( -1 - wheelWidth ),
		Application::instance->getYGLPosition( 0 - wheelRadius ),
		Application::instance->getYGLPosition( -1 - wheelWidth ),
		RGBColor( 0.0, 0.0, 1.0 ) );
	this->m_renderables.push_back( tQuad1 );
	gPrimitives::Quad* tQuad2 = new gPrimitives::Quad(
		Application::instance->getXGLPosition( 0 - wheelRadius ),
		Application::instance->getYGLPosition( 1 ),
		Application::instance->getXGLPosition( 0 + wheelRadius ),
		Application::instance->getYGLPosition( 1 ),
		Application::instance->getXGLPosition( 0 + wheelRadius ),
		Application::instance->getYGLPosition( 1 + wheelWidth ),
		Application::instance->getYGLPosition( 0 - wheelRadius ),
		Application::instance->getYGLPosition( 1 + wheelWidth ),
		RGBColor( 0.0, 0.0, 1.0 ) );
	this->m_renderables.push_back( tQuad2 );
}
