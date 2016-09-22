#ifndef __MY_SHOP_RPG_H__
#define __MY_SHOP_RPG_H__

#include "cocos2d.h"
#include "GameSprite.h"

class MyShopRPG : public cocos2d::Layer
{
private:
	void update(float dt);
	void initTouch();
	void initTiled();

	void tempSetupSprite();
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	virtual bool onTouchBegan(cocos2d::Touch* _touch, cocos2d::Event* _event);
	virtual void onTouchEnded(cocos2d::Touch* _touch, cocos2d::Event* _event);
	virtual void onTouchMoved(cocos2d::Touch* _touch, cocos2d::Event* _event);
	virtual void onTouchCancelled(cocos2d::Touch* _touch, cocos2d::Event* _event);

	CREATE_FUNC(MyShopRPG);
private:
	GameSprite* sprite;
};

#endif // __MY_SHOP_RPG_H__
