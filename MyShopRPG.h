#ifndef __MY_SHOP_RPG_H__
#define __MY_SHOP_RPG_H__

#include "cocos2d.h"
#include "GameSprite.h"
#include "GameMap.h"
#include "Shop.h"

class MyShopRPG : public cocos2d::Layer, Shop
{
private:
	void update(float dt);
	void initTouch();
	void initTiled();

	void tempSetupSprite();
	void debugDrawLine();
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	virtual bool onTouchBegan(cocos2d::Touch* _touch, cocos2d::Event* _event);
	virtual void onTouchEnded(cocos2d::Touch* _touch, cocos2d::Event* _event);
	virtual void onTouchMoved(cocos2d::Touch* _touch, cocos2d::Event* _event);
	virtual void onTouchCancelled(cocos2d::Touch* _touch, cocos2d::Event* _event);

	CREATE_FUNC(MyShopRPG);
private:
	bool is_dragged;

	Vec2 first_touch;
	Vec2 last_drag_touch;

	GameSprite* sprite;
	GameMap* map;
};

#endif // __MY_SHOP_RPG_H__
