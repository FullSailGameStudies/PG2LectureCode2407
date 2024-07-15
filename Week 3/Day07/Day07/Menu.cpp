#include "Menu.h"
#include <iostream>


//static = shared by all the instances of a class
int Menu::someData_ = 0;//ALL menu instances have this ONE variable	

Menu::Menu(std::string title) :
	//1) member initialization list (preferred way)
	title_(title)
{
	//2) set the fields in the ctor code
	//title_ = title;
}

void Menu::AddMenuItem(std::string itemToAdd, float price)
{
	std::pair<std::map<std::string,float>::iterator,bool> wasAddedPair = menuItems_.insert(std::make_pair(itemToAdd, price));
	if (wasAddedPair.second)//bool
		std::cout << itemToAdd << " was added to the menu.\n";
	else
		std::cout << "Could not add " << itemToAdd << " because it was already on the menu.\n";
}

//non-static methods:
//	there is a "hidden" parameter called 'this'
//	can access non-static AND static members
void Menu::ViewMenu()//Menu* this)
{
	std::cout << menuItems_.size() << "\n";
	for (auto& [menuItem,price] : this->menuItems_)
	{
		std::cout << price << " "<< menuItem << "\n";
	}
}
//static methods:
//	do NOT have a 'this' pointer
//	cannot access NON-static members (fields or methods)
void Menu::PrintSomeData()
{
	//std::cout << menuItems_.size() << "\n";
	std::cout << someData_ << "\n";
}
