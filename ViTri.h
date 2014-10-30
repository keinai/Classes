#ifndef __VITRI_H__
#define __VITRI_H__

#include "cocos2d.h"



class ViTri
{
private:
	ViTri *instance;
	cocos2d::Size screenSize;
	cocos2d::Point origin;

public:

	static int const PHIA_DUOI;
	static int const O_GIUA;
	static int const PHIA_TREN;

	ViTri* getInstance();
	void thietLapKichThuocManHinh(cocos2d::Size screenSize, cocos2d::Point origin);
	cocos2d::Point createPoint( cocos2d::Size kichthuocVat, int traiPhai, int trenDuoi);

};

#endif // __VITRI_H__
