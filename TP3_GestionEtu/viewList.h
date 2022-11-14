#pragma once
#include "promotion.h"
#include "observer.h"
#include <qlistwidget.h>
#include <iostream>
#include "Controller_Delete.h"

/**
 * @brief Class to manage the QListWidget
 * @author Adrien Peytavie
*/
class ViewList : public Observer, public QObject
{
public:
	ViewList(Promotion* prom, QListWidget* q);
	Promotion* promo;
	QListWidget* liste;
	AbstractController* controller;
	void update();
	void remove();
};

