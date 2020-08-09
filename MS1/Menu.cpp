#include <iostream>
#include <cstring> //strcpy and strlen
#include <iomanip>
#include "Menu.h"
using namespace std;

namespace sdds
{
	MenuItem::MenuItem()
	{
		m_item = nullptr;
	}

	MenuItem::MenuItem(const char* tempItem) : MenuItem()
	{
		m_item = nullptr; 
		if (tempItem != nullptr && tempItem[0] != 0) 
		{
			//allocate new memory
			m_item = new char[strlen(tempItem) + 1];
			strcpy(m_item, tempItem);
		}
	}

	void MenuItem::display()
	{
		if (m_item != nullptr)
		{
			cout << m_item << "\n" << endl;
		}
	}

	MenuItem::~MenuItem()
	{
		delete[] m_item;
		m_item = nullptr;
	}

	Menu::Menu()
	{
		menuTitle = nullptr;
		indentation = 0;
		index = 0;

		//check to make sure MAX_NO_OF_ITEMS/menuItem is set to empty if array index is 0
		for (int i = 0; i < MAX_NO_OF_ITEMS; i++)
		{
			menuItem[i] = nullptr;
		}
	}

	Menu::Menu(const char* title, int indent) : Menu() //call default to set empty
	{
		if (title != nullptr)
		{
			//allocate new memory and copy values
			menuTitle = new char[strlen(title) + 1];
			strcpy(menuTitle, title);

			indentation = indent;
		}
	}

	Menu::Menu(const Menu& cpy) : Menu() //copy constructor
	{
		*this = cpy;
	}

	Menu::~Menu()
	{
		for (int i = 0; i < MAX_NO_OF_ITEMS; i++)
		{
			delete menuItem[i];
		}

		delete[] menuTitle;
		menuTitle = nullptr;
	}

	Menu& Menu::operator=(const Menu& pmenu) //copy assignment
	{
		//check for self-assignment
		if (this != &pmenu)
		{
			for (auto i = 0; i < index; i++)
			{
				delete menuItem[i];
				menuItem[i] = nullptr;
			}

			indentation = pmenu.indentation;
			index = pmenu.index;

			//deep copying
			for (auto i = 0; i < index; i++)
			{
				menuItem[i] = new MenuItem(pmenu.menuItem[i]->m_item);
			}

			delete[] menuTitle; 
			//allocate new memory if needed
			if (pmenu.menuTitle != nullptr)
			{
				menuTitle = new char[strlen(pmenu.menuTitle) + 1];
				strcpy(menuTitle, pmenu.menuTitle);
			}
			else
			{
				menuTitle = nullptr;
			}
		}
		return *this; //returns this instance of Menu
	}

	Menu::operator bool() const //bool cast overload
	{
		if (isEmpty()) {
			return true; //if menu is valid and usable
		}
		else {
			return false;
		}
	}

	bool Menu::isEmpty() const
	{
		if (menuTitle == nullptr)
		{
			return false;
		}	
		else {
			return true;
		}
	}

	void Menu::display() const
	{
		if (!isEmpty())
		{
			cout << "Invalid Menu!" << endl;
		}
		else if (this->menuItem[0] == nullptr)
		{
			cout.width(strlen(menuTitle) + 8);
			cout << this->menuTitle << endl;
			cout << "No Items to display!" << endl;
		}
		else
		{
			//display output example from PDF. ind 2
			if (indentation == 2)
			{
				//make sure to reset the title of menu after newly assigned string
				cout.width(strlen(menuTitle) + 8);
				cout << menuTitle << endl;

				for (int i = 0; i < index; i++)
				{
					cout.width(9);
					cout << i + 1 << "- " << menuItem[i]->m_item << endl;
				}
				cout.width(10);
				cout << "> ";
			}
			else if (indentation == 1)
			{
				cout.width(strlen(menuTitle) + 4);
				cout << menuTitle << endl;

				for (int i = 0; i < index; i++)
				{
					cout.width(5);
					cout << i + 1 << "- " << menuItem[i]->m_item << endl;
				}
				cout.width(6);
				cout << "> ";
			}
			else
			{
				cout << this->menuTitle << endl;

				for (int i = 0; i < index; i++)
				{
					cout << i + 1 << "- " << menuItem[i]->m_item << endl;
				}

				cout << "> ";
			}
		}
	}

	void Menu::add(const char* newMenuItem)
	{	
		if (newMenuItem != nullptr && index != MAX_NO_OF_ITEMS)
		{

			menuItem[index] = new MenuItem(newMenuItem);
			index++;
		}
		else
		{
			*this = Menu();
		}
	}

	Menu& Menu::operator<<(const char* tempItem)
	{
		add(tempItem); //calling add function
		return *this; //return value
	}

	int Menu::run() const
	{
		int choice; //collect the user's input
		display();

		if (index > 0 && isEmpty())
		{
			cin >> choice;
			cin.ignore(9000, '\n');

			while (true)
			{
				//if user enters non-integer value. wait for user's response
				if (cin.fail())
				{
					cout << "Invalid Integer, try again: ";
					cin.clear();
					cin.ignore(9000, '\n');
				}
				//input is int but out of boundary of the available options. wait for user
				else if (choice <= 0 || choice > index)
				{
					cout << "Invalid selection, try again: ";
				}
				else //valid option. return option
				{
					break;
				}
				cin >> choice;
				cin.ignore(9000, '\n');
			}
		}
		else 
		{ 
			choice = 0; //if menu has no menuitems then returns with no user interaction
		}
		return choice;
	}

	Menu::operator int() const
	{
		//if Menu is casted to integer then call run() and it's value is returned as int cast value
		int mcast = run();
		return mcast;
	}

}