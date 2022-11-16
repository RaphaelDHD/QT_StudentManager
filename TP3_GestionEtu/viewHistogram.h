#pragma once
#include "observer.h"
#include <qobject.h>


class ViewHistogram : public Observer, public QObject
{
public:
	ViewHistogram();
	void update();
};

