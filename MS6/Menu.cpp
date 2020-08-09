/*I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.

Priya Khatri | 110149176 | pkhatri4@myseneca.ca*/
 
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Menu.h"

using namespace std;

namespace sdds
{
	MenuItem::MenuItem()
	{
		m_menuItem = nullptr;
	}

	MenuItem::MenuItem(const char* item)
	{
		if (item != nullptr)
		{
			m_menuItem = new char[strlen(item) + 1]; //allocate new memory if needed
			strcpy(m_menuItem, item);
		}
		else
		{
			m_menuItem = nullptr;
		}

	}

	Menu::~Menu()
	{
		delete[] m_title;
		m_title = nullptr;
	}

	MenuItem::~MenuItem()
	{
		delete[] m_menuItem;
		m_menuItem = nullptr;
	}

	void MenuItem::display()
	{
		if (this->m_menuItem != nullptr)
		{
			cout << this->m_menuItem << "\n" << endl;
		}
	}

	Menu::Menu()
	{
		m_title = nullptr;
		m_indentation = 0;
		m_index = 0;

		//check to make sure MAX_NO_OF_ITEMS/menuItem is set to empty if array index is 0
		for (int i = 0; i < MAX_NO_OF_ITEMS; i++)
		{
			m_items[i] = nullptr;
		}

	}

	Menu::Menu(const char* title, int indentation) : Menu() //call default ot set empty
	{
		if (title != nullptr)
		{
			//allocate new memory and copy values
			m_title = new char[strlen(title) + 1];
			strcpy(m_title, title);
			m_indentation = indentation;
		}
	}

	Menu::Menu(const Menu& src) : Menu() //copy constructor
	{
		*this = src;
	}

	Menu& Menu::operator=(const Menu& src)
	{
		if (this != &src) //check for self-assignment
		{
			for (int i = 0; i < m_index; i++)
			{
				delete m_items[i];
				m_items[i] = nullptr;
			}

			m_indentation = src.m_indentation;
			m_index = src.m_index;

			//deep copying
			for (int i = 0; i < m_index; i++)
			{
				m_items[i] = new MenuItem(src.m_items[i]->m_menuItem);
			}

			if (src.m_title != nullptr) //allocate new memory if needed
			{
				m_title = new char[strlen(src.m_title) + 1];
				strcpy(m_title, src.m_title);


			}
			else
			{
				m_title = nullptr;
			}
		}

		return *this;
	}

	bool Menu::isEmpty() const
	{

		if (m_title == nullptr)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	void Menu::display() const
	{

		if (!isEmpty())
		{
			cout << "Invalid Menu!" << endl;

		}
		else if (this->m_items[0] == nullptr)
		{
			cout.width(strlen(m_title) + 8);
			cout << this->m_title << endl;
			cout << "No Items to display!" << endl;
		}
		else
		{
			if (m_indentation == 2)
			{
				cout.width(strlen(m_title) + 8);
				cout << m_title << endl;

				int i;
				for (i = 0; i < m_index; i++)
				{
					cout.width(9);
					cout << i + 1 << "- " << m_items[i]->m_menuItem << "\n";
				}

				cout.width(10);
				cout << "> ";
			}
			else if (m_indentation == 1)
			{
				cout.width(strlen(m_title) + 4);
				cout << m_title << endl;

				int i;
				for (i = 0; i < m_index; i++)
				{
					cout.width(5);
					cout << i + 1 << "- " << m_items[i]->m_menuItem << "\n";
				}

				cout.width(6);
				cout << "> ";
			}
			else
			{
				cout << this->m_title << endl;

				int i;
				for (i = 0; i < m_index; i++)
				{
					cout << i + 1 << "- " << m_items[i]->m_menuItem << "\n";
				}

				cout << "> ";
			}


		}
	}

	Menu::operator bool() const
	{
		if (isEmpty())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	Menu::operator int() const
	{
		int mcast = run(); //if Menu is cased to interger then call run() and it's value is returned as int cast value
		return mcast;
	}

	void Menu::add(const char* newMenuItem)
	{

		if (newMenuItem != nullptr && m_index != MAX_NO_OF_ITEMS)
		{
			m_items[m_index] = new MenuItem(newMenuItem);

			this->m_index++;
		}
		else
		{
			*this = Menu();
		}
	}

	Menu& Menu::operator<<(const char* newMenuItem)
	{
		if (newMenuItem != nullptr && m_index != MAX_NO_OF_ITEMS)
		{
			m_items[m_index] = new MenuItem(newMenuItem);

			this->m_index++;
		}
		else
		{
			*this = Menu();
		}

		return *this;
	}

	int Menu::run() const
	{
		int option; //collect the user's input
		display();

		if (m_index > 0 && isEmpty())
		{
			cin >> option;
			cin.ignore(9000, '\n');

			while (true)
			{
				if (cin.fail())
				{
					//if user enters non-integer value. wait for user's response
					cout << "Invalid Integer, try again: ";
					cin.clear();
					cin.ignore(9000, '\n');

				}
				//input is int but out of boundary of the available options. wait for user
				else if (option <= 0 || option > m_index)
				{
					cout << "Invalid selection, try again: ";

				}
				else //valid option. return option
				{
					break;
				}


				cin >> option;
				cin.ignore(9000, '\n');

			}
		}
		else
		{
			option = 0; //if menu has no menuitems then returns with no user interaction
		}

		return option;

	}



}