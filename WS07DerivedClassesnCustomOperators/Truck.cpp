#include <iostream>
#include "Truck.h"
#include "MotorVehicle.h"

namespace sdds
{
	Truck::Truck()
	{
		km_max = 0;
		km_curr = 0;
	}

	//MotorVehicle(plate,year) is passing those values to the base constructor
	Truck::Truck(const char* license, int year, double max, const char* address) : MotorVehicle(license, year)
	{
		km_curr = 0;
		km_max = max;
		moveTo(address); //move truck to the address
	}

	bool Truck::addCargo(double cargo)
	{
		bool value = true;
		if (km_curr < km_max)
		{
			km_curr += cargo;

			if (km_curr > km_max)
			{
				km_curr = km_max;
			}
		}
		else
		{
			value = false;
		}
		return value;
	}

	bool Truck::unloadCargo()
	{
		bool value = false;
		if (km_curr == 0)
		{
			value = false;
		}
		else if(km_curr > 0)
		{
			km_curr = 0;
			value = true;
		}
		return value;
	}

	void Truck::write(ostream& os) const
	{
		MotorVehicle::write(os);
		os << " | " << this->km_curr << "/" << this->km_max;
	}

	void Truck::read(istream& in)
	{
		MotorVehicle::read(in); 
		cout << "Capacity: "; in >> km_max;
		cout << "Cargo: "; in >> km_curr;
	}

	std::ostream& operator<<(std::ostream& os, const sdds::Truck& t)
	{
		t.write(os);
		return os;
	}

	std::istream& operator>>(std::istream& in, sdds::Truck& t)
	{
		t.read(in);
		return in;
	}
}