#include "viewForms.h"


ViewForms::ViewForms(Promotion* prom, QLineEdit* first, QLineEdit* last, QLineEdit* identifiant, QComboBox* bacliste, QComboBox* dept, QLineEdit* iddel)
{
	promo = prom;
	firstname = first;
	lastname = last;
	id = identifiant;
	bac = bacliste;
	departement = dept;
	idDel = iddel;

	for (int i = 1; i < 101; i++) {
		departement->addItem(QString::number(i));
	}

	bac->addItem("S");
	bac->addItem("ES");
	bac->addItem("L");
	bac->addItem("STMG");
	controller = new Controller_AddForm(promo);
	controllerDel = new Controller_DeleteForm(promo);
}

void ViewForms::update()
{
	id->setText("");
	firstname->setText("");
	lastname->setText("");
	bac->setCurrentIndex(0);
	departement->setCurrentIndex(0);
}


void ViewForms::add() {
	QList<QString> lst;
	lst.append(id->text());
	lst.append(firstname->text());
	lst.append(lastname->text());
	lst.append(departement->currentText());
	lst.append(bac->currentText());
	controller->control(lst);
}

void ViewForms::del()
{
if (idDel->text() != "") {
	QList<QString> lst;
	lst.append(idDel->text());


	controllerDel->control(lst);
}
}
