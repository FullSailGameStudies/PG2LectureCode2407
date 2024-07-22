// Day08.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include "Inheritance.h"
#include "Polymorphism.h"
#include "Car.h"
#include "FlyingCar.h"
#include "Pistol.h"
#include <vector>


void ShowNumber()
{
	static int i = 0;
	std::cout << ++i << "\n";
}
int main()
{
	for (size_t i = 0; i < 10; i++)
	{
		ShowNumber();
	}
	std::cin.get();
	/*
		╔═══════════════╗
		║  Inheritance  ║
		╚═══════════════╝

								╔═════════╗     ╔══════════╗
						 class  ║SomeClass║  :  ║OtherClass║
								╚═════════╝     ╚══════════╝
									 │                │
									 └──┐             └──┐
								   ┌────▼────┐      ┌────▼────┐
								   │ Derived │      │  Base   │
								   │  Class  │      │  Class  │
								   └─────────┘      └─────────┘

			Access modes:
				public inheritance:
				protected inheritance:
				private inheritance: (default if not specified)



				CONSTRUCTORS: the derived constructor must call a base constructor
				public SomeClass(.....) : baseClass(....)


			Lecture Code: add a FlyingCar class that derives from Car

	*/

	FlyingCar delorean(1983, "Delorean", "DMC-15", 1000, 150);//calling the default ctor
	delorean.refuel();
	delorean.refuel(15);//compile decision -- which one gets called?
	Car myOtherCar(1988, "Ford", "Mustang GT 5.0");

	Account savings1(10);
	Account savings2(100);
	savings1 = savings1 + savings2;


	std::vector<Car*> garage;
	FlyingCar* myRide = &delorean;
	FlyingCar* myRide2 = myRide;//copy the pointer
	Car* myCurrentRide = &myOtherCar;
	garage.push_back(myRide);
	garage.push_back(myCurrentRide);

	Car* heapCar = new Car(2024, "Tesla", "Cybertruck");
	delete heapCar;//to clean up the heap
	heapCar = nullptr;
	if(heapCar != nullptr) {}

	std::cout << "\nCOPY vs POINTER\n";
	Car car   = delorean;//COPIES the car parts to car
	std::cout << "COPY: " << car.vehicleInformation() << "\n";
	//UPCAST
	Car* pCar = &delorean;//POINTS pCar to a FlyingCar
	std::cout << "PTR: " << pCar->vehicleInformation() << "\n\n";

	garage.push_back(pCar);
	std::cout << "\nJay's Garage\n";
	for (auto carPtr : garage)
	{
		std::cout << carPtr->vehicleInformation() << "\n";
	}


	{
		std::vector<std::unique_ptr<Car>> gsGarage;
		std::unique_ptr<Car> uniqueHeap = std::make_unique<Car>(2024, "Tesla", "Cybertruck");

		std::unique_ptr<Car> myHeapRide = std::move(uniqueHeap);//changes ownership of the pointer
		if(uniqueHeap != nullptr)
			uniqueHeap->refuel();

		gsGarage.push_back(std::move(myHeapRide));
		gsGarage.push_back(std::make_unique<FlyingCar>(1983, "Delorean", "DMC-15", 1000, 150));
		std::cout << "\nG's Garage\n";
		for (auto& uCar : gsGarage)
		{
			std::cout << uCar->vehicleInformation() << "\n";
		}
		std::cout << "\n\n";
	}//uniqueHeap will be cleaned up here

	int num = 5;
	long bigNum = num;//implicit cast
	float fNum = 5.F;
	bigNum = (long)fNum;//explicit cast
	std::string sNum = "5";
	//bigNum = (long)sNum;


	/*
		╔═════════════════════════════╗
		║  COMPILE-TIME Polymorphism  ║
		╚═════════════════════════════╝

		Method Overloading:
			- changing the number of parameters
			- changing the types of the parameters

		Lecture Code: Overload the refuel method in Car

	*/







	/*
		╔═════════════════════════════╗
		║  COMPILE-TIME Polymorphism  ║
		╚═════════════════════════════╝

		Operator Overloading

		Lecture Code: overload the + operator in Account

	*/







	/*
		╔════════════════════════╗
		║  RUNTIME Polymorphism  ║
		╚════════════════════════╝

		╔═════════════╗
		║ OVERRIDING  ║ - changing the behavior of a base method
		╚═════════════╝

		1) add 'virtual' to the base method
		2) add a method to the derived class that has the same signature as the base.
			OPTIONALLY put 'override' on the derived method


		FULLY OVERRIDING:
			not calling the base method from the derived method

		EXTENDING:
			calling the base method from the derived method
			to call the base method...  baseClassName::method(...)



		Lecture Code: override the print method in the base/derived classes in the Polymorphism.h file

		╔*************╗
		║  CHALLENGE  ║
		╚*************╝

		overload the + in the Pistol class to add 2 pistols
			- it sets the magCapacity to the max of the 2 pistols
			- adds the # of rounds from both pistols. should not exceed the magCapacity.
	*/



	/*
		╔*************╗
		║  CHALLENGE  ║
		╚*************╝

			add a new class, Pistol, that derives from Weapon.
			Pistol should have fields with getters/setters for rounds and magCapacity.
			Add a constructor that calls the base constructor

		╔*************╗
		║  CHALLENGE  ║
		╚*************╝

			Add an OVERLOAD of the calcDamage method in the Weapon class.
			The overload should take an int parameter called modifier
			to increase the damage when calculating the damage.


		╔*************╗
		║  CHALLENGE  ║
		╚*************╝

			Override Weapon's showMe method in the Pistol class.
			In Pistol's version, call the base version then print out the rounds and magCapacity



	*/
	Pistol pewpew(50, 100, 10, 15);
	pewpew.showMe();



}

