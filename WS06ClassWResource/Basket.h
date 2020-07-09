/*I have done all the coding by myself and only copied the code that my professor provided my workshops and assignments.
 * Priya Khatri | 110149176 | pkhatri4@myseneca.ca | July 2nd, 2020*/

#ifndef SDDS_BASKET_H
#define SDDS_BASKET_H
#include <iostream>

namespace sdds
{
	struct Fruit
	{
		char m_name[30 + 1]; // the name of the fruit
		double m_qty; // quantity in kilograms
	};

	class Basket : Fruit //this holds information about a Fruit Basket
	{
		Fruit* m_fruits; //dynamically allocated array of objects of type Fruit. Resource
		int m_cnt; //size of m_fruits array
		double m_price; //price of basket
	public:
		Basket();
		Basket(Fruit* fruits, int size, double price);
		Basket(const Basket& src); //copy constructor
		Basket& operator=(const Basket& src); //copy assignment operator
		~Basket();
		void setPrice(double price); //set the price of the basket
		operator bool() const; //returns true if the basket contains any fruits, false otherwise.
		Basket& operator+=(Fruit fruit);
		void display(std::ostream& os) const;
		friend std::ostream& operator<<(std::ostream& os, const Basket& b); //insert into the stream (received as the first parameter) the content 
										//of an object of type Basket (received as the second parameter)									   
	};
		
}

#endif // !SDDS_BASKET_H
