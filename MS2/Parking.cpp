#include <iostream>
#include <cstring>
#include "Parking.h"
#include "Menu.h"
using namespace std;

namespace sdds
{
	Parking::Parking()
	{
		p_filename = nullptr;
		p_menu = nullptr;
		p_vehicleMenu = nullptr;
	}

	Parking::Parking(const char* file) :

		p_filename(nullptr),
		p_menu ("Parking Menu, select an action:", 0),
		p_vehicleMenu ("Select type of the vehicle:", 1)
	{	
		if (file != nullptr && file[0] != '\0')
		{
			p_filename = new char[strlen(file) + 1];
			strcpy(p_filename, file);
		}

		if (LoadDataFile()) //loading menu
		{
			//p_menu = new Menu("Parking Menu, select an action:", 0);
			p_menu.add("Park Vehicle");
			p_menu.add("Return Vehicle");
			p_menu.add("List Parked Vehicles");
			p_menu.add("Close Parking (End of day)");
			p_menu.add("Exit Program");

			//p_vehicleMenu = new Menu("Select type of the vehicle:", 1);
			p_vehicleMenu.add("Car");
			p_vehicleMenu.add("Motorcycle");
			p_vehicleMenu.add("Cancel");
		}
		else {
			cout << "Error in data file" << endl;
			setEmpty();
		}
	}

	int Parking::run()
	{
		int select; bool exitapp = false; 

		if (!isEmpty())
		{
			while (exitapp == false)
			{
				ParkingMenu();
				cin >> select; //user

				if (select == 1)
				{
					ParkVehicles();
				}

				if (select == 2)
				{
					ReturnVehicles();
				}

				if (select == 3)
				{
					ListParkedVehicles();
				}

				if (select == 4)
				{
					CloseParking();
					break;
				}

				if (select == 5)
				{
					if (ExitParking() == true)
					{
						cout << "Exiting program!" << endl;
						return 0;
					}
				}
			} return 0;
		}
		else 
		{ 
			return 1; 
		}
	}

	Parking::~Parking()
	{
		SaveDataFile();
		delete[] p_filename;
		p_filename = nullptr;
	}

	bool Parking::isEmpty() const
	{
		if (p_filename == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Parking::setEmpty()
	{
		p_filename = nullptr;
		p_menu = nullptr;
		p_vehicleMenu = nullptr;
	}

	bool Parking::LoadDataFile() const
	{
		if (!isEmpty())
		{
			cout << "loading data from " << p_filename << endl;
			return true;
		}
		else
		{
			return false;
		}
	}

	void Parking::SaveDataFile() const
	{
		if (!isEmpty())
		{
			cout << "Saving data into " << p_filename << endl;
		}
	}

	void Parking::ParkingMenu() const
	{
		ParkingStatus();
	}

	void Parking::ParkingStatus() const
	{
		cout << "****** Seneca Valet Parking ******" << endl;
		p_menu.display();
	}

	void Parking::ParkVehicles() const
	{
		int user = 0;
		p_vehicleMenu.display();
		cin >> user;

		if (user == 1)
		{
			cout << "Parking Car" << endl;
		}

		if (user == 2)
		{
			cout << "Parking Motorcycle" << endl;
		}

		if (user == 3)
		{
			cout << "Cancelled parking" << endl;
		}
	}

	void Parking::ReturnVehicles() const
	{
		cout << "Returning Vehicle" << endl;
	}
	
	void Parking::ListParkedVehicles() const
	{
		cout << "Listing Parked Vehicles" << endl;
	}

	bool Parking::CloseParking() const
	{
		cout << "Closing Parking" << endl;
		return true;
	}
	
	bool Parking::ExitParking() const
	{
		bool userinput, exitapp = false;
		char select[10]; //supports arr 10 

		cout << "This will terminate the program!" << endl;
		cout << "Are you sure? (Y)es/(N)o: ";
		cin.getline(select, 3);

		while (exitapp == false)
		{
			//if user enters y. not case sensitive
			if ((select[0] == 'y' || select[0] == 'Y') && (select[1] == '\0'))
			{
				exitapp = true;
				userinput = true;
			}
			//if user enters n. not case sensitive
			else if ((select[0] == 'n' || select[0] == 'N') && (select[1] == '\0'))
			{
				exitapp = true;
				userinput = false;
			}
			else { //repeats asking user if invalid response
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
				cin >> select;
			}
		}
		return userinput;
	}
}

