#include <iostream>
#include <cstring>
#include "MotorVehicle.h"
using namespace std;

namespace sdds
{
	MotorVehicle::MotorVehicle()
	{
		m_licenseplate[0] = '\0';
		m_address[0] = '\0';
		m_year = 0;

	}

	MotorVehicle::MotorVehicle(const char* license, int year) : MotorVehicle()
	{
		strcpy(m_licenseplate, license);
		m_year = year;
		string temp = "Factory";
		strcpy(m_address, temp.c_str()); //c_str copies string to array
	}

	void MotorVehicle::moveTo(const char* address)
	{
		if (strcmp(m_address, address) != 0)
		{
			cout << "|"; cout.width(10); cout << right << m_licenseplate << "| ";
			cout << "|"; cout.width(20); cout << right << m_address;
			cout << " --->--- ";
			cout.width(20); cout << left << address << "|" << endl;
			strcpy(m_address, address);
		}
	}
	void MotorVehicle::write(ostream& os) const
	{
		os << "| " << m_year << " | " << m_licenseplate << " | " << m_address;
	}

	void MotorVehicle::read(istream& is)
	{
		cout << "Built year: "; is >> m_year;
		cout << "License plate: "; is >> m_licenseplate;
		cout << "Current location: "; is >> m_address;
	}

	ostream& operator<<(ostream& os, const MotorVehicle& m)
	{
		m.write(os);
		return os;
	}

	istream& operator>>(istream& in, MotorVehicle& m)
	{
		m.read(in);
		return in;
	}
}
