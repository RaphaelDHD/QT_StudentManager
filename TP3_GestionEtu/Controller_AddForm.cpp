#include "Controller_AddForm.h"

Controller_AddForm::Controller_AddForm(Promotion* prom)
{
	promo = prom;
}

void Controller_AddForm::control(QVector<QString> Vstring)
{

	promo->add(new Student(Vstring[0].toInt(),Vstring[1],Vstring[2],Vstring[3].toInt(), Vstring[4]));
	promo->notifyObserver();
}

