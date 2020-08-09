/*I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.

Priya Khatri | 110149176 | pkhatri4@myseneca.ca*/

#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include "Parking.h"
#include "Menu.h"
#include "Car.h"
#include "Motorcycle.h"
#include "Vehicle.h"

using namespace std;

namespace sdds
{

	Parking::Parking()
	{
		setEmpty();
	}

	void Parking::setEmpty()
	{
		m_filename = nullptr;
		m_ParkingMenu = nullptr;
		m_VehicleMenu = nullptr;
		m_numOfParkedVehicles = 0;
		m_numOfParkingSpots = 0;
		m_numOfAvailableSpots = 0;
		
		for (int i = 0; i < MAX_NUMBER_PARKING_SPOTS; i++)
		{
			m_ParkingSpot[i] = nullptr;
		}

	}

	Parking::Parking(const char* filename, int noOfSpots) : m_filename(nullptr)
	{
		if ((filename != nullptr && strlen(filename) > 0) && (noOfSpots >= 10 && noOfSpots < MAX_NUMBER_PARKING_SPOTS))
		{
			m_filename = new char[strlen(filename) + 1];
			strcpy(m_filename, filename);
			m_numOfParkingSpots = noOfSpots;

			for (int i = 0; i < MAX_NUMBER_PARKING_SPOTS; i++)
			{
				m_ParkingSpot[i] = nullptr;
			}
		}
		else
		{
			setEmpty();
		}

		if (LoadDataFile())
		{
			m_ParkingMenu = new Menu("Parking Menu, select an action:", 0);
			m_ParkingMenu->add("Park Vehicle");
			m_ParkingMenu->add("Return Vehicle");
			m_ParkingMenu->add("List Parked Vehicles");
			m_ParkingMenu->add("Close Parking (End of day)");
			m_ParkingMenu->add("Exit Program");

			m_VehicleMenu = new Menu("Select type of the vehicle:", 1);
			m_VehicleMenu->add("Car");
			m_VehicleMenu->add("Motorcycle");
			m_VehicleMenu->add("Cancel");
		}
		else
		{
			cout << "Error in data file\n";
			setEmpty();
		}

	}

	Parking::~Parking()
	{
		SaveDataFile();
		delete[] m_filename;
		m_filename = nullptr;

	}

	void Parking::ParkingMenu() const
	{
		ParkingStatus();
	}

	bool Parking::isEmpty() const
	{
		if (m_filename == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Parking::ParkingStatus() const
	{
		cout << "****** Seneca Valet Parking ******\n";
		cout << "*****  Available spots: ";
		cout.width(4);
		cout << left << (m_numOfParkingSpots - m_numOfParkedVehicles) << " *****" << endl;
		cout.unsetf(ios::left);

		m_ParkingMenu->display();
	}

	void Parking::ParkVehicles() 
	{
		bool OpenSpots = false;

		if (m_numOfParkedVehicles == m_numOfParkingSpots)
		{
			cout << "Parking is full" << endl;
		}
		if (m_numOfParkingSpots > m_numOfParkedVehicles)
		{
			OpenSpots = true;
		}

		if (OpenSpots)
		{
			bool Park = false;
			int emptySpot = -1;
			int option;

			m_VehicleMenu->display();
			cin >> option;

			for (int i = 0; i < m_numOfParkingSpots; i++)
			{
				if (m_ParkingSpot[i] == nullptr)
				{
					emptySpot = i;
					break;
				}
			}

			if (option == 1)
			{
				Vehicle* temp = new Car;
				temp->setCsv(false);
				temp->read(cin);

				for (int i = 0; i < m_numOfParkingSpots; i++)
				{
					if (m_ParkingSpot[i] == temp)
					{
						Park = true;
						break;
					}
				}

				if (Park)
				{
					cout << "Can not park; license plate already in the system!" << endl;
					delete temp;
				}
				else
				{
					m_ParkingSpot[emptySpot] = temp;
					m_ParkingSpot[emptySpot]->setParkingSpot(emptySpot + 1);
					cout << endl;
					cout << "Parking Ticket" << endl;
					cout << *m_ParkingSpot[emptySpot];
					cout << endl;
					m_numOfParkedVehicles++;
				}
			}

			if (option == 2)
			{
				Vehicle* temp = new Motorcycle;
				temp->setCsv(false);
				temp->read(cin);

				for (int i = 0; i < m_numOfParkingSpots; i++)
				{
					if (m_ParkingSpot[i] == temp)
					{
						Park = true;
						break;
					}
				}

				if (Park)
				{
					cout << "Can not park; license plate already in the system!" << endl;
					delete temp;
				}
				else
				{
					m_ParkingSpot[emptySpot] = temp;
					m_ParkingSpot[emptySpot]->setParkingSpot(emptySpot + 1);
					cout << endl;
					cout << "Parking Ticket" << endl;
					cout << *m_ParkingSpot[emptySpot];
					cout << endl;
					m_numOfParkedVehicles++;
				}
			}


			if (option == 3)
			{
				cout << "Parking cancelled" << endl;
			}

		}

	}

	void Parking::ReturnVehicles()
	{	
		bool match = false;
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Return Vehicle\n";
		char templicence[10];
		cout << "Enter Licence Plate Number: ";
		cin.get(templicence, 10, '\n');

		while (strlen(templicence) > 8)
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Invalid Licence Plate, try again: ";
			cin.get(templicence, 10, '\n');
		}

		for (unsigned int i = 0; i < strlen(templicence); i++)
		{
			templicence[i] = toupper(templicence[i]);
		}


		for (int i = 0; i < m_numOfParkedVehicles; i++)
		{
			if (*m_ParkingSpot[i] == templicence)
			{
				m_ParkingSpot[i]->setCsv(false);
				cout << "\nReturning: " << endl;
				cout << *m_ParkingSpot[i] << endl;
				delete m_ParkingSpot[i];
				m_ParkingSpot[i] = nullptr;
				m_numOfParkedVehicles--;
				match = true;

			}
		}	
		if (match == false)
		{
			cout << "License plate " << templicence << " Not found" << endl;
			match = true;
		}
	}

	void Parking::ListparkedVehicles() const
	{
		cout << "*** List of parked vehicles ***" << endl;

		for (int i = 0; i < m_numOfParkingSpots; i++)
		{
			if (m_ParkingSpot[i] != nullptr)
			{
				this->m_ParkingSpot[i]->setCsv(false);
				this->m_ParkingSpot[i]->write(cout);
				cout << "-------------------------------" << endl;
			}
		}
	}

	bool Parking::CloseParking()
	{
		char option = '\0';
		bool exitloop = false;

		if (m_numOfParkedVehicles == 0)
		{
			cout << "Closing Parking\n";

			return true;
		}
		else
		{
			cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
			cout << "Are you sure? (Y)es/(N)o: ";
			cin >> option;

			while (exitloop == false)
			{

				if ((option == 'Y' || option == 'y'))
				{
					cout << "Closing Parking" << endl;
					cout << endl;

					for (int i = 0; i < m_numOfParkingSpots; i++)
					{
						if (m_ParkingSpot[i] != nullptr)
						{
							cout << "Towing request" << endl;
							cout << "*********************" << endl;
							this->m_ParkingSpot[i]->setCsv(false);
							this->m_ParkingSpot[i]->write(cout);
							delete this->m_ParkingSpot[i];
							this->m_ParkingSpot[i] = nullptr;
							m_numOfParkedVehicles--;
						}
						if (m_ParkingSpot[i + 1] != nullptr)
						{
							cout << endl;
						}
							
					}
					exitloop = true;
					return true;
				}
				else if ((option == 'N' || option == 'n'))
				{
					cout << "Aborted!" << endl;
					exitloop = true;
					return false;
				}
				else
				{
					cin.clear();
					cin.ignore(9000, '\n');
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
					cin >> option;
				}

			}

			cin.clear();
			return false;
		}
		
	}

	bool Parking::ExitParkingApp() const
	{
		bool confirm = false;
		bool exitloop = false;
		char option = '\0';
		cout << "This will terminate the program!\n";
		cout << "Are you sure? (Y)es/(N)o: ";
		cin >> option;

		while (exitloop == false)
		{

			if ((option == 'Y' || option == 'y'))
			{
				exitloop = true;
				confirm = true;
			}
			else if ((option == 'N' || option == 'n'))
			{
				exitloop = true;
				confirm = false;
			}
			else
			{
				cin.clear();
				cin.ignore(9000, '\n');
				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
				cin >> option;
			}

		}

		cin.clear();
		return confirm;

	}

	bool Parking::LoadDataFile()
	{
		bool exit = true;

		m_numOfAvailableSpots = 10;
		m_numOfParkedVehicles = 0;

		if (!isEmpty())
		{
			std::ifstream fin;
			fin.open(m_filename, ios::in);

			if (fin.is_open())
			{
				do
				{
					char type = '0';

					Vehicle* temp = nullptr;
					fin >> type;

					if (type == 'C')
					{
						temp = new Car;
					}
					else if (type == 'M')
					{
						temp = new Motorcycle;
					}
					type = '0';

					if (temp != nullptr && m_numOfParkedVehicles < m_numOfParkingSpots)
					{
						temp->setCsv(true);
						temp->read(fin);

						if (fin.fail())
						{
							fin.clear();
							delete temp;
							temp = nullptr;
							exit = false;
						}
						else
						{
							m_ParkingSpot[temp->getParkingSpot() - 1] = temp;
							m_numOfParkedVehicles++;
							m_numOfAvailableSpots--;
						}
					}
				} while (exit == true && !fin.eof());
			}
	
		}

		return exit;
	}

	void Parking::SaveDataFile() const
	{
		if (!isEmpty())
		{

			std::fstream fout;
			fout.open(m_filename, ios::out);
			fout.seekp(ios::beg);

			if (fout.is_open())
			{
				for (int i = 0; i < m_numOfParkedVehicles; i++)
				{
					if (m_ParkingSpot[i] != nullptr)
					{
						m_ParkingSpot[i]->setCsv(true);
						m_ParkingSpot[i]->write(fout);
					}
				}

				fout.close();
			}
	
		}

		cin.ignore(100, '\n');
		cin.clear();
	}

	int Parking::run()
	{
		int option;
		bool exitloop = false;

		if (!isEmpty())
		{
			while (exitloop == false)
			{
				this->ParkingMenu();

				cin >> option;

				if (option == 1)
				{
					this->ParkVehicles();
				}

				if (option == 2)
				{
					this->ReturnVehicles();
				}

				if (option == 3)
				{
					this->ListparkedVehicles();
				}

				if (option == 4)
				{
					if (CloseParking() == true)
					{
						return 0;
					}
					
				}

				if (option == 5)
				{
					if (ExitParkingApp() == true)
					{
						cout << "Exiting program!" << endl;
						return 0;
					}

				}
			}

			return 0;
		}
		else
		{
			return 1;
		}

	}

}