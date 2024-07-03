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

	//add menu item
		// should it return anything? no
		// does it need me to pass data to it? yes.
		//parameters are just variable declarations. type name
	void AddMenuItem(const std::string& itemToAdd, float price);//end the declaration with a ;

	//add menu items
		// should it return anything? no
		// does it need me to pass data to it? yes
		// how do we pass the parameters? by value or by ref?
		// does the method need to modify the variable? const will prevent the method from changing the parameters
		// does the method modify the class members?
	void AddMenuItems(const std::vector<std::string>& itemNames,const std::vector<float>& itemPrices);

	//get the number of menu items
		//should it return anything? yes. int
		//does it need me to pass data to it? no. the vector is part of the class.
		// does the method modify the class members? NO. so make it a const method.
	int ItemCount() const;//the declaration of the method

	//remove a menu item
		// should it return anything? yes. whether it removed anything. bool
		// does it need me to pass data to it? yes. index to remove. int.
	bool RemoveMenuItem(int indexToRemove);
private:
	std::vector<std::string> menuItems;
	std::vector<float> prices;
};

