#include "viewList.h"




ViewList::ViewList(Promotion* prom, QListWidget* q)
{
	promo = prom;
	liste = q;
	update();
}

void ViewList::update()
{
	liste->clear();

	for (int i = 0; i < promo->getListe().size(); i++) {
		QString s = QString::number(promo->getListe().at(i)->getId()) + " " + promo->getListe().at(i)->getLastName() + " " + promo->getListe().at(i)->getFirstName() + " (" + QString::number(promo->getListe().at(i)->getDept()) + ")";
		liste->addItem(s);
	}

	/*liste->addItem(promo->getListe());*/
}