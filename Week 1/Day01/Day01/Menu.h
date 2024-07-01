#pragma once
#include <vector>
#include <string>
//using namespace std;//BAD practice
class Menu
{
public:
	//print the menu
	// should it return anything? no
	// does it need me to pass data to it? no
	// 
	void PrintMenu();

	//add menu items
		// should it return anything? no
		// does it need me to pass data to it? yes.
		//parameters are just variable declarations. type name
	void AddMenuItem(std::string itemToAdd);//end the declaration with a ;

	//get the number of menu items
		//should it return anything? yes. int
		//does it need me to pass data to it? no. the vector is part of the class.
	int ItemCount();//the declaration of the method

	//remove a menu item
		// should it return anything? yes. whether it removed anything. bool
		// does it need me to pass data to it? yes. index to remove. int.
	bool RemoveMenuItem(int indexToRemove);
private:
	std::vector<std::string> menuItems;
};

