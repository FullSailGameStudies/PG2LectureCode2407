#include "Menu.h"
#include <iostream>
#include <iomanip>


void Menu::PrintMenu()
{
	//loop over the vector and print each item
	//std::cout << menuItems << "\n";
	// first item...
	//	.at(0)
	//	[0]
	//	front()
	std::cout << "\nfor loop...\n";
	for (int index = 0; index < menuItems.size(); index++)
	{
		//setw(#) - sets the width of the next item
		//left/right - alignment within the spaces
		std::string menuItem = menuItems.at(index);
		std::cout << std::setw(7) << std::right << prices[index] << "\t" << menuItem << "\n";
	}
	//range-based for loop
	//auto is a placeholder for the type. the compiler will figure it out.
	//& creates a REFERENCE variable. PREVENTS a copy.
	std::cout << "\nRange-Based loop...\n";
	for (auto& menuItem : menuItems)
	{
		std::cout << menuItem << "\n";
	}

	//iterators are objects that "point" to a specific item in the collection
	//  AND know how to move through the collection
	//	begin() gives an iterator to the first item in the collection (like [0])
	//  end() gives an iterator to the item AFTER the last one???
	//	end()-1 gives an iterator to the last item
	std::cout << "\nIterator loop...\n";
	//std::vector<std::string>::iterator iterator = menuItems.begin();
	for (auto iterator = menuItems.begin(); iterator != menuItems.end(); iterator++)
	{
		std::string menuItem = *iterator;//"DEREFENCE" the "pointer" to get to the item is points to
		std::cout << menuItem << "\n";
	}

}

void Menu::AddMenuItem(const std::string& itemToAdd, float price)//pass by reference (ALIAS)
{
	std::cout << "\nmemory address of itemToAdd: " << &itemToAdd << "\n";
	menuItems.push_back(itemToAdd);
	prices.push_back(price);
}

void Menu::AddMenuItems(const std::vector<std::string>& itemNames,const std::vector<float>& itemPrices)
{
	//itemNames.push_back("Burger");
	for (size_t i = 0; i < itemNames.size(); i++)
	{
		std::string name = itemNames[i];
		menuItems.push_back(name);
	}
	for (auto& price : itemPrices)
	{
		prices.push_back(price);
	}
}

int Menu::ItemCount() const
{
	//AddMenuItem("whatever", 15.99f);
	//menuItems.clear();
	//.size to get the # of items in the vector
	//int size = menuItems.size();
	return static_cast<int>(menuItems.size());
}

bool Menu::RemoveMenuItem(int indexToRemove)
{
	bool wasRemoved = false;
	int count = menuItems.size();
	//erase requires an iterator
	//begin() + index
	menuItems.erase(menuItems.begin() + indexToRemove);
	//if (menuItems.size() != count)
	//	wasRemoved = true;
	wasRemoved = menuItems.size() != count;
	return wasRemoved;
}
