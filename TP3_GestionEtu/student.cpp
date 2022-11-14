#include "student.h"
#include <qstring.h>

Student::Student()
{
}

Student::Student(int i, QString ln, QString fn, int dept, QString ba)
{
	id = i;
	lastName = ln;
	firstName = fn;
	departement = dept;
	bac = ba;
}

int Student::getId()
{
	return id;
}

int Student::getDept()
{
	return departement;
}

QString Student::getLastName()
{
	return lastName;
}

QString Student::getFirstName()
{
	return firstName;
}

QString Student::getBac()
{
	return bac;
}
