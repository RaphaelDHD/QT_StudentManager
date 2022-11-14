#include "Controller_DeleteForm.h"

Controller_DeleteForm::Controller_DeleteForm(Promotion* prom)
{
	promo = prom;
}

void Controller_DeleteForm::control(QVector<QString> Vstring)
{
	promo->remove(Vstring[0]);
	promo->notifyObserver();
}
