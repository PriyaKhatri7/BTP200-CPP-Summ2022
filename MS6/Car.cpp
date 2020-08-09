/*I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.

Priya Khatri | 110149176 | pkhatri4@myseneca.ca*/

#include <iostream>
#include <cstring>
#include "Car.h"
#include "Vehicle.h"
#include "ReadWritable.h"

using namespace std;

namespace sdds
{
	Car::Car() : Vehicle()
	{
		m_carWashFlag = false;
		m_clicensePlate = nullptr;
		m_makeModel = nullptr;

	}

	Car::Car(const char* plate, const char* makeModel) : Car()
	{
		if ((plate != nullptr && strlen(plate) < 8 && strlen(plate) > 1) && (makeModel != nullptr) && (strlen(makeModel) > 2))
		{
			m_clicensePlate = new char[strlen(plate) + 1];
			strcpy(m_clicensePlate, plate);
			m_makeModel = new char[strlen(makeModel) + 1];
			strcpy(m_makeModel, makeModel);
			m_carWashFlag = false;
		}
	}

	Car::~Car()
	{
		delete[] m_makeModel;
		m_makeModel = nullptr;
	}

	istream& Car::read(istream& istr)
	{
		bool exitloop = false;
		char option[10];

		if (this->isCsv() == true)
		{
			Vehicle::read(istr);
			istr >> m_carWashFlag;
			istr.ignore(800, '\n');
		}
		else
		{
			cout << "\nCar information entry\n";
			Vehicle::read(istr);

			cout << "Carwash while parked? (Y)es/(N)o: ";
			istr.getline(option, 3);

			while (exitloop == false)
			{
				if ((option[0] == 'Y' || option[0] == 'y') && (option[1] == '\0'))
				{
					m_carWashFlag = true;
					return istr;
				}
				else if ((option[0] == 'N' || option[0] == 'n') && (option[1] == '\0'))
				{
					m_carWashFlag = false;
					return istr;
				}
				else
				{
					istr.clear();
					istr.ignore(9000, '\n');
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
					istr.getline(option, 3);
				}
			}

		}

		return istr;

	}

	ostream& Car::write(std::ostream& ostr) const
	{
		if (Vehicle::isEmpty())
		{
			ostr << "Invalid Car Object" << endl;
		}
		else if (isCsv() == true)
		{
			ostr << "C,";

			Vehicle::write(ostr);

			ostr << m_carWashFlag << endl;
		}
		else
		{
			ostr << "Vehicle type: Car" << endl;

			Vehicle::write(ostr);

			if (isCsv() == true)
			{
				ostr << m_carWashFlag << endl;
			}
			else
			{
				if (m_carWashFlag == true)
				{
					ostr << "With Carwash" << endl;
				}
				else
				{
					ostr << "Without Carwash" << endl;
				}
			}
		}

		return ostr;
	}
}