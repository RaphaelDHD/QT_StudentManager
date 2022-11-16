#pragma once
#include "AbstractController.h"
#include "viewForms.h"
#include "promotion.h"

class Controller_DeleteForm : public AbstractController
{

public:
	Promotion* promo;
	Controller_DeleteForm(Promotion* prom);
	void control(QVector<QString> Vstring);
};