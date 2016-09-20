#include "MainMenuScene.h"
#include "MyShopRPG.h"

USING_NS_CC;

Scene* MainMenu::createScene()
{
	auto scene = Scene::create();
	auto layer = MainMenu::create();
	scene->addChild(layer);
	return scene;
}

bool MainMenu::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	return true;
}

void MainMenu::goToMainGame(Ref * pSender)
{
	auto scene = MyShopRPG::createScene();
	Director::getInstance()->replaceScene(scene);
}