/*have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.

Priya Khatri | 110149176 | pkhatri4@myseneca.ca*/
#ifndef SDDS_READWRITABLE_H
#define SDDS_READWRITABLE_H
#include <iostream>

namespace sdds
{
	class ReadWritable
	{
		bool commaSepValFlag; //hold object for comma separated mode or not
	public:
		ReadWritable();
		virtual ~ReadWritable(); //empty virtual destructor = no implementation. just an empty body
		bool isCsv() const;
		void setCsv(bool value);
		virtual std::istream& read(std::istream& istr = std::cin) = 0; //pure virtual function sig
		virtual std::ostream& write(std::ostream& ostr = std::cout) const = 0;
	};
	std::istream& operator>>(std::istream& is, ReadWritable& rw); //helper read function
	std::ostream& operator<<(std::ostream& os, const ReadWritable& rw); //helper write function
}
#endif // !SDDS_READWRITABLE_H

