#include "Controller_Delete.h"
#include <qstring.h>


Controller_Delete::Controller_Delete(Promotion* prom)
{
	promo = prom;
}

void Controller_Delete::control(QVector<QString> Vstring)
{
	for (int i = 0; i < Vstring.size(); i++) {
		promo->remove(Vstring[i].split(' ')[0]);
	}
	promo->notifyObserver();
}
