#include "Project.h"
//destructor
Project::Project(char*nm, int bget, int dur)
{
	int length = 0;
	for (int i = 0; nm[i] != '\0'; i++)
		length++;
	name = new char[length];
	for (int i = 0; nm[i] != '\0'; i++)
		name[i] = nm[i];
	name[length] = '\0';
	budget = bget;
	duration = dur;
}

//Copy Constructor
Project::Project(const Project& p1)
{
	int length = 0;
	for (int i = 0; p1.name[i] != '\0'; i++)
		length++;
	name = new char[length];
	for (int i = 0; p1.name[i] != '\0'; i++)
		name[i] = p1.name[i];
	name[length] = '\0';
	budget = p1.budget;
	duration = p1.duration;
}

//Print Overload
ostream& operator<<(ostream& osObject, const Project&p1)
{
	osObject << "Project Name: " << *p1.name << endl;
	osObject << "Budget: " << p1.budget << endl;
	osObject << "Duration: " << p1.duration << endl;
	return osObject;
}

//Store Overload
const Project& Project::operator=(const Project& other)
{
	int length = 0;
	for (int i = 0; other.name[i] != '\0'; i++)
		length++;
	if (name != nullptr)
		delete[]name;
	name = new char[length];
	for (int i = 0; other.name[i] != '\0'; i++)
		name[i] = other.name[i];
	name[length] = '\0';
	budget = other.budget;
	duration = other.duration;
	return *this;
}

//getters
void Project::setBudget(int val)
{
	budget = val;
}

char* Project::getname() const
{
	return name;
}

int Project::getbudget() const
{
	return budget;
}

int Project::getduration() const
{
	return duration;
}

//destructor
Project::~Project()
{
	delete[]name;
}