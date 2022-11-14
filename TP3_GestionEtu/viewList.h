#pragma once
#include "promotion.h"
#include "observer.h"
#include <qlistwidget.h>

/**
 * @brief Class to manage the QListWidget
 * @author Adrien Peytavie
*/
class ViewList : public Observer
{
public:
	ViewList(Promotion* prom, QListWidget* q);
	Promotion* promo;
	QListWidget* liste;
	void update();
};

