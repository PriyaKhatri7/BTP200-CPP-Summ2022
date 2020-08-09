/*have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.

Priya Khatri | 110149176 | pkhatri4@myseneca.ca*/

#include <cstring>
#include "Vehicle.h"
using namespace std;

namespace sdds
{
	Vehicle::Vehicle()
	{
		setEmpty();
	}

	Vehicle::Vehicle(const char* license, const char* model) : v_makeModel(nullptr)
	{
		//licence has to be 1-8 chars && makeModel has to have ATLEAST 2 chars
		if (license != nullptr && (strlen(license) < 8 && strlen(license) > 1) && model != nullptr && strlen(model) > 2)
		{
			strcpy(v_licenseplate, license);
			v_makeModel = new char[strlen(model) + 1]; strcpy(v_makeModel, model);
			v_parkingspotnum = 0;
		}
		else
		{
			setEmpty();
		}
	}

	Vehicle::~Vehicle()
	{
		delete[] v_makeModel;
		v_makeModel = nullptr;
	}

	int Vehicle::getParkingSpot() const
	{
		return v_parkingspotnum;
	}

	void Vehicle::setParkingSpot(int newSpot)
	{
		if (newSpot >= 0)
		{
			v_parkingspotnum = -1;
			v_parkingspotnum = newSpot;
		}
		else
		{
			delete[] v_makeModel;
			setEmpty();
		}
	}

	istream& Vehicle::read(istream& read)
	{
		char tmp[61 + 1];
		tmp[0] = 0;
		int ifFail = 0;
		bool flag = false;

		if (!isEmpty())
		{
			delete[] v_makeModel;
			setEmpty();
		}
		if (isCsv() == true)
		{
			read >> v_parkingspotnum;
			if (read.fail())
			{
				ifFail = 1;
				read.clear();
			}
			read.ignore(1000, ','); //ignore 1 char for delimiter comma
			read.getline(v_licenseplate, 8, ','); //read up to 8 chars

			if (read.fail())
			{
				ifFail = 1;
				read.clear();
			}
			read.getline(tmp, 60, ',');

			if (read.fail())
			{
				ifFail = 1;
				read.clear();
			}
		}

		else
		{
			cout << "Enter Licence Plate Number: ";
			do
			{
				read.getline(tmp, 62);

				//read up to 8 chars. if user enters more then error and try again
				if (strlen(tmp) > 8)
				{
					cout << "Invalid Licence Plate, try again: ";
					flag = false;
				}
				else
				{
					strcpy(v_licenseplate, tmp);
					flag = true;
				}
			} while (!flag);

			cout << "Enter Make and Model: ";
			do
			{
				read.getline(tmp, 62);
				//read 2-60 chars.
				if (strlen(tmp) < 2 || strlen(tmp) > 60)
				{
					cout << "Invalid Make and model, try again: ";
					flag = false;
				}
				else
				{
					flag = true;
				}
			} while (!flag);

			v_parkingspotnum = 0;
		}

		if (ifFail != 1)
		{
			int t = strlen(v_licenseplate);
			for (auto i = 0; i < t; i++)
			{
				v_licenseplate[i] = toupper(v_licenseplate[i]);
			}
			setMakeModel(tmp);
		}
		else
		{
			delete[] v_makeModel;
			setEmpty();
		}
		return read;
	}

	ostream& Vehicle::write(ostream& write) const
	{
		if (isEmpty())
		{
			write << "Invalid Vehicle Object" << endl;
		}

		else if (isCsv() == true)
		{
			write << v_parkingspotnum << "," << v_licenseplate << "," << v_makeModel << ",";
		}

		else
		{
			write << "Parking Spot Number: ";
			if (v_parkingspotnum == 0)
			{
				write << "N/A" << endl;
			}
			else
			{
				write << v_parkingspotnum << endl;
			}

			write << "Licence Plate: ";
			for (unsigned int i = 0; i < strlen(v_licenseplate); i++)
			{
				putchar(toupper(v_licenseplate[i]));
			}
			write << endl;

			write << "Make and Model: ";
			write << v_makeModel << endl;
		}
		return write;
	}

	void Vehicle::setEmpty()
	{
		v_licenseplate[0] = '\0';
		v_makeModel = nullptr;
		v_parkingspotnum = 0;
	}

	bool Vehicle::isEmpty() const
	{
		if (v_licenseplate[0] == '\0')
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	istream& Vehicle::getLicensePlate(istream& license) const
	{
		return license;
	}

	istream& Vehicle::getMakeModel(istream& model) const
	{
		return model;
	}

	void Vehicle::setMakeModel(const char* newModel)
	{
		if (newModel[0] != 0 && newModel != nullptr)
		{
			delete[] v_makeModel;
			v_makeModel = new char[strlen(newModel) + 1];
			strcpy(v_makeModel, newModel);
		}
		else
		{
			delete[] v_makeModel;
			setEmpty();
		}
	}
	bool operator==(const Vehicle& lp, const char* lpValue)
	{
		if (strcmp(lp.v_licenseplate, lpValue)) //if license plate of Vehicle are identical to lpValue return true
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	bool operator==(const Vehicle& lp, const Vehicle& lpValue)
	{
		if (strcmp(lp.v_licenseplate, lpValue.v_licenseplate)) //compare both vehicles for same license plate
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}