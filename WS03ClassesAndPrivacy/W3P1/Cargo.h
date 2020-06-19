//WS03 - Part 1 | Name: Priya Khatri | Email: pkhatri4@myseneca.ca | Student number: 110149176
#ifndef SDDS_CARGO_H
#define SDDS_CARGO_H

namespace sdds
{
	//Max lenght of cargo desc
	const int MAX_DESC = 20;

	struct Cargo
	{
		char description[MAX_DESC];
		double weight;
	};
}

#endif // !SDDS_CARGO_H