/*I have done all the coding by myself and only copied the code
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
		char* m_licensePlate;
		char* m_makeModel;
		int m_parkingNumber;

	public:

		Vehicle();
		Vehicle(const char*, const char*);
		~Vehicle();
		Vehicle(const Vehicle&) = delete;
		Vehicle& operator=(const Vehicle&) = delete;
		
		bool operator==(const char*) const;
		bool operator==(const Vehicle&) const;
		int getParkingSpot() const;
		void setParkingSpot(int);
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;

	protected:

		void setEmpty();
		bool isEmpty() const;
		std::istream& getLicensePlate(std::istream&) const;
		std::istream& getMakeModel(std::istream&) const;
		void setMakeModel(const char*);

	};

	





}

#endif // !SDDS_VEHICLE_H

