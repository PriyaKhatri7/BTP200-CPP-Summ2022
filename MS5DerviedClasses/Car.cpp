/*have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.

Priya Khatri | 110149176 | pkhatri4@myseneca.ca*/
#include <iostream>
#include <cstring> //strcpy and strlen
#include "Car.h"
#include "ReadWritable.h"
#include "Vehicle.h"
using namespace std;

namespace sdds
{
	Car::Car()
	{
		c_carwashflag = false;
		cv_licenseplate[0] = '\0';
		cv_makemodel = nullptr;
	}

	Car::Car(const char* license, const char* model) : Car()
	{
		if (license != nullptr && (strlen(license) < 8 && strlen(license) > 1) && model != nullptr && strlen(model) > 2)
		{
			strcpy(cv_licenseplate, license);
			cv_makemodel = new char[strlen(model) + 1]; strcpy(cv_makemodel, model);
			c_carwashflag = false;
		}
	}

	istream& Car::read(istream& read)
	{
		if (isCsv() == true)
		{
			Vehicle::read(read); //read of base class vehicle
			read >> c_carwashflag; //read value 1/0 into carwash flag
			read.ignore(800, '\n');
		}
		else
		{
			bool exitapp = false;
			char select[10];

			cout << "\nCar information entry\n";
			Vehicle::read(read); //read from base class
			cout << "Carwash while parked? (Y)es/(N)o: ";

			read.getline(select, 3);

			while (exitapp == false)
			{
				if ((select[0] == 'Y' || select[0] == 'y') && (select[1] == '\0'))
				{
					c_carwashflag = true;
					return read;
				}
				else if ((select[0] == 'N' || select[0] == 'n') && (select[1] == '\0'))
				{
					c_carwashflag = false;
					return read;
				}
				else
				{
					read.clear();
					read.ignore(9000, '\n');
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: "; //will keep asking until user is correct answer
					read.getline(select, 3);
				}
			}
		}
		return read;
	}

	ostream& Car::write(ostream& write) const
	{
		if (Vehicle::isEmpty())
		{
			write << "Invalid Car Object\n";
		}
		else if (isCsv() == true)
		{
			write << "C,";
			Vehicle::write(write);
			write << c_carwashflag << endl;
		}
		else
		{
			write << "Vehicle type: Car\n";
			Vehicle::write(write);

			if (isCsv() == true)
			{
				write << c_carwashflag << endl;
			}
			else
			{
				if (c_carwashflag == true)
				{
					write << "With Carwash\n";
				}
				else
				{
					write << "Without Carwash" << endl;
				}
			}
		}
		return write;
	}

	Car::~Car()
	{
		delete[] cv_makemodel;
		cv_makemodel = nullptr;
	}
}