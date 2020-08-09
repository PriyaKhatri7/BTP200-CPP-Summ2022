/*have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.

Priya Khatri | 110149176 | pkhatri4@myseneca.ca*/
#ifndef SDDS_MOTORCYCLE_H
#define SDDS_MOTORCYCLE_H

#include "Vehicle.h"

namespace sdds
{
	class Motorcycle : public Vehicle
	{
		bool m_sidecarflag; //if a sidecar is attached or not
		char mv_licenseplate[8 + 1];
		char* mv_makemodel;

	public:
		Motorcycle();
		Motorcycle(const char* license, const char* model);
		Motorcycle(const Motorcycle&) = delete;
		Motorcycle& operator=(const Motorcycle&) = delete;
		std::istream& read(std::istream& read);
		std::ostream& write(std::ostream& write) const;
		~Motorcycle();
	};
}
#endif // !SDDS_MOTORCYCLE_H