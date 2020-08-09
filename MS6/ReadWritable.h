/*I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.

Priya Khatri | 110149176 | pkhatri4@myseneca.ca*/

#ifndef SDDS_READWRITABLE_H
#define SDDS_READWRITABLE_H

namespace sdds
{
	class ReadWritable
	{
		bool m_CommaSeparationFlag;//hold object for CSV mode or not

	public:

		ReadWritable();
		virtual ~ReadWritable(); //empty virtual destructor = no implementation. just an empty body
		bool isCsv() const;
		void setCsv(bool);
		virtual std::istream& read(std::istream& istr = std::cin) = 0; //pure virtual function
		virtual std::ostream& write(std::ostream& ostr = std::cout) const = 0;

	};

	std::ostream& operator<<(std::ostream&, const ReadWritable&); //helper read function
	std::istream& operator>>(std::istream&, ReadWritable&); //helper write function
}

#endif // !SDDS_READWRITABLE_H

