/*have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.

Priya Khatri | 110149176 | pkhatri4@myseneca.ca*/

#include <iostream>
#include <cstring>
#include "Motorcycle.h"
#include "ReadWritable.h"
#include "Vehicle.h"
using namespace std;
namespace sdds
{
	Motorcycle::Motorcycle()
	{
		m_sidecarflag = false;
		mv_licenseplate[0] = '\0';
		mv_makemodel = nullptr;
	}

	Motorcycle::Motorcycle(const char* license, const char* model)
	{
		if ((license != nullptr && strlen(license) < 8 && strlen(license) > 1) && (model != nullptr) && (strlen(model) > 2))
		{
			strcpy(mv_licenseplate, license);
			mv_makemodel = new char[strlen(model) + 1]; strcpy(mv_makemodel, model);
			m_sidecarflag = false;
		}
	}

	istream& Motorcycle::read(std::istream& read)
	{
		if (isCsv() == true)
		{
			Vehicle::read(read); //read of base class vehicle
			read >> m_sidecarflag; //read value 1/0 into sidecar flag
			read.ignore(800, '\n');
		}
		else
		{
			char select[10]; //input user value
			bool exitapp = false;

			cout << "\nMotorcycle information entry\n";
			Vehicle::read(read);
			cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";

			read.getline(select, 3);
			while (exitapp == false)
			{
				if ((select[0] == 'Y' || select[0] == 'y') && (select[1] == '\0'))
				{
					m_sidecarflag = true;
					return read;
				}
				else if ((select[0] == 'N' || select[0] == 'n') && (select[1] == '\0'))
				{
					m_sidecarflag = false;
					return read;
				}
				else
				{
					read.clear();
					read.ignore(9000, '\n');
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: "; //keep printing this if the user inputs anything else
					read.getline(select, 3);
				}
			}
		}
		return read;
	}

	ostream& Motorcycle::write(ostream& write) const
	{
		if (isEmpty())
		{
			write << "Invalid Motorcycle Object" << endl;
		}

		else if (isCsv() == true)
		{
			write << "M,";
			Vehicle::write(write);
			write << m_sidecarflag << endl;
		}
		else
		{
			write << "Vehicle type: Motorcycle" << endl;
			Vehicle::write(write);

			if (isCsv() == true)
			{
				write << m_sidecarflag << endl;
			}
			else
			{
				if (m_sidecarflag == true)
				{
					write << "With Sidecar" << endl;
				}
			}
		}
		return write;
	}

	Motorcycle::~Motorcycle()
	{
		delete[] mv_makemodel;
		mv_makemodel = nullptr;
	}
}