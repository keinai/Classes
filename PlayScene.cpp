#include "PlayScene.h"

USING_NS_CC;

Scene* PlayScene::createScene() {
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = PlayScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool PlayScene::init() {
	//////////////////////////////
	// 1. super init first
	if (!Layer::init()) {
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	// add background splash screen"
	auto sprite = Sprite::create("background.png");

	// position the sprite on the center of the screen
	sprite->setPosition(
			Point(visibleSize.width / 2 + origin.x,
					visibleSize.height / 2 + origin.y));

	// add the sprite as a child to this layer
	this->addChild(sprite, 0);

	//Add line
	Sprite *sprite2 = Sprite::create("line.png");

	sprite2->setPosition(
			Point(origin.x + visibleSize.width / 2,
					origin.y + visibleSize.height));
	sprite2->setScaleX(0.5);
	sprite2->setScaleY(10);

	this->addChild(sprite2, 0);

	//Them chuong ngai vat
	Sprite *chuongNgaiVat = Sprite::create("chuongNgaiVat.png");

	auto doRongBanDau = chuongNgaiVat->getTextureRect().size.width;
	CCLOG("Ban dau: %f", doRongBanDau);
	chuongNgaiVat->setScaleX(0.25 * visibleSize.width / doRongBanDau);
	auto doRong = 0.25 * visibleSize.width;
	CCLOG("Sau do: %f", doRong);
	chuongNgaiVat->setPosition(
			Point(origin.x + doRong / 2, origin.y + visibleSize.height + 40));
	MoveBy *diXuong = MoveTo::create(2, Point(origin.x + doRong / 2, origin.y));

	CCFiniteTimeAction *diXuongXong = CCCallFuncN::create(this,
			callfuncN_selector(PlayScene::chuongNgaiVatBienMat));
	chuongNgaiVat->runAction(CCSequence::create(diXuong, diXuongXong, NULL));

	//Them DoChoiBenTrai
	Sprite *doChoiBenTrai = Sprite::create("doChoiBenTrai.png");
	doRongBanDau = doChoiBenTrai->getTextureRect().size.width;
	doChoiBenTrai->setScaleX(doRong / doRongBanDau);
	doChoiBenTrai->setPosition(
			Point(origin.x + doRong / 2, origin.y + visibleSize.height / 2));
	this->addChild(doChoiBenTrai, 0);

	this->addChild(chuongNgaiVat, 0);

	//Them nut Trai cua ben trai
	Sprite *nutTraiBenTrai = Sprite::create("nutTraiBenTrai.png");
	doRongBanDau = nutTraiBenTrai->getTextureRect().size.width;
	nutTraiBenTrai->setScaleX(0.25 * visibleSize.width / doRongBanDau);
	auto doCaoBanDau = nutTraiBenTrai->getTextureRect().size.height;
	nutTraiBenTrai->setPosition(
			Point(origin.x + doRong / 2, origin.y + doCaoBanDau / 2));

	this->addChild(nutTraiBenTrai, 0);

	//Them nut Phai cua ben trai
	Sprite *nutPhaiBenTrai = Sprite::create("nutPhaiBenTrai.png");
	doRongBanDau = nutPhaiBenTrai->getTextureRect().size.width;
	nutPhaiBenTrai->setScaleX(0.25 * visibleSize.width / doRongBanDau);
	doCaoBanDau = nutPhaiBenTrai->getTextureRect().size.height;
	nutPhaiBenTrai->setPosition(
			Point(origin.x + 3 * doRong / 2, origin.y + doCaoBanDau / 2));

	this->addChild(nutPhaiBenTrai, 0);

	return true;
}

void PlayScene::chuongNgaiVatBienMat(CCNode *sender) {
	CCSprite *sprite = (CCSprite *) sender;
	this->removeChild(sprite, true);
}

