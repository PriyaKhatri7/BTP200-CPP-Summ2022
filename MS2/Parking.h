#ifndef SDDS_PARKING_H
#define SDDS_PARKING_H
#include "Menu.h"

namespace sdds
{
	class Parking
	{
		char* p_filename; //filename of app
		Menu p_menu; //menu of app
		Menu p_vehicleMenu; //vehicle menu

		bool isEmpty() const; //true if parking is invalid. false is parking is valid
		void setEmpty();
		bool LoadDataFile() const;
		void ParkingStatus() const;
		void ParkVehicles() const;
		void ReturnVehicles() const; //only prints message
		void ListParkedVehicles() const;
		bool CloseParking() const;
		bool ExitParking() const;
		void SaveDataFile() const;
		void ParkingMenu() const;
		Parking& operator=(const Parking&) = delete; //copy assignment prohibited
		Parking(const Parking&) = delete; //copy constructor prohibited
	public:
		Parking();
		Parking(const char* name);
		int run();
		~Parking();
	};

}
#endif // !SDDS_PARKING_H

