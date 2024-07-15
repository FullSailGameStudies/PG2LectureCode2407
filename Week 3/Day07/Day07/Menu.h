#pragma once
#include <string>
#include <vector>
#include <map>
class Menu
{
public:
	
	//constructors are to initialize the fields
	Menu() //default ctor - no parameters
	{
		title_ = "";
	}
	Menu(std::string title);

	void AddMenuItem(std::string itemToAdd,float price);
	std::pair<std::string, float> LookupMenuItem(std::string itemToFind);
	bool RemoveMenuItem(std::string itemToRemove);
	void ViewMenu();

	//getters (accessors) of the fields
	//	return the data
	int GetNumberOfItems() { return menuItems_.size(); }
	const std::map<std::string, float>& MenuItems() {
		return menuItems_;
	}
	std::string Title() { return title_; }

	//setters (mutators) of the fields
	//	CHANGE the data
	void Title(std::string newTitle)
	{
		//put some checks so that code outside of this class
		//cannot modify the data in an unacceptable way
		if (newTitle.size() > 0)
		{
			title_ = newTitle;
		}
	}

	static void PrintSomeData();
private:
	static int someData_;
	std::string title_;
	//int numberOfItems_;//camel casing
	std::map<std::string,float> menuItems_;
};

