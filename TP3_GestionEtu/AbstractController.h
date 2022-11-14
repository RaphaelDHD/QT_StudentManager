#pragma once
#include <QVector>
#include <qstring.h>

class AbstractController abstract{
public :
	virtual void control(QVector<QString>) = 0;
};
