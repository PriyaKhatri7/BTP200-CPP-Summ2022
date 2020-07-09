#include <cstring> //strcpy
#include <iostream>
#include "Saiyan.h"
using namespace std;

namespace sdds
{
	Saiyan::Saiyan()
	{
		m_name = nullptr;
		m_dob = 0;
		m_power = 0;
		m_super = false;
		m_level = -1;
	}

	Saiyan::Saiyan(const char* name, int dob, int power) :Saiyan()
	{
		set(name, dob, power);
	}

	Saiyan::~Saiyan()
	{
		delete[] m_name;
		m_name = nullptr;
	}

	void Saiyan::set(const char* name, int dob, int power, int level, bool super)
	{
		if (m_name != nullptr)
		{
			delete[] m_name;
			m_name = nullptr;
		}

		if (name != nullptr && name[0] != '\0' && dob < 2020 && power > 0)
		{
			//int size = strlen(name) + 1;
			//m_name = new char[size]; //allocate dynamic memory

			m_name = new char[strlen(name) + 1];
			
			//need to allocate memory
			strcpy(m_name, name);
			m_dob = dob;
			m_power = power;
			m_super = super;
			m_level = level;
		}
		else
		{
			m_name = nullptr;
			m_dob = 0;
			m_power = 0;
			m_super = false;
			m_level = -1;
		}
	}

	bool Saiyan::isValid() const
	{
		if (m_name == nullptr || m_name[0] == '\0' || m_dob > 2020 || m_power < 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	void Saiyan::display() const
	{
		string super;
		if (!isValid())
		{
			cout << "Invalid Saiyan!" << endl;
		}
		else
		{
			cout << this->m_name << endl;
			cout.width(10); cout.setf(ios::right); cout << "DOB: " << this->m_dob << endl;
			cout.width(10); cout.setf(ios::right); cout << "Power: " << this->m_power << endl;
			super = (m_super == true) ? "yes" : "no";
			cout.width(10); cout.setf(ios::right); cout << "Super: " << super << endl;
			if (this->m_level >= 1)
			{
				cout.width(10); cout.setf(ios::right); cout << "Level: " << m_level << endl;
			}
			cout.unsetf(ios::fixed);
		}
	}

	bool Saiyan::fight(Saiyan& other)
	{	
		/*if (m_power < other.m_power && this->isValid() && other.isValid())
		{
			if (this->m_super == true)
			{
				m_power += ((int)(this->m_power * (double)this->m_level * power));
			}
			if (other.m_super == true)
			{
				other.m_power += ((int)(other.m_power * (double)other.m_level * power));
			}

			if (this->m_power > other.m_power)
				return true;//if they win the fight
		}
		else
		{
			return false; //lost!
		}*/

		if (this->isValid() == true && other.isValid() == true) {
			if (this->m_power < other.m_power) {
				//current instance
				if (this->m_super == true)
					m_power += ((int)(this->m_power * (double)this->m_level * power));

				//other object
				if (other.m_super == true)
					other.m_power += ((int)(other.m_power * (double)other.m_level * power));
			}
			if (this->m_power > other.m_power)
				//wins fight
				return true;
		}
		//loses fight
		return false;
	}

}