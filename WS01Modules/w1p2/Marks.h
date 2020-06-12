#ifndef SDDS_MARKS_H
#define SDDS_MARKS_H

//constexpr auto SIZE = 40;

namespace sdds
{
	const int SIZE = 40;

	struct Marks 
	{
		char n_assessment [SIZE + 1]; //name of assessment include nullbyte 
		int n_marks; //num of marks
	};
	
	void titleDisplay();
	void enterAssessment(Marks*);
	int enterNumMarks(Marks*);
	void display(Marks* n_marks);

	void sortMarks(int[]);
	
}

void markstat();

#endif // !SDDS_MARKS_H



