#include <iostream>
#include <cstring> //strcpy
#include "Cargo.h"

using namespace std;

namespace sdds
{
	void Cargo::initialize(const char* desc, double weight)
	{
		setWeight(weight);
		setDesc(desc);
	}

	const char* Cargo::getDesc() const
	{
		return c_description;
	}

	double Cargo::getWeight() const
	{
		return c_weight;
	}

	void Cargo::setDesc(const char* description)
	{
		/*for (int i = 0; i < MAX_DESC; i++) 
		{
			Cargo::c_description[i] = description[i];
		}*/
		strncpy(c_description, description, MAX_DESC);
	}

	void Cargo::setWeight(double weight)
	{
		//checks if value is within range
		if (weight > MAX_WEIGHT || weight < MIN_WEIGHT)
		{
			//set to min value
			c_weight = MIN_WEIGHT;
		}
		else
		{
			//if in range then set the weight to min
			c_weight = weight;
		}
	}

}