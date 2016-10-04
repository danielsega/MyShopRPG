#include "MyShopRPG.h"
#include "GlobalVariables.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* MyShopRPG::createScene()
{
	auto scene = Scene::create();
	auto layer = MyShopRPG::create();
	scene->addChild(layer);
	return scene;
}

bool MyShopRPG::init()
{
	if (!Layer::init())
	{
		return false;
	}

	is_dragged = false;

	initTouch();
	initTiled();
	tempSetupSprite();

	debugDrawLine();

	this->scheduleUpdate();
	return true;
}

bool MyShopRPG::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event * _event)
{
	CCLOG("Click locations x: %f y:%f", touch->getLocation().x, touch->getLocation().y);
	first_touch = touch->getLocation();

	sprite->setPosition(convertToNodeSpace(touch->getLocation()));
	return true;
}

void MyShopRPG::onTouchEnded(cocos2d::Touch* _touch, cocos2d::Event* _event)
{
	is_dragged = false;
}

void MyShopRPG::onTouchMoved(cocos2d::Touch* _touch, cocos2d::Event * _event)
{
	last_drag_touch = first_touch - _touch->getLocation();
	is_dragged = true;
}

void MyShopRPG::onTouchCancelled(cocos2d::Touch* _touch, cocos2d::Event* _event)
{
	is_dragged = false;
}

void MyShopRPG::update(float dt)
{
	if (is_dragged)
	{
		this->setPositionX(this->getPositionX() - (last_drag_touch.x * dt));
		this->setPositionY(this->getPositionY() - (last_drag_touch.y * dt));
	}
}

void MyShopRPG::initTouch()
{
	auto touch_listener = EventListenerTouchOneByOne::create();
	touch_listener->setSwallowTouches(true);

	touch_listener->onTouchBegan = CC_CALLBACK_2(MyShopRPG::onTouchBegan, this);
	touch_listener->onTouchEnded = CC_CALLBACK_2(MyShopRPG::onTouchEnded, this);
	touch_listener->onTouchMoved = CC_CALLBACK_2(MyShopRPG::onTouchMoved, this);
	touch_listener->onTouchCancelled = CC_CALLBACK_2(MyShopRPG::onTouchCancelled, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(touch_listener, this);
}

void MyShopRPG::initTiled()
{
	map = GameMap::createMap("Map/MyShopSpace.tmx"); //4 bytes
	map->initLayers(3, 29);
	this->addChild(map, 0);
}

void MyShopRPG::tempSetupSprite()
{
	sprite = GameSprite::gameSpriteWithFile("man-se.png");
	this->addChild(sprite, 1);
}

void MyShopRPG::debugDrawLine()
{
	auto test = map->getObjGroup()->objectNamed("Floor");
	float pos_x = test["x"].asFloat() + ( (test["width"].asFloat() / 2) - map->getFloor()->getTileSet()->_tileSize.width / 2);
	float pos_y = test["y"].asFloat() + ( (test["height"].asFloat() / 2) - map->getFloor()->getTileSet()->_tileSize.height / 2);

	for (float x = pos_x; x < test["x"].asFloat(); x += map->getFloor()->getTileSet()->_tileSize.width)
	{
		for (float y = pos_y; y < test["y"].asFloat(); y += map->getFloor()->getTileSet()->_tileSize.height)
		{
			DrawNode* debog_draw = DrawNode::create();
			debog_draw->drawLine(Vec2(pos_x, pos_y), Vec2(x, y), Color4F::WHITE);
			this->addChild(debog_draw);

			pos_y += map->getTileSize().height;
		}
		pos_x += map->getTileSize().width;
	}
}