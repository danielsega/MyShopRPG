#include "MyShopRPG.h"
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

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	initTouch();
	initTiled();

	this->scheduleUpdate();
	return true;
}

bool MyShopRPG::onTouchBegan(cocos2d::Touch* _touch, cocos2d::Event * _event)
{
	return true;
}

void MyShopRPG::onTouchEnded(cocos2d::Touch* _touch, cocos2d::Event* _event)
{
}

void MyShopRPG::onTouchMoved(cocos2d::Touch* _touch, cocos2d::Event * _event)
{
}

void MyShopRPG::onTouchCancelled(cocos2d::Touch* _touch, cocos2d::Event* _event)
{
}

void MyShopRPG::update(float dt)
{
	//CCLOG("Delta time: %f", dt);
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
	CCTMXTiledMap* tiled_map = CCTMXTiledMap::create("Map/MyShopSpace.tmx");
	CCTMXLayer* ground = tiled_map->layerNamed("Ground");
	CCTMXLayer* floor = tiled_map->layerNamed("Floor");
	CCTMXLayer* lower_wall = tiled_map->layerNamed("LowerWall");
	CCTMXLayer* higher_wall = tiled_map->layerNamed("HigherWall");
	CCTMXLayer* items = tiled_map->layerNamed("Items");

	floor->setPositionX(floor->getPositionX() - 3);
	floor->setPositionY(floor->getPositionY() - 29);
	//CCTMXObjectGroup* object_group = tiled_map->objectGroupNamed("GameObjects");
	//auto start_point = object_group->getObject("StartPoint");

	tiled_map->setPositionX(tiled_map->getPositionX() - (tiled_map->getBoundingBox().getMidX() - tiled_map->getTileSize().width));
	tiled_map->setPositionY(tiled_map->getPositionY() - (tiled_map->getBoundingBox().getMinY() + tiled_map->getTileSize().height));

	this->addChild(tiled_map, 0);
}
