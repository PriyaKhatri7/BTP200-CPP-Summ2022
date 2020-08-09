/*have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.

Priya Khatri | 110149176 | pkhatri4@myseneca.ca*/

#ifndef SDDS_VEHICLE_H
#define SDDS_VEHICLE_H
#include <iostream>
#include "ReadWritable.h"

namespace sdds
{
	class Vehicle : public ReadWritable
	{
		char v_licenseplate[8 + 1]; //1-8 characters. Static array
		char* v_makeModel; //can't be null or empty
		int v_parkingspotnum; //0 parking spot means the vehicle is not parked

	public:
		Vehicle();
		Vehicle(const char* license, const char* model);
		Vehicle(const Vehicle&) = delete;
		Vehicle& operator=(const Vehicle&) = delete;
		~Vehicle();
		int getParkingSpot() const;
		void setParkingSpot(int newSpot);
		friend bool operator==(const Vehicle& lp, const char* lpValue);
		friend bool operator==(const Vehicle& lp, const Vehicle& lpValue);
		std::istream& read(std::istream& read);
		std::ostream& write(std::ostream& write) const;

	protected:
		void setEmpty();
		bool isEmpty() const;
		std::istream& getLicensePlate(std::istream& license) const; //read only address of license plate 
		std::istream& getMakeModel(std::istream& model) const; //read only address for the make model
		void setMakeModel(const char* newModel);
	};

}
#endif // !SDDS_VEHICLE_H
