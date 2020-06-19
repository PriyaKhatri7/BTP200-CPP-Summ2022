//WS03 - Part 1 | Name: Priya Khatri | Email: pkhatri4@myseneca.ca | Student number: 110149176
#include <iostream>
#include <cstring> //strcpy
#include "Train.h"
using namespace std;

namespace sdds
{
	void Train::initialize(const char* name, int id)
	{
		//if invalid, set empty
		if (name == nullptr || name[0] == '\0' || id < 0)
		{
			t_name[0] = '\0';
			t_id = 0;
		}
		else
		{
			//if valid, copy into the attributes, no more than MAX_NAME
			strcpy(t_name, name);
			t_id = id;
		}
		//initialize to null
		cargo = nullptr;
	}

	bool Train::isValid() const
	{
		//if values exsist then return true
		if (t_name[0] != '\0' || t_id > 0 || this->cargo != nullptr)
		{
			return true;
		}
		else
			return false;
	}

	void Train::loadCargo(Cargo car)
	{
		//delete any existing error first (t5 calls this 3 times - without this it will give memory leaks
		unloadCargo();
		//dynamically allocate memory for a single instance of Cargo to cargo pointer data member than copy over the values from 
		//the parameter to it

		//pointer = new type
		cargo = new Cargo;
		*cargo = car;
	}

	void Train::unloadCargo()
	{
		//removes existing cargo from the train by deallocating the memory used
		delete cargo;
		cargo = nullptr;
	}

	void Train::display() const
	{
		//if train/isValid = false then it will display this
		if (!isValid())
		{
			cout << "***Train Summary***\n";
			cout << "This is an invalid train.\n";
		}
		else 
		{
			cout << "***Train Summary***" << endl;
			cout << "Name: " << this->t_name << endl;
			cout << "ID: " << this->t_id << endl;
			if (isValid() && cargo == nullptr)
			{
				cout << "No cargo on this train." << endl;
			}
			else
			{
				cout << "Cargo: " << cargo->description << endl;
				cout << "Weight: " << cargo->weight << endl;
			}
		} 
	}
}