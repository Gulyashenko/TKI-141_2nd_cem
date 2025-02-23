#include "Person.h"

Person::Person()
{
	lastname = "";
	name = "";
	patronymic = "";
}

Person::Person(const string& ln, const string& n, const string p)
{
	lastname = ln;
	name = n;
	patronymic = p;
}

void Person::show(const string& lastname, const string& name)
{
	cout << lastname << " " << name << endl;
}

void Person::showFormal(const string& lastname, const string& name, const string& patronymic)
{
	cout << lastname << " " << name << " " << patronymic << endl;
}