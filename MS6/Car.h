/*I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.

Priya Khatri | 110149176 | pkhatri4@myseneca.ca*/

#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include "Vehicle.h"
#include "ReadWritable.h"

namespace sdds
{
	class Car : public Vehicle
	{
		bool m_carWashFlag;
		char* m_clicensePlate;
		char* m_makeModel;

	public:

		Car();
		Car(const char*, const char*);
		~Car();
		Car(const Car&) = delete;
		Car& operator=(const Car&) = delete;

		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;

	};
}
#endif // !SDDS_CAR_H
