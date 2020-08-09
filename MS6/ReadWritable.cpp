/*have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.

Priya Khatri | 110149176 | pkhatri4@myseneca.ca*/

#include <iostream>
#include "ReadWritable.h"

using namespace std;

namespace sdds
{
	ReadWritable::ReadWritable()
	{
		m_CommaSeparationFlag = false;
	}

	ReadWritable::~ReadWritable()
	{
		//empty virtual. no implementation.
	}

	bool ReadWritable::isCsv() const
	{
		return m_CommaSeparationFlag;
	}

	void ReadWritable::setCsv(bool value)
	{
		m_CommaSeparationFlag = value;
	}

	ostream& operator<<(ostream& os, const ReadWritable& wrt)
	{
		wrt.write(os);
		return os;
	}

	istream& operator>>(istream& is, ReadWritable& rd)
	{
		rd.read(is);
		return is;
	}





}