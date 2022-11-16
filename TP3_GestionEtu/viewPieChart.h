#pragma once
#include <qpieseries.h>
#include <qchartview.h>
#include <qgroupbox.h>
#include <qgridlayout.h>
#include "promotion.h"
#include "observer.h"
#include <qobject.h>

/**
 * @brief Class to manage the PieChart View
 * @author Adrien Peytavie
*/
class ViewPieChart : public Observer , public QObject
{
public:
	ViewPieChart(Promotion* prom, QGroupBox* b);
	void update();

private :
	Promotion* promo;
	QPieSeries* series;
	QChart* chart;
	QChartView* chartView;
	QGridLayout* layout;
	QGroupBox* box;
};

