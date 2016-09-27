#include "GameMap.h"

GameMap * GameMap::createMap(const std::string & tmxFile)
{
	GameMap* map = new (std::nothrow) GameMap();

	if (map && map->initWithTMXFile(tmxFile))
	{
		map->autorelease();
		return map;
	}

	CC_SAFE_DELETE(map);
	return nullptr;
}

void GameMap::initLayers(int offset_x, int offset_y)
{
	//Layers
	ground = this->layerNamed("Ground");
	floors = this->layerNamed("Floor");
	lower_wall = this->layerNamed("LowerWall");
	higher_wall = this->layerNamed("HigherWall");
	game_items = this->layerNamed("GameItems");

	//Get 
	object_group = this->objectGroupNamed("GameObjects");

	//Move to Offset
	floors->setPositionX(floors->getPositionX() - offset_x);
	floors->setPositionY(floors->getPositionY() - offset_y);
}

CCTMXLayer * GameMap::getGround()
{
	if (ground != nullptr)
	{
		return ground;
	}

	return nullptr;
}

CCTMXLayer * GameMap::getFloor()
{
	if (floors != nullptr)
	{
		return floors;
	}

	return nullptr;
}

CCTMXLayer * GameMap::getLowerWall()
{
	if (lower_wall != nullptr)
	{
		return lower_wall;
	}

	return nullptr;
}

CCTMXLayer * GameMap::getHigherWall()
{
	if (higher_wall != nullptr)
	{
		return higher_wall;
	}

	return nullptr;
}

CCTMXLayer * GameMap::getGameItems()
{
	if (game_items != nullptr)
	{
		return game_items;
	}

	return nullptr;
}

CCTMXObjectGroup *  GameMap::getObjGroup()
{
	if (object_group != nullptr)
	{
		return object_group;
	}

	return nullptr;
}