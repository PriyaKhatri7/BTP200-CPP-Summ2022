#ifndef SDDS_MOTORVEHICLE_H
#define SDDS_MOTORVEHICLE_H
#include <iostream>
#include <ostream>
#include <istream>
using namespace std;

namespace sdds
{
	class MotorVehicle
	{
		char m_licenseplate[32];
		char m_address[64];
		int m_year; //year vehicle was built

	public:
		MotorVehicle();
		MotorVehicle(const char* license, int year);
		void moveTo(const char* address);
		void write(ostream& os) const;
		void read(istream& is);

	};
	ostream& operator<<(ostream& os, const MotorVehicle& m);
	istream& operator>>(istream& in, MotorVehicle& m);
}

#endif // !SDDS_MOTORVEHICLE_H

