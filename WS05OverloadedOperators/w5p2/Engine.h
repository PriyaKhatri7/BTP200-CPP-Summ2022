/*
Priya Khatri | 110149176 | pkhatri4@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
*/

#ifndef SDDS_ENGINE_H
#define SDDS_ENGINE_H

namespace sdds
{
	const int TYPE_MAX_SIZE = 30;

	class Engine
	{
		double m_size;
		char m_type[TYPE_MAX_SIZE];

	public:
		Engine();
		Engine(const char* type, double size);
		double get() const;
		void display() const;
	};
}
#endif // !SDDS_ENGINE_H