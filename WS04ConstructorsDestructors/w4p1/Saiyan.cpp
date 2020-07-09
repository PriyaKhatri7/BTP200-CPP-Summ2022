#include <iostream>
#include <cstring> //strcpy
#include "Saiyan.h"
using namespace std;

namespace sdds
{
	Saiyan::Saiyan()
	{
		m_name[0] = '\0';
		m_dob = 0;
		m_power = 0;
		m_super = false;
	}

	Saiyan::Saiyan(const char* name, int dob, int power)
	{
		set(name, dob, power);
	}

	void Saiyan::set(const char* name, int dob, int power, bool super)
	{
		if (name != nullptr && name[0] != '\0' && dob <= 2020 && power >= 0)
		{
			strcpy(m_name, name);
			m_dob = dob;
			m_power = power;
			m_super = super;
		}
		else
		{
			//Saiyan();
			m_name[0] = '\0';
			m_dob = 0;
			m_power = 0;
			m_super = false;
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
			//if NOT in empty state return true
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
			cout << "DOB: " << this->m_dob << endl;
			cout << "Power: " << this->m_power << endl;
			super = (m_super == true) ? "yes" : "no";
			cout << "Super: " << super << endl;
		}
	}

	bool Saiyan::fight(const Saiyan& other) const
	{
		if (m_power > other.m_power || !isValid())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

}