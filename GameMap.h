#ifndef _GAME_MAP_
#define _GAME_MAP_

#include "cocos2d.h"

using namespace cocos2d;

class GameMap : public CCTMXTiledMap
{
public:
	static GameMap* createMap(const std::string& tmxFile);
	void initLayers(int offset_x = 0, int offset_y = 0);

	CCTMXLayer* getGround();
	CCTMXLayer* getFloor();
	CCTMXLayer* getLowerWall();
	CCTMXLayer* getHigherWall();
	CCTMXLayer* getGameItems();

	CCTMXObjectGroup* getObjGroup();

private:
	CCTMXLayer* ground;
	CCTMXLayer* floors;
	CCTMXLayer* lower_wall;
	CCTMXLayer* higher_wall;
	CCTMXLayer* game_items;

	CCTMXObjectGroup* object_group;
};

#endif
