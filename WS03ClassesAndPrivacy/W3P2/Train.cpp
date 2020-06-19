//WS03 - Part 2 | Name: Priya Khatri | Email: pkhatri4@myseneca.ca | Student number: 110149176
#include <iostream>
#include <iomanip> //setprecision
#include <cstring> //strncpy
#include "Train.h"
#include "Cargo.h"
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
			strncpy(t_name, name, MAX_NAME + 1);
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

	bool Train::swapCargo(Train& other)
	{
		if (this->cargo != nullptr && other.cargo != nullptr)
		{
			Cargo* temp = cargo;
			cargo = other.cargo;
			other.cargo = temp;
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Train::increaseCargo(double weight)
	{
		bool valid = false;
		double totalWeight = 0;

		if (cargo != nullptr)
		{
			totalWeight = cargo->getWeight() + weight;

			//check to see if weight is below max_weight
			if (cargo->getWeight() < MAX_WEIGHT)
			{
				if (totalWeight > MAX_WEIGHT)
				{
					cargo->setWeight(MAX_WEIGHT);
					valid = true;
				}
				else
				{
					cargo->setWeight(totalWeight);
					valid = true;
				}
			}
		}
		return valid;
	}

	bool Train::decreaseCargo(double weight)
	{
		bool valid = false;

		//if the train is valid
		if (cargo != nullptr)
		{
			double totalWeight = cargo->getWeight();

			totalWeight = cargo->getWeight() - weight;

			if (cargo->getWeight() > MIN_WEIGHT)
			{
				if (totalWeight < MIN_WEIGHT)
				{
					cargo->setWeight(MIN_WEIGHT);
					valid = true;
				}
				else
				{
					cargo->setWeight(totalWeight);
					valid = true;
				}
			}
		}
		return valid;
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
			//cout << right << setw(10); //align right. size 10
			cout.width(10); cout.setf(ios::right);
			cout << "Name: " << this->t_name << endl;
			cout.width(10); cout.setf(ios::right);
			cout << "ID: " << this->t_id << endl;
			cout.unsetf(ios::right);
			if (isValid() && cargo == nullptr)
			{
				cout << "No cargo on this train." << endl;
			}
			else
			{
				cout.width(10);
				cout << "Cargo: " << cargo->getDesc() << endl;
				cout.width(10);
				//weight format
				cout.setf(ios::fixed);
				
				auto oldprecision = cout.precision(2);
				cout << "Weight: " << cargo->getWeight() << endl;
				cout.unsetf(ios::fixed);
				cout.precision(oldprecision);
			}
		}
	}
}
