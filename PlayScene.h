#ifndef __PLAY_SCENE_H__
#define __PLAY_SCENE_H__

#include "cocos2d.h"



class PlayScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    //Add callback function
    void chuongNgaiVatBienMat(cocos2d::CCNode *sender);

    // implement the "static create()" method manually
    CREATE_FUNC(PlayScene);
};

#endif // __PLAY_SCENE_H__
