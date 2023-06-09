#include "viewHistogram.h"


/**
 * Constructor of the view histogram wich will also create de histogram and integrate it into the page
 * 
 * @param prom pointer to the main promotion of the application
 * @param b pointer to the groupbox wich will contain the chartview
 */

ViewHistogram::ViewHistogram(Promotion* prom, QGroupBox* b)
{
	promo = prom;
	box = b;

	QVector<QBarSet*> set(4, 0);

	set[0] = new QBarSet("STI");
	set[1] = new QBarSet("L");
	set[2] = new QBarSet("S");
	set[3] = new QBarSet("ES");

	QVector<int> nb(4, 0);


	for (int i = 0; i < promo->getListe().size(); i++) {
		if (promo->getListe()[i]->getBac() == "STI") {
			nb[0]++;
		}
		if (promo->getListe()[i]->getBac() == "L") {
			nb[1]++;
		}
		if (promo->getListe()[i]->getBac() == "S") {
			nb[2]++;
		}
		if (promo->getListe()[i]->getBac() == "ES") {
			nb[3]++;
		}
	}

	set[0]->append(nb[0]);
	set[1]->append(nb[1]);
	set[2]->append(nb[2]);
	set[3]->append(nb[3]);

	series = new QBarSeries();
	series->append(set[0]);
	series->append(set[1]);
	series->append(set[2]);
	series->append(set[3]);

	chart = new QChart();
	chart->addSeries(series);
	chart->setTitle("Series de Bac");
	chart->setAnimationOptions(QChart::SeriesAnimations);


	chart->legend()->setVisible(true);
	chart->legend()->setAlignment(Qt::AlignBottom);

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
void ViewHistogram::update() {
	delete chart;
	delete chartView;
	delete layout;


	QVector<QBarSet*> set(4, 0);

	set[0] = new QBarSet("STI");
	set[1] = new QBarSet("L");
	set[2] = new QBarSet("S");
	set[3] = new QBarSet("ES");

	QVector<int> nb(4, 0);


	for (int i = 0; i < promo->getListe().size(); i++) {
		if (promo->getListe()[i]->getBac() == "STI") {
			nb[0]++;
		}
		if (promo->getListe()[i]->getBac() == "L") {
			nb[1]++;
		}
		if (promo->getListe()[i]->getBac() == "S") {
			nb[2]++;
		}
		if (promo->getListe()[i]->getBac() == "ES") {
			nb[3]++;
		}
	}
	set[0]->append(nb[0]);
	set[1]->append(nb[1]);
	set[2]->append(nb[2]);
	set[3]->append(nb[3]);

	series = new QBarSeries();
	series->append(set[0]);
	series->append(set[1]);
	series->append(set[2]);
	series->append(set[3]);

	chart = new QChart();
	chart->addSeries(series);
	chart->setTitle("Series de Bac");
	chart->setAnimationOptions(QChart::SeriesAnimations);
	chart->setScale(1.08);

	chart->legend()->setVisible(true);
	chart->legend()->setAlignment(Qt::AlignBottom);

	chartView = new QChartView(chart);
	chartView->setRenderHint(QPainter::Antialiasing);

	layout = new QGridLayout();
	layout->addWidget(chartView);

	box->setLayout(layout);
}
