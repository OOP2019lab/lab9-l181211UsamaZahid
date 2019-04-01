#include "Employee.h"
#include "Address.h"
#include "Project.h"

//Constructor
Employee::Employee(char*name, const Address& ad1)
{
	emp_name = new char[strlen(name)];
	for (int i = 0; i < strlen(name); i++)
		emp_name[i] = name[i];
	emp_name[strlen(name)] = '\0';
	emp_address = new Address(ad1);
	noofProjects = 0;
	emp_projects = new Project*[2];
	emp_projects[0] = nullptr;
	emp_projects[1] = nullptr;
}

//Copy Constructor
Employee::Employee(const Employee& ep2)
{
	emp_name = new char[strlen(ep2.emp_name)];
	for (int i = 0; i < strlen(ep2.emp_name); i++)
		emp_name[i] = ep2.emp_name[i];
	emp_name[strlen(ep2.emp_name)] = '\0';
	emp_address = new Address(*ep2.emp_address);
	noofProjects = ep2.noofProjects;
	emp_projects = new Project*[noofProjects];
	for (int i = 0; i < noofProjects; i++)
		addProject(ep2.emp_projects[i]);
}

//Output Overload
ostream& operator<<(ostream& osObject, const Employee& ep1)
{
	cout << "Employee Name: " << ep1.emp_name << endl;
	cout << "Employee Address:\n" << ep1.emp_address << endl;
	cout << "Employee's Projects: " << ep1.noofProjects << endl;
	if (ep1.emp_projects != nullptr)
	{
		cout << "Projects:\n";
		for (int i = 0; i < ep1.noofProjects; i++)
			cout << i << ") " << ep1.emp_projects[i] << endl;
	}
	return osObject;
}

//Store Overload
const Employee& Employee::operator=(const Employee& other)
{
	emp_name = new char[strlen(other.emp_name)];
	for (int i = 0; i < strlen(other.emp_name); i++)
		emp_name[i] = other.emp_name[i];
	emp_name[strlen(other.emp_name)] = '\0';
	emp_address = new Address(*other.emp_address);
	if (noofProjects > 0)
	{
		for (int i = 0; i < noofProjects; i++)
			delete emp_projects[i];
		delete emp_projects;
	}
	noofProjects = other.noofProjects;
	emp_projects = new Project*[noofProjects];
	for (int i = 0; i < noofProjects; i++)
		addProject(other.emp_projects[i]);
	return *this;
}

//Project Adder
void Employee::addProject(Project const* p2)
{
	if (noofProjects < 2)
	{
		emp_projects[noofProjects] = new Project(p2[0]);
		noofProjects++;
	}
	else
		cout << "Maximum projects held\n";
}

//Project Remover
void Employee::removeProject(Project const* p2)
{
	bool found = 0;
	for (int i = 0; i < noofProjects; i++)
	{
		if (emp_projects[i][0].getname()==p2[0].getname())
			if (emp_projects[i][0].getbudget()==p2[0].getbudget())
				if (emp_projects[i][0].getduration() == p2[0].getduration())
				{
					delete emp_projects[i];
					noofProjects--;
					found = 1;
					emp_projects[i]=nullptr;
				}
	}
	if (found == 1)
	{
		Project** temp = new Project*[noofProjects];
		for (int i = 0; i < noofProjects + 1; i++)
		{
			if (emp_projects[i] != nullptr)
				temp[i] = emp_projects[i];
		}
		for (int i = 0; i < noofProjects+1; i++)
		{
			delete emp_projects[i];
		}
		delete[]emp_projects;
		emp_projects = temp;
	}
}

//Deconstructor
Employee::~Employee()
{
	delete[]emp_name;
	delete[]emp_address;
	for (int i = 0; i < noofProjects; i++)
		delete emp_projects[i];
	delete emp_projects;
}