#ifndef BASEGRAPHICSCOMPONENT_HPP_
#define BASEGRAPHICSCOMPONENT_HPP_

#pragma once

#include "BaseRobot.hpp"
#include "Common.hpp"
#include <vector>
#include "Node.hpp"
#include "Primitives.hpp"

class BaseRobot;

class BaseGraphicsComponent
{

public:
	BaseGraphicsComponent();
	BaseGraphicsComponent( BaseRobot* parent );
	void render();	

protected:
	BaseRobot* m_parent;
	std::vector<Node*> m_renderables;

	void drawQuad( Point p1, Point p2, Point p3, Point p4 );
};

#endif /* BASEGRAPHICSCOMPONENT_HPP_ */