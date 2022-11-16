#pragma once
#include "observer.h"
#include <qobject.h>
#include <qgroupbox.h>
#include <qbarset.h>
#include <qbarseries.h>
#include <qchart.h>
#include <qchartview.h>
#include <qgridlayout.h>
#include "promotion.h"

class ViewHistogram : public Observer, public QObject
{
public:
	ViewHistogram(Promotion* prom, QGroupBox* b);
	void update();
private:
	Promotion* promo;
	QVector<QBarSet*> set;
	QBarSeries* series;
	QChart* chart;
	QChartView* chartView;
	QGridLayout* layout;
	QGroupBox* box;
};
