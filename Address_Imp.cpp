#include "Address.h"
//Constructor
Address::Address(char*house_num, char*street_Nm, char*citynm, char*Countynm)
{
	house_Number = new char[strlen(house_num)];
	for (int i = 0; i < strlen(house_num); i++)
	{
		house_Number[i] = house_num[i];
	}
	house_Number[strlen(house_num)] = '\0';

	street_Name = new char[strlen(street_Nm)];
	for (int i = 0; i < strlen(street_Nm); i++)
	{
		street_Name[i] = street_Nm[i];
	}
	street_Name[strlen(street_Nm)] = '\0';

	city = new char[strlen(citynm)];
	for (int i = 0; i < strlen(citynm); i++)
	{
		city[i] = citynm[i];
	}
	city[strlen(citynm)] = '\0';

	county = new char[strlen(Countynm)];
	for (int i = 0; i < strlen(Countynm); i++)
	{
		county[i] = Countynm[i];
	}
	county[strlen(Countynm)] = '\0';
}

//Copy Constructor
Address::Address(const Address& ad2)
{
	house_Number = new char[strlen(ad2.house_Number)];
	for (int i = 0; i < strlen(ad2.house_Number); i++)
	{
		house_Number[i] = ad2.house_Number[i];
	}
	house_Number[strlen(ad2.house_Number)] = '\0';

	street_Name = new char[strlen(ad2.street_Name)];
	for (int i = 0; i < strlen(ad2.street_Name); i++)
	{
		street_Name[i] = ad2.street_Name[i];
	}
	street_Name[strlen(ad2.street_Name)] = '\0';

	city = new char[strlen(ad2.city)];
	for (int i = 0; i < strlen(ad2.city); i++)
	{
		city[i] = ad2.city[i];
	}
	city[strlen(ad2.city)] = '\0';

	county = new char[strlen(ad2.county)];
	for (int i = 0; i < strlen(ad2.county); i++)
	{
		county[i] = ad2.county[i];
	}
	county[strlen(ad2.county)]='\0';
}

//Output Overload
ostream& operator<<(ostream& osObject, const Address& ad1)
{
	osObject << "House Number: " << *ad1.house_Number << endl;
	osObject << "Street Name: " << *ad1.street_Name << endl;
	osObject << "City: " << *ad1.city << endl;
	osObject << "County: " << *ad1.county << endl;
	return osObject;
}

//Store Overload
const Address& Address::operator=(const Address& other)
{
	if (house_Number != nullptr)
		delete[]house_Number;
	house_Number = new char[strlen(other.house_Number)];
	for (int i = 0; i < strlen(other.house_Number); i++)
	{
		house_Number[i] = other.house_Number[i];
	}
	house_Number[strlen(other.house_Number)] = '\0';

	if (street_Name != nullptr)
		delete[]street_Name;
	street_Name = new char[strlen(other.street_Name)];
	for (int i = 0; i < strlen(other.street_Name); i++)
	{
		street_Name[i] = other.street_Name[i];
	}
	street_Name[strlen(other.street_Name)] = '\0';

	if (city != nullptr)
		delete[]city;
	city = new char[strlen(other.city)];
	for (int i = 0; i < strlen(other.city); i++)
	{
		city[i] = other.city[i];
	}
	city[strlen(other.city)] = '\0';

	if (county != nullptr)
		delete[]county;
	county = new char[strlen(other.county)];
	for (int i = 0; i < strlen(other.county); i++)
	{
		county[i] = other.county[i];
	}
	county[strlen(other.county)] = '\0';
	return *this;
}

//Destructor
Address::~Address()
{
	delete[]house_Number;
	delete[]street_Name;
	delete[]city;
	delete[]county;
}