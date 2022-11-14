#pragma once
#include <QString>
#include <qstring.h>


class Student
{
private:
    int id;
    QString lastName;
    QString firstName;
    int departement;
    QString bac;
    
public: 
    Student();
    Student(int i, QString ln, QString fn, int dept, QString ba);
    int getId();
    int getDept();
    QString getLastName();
    QString getFirstName();
    QString getBac();
};

