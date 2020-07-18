#ifndef SDDS_TRUCK_H
#define SDDS_TRUCK_H
#include <iostream>

#include "MotorVehicle.h"
using namespace std;
namespace sdds
{
	class Truck : public MotorVehicle //auto private. inherit from MotorVehicle class
	{
		double km_max; //max capacity km a Truck cargo can carry
		double km_curr; //current cargo load km
	public:
		Truck();
		Truck(const char* license, int year, double max, const char* address);
		bool addCargo(double cargo);
		bool unloadCargo();
		void write(ostream& os) const;
		void read(istream& in);
	};
	std::ostream& operator<<(std::ostream& os, const sdds::Truck& t);
	std::istream& operator>>(std::istream& in, sdds::Truck& t);
}
#endif // !SDDS_TRUCK_H

