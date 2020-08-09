/*have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.

Priya Khatri | 110149176 | pkhatri4@myseneca.ca*/

#include <iostream>
#include <cstring>
#include "Motorcycle.h"
#include "Vehicle.h"
#include "ReadWritable.h"

using namespace std;

namespace sdds
{
	Motorcycle::Motorcycle() : Vehicle()
	{
		m_sideCar = false;
		m_mlicensePlate = nullptr;
		m_makeModel = nullptr;

	}

	Motorcycle::Motorcycle(const char* plate, const char* makeModel) : Motorcycle()
	{
		if ((plate != nullptr && strlen(plate) < 8 && strlen(plate) > 1) && (makeModel != nullptr) && (strlen(makeModel) > 2))
		{
			m_mlicensePlate = new char[strlen(plate) + 1];
			strcpy(m_mlicensePlate, plate);
			m_makeModel = new char[strlen(makeModel) + 1];
			strcpy(m_makeModel, makeModel);
			m_sideCar = false;
		}
	}

	Motorcycle::~Motorcycle()
	{
		delete[] m_makeModel;
		m_makeModel = nullptr;
	}

	istream& Motorcycle::read(istream& istr)
	{
		bool exitloop = false;
		char option[10];

		if (this->isCsv() == true)
		{
			Vehicle::read(istr);
			istr >> m_sideCar;
			istr.ignore(800, '\n');
		}
		else
		{
			cout << "\nMotorcycle information entry\n";
			Vehicle::read(istr);

			cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
			istr.getline(option, 3);

			while (exitloop == false)
			{
				if ((option[0] == 'Y' || option[0] == 'y') && (option[1] == '\0'))
				{
					m_sideCar = true;
					return istr;
				}
				else if ((option[0] == 'N' || option[0] == 'n') && (option[1] == '\0'))
				{
					m_sideCar = false;
					return istr;
				}
				else
				{
					istr.clear();
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
					istr.getline(option, 3);
				}
			}
		}

		return istr;
	}

	ostream& Motorcycle::write(std::ostream& ostr) const
	{
		if (isEmpty())
		{
			ostr << "Invalid Motorcycle Object" << endl;
		}
		else if (isCsv() == true)
		{
			ostr << "M,";

			Vehicle::write(ostr);

			ostr << m_sideCar << endl;
		}
		else
		{
			ostr << "Vehicle type: Motorcycle" << endl;

			Vehicle::write(ostr);

			if (isCsv() == true)
			{
				ostr << m_sideCar << endl;
			}
			else
			{
				if (m_sideCar == true)
				{
					ostr << "With Sidecar" << endl;
				}
			}
		}

		return ostr;
	}
}