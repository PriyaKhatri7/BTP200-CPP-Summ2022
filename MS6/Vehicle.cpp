/*I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.

Priya Khatri | 110149176 | pkhatri4@myseneca.ca*/

#include <iostream>
#include <cstring>
#include <cctype>
#include "Vehicle.h"
#include "ReadWritable.h"

using namespace std;

namespace sdds
{
	Vehicle::Vehicle()
	{
		m_licensePlate = nullptr;
		m_makeModel = nullptr;
		m_parkingNumber = 0;
	}

	Vehicle::Vehicle(const char* plate, const char* makeModel)
	{
		if ((plate != nullptr && strlen(plate) < 8 && strlen(plate) > 1) && (makeModel != nullptr) && (strlen(makeModel) > 2))
		{
			m_licensePlate = new char[strlen(plate) + 1];
			strcpy(m_licensePlate, plate);
			m_makeModel = new char[strlen(makeModel) + 1];
			strcpy(m_makeModel, makeModel);
			m_parkingNumber = 0;
		}
		else
		{
			setEmpty();
		}

	}

	Vehicle::~Vehicle()
	{
		delete[] m_makeModel;
		m_makeModel = nullptr;
	}

	void Vehicle::setEmpty()
	{
		m_licensePlate = nullptr;
		m_makeModel = nullptr;
		m_parkingNumber = 0;
	}

	bool Vehicle::isEmpty() const
	{
		if (m_makeModel == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	istream& Vehicle::getLicensePlate(istream& plate) const
	{
		return plate;
	}

	istream& Vehicle::getMakeModel(istream& makeModel) const
	{
		return makeModel;
	}

	void Vehicle::setMakeModel(const char* newMakeModel)
	{
		if (newMakeModel != nullptr)
		{
			m_makeModel = nullptr;
			m_makeModel = new char[strlen(newMakeModel) + 1];
			strcpy(m_makeModel, newMakeModel);
		}
		else
		{
			setEmpty();
		}
	}

	int Vehicle::getParkingSpot() const
	{
		return this->m_parkingNumber;
	}

	void Vehicle::setParkingSpot(int newParkingSpot)
	{
		if (newParkingSpot >= 0)
		{
			m_parkingNumber = -1;
			m_parkingNumber = newParkingSpot;
		}
		else
		{
			setEmpty();
		}
	}

	bool Vehicle::operator==(const char* plate) const
	{
		if (strncmp(this->m_licensePlate, plate, 8) == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Vehicle::operator==(const Vehicle& lhs) const
	{
		if (strcmp(lhs.m_licensePlate, this->m_licensePlate))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	istream& Vehicle::read(istream& istr)
	{
		char tempLicence[100] = "\0";
		char tempMakeModel[100] = "\0";
		
		if (this->isCsv() == true)
		{
			istr.ignore(1, ',');
			istr >> m_parkingNumber;
			istr.ignore(1, ',');
			istr.getline(tempLicence, 10, ',');

			for (unsigned int i = 0; i < strlen(tempLicence); i++)
			{
				tempLicence[i] = toupper(tempLicence[i]);
			}

			if (istr.fail())
			{
				delete[] m_licensePlate;
				m_licensePlate = nullptr;
			}
			else
			{
				delete[] m_licensePlate;
				m_licensePlate = nullptr;
				m_licensePlate = new char[strlen(tempLicence) + 1];
				strcpy(m_licensePlate, tempLicence);
			}

			istr.getline(tempMakeModel, 60, ',');

			if (istr.fail())
			{
				delete[] m_makeModel;
				m_makeModel = nullptr;
			}
			else
			{
				delete[] m_makeModel;
				m_makeModel = nullptr;
				m_makeModel = new char[strlen(tempMakeModel) + 1];
				strcpy(m_makeModel, tempMakeModel);
			}
		}
		else
		{

			cout << "Enter Licence Plate Number: ";
			do
			{
				istr.clear();
				istr.ignore(100, '\n');
				istr.getline(tempLicence, 10, '\n');

				for (unsigned int i = 0; i < strlen(tempLicence); i++)
				{
					tempLicence[i] = toupper(tempLicence[i]);
				}
				delete[] m_licensePlate;
				m_licensePlate = nullptr;
				m_licensePlate = new char[strlen(tempLicence) + 1];
				strcpy(m_licensePlate, tempLicence);

				while (strlen(m_licensePlate) > 8 || strcmp(m_licensePlate, "") == 0 || istr.fail())
				{
					istr.clear();
					cout << "Invalid Licence Plate, try again: ";
					istr.getline(tempLicence, 10, '\n');
					delete[] m_licensePlate;
					m_licensePlate = nullptr;
					m_licensePlate = new char[strlen(tempLicence) + 1];
					strcpy(m_licensePlate, tempLicence);
				}
			} while (strlen(m_licensePlate) > 8);

			cout << "Enter Make and Model: ";
			do
			{
				istr.getline(tempMakeModel, 60, '\n');

				if (istr.fail())
				{
					delete[] m_makeModel;
					m_makeModel = nullptr;
				}
				else
				{
					delete[] m_makeModel;
					m_makeModel = nullptr;
					m_makeModel = new char[strlen(tempMakeModel) + 1];
					strcpy(m_makeModel, tempMakeModel);
				}

				if (strlen(m_makeModel) < 2 || strlen(m_makeModel) > 60)
				{
					cout << "Invalid Make and model, try again: ";
				}

			} while (strlen(m_makeModel) < 2 || strlen(m_makeModel) > 60);

		}

		if (istr.fail())
		{
			setEmpty();
		}

		return istr;
	}

	ostream& Vehicle::write(std::ostream& ostr) const
	{
		if (isEmpty())
		{
			ostr << "Invalid Vehicle Object" << endl;
		}
		else if (this->isCsv() == true)
		{
			ostr << m_parkingNumber << ",";

			ostr << m_licensePlate << ",";

			ostr << m_makeModel << ",";
		}
		else if (this->isCsv() == false)
		{
			ostr << "Parking Spot Number: ";

			if (m_parkingNumber == 0)
			{
				ostr << "N/A" << endl;
			}
			else
			{
				ostr << m_parkingNumber << endl;
			}

			ostr << "Licence Plate: ";

			for (unsigned int i = 0; i < strlen(m_licensePlate); i++)
			{
				putchar(toupper(m_licensePlate[i]));
			}
			ostr << endl;

			ostr << "Make and Model: ";
			ostr << m_makeModel << endl;

		}

		return ostr;

	}
}