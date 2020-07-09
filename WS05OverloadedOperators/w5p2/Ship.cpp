#include <iostream>
#include <iomanip>
#include <cstring>
#include "Ship.h"
using namespace std;

namespace sdds
{
	Ship::Ship()
	{
		m_engines = nullptr;
		m_type = nullptr;
		m_engCnt = 0;
	}

	Ship::Ship(const char* type, Engine engine[], int sizeEng)
	{
		if (type != nullptr && engine > 0)
		{
			m_type = new char[strlen(type) + 1];
			strcpy(m_type, type);
			m_engines = new Engine[sizeEng];
			for (int i = 0; i < sizeEng; i++)
			{
				//copying over for engine since it's a stat arr
				m_engines[i] = engine[i];
			}
			this->m_engCnt = sizeEng;
		}
		else
		{
			Ship();
		}
	}

	Ship::~Ship()
	{
		delete[] m_engines;
		delete[] m_type;
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
		if (m_engCnt != 0 && m_type != nullptr)
		{
			//create a new array
			Engine* tmpArr = new Engine[m_engCnt + 1];

			for (auto i = 0; i < m_engCnt; i++)
			{
				tmpArr[i] = m_engines[i]; //copying 1 element at a time from old array to new array
			}

			tmpArr[m_engCnt] = engine; //then updates the count

			delete[] m_engines; //delete the old array
			
			m_engines = tmpArr; //switch to bigger array
			++m_engCnt; //update the size
		}
		else
		{
			cout << "The object is not valid! Engine cannot be added!" << endl;
			this->~Ship();
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
		if (this->m_type == nullptr)
		{
			cout << "No available data" << endl;
		}
		else
		{
			cout << m_type << " - "; cout.width(6); cout << fixed << setprecision(2); 
			cout << calculatePower() << endl;

			for (int i = 0; i < m_engCnt; i++)
			{
				m_engines[i].display();
			}
			cout.unsetf(ios::fixed); cout.precision(5);
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