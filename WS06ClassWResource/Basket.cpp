/*I have done all the coding by myself and only copied the code that my professor provided my workshops and assignments.
 * Priya Khatri | 110149176 | pkhatri4@myseneca.ca | July 2nd, 2020*/

#include <iomanip>
#include <iostream>
#include "Basket.h"

using namespace std;

namespace sdds
{
	Basket::Basket()
	{
		m_fruits = nullptr;
		m_cnt = 0;
		m_price = 0.0;
	}

	Basket::Basket(Fruit* fruits, int size, double price) : Basket()
	{
		if (fruits != nullptr && size > 0 && price > 0.0)
		{
			m_fruits = new Fruit[size];
			for (auto i = 0; i < size; i++)
			{
				m_fruits[i] = fruits[i];
			}
			m_cnt = size;
			m_price = price;
		}
	}

	Basket::Basket(const Basket& src) //copy constructor
	{
		m_fruits = nullptr;
		*this = src; //copy current object from copy assignment - was giving errors
		//deep copies to allocate dynamic memory for fruits
			}

	Basket& Basket::operator=(const Basket& bsk) //copy assignment
	{
		if (this != &bsk) //check for self-assignment
		{
			m_cnt = bsk.m_cnt;
			m_price = bsk.m_price;

			delete[] m_fruits;

			if (bsk.m_fruits != nullptr)
			{
				//allocate new memory if needed
				m_fruits = new Fruit[m_cnt];
				//copy data from resource to newly allocated resource
				for (auto i = 0; i < m_cnt; i++)
				{
					m_fruits[i] = bsk.m_fruits[i];
				}
			}
			else
			{
				m_fruits = nullptr;
			}
		}
		return *this;
	}

	Basket::~Basket()
	{
		delete[] m_fruits;
		m_fruits = nullptr;
	}

	void Basket::setPrice(double price)
	{
		m_price = price;
	}

	Basket::operator bool() const
	{
		if (m_fruits != nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}	
	}

	Basket& Basket::operator+=(Fruit fruit)
	{
		//if the object exist is valid
		if (fruit.m_qty > 0.0 && fruit.m_name != nullptr)
		{
			Fruit* tmpArr = new Fruit[m_cnt + 1]; //create a new array

			for (auto i = 0; i < m_cnt; i++)
			{
				tmpArr[i] = m_fruits[i];
			}
			tmpArr[m_cnt] = fruit; //update the count

			delete[] m_fruits;

			m_fruits = tmpArr; //switch to bigger array
			++m_cnt; //update the size
		}
		return *this;
	}

	void Basket::display(ostream& os) const
	{
		if (m_fruits != nullptr)
		{
			os << "Basket Content:" << endl;
			for (auto i = 0; i < m_cnt; i++)
			{
				os.width(10);
				os << right << m_fruits[i].m_name << ": ";
				os << fixed << setprecision(2);
				os << m_fruits[i].m_qty << "kg" << endl;
			}
			os << "Price: " << m_price << endl;
		}
		else
		{
			os << "The basket is empty!" << endl;
		}
	}

	ostream& operator<<(ostream& os, const Basket& b)
	{
		b.display(os);
		return os;
	}
}
