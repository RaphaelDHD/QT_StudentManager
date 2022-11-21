#include "viewForms.h"
#include <iostream>
using namespace std;


/**
 * Constructor of the view forms.
 * 
 * \param prom Pointer to the main promotion
 * \param first LineEdit for the firstname to add
 * \param last LineEdit for the lastname to add
 * \param identifiant LineEdit for the id to add
 * \param bacliste QCombobox who's contain all the bac available
 * \param dept QCombobox who's contain all the department available
 * \param iddel LineEdit for the id to delete
 */
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
	bac->addItem("STI");
	controller = new Controller_AddForm(promo);
	controllerDel = new Controller_DeleteForm(promo);
}
/**
 * Function wich will be called at every update from the application, it update all the forms
 *
 */
void ViewForms::update()
{
	id->setText("");
	firstname->setText("");
	lastname->setText("");
	bac->setCurrentIndex(0);
	departement->setCurrentIndex(0);
	idDel->setText("");
}


/**
 * This function add a student to promotion, it get the information from the line edits and the combobox.
 * 
 */

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
/**
 * this function delete a student from promotion by getting is id from de lineEdit del.
 * 
 */
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

