#include "viewPieChart.h"
#include <iostream>
using namespace std;

ViewPieChart::ViewPieChart(Promotion* prom, QGroupBox* b)
{
	promo = prom;
	box = b;


	QVector<int> dept(100, 0);
	for (int i = 0; i < promo->getListe().size(); i++) {
		dept[promo->getListe().at(i)->getDept()]++;
	}
	series = new QPieSeries();
	for (int i = 0; i < dept.size(); i++) {
		if (dept[i] != 0) {
			series->append(QString::number(i), dept[i]);
		}
	}
	chart = new QChart();
	chart->addSeries(series);
	chart->setTitle("Proportions H/F");
	chart->setAnimationOptions(QChart::SeriesAnimations);
	chartView = new QChartView(chart);
	chartView->setRenderHint(QPainter::Antialiasing);


	layout = new QGridLayout();
	layout->addWidget(chartView);

	box->setLayout(layout);
}

void ViewPieChart::update()
{
	delete chart;
	delete chartView;
	delete layout;


	QVector<int> dept(100,0);
	for (int i = 0; i < promo->getListe().size(); i++) {
		dept[promo->getListe().at(i)->getDept()]++;
	}
	series = new QPieSeries();
	for (int i = 0; i < dept.size(); i++) {
		if (dept[i] != 0) {
			series->append(QString::number(i), dept[i]);
		}
	}
	chart = new QChart();
	chart->addSeries(series);
	chart->setTitle("Proportions H/F");
	chart->setAnimationOptions(QChart::SeriesAnimations);
	chartView = new QChartView(chart);
	chartView->setRenderHint(QPainter::Antialiasing);


	layout = new QGridLayout();
	layout->addWidget(chartView);

	box->setLayout(layout);
}
