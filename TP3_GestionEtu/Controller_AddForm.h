#pragma once
#include "AbstractController.h"
#include "viewForms.h"
#include "promotion.h"

class Controller_AddForm : public AbstractController
{

public:
	Promotion* promo;
	Controller_AddForm(Promotion* prom);
	void control(QVector<QString> Vstring);
};