#pragma once
#include "student.h"
#include <QVector>
#include <qstring.h>
#include "observer.h"

/**
 * The promotion will contain all the student.
 */

class Promotion : public Observable
{
private :
	QVector<Student*> studentList;
	Student selectedStudent;
	QVector<Observer*> observerList;

public: 
	void add(Student* s);
	QVector<Student*> getListe();
	QVector<Observer*> getObserver();
	void remove(QString s);
	void find(QString i);
	void removeObserver(Observer* observer);
	Promotion(QString& filename);
	void read_list();
	void notifyObserver() override;
	void addObserver(Observer* observer);
};

