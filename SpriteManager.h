#ifndef _SPRITE_MANAGER_
#define _SPRITE_MANAGER_

#include "GameSprite.h"

class SpriteManager
{
public:
	SpriteManager();
	~SpriteManager();

private:
	Vector<GameSprite*> game_items;
	Vector<GameSprite*> characters;
};

#endif
