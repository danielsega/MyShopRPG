#ifndef __MY_SHOP_RPG_H__
#define __MY_SHOP_RPG_H__

#include "cocos2d.h"

class MyShopRPG : public cocos2d::Layer
{
private:
	void update(float dt);
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(MyShopRPG);
};

#endif // __MY_SHOP_RPG_H__
