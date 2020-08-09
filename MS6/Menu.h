/*I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.

Priya Khatri | 110149176 | pkhatri4@myseneca.ca*/

#ifndef SDDS_MENU_H
#define SDDS_MENU_H

namespace sdds
{
	const int MAX_NO_OF_ITEMS = 10;

	class MenuItem
	{
		char* m_menuItem; //length for content

		MenuItem();
		MenuItem(const char*);
		~MenuItem();
		void display();
		MenuItem(const MenuItem&) = delete; //copy constructor prohibited
		MenuItem& operator=(const MenuItem&) = delete; //copy assignment prohibited

		friend class Menu;
	};

	class Menu
	{
		char* m_title; //size to hold title of menu
		MenuItem* m_items[MAX_NO_OF_ITEMS];
		int m_indentation; //indent the results
		int m_index;

	public:

		Menu();
		Menu(const char*, int indentation = 0);
		Menu(const Menu&); //copy constructor
		~Menu();
		Menu& operator=(const Menu&); //copt assignment operator
		bool isEmpty() const; //bool cast overload
		void display() const;
		void add(const char*);
		Menu& operator<<(const char* newMenuItem);
		int run() const;
		operator int() const; //integer cast overload
		operator bool() const;


	};
}


#endif // !SDDS_MENU_H


