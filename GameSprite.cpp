#include "GameSprite.h"

GameSprite::GameSprite()
{
	next_position = ccp(0, 0);
	this->scheduleUpdate();
}

GameSprite::~GameSprite()
{
}

GameSprite * GameSprite::gameSpriteWithFile(const char * file_name)
{
	GameSprite* sprite = new GameSprite();

	if (sprite && sprite->initWithFile(file_name))
	{
		sprite->autorelease();
		return sprite;
	}

	CC_SAFE_DELETE(sprite);
	return NULL;
}

void GameSprite::setPosition(const CCPoint& pos)
{
	CCSprite::setPosition(pos);

	if (!next_position.equals(pos))
	{
		next_position = pos;
	}
}

void GameSprite::update(float dt)
{
}

void GameSprite::handleEvents()
{
}
