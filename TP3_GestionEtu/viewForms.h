#pragma once
#include "promotion.h"
#include "observer.h"
#include <qlineedit.h>
#include <iostream>
#include "Controller_AddForm.h"
#include "Controller_DeleteForm.h"
#include <qcombobox.h>

/**
 * @brief Class to manage the histogram View
*/
class ViewForms : public Observer, public QObject
{
private :
	Promotion* promo;
	QLineEdit* firstname;
	QLineEdit* lastname;
	QLineEdit* id;
	QComboBox* bac;
	QComboBox* departement;
	AbstractController* controller;
	AbstractController* controllerDel;
	QLineEdit* idDel;

public:
	ViewForms(Promotion* prom, QLineEdit* first, QLineEdit* last, QLineEdit* identifiant, QComboBox* bacliste, QComboBox* dept, QLineEdit* iddel);
	void update();
	void add();
	void del();
};

