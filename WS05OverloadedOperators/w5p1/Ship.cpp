#include <iostream>
#include <iomanip>
#include <cstring>
#include "Ship.h"
using namespace std;

namespace sdds
{
	Ship::Ship()
	{
		m_type[0] = '\0';
		m_engCnt = 0;
	}

	Ship::Ship(const char* type, Engine engine[], int sizeEng)
	{
		strcpy(this->m_type, type);
		for (int i = 0; i < sizeEng; i++)
		{
			//copying over for engine since it's a stat arr
			m_engines[i] = engine[i]; 
		}
		this->m_engCnt = sizeEng;
	}

	Ship::operator bool() const
	{
		if (m_type != nullptr && m_engCnt > 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	Ship& Ship::operator+=(Engine engine)
	{
		//adds engine to the arr of engines
		//numofengines < max num of engines allowed
		if (m_engCnt < 10 && this->m_type[0] != '\0')
		{
			m_engines[m_engCnt++] = engine;
			//m_engCnt++;
		}
		else
		{
			cout << "The object is not valid! Engine cannot be added!" << endl;
		}
		return *this;
	}

	float Ship::calculatePower() const
	{
		float outputEngPower = 0.0;
		float sumEngine = 0.0;

		for (int i = 0; i < m_engCnt; i++)
		{
			//engine size times 5
			sumEngine = float(this->m_engines[i].get() * 5);
			outputEngPower += sumEngine;
		}
		return outputEngPower;
	}

	bool Ship::operator<(double power) const
	{
		if (calculatePower() < power)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Ship::display() const
	{
		if (this->m_type[0] == '\0')
		{
			cout << "No available data" << endl;
		}
		else
		{
			//cout << fixed; cout << setprecision(2);
			cout << m_type << " - " << this->calculatePower() << endl; //Ship::operator<
		}
		for (int i = 0; i < this->m_engCnt; i++)
		{
			m_engines[i].display();
		}
	}


	bool operator<(double power, const Ship& theShip)
	{
		if (power < theShip.calculatePower())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

}

