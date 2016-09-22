#ifndef _GAME_SPRITE_
#define _GAME_SPRITE_

#include "cocos2d.h"

using namespace cocos2d;

class GameSprite : public CCSprite
{
public:
	GameSprite();
	~GameSprite();

	static GameSprite* gameSpriteWithFile(const char* file_name);

	virtual void setPosition(const CCPoint& pos);

	CC_SYNTHESIZE(CCPoint, next_position, NextPosition);

	virtual void update(float dt);

	virtual void handleEvents();
};

#endif
