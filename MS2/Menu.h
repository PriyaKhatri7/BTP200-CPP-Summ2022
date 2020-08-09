/*I have done all the coding by myselfand only copied the code
that my professor provided to complete my workshopsand assignments.*/
#ifndef SDDS_MENU_H
#define SDDS_MENU_H

namespace sdds
{
	const int MAX_NO_OF_ITEMS = 10;

	class MenuItem
	{
		char* m_item; //length for content
	public:
		MenuItem();
		MenuItem(const char* tempItem);
		void display();
		MenuItem(const MenuItem&) = delete; //copy constructor prohibited
		MenuItem& operator=(const MenuItem&) = delete; //copy assignment prohibited
		~MenuItem();
		friend class Menu;
	};

	class Menu
	{
		char* menuTitle; //size to hold title of menu
		MenuItem* menuItem[MAX_NO_OF_ITEMS];
		int indentation; //indent the results
		int index;
	public:
		Menu();
		Menu(const char* title, int indent = 0);
		Menu(const Menu& cpy); //copy constructor
		~Menu();
		Menu& operator=(const Menu& pmenu); //copy assignment operator
		operator bool() const; //bool cast overload
		bool isEmpty() const;
		void display() const;
		void add(const char* tempItem);
		Menu& operator<<(const char* tempItem);
		int run() const;
		operator int() const; //integer cast overload
	};
}
#endif // !SDDS_MENU_H
