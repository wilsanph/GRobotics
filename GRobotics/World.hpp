#ifndef WORLD_HPP_
#define WORLD_HPP_

#include "Common.hpp"
#include "BaseRobot.hpp"
#include "DifferentialRobot.hpp"
#include <vector>

class World
{
	
public:
	World();
	const World* instance;
	void init();
	void addRobot( BaseRobot* robot );
	void createRobot( double x, double y, double theta );

	void update( double dt );
	void render();

	//void loadJsonMap( const char* filename );

private:	 
	std::vector<BaseRobot*> m_robots;
	//BaseMap m_map;	
};

#endif /* WORLD_HPP_ */