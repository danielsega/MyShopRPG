#ifndef _GAME_MAP_
#define _GAME_MAP_

#include "cocos2d.h"

using namespace cocos2d;

class GameMap : public TMXTiledMap
{
public:
	static GameMap* createMap(const std::string& tmxFile);
	void initLayers(int offset_x = 0, int offset_y = 0);

	TMXLayer* getGround();
	TMXLayer* getFloor();
	TMXLayer* getLowerWall();
	TMXLayer* getHigherWall();
	TMXLayer* getAppliances();
	TMXObjectGroup* getObjGroup();

private:
	TMXLayer* ground;
	TMXLayer* floors;
	TMXLayer* lower_wall;
	TMXLayer* higher_wall;
	TMXLayer* appliances;

	TMXObjectGroup* object_group;
};

#endif
