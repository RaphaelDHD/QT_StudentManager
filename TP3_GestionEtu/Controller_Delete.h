#pragma once
#include "AbstractController.h"
#include "viewList.h"
#include "promotion.h"

class Controller_Delete : public AbstractController
{

public : 
	Promotion* promo;
	Controller_Delete(Promotion * prom);
	void control(QVector<QString> Vstring);
};