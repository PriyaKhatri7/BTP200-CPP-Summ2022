#include <iostream>
#include <cstring>
#include "Engine.h"

using namespace std;

namespace sdds
{
	Engine::Engine()
	{
		m_size = 0.0;
		m_type[0] = '\0';
	}

	Engine::Engine(const char* type, double size)
	{
			strcpy(m_type, type);
			m_size = size;
	}

	double Engine::get() const
	{
		return m_size;
	}

	void Engine::display() const
	{
		cout << m_size << " liters - " << m_type << endl;
	}
}