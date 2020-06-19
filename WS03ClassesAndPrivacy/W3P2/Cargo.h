//WS03 - Part 2 | Name: Priya Khatri | Email: pkhatri4@myseneca.ca | Student number: 110149176
#ifndef SDDS_CARGO_H
#define SDDS_CARGO_H

namespace sdds
{
	const int MAX_DESC = 20; //max len of cargo desc
	const double MAX_WEIGHT = 777.555; //max weight for cargo
	const double MIN_WEIGHT = 44.2222; //min weight for cargo

	class Cargo
	{	
		char c_description[MAX_DESC];
		double c_weight;

	public:
		void initialize(const char* desc, double weight);
		const char* getDesc() const;
		double getWeight() const;
		void setDesc(const char* description);
		void setWeight(double weight);
	};
}

#endif // !SDDS_CARGO_H