#include "promotion.h"
#include "student.h"
#include <qstring.h>
#include <QVector>
#include <fstream>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <iostream>


using namespace std;

void Promotion::add(Student* s)
{
    studentList.append(s);
}

QVector<Student*> Promotion::getListe() {
    return studentList;
}

QVector<Observer*> Promotion::getObserver()
{
    return observerList;
}

void Promotion::remove(QString s)
{
    for (int i = 0; i < studentList.size(); i++) {
        if (QString::number(studentList[i]->getId()) == s) {
            studentList.removeAt(i);
        }
    }
    notifyObserver();
}


void Promotion::read_list()
{
    for (auto& it : studentList) {
        cout << it->getId() << " " << it->getFirstName().toStdString() << " " << it->getLastName().toStdString() << " " << it->getDept() << " " << it->getBac().toStdString() << endl;
    }
}

void Promotion::notifyObserver() {
    for (int i = 0; i < getObserver().size(); i++) {
        observerList[i]->update();
    }
}

void Promotion::addObserver(Observer* observer) {
    observerList.append(observer);
}

void Promotion::removeObserver(Observer* observer) {

}

Promotion::Promotion(QString &filename)
{
    QString line;
    QFile myfile(filename);
    if (myfile.open(QIODevice::ReadOnly | QFile::Text))
    {
        QTextStream in(&myfile);
        while (!in.atEnd())
        {
            QStringList split = in.readLine().split(';');
            add(new Student(split[0].toInt(), split[1], split[2], split[3].toInt(), split[4]));
        }
        myfile.close();
    }

    else qDebug() << "Unable to open file" << filename << ": error" << myfile.error() << "," << myfile.errorString();
}


