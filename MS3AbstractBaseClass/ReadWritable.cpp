/*have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.

Priya Khatri | 110149176 | pkhatri4@myseneca.ca*/
#include "ReadWritable.h"

namespace sdds
{
	ReadWritable::ReadWritable()
	{
		commaSepValFlag = false;
	}

	ReadWritable::~ReadWritable()
	{//empty virtual. no implementation.
	}

	bool ReadWritable::isCsv() const
	{
		return commaSepValFlag;
	}

	void ReadWritable::setCsv(bool value)
	{
		commaSepValFlag = value;
	}

	std::istream& operator>>(std::istream& is, ReadWritable& rw)
	{
		rw.read(is);
		return is;
	}

	std::ostream& operator<<(std::ostream& os, const ReadWritable& rw)
	{
		rw.write(os);
		return os;
	}
}