#include "ViTri.h"

USING_NS_CC;


int const ViTri::PHIA_DUOI = 0;
int const ViTri::O_GIUA = 1;
int const ViTri::PHIA_TREN = 2;


ViTri* ViTri::getInstance()
{
    if (!this->instance)
    {
        this->instance = new ViTri();
    }

    return this->instance;
}

void ViTri::thietLapKichThuocManHinh(Size screenSize, Point origin)
{
	this->screenSize = screenSize;
	this->origin = origin;
}
Point ViTri::createPoint(Size kichThuocVat, int traiPhai, int trenDuoi)
{
	double chieuRongBanDau = this->origin.x + 0.5 * kichThuocVat.width;
	double chieuRong = chieuRongBanDau + 0.25 * traiPhai * this->screenSize.width;
	double chieuCao;
	switch(trenDuoi){
	case ViTri::PHIA_DUOI:
		chieuCao = this->origin.y + 0.5 * kichThuocVat.height;
		break;
	case ViTri::O_GIUA:
		chieuCao = this->origin.y + 0.5 * this->screenSize.height;
		break;
	case ViTri::PHIA_TREN:
		chieuCao = this->origin.y + this->screenSize.height - 0.5 * kichThuocVat.height;
		break;
	}
	return Point(chieuRong, chieuCao);

}

