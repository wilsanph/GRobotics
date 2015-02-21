
#include "World.hpp"


World::World()
{
	World::instance = this;
}

void World::init()
{
	this->createRobot( 0, 0, 0 );
}

void World::addRobot( BaseRobot* robot )
{
	this->m_robots.push_back( robot );
}

void World::createRobot( double x, double y, double theta )
{
	//BaseRobot* robot = new BaseRobot( x, y, theta );
	DifferentialRobot* robot = new DifferentialRobot( x, y, theta );
	this->addRobot( robot );
}


void World::update( double dt )
{
	unsigned int i = 0;

	for ( i = 0; i < this->m_robots.size(); i++ )
	{
		this->m_robots[i]->update( dt );
	}
}

void World::render()
{
	unsigned int i = 0;

	for ( i = 0; i < this->m_robots.size(); i++ )
	{
		this->m_robots[i]->render();
	}
}