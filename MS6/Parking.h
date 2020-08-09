/*have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.

Priya Khatri | 110149176 | pkhatri4@myseneca.ca*/

#ifndef SDDS_PARKING_H
#define SDDS_PARKING_H
#include "Menu.h"
#include "Vehicle.h"

namespace sdds
{

	const int MAX_NUMBER_PARKING_SPOTS = 100;

	class Parking 
	{

		char* m_filename; //filename of app
		Menu* m_ParkingMenu; //menu of app
		Menu* m_VehicleMenu;// vehicle menu
		int m_numOfParkingSpots; //num of spots
		int m_numOfParkedVehicles; //num of parked vehicles
		int m_numOfAvailableSpots; //num of available spots
		Vehicle* m_ParkingSpot[MAX_NUMBER_PARKING_SPOTS]; //parking spots


		Parking& operator=(const Parking&) = delete; //copy assignment prohibited
		Parking(const Parking&) = delete; //copy constructor prohibited
		bool isEmpty() const; //true if parking is invalid. false is parking is valid
		void ParkingStatus() const;
		void ParkVehicles();
		void ReturnVehicles();
		void ListparkedVehicles() const;
		bool CloseParking();
		bool ExitParkingApp() const;
		bool LoadDataFile();
		void SaveDataFile() const;
		void ParkingMenu() const;
		void setEmpty();

	public:

		int run();
		Parking();
		Parking(const char*, int);
		~Parking();
	};
}

#endif // !PARKING_H


