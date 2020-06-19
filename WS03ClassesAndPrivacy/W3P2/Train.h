//WS03 - Part 2 | Name: Priya Khatri | Email: pkhatri4@myseneca.ca | Student number: 110149176
#ifndef SDDS_TRAIN_H
#define SDDS_TRAIN_H
#include "Cargo.h"

namespace sdds
{
	//max length of a train name
	const int MAX_NAME = 30;

	class Train
	{
	public:
		
		char t_name[MAX_NAME + 1];
		int t_id;
		Cargo* cargo;

		void initialize(const char* name, int id);
		bool isValid() const;
		void loadCargo(Cargo car);
		void unloadCargo();
		bool swapCargo(Train& other);
		bool increaseCargo(double weight);
		bool decreaseCargo(double weight);
		void display() const;
	};

}
#endif // !SDDS_TRAIN_H

