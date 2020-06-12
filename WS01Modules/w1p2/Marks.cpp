#include <iostream>
#include "Marks.h"
#include "Utils.h"

using namespace std;

void markstat()
{
	sdds::Marks aMarks; //have to make an instance of Marks since it's outside of the namespace
	sdds::titleDisplay();
	sdds::enterAssessment(&aMarks);
	sdds::enterNumMarks(&aMarks);
	sdds::display(&aMarks);
}

namespace sdds
{

	void titleDisplay()
	{
		cout << "Mark Stats Program." << endl << endl;
	}

	void enterAssessment(Marks* name)
	{
		//asking the user for assessment name vales
		cout << "Please enter the assessment name: ";
		cin.ignore();
		cin.getline(name->n_assessment, 41); //no more than 40 chars + nullbyte

	}

	int enterNumMarks(Marks* num)
	{
		int i = 0;
		bool check = true;
		int numOfMarks = 0;

		cout << "Please enter the number of marks: ";
		cin >> num->n_marks;
		
		if (i < 5 || i > 50)
		{
			cout << "Invalid value(5 <= value <= 50), try again: ";
			num = 0;
		}

		//checking for marks
		do
		{
			cin >> numOfMarks;
			if (cin.fail())
			{
				cout << "Invalid Number, try again: ";
				cin.clear();
				cin.ignore(123, '\n');
			}
			else if (cin.fail())
			{
				cout << "Invalid value(5 <= value <= 50), try again: ";
				cin.clear();
				cin.ignore(123, '\n');
				cin >> numOfMarks;
			}
			else if (cin.get() != '\n')
			{
				cout << "Invalid trailing characters, try again: ";
				cin.clear();
				cin.ignore(123, '\n');
			}
			else
			{
				int marks = 0;
				cout << "Please enter " << numOfMarks << " marks (0<=Mark<=100): " << endl;
			
				
				for (int i = 0; i < numOfMarks; i++)
				{
					cout << i + 1 << "> ";
					cin >> marks;

					while (marks < -1 || marks > 101)
					{
						cout << "Invalid value(0 <= value <= 100), try again: ";
						cin >> marks;
						
					}
				}
				return numOfMarks;

			}
		}
		while (check);
		return numOfMarks;
	}
	void sortMarks(int[] s)
	{

	}
	//display mark stats program 
	void display(Marks* n_marks)
	{
		cout << "Thank you..." << endl;
		cout << "Assessment Name: " << n_marks->n_assessment << endl;
		cout << "----------------" << endl;
		//cout << sort();
		cout << "Average: " << endl;
		cout << "Number of Passing Marks: " << endl;
		
	}
}
