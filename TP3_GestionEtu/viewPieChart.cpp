#include "viewPieChart.h"
#include <iostream>
using namespace std;
/**
 * Create the view and the pie chart.
 * 
 * \param prom pointer to the main promotion
 * \param b pointer to the groupbox that will integrate the chart
 */
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
			cout << QString::number(i).toStdString() << endl;
		}
	}
	chart = new QChart();
	chart->addSeries(series);
	chart->setTitle("Departements");
	chart->setAnimationOptions(QChart::SeriesAnimations);
	chartView = new QChartView(chart);
	chartView->setRenderHint(QPainter::Antialiasing);


	layout = new QGridLayout();
	layout->addWidget(chartView);

	box->setLayout(layout);
}
/**
 * Function wich will be called at every update from the application, it update the chart
 *
 */
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
