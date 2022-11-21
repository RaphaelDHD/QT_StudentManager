#include "viewList.h"
#include <iostream>
 

using namespace std;


/* Create the view for the list of student
* @param prom the promotion that will be show in the list
*/
ViewList::ViewList(Promotion* prom, QListWidget* q)
{
	promo = prom;
	liste = q;
	controller = new Controller_Delete(promo);
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

void ViewList::remove()
{
	QList<QString> lst;
	for (int i = 0; i < liste->selectedItems().size(); i++) {
		lst.append(liste->selectedItems()[i]->text());
	}
	controller->control(lst);
	
}
