/*have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.

Priya Khatri | 110149176 | pkhatri4@myseneca.ca*/
#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include "Vehicle.h"

namespace sdds
{
	class Car : public Vehicle
	{
		bool c_carwashflag; //should the car be able to store having carwash during the park or not
		char cv_licenseplate[8 + 1];
		char* cv_makemodel;

	public:
		Car();
		Car(const char* license, const char* model);
		Car(const Car&) = delete; //copying prohibited
		Car& operator=(const Car&) = delete;
		std::istream& read(std::istream& read);
		std::ostream& write(std::ostream& write) const;
		~Car();
	};
}
#endif // !SDDS_CAR_H

