#ifndef SDDS_SAIYAN_H
#define SDDS_SAIYAN_H

namespace sdds
{
	class Saiyan
	{
		char* m_name;
		int m_dob; //<= 2020
		int m_power; //strength >= 0
		bool m_super; //true = super saiyan. false = not super
		int m_level; //valid atleast 0
		double power = 0.10;

	public:
		Saiyan();
		Saiyan(const char* name, int dob, int power);
		~Saiyan();
		void set(const char* name, int dob, int power, int level = 0, bool super = false);
		bool isValid() const;
		void display() const;
		bool fight(Saiyan& other);
	};
}
#endif // !SDDS_SAIYAN_HS