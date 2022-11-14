#pragma once
#include "student.h"
#include <QVector>
#include <qstring.h>

class Promotion
{
private :
	QVector<Student*> studentList;
	Student selectedStudent;

public: 
	void add(Student* s);
	QVector<Student*> getListe();
	void remove(QString s);
	void find(QString i);
	Promotion(QString& filename);
	void read_list();

};

