#include "BaseGraphicsComponent.hpp"
#include "Application.hpp"

BaseGraphicsComponent::BaseGraphicsComponent()
{
	this->m_parent = NULL;
}

BaseGraphicsComponent::BaseGraphicsComponent( BaseRobot* parent )
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

void BaseGraphicsComponent::render()
{
	if ( this->m_parent == NULL )
	{
		return;
	}

	for ( int k = 0; k < this->m_renderables.size(); k++ )
	{
		this->m_renderables[k]->setBasePoint(
			Application::instance->getXGLPosition( this->m_parent->getX() ),
			Application::instance->getYGLPosition( this->m_parent->getY() ) );
		this->m_renderables[k]->setBaseAngle( this->m_parent->getTheta() );
		this->m_renderables[k]->render();
	}
}

void BaseGraphicsComponent::drawQuad( Point p1, Point p2, Point p3, Point p4 )
{
	glBegin( GL_QUADS );
	glVertex2f( p1.x, p1.y );
	glVertex2f( p2.x, p2.y );
	glVertex2f( p3.x, p3.y );
	glVertex2f( p4.x, p4.y );
	glEnd();
}