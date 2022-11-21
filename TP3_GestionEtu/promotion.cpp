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

/**
* Add a student to the promotion
*
*/
void Promotion::add(Student* s)
{
    studentList.append(s);
}


/**
* Return the student list of the promotion
*
*/
QVector<Student*> Promotion::getListe() {
    return studentList;
}

/*
* Return the list of all the observer of the promotion
*
*/
QVector<Observer*> Promotion::getObserver()
{
    return observerList;
}

/*
* Remove a student from the list in the promotion
*   @param s id of the student you want to remove
*/

void Promotion::remove(QString s)
{
    for (int i = 0; i < studentList.size(); i++) {
        if (QString::number(studentList[i]->getId()) == s) {
            studentList.removeAt(i);
        }
    }
    notifyObserver();
}


/*
*   Print in console all the element of the list
*
*
*/

void Promotion::read_list()
{
    for (auto& it : studentList) {
        cout << it->getId() << " " << it->getFirstName().toStdString() << " " << it->getLastName().toStdString() << " " << it->getDept() << " " << it->getBac().toStdString() << endl;
    }
}


/*
*   Notify all the observer in the observer list
*
*/
void Promotion::notifyObserver() {
    for (int i = 0; i < getObserver().size(); i++) {
        observerList[i]->update();
    }
}

/*
*   Add an observer to the observer list
* @param observer The observer you want to add to your list
*
*/

void Promotion::addObserver(Observer* observer) {
    observerList.append(observer);
}


/*
*   Remove an observer from the list
* @param observer The observer you want to remove from your list
*/
void Promotion::removeObserver(Observer* observer) {

}


/*
*   Constructor of the promotion
*   @filename the name of the file wich will load all the students
*/
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


