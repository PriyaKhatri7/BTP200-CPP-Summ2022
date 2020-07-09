/*
Priya Khatri | 110149176 | pkhatri4@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
*/

#ifndef SDDS_SHIP_H
#define SDDS_SHIP_H
#include "Engine.h"

namespace sdds
{
	const double MIN_STD_POWER = 90.111;
	const double MAX_STD_POWER = 99.999;

	class Ship 
	{
		Engine m_engines[10]; //statically allocated arr of engines. Size 10 max, can have less than. 
		char m_type[TYPE_MAX_SIZE]; //type of model ship
		int m_engCnt;//# of engines installed
		//double* outputEngPower; //total output power

	public:
		Ship();
		Ship(const char* type, Engine engine[], int sizeEng);
		float calculatePower() const;
		explicit operator bool() const; //convert to bool
		Ship& operator+=(Engine engine);
		bool operator<(double power) const;
		void display() const;
	};
	bool operator<(double power, const Ship& theShip);
}



#endif // !SDDS_SHIP_H
