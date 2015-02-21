#include "Application.hpp"

Application* Application::instance = NULL;

Application::Application()
{	
	this->m_realToGLRatio = 10;
	this->m_width = 2 * this->m_realToGLRatio;
	this->m_height = 2 * this->m_realToGLRatio;
}

Application::Application( double realToGLRatio )
{
	this->m_realToGLRatio = realToGLRatio;
	this->m_width = 2 * this->m_realToGLRatio;
	this->m_height = 2 * this->m_realToGLRatio;
}

void Application::init()
{
	this->m_world = new World();
	this->m_world->init();
}

void Application::update( double dt )
{
	this->m_world->update( dt );
}

void Application::render()
{
	this->m_world->render();
}

double Application::width()
{
	return this->m_width;
}

double Application::height()
{
	return this->m_height;
}

double Application::realToGLRatio()
{
	return this->m_realToGLRatio;
}

double Application::metersToGLlength( double length )
{
	return length / Application::instance->realToGLRatio();
}

double Application::getXGLPosition( double xReal )
{
	// the origin of both Real and GL coordinate frames set ...
	// ... in the same position ( to make things simpler )
	return this->metersToGLlength( xReal );
}

double Application::getYGLPosition( double yReal )
{
	// the origin of both Real and GL coordinate frames set ...
	// ... in the same position ( to make things simpler )
	return this->metersToGLlength( yReal );
}
