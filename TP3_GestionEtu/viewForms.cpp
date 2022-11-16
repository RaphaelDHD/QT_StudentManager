#include "viewForms.h"
#include <iostream>
using namespace std;

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
	idDel->setText("");
}


void ViewForms::add() {
	QList<QString> lst;
	if (id->text() != nullptr && firstname->text() != nullptr && lastname->text() != nullptr) {
		lst.append(id->text());
		lst.append(firstname->text());
		lst.append(lastname->text());
		lst.append(departement->currentText());
		lst.append(bac->currentText());
		controller->control(lst);
	}
	else {
		cout << "Veuillez remplir toutes les champs avant d'ajouter" << endl;
	}
}

void ViewForms::del()
{
if (idDel->text() != nullptr) {
	QList<QString> lst;
	lst.append(idDel->text());


	controllerDel->control(lst);
}
else {
	cout << "Veuillez remplir tout les champs avant de supprimer un etudiant" << endl;
}
}
