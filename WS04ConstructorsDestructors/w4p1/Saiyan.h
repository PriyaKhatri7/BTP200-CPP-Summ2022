#ifndef SDDS_SAIYAN_H
#define SDDS_SAIYAN_H

namespace sdds
{
	class Saiyan
	{
		char m_name[32 + 1];
		int m_dob; //<= 2020
		int m_power; //strength >= 0
		bool m_super; //true = super saiyan. false = not super

	public:
		Saiyan();
		Saiyan(const char* name, int dob, int power);
		void set(const char* name, int dob, int power, bool super = false);
		bool isValid() const;
		void display() const;
		bool fight(const Saiyan& other) const;
	};
}
#endif // !SDDS_SAIYAN_H

