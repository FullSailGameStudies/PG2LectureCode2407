// Day05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>

enum class Weapon
{
    Sword, Axe, Spear, Mace
};

//return type: (index) int
//parameters: the thing we're searching, the thing we're looking for
int LinearSearch(std::vector<int> numbersToSearch, int searchNumber)
{
    int foundIndex = -1;//-1 means NOT FOUND
    for (int i = 0; i < numbersToSearch.size(); i++)
    {
        if (searchNumber == numbersToSearch.at(i))
        {
            foundIndex = i;
            break;
        }
    }
    return foundIndex;
}

void PrintCourse(const std::map<std::string,float>& grades)
{
    std::cout << "\nPG2 2407\n";
    for (auto& [student, grade] : grades)
    {
        std::cout << std::setw(20) << std::left << student;
        std::cout << std::setw(8) << std::right << grade << "\n";
    }
}

int main()
{
    /*
        ╔═════════╗
        ║Searching║
        ╚═════════╝

        There are 2 ways to search a vector: linear search or binary search

        CHALLENGE 1:

            write a method to linear search the numbers list.
                The method should take 2 parameters: vector of ints to search, int to search for.
                The method should return -1 if NOT found or the index if found.

            The algorithm:
                1) start at the beginning of the vector
                2) compare each item in the vector to the search item
                3) if found, return the index
                4) if reach the end of the vector, return -1 which means not found

    */
    std::vector<int> numbers = { 0,1,2,3,4,5,6 };
    int searchNumber = 6;
    int index = LinearSearch(numbers, searchNumber);
    if (index == -1)
        std::cout << searchNumber << " is not found.\n";
    else
        std::cout << searchNumber << " was found at index " << index << "\n";
    std::cin.get();


    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Creating a map  ]

        map<TKey, TValue>  - an associative collection.
            TKey is a placeholder for the type of the keys.
            TValue is a placeholder for the type of the values.

        When you want to create a map variable,
            1) replace TKey with whatever type of data you want to use for the keys
            2) replace TValue with the type you want to use for the values


        [  Adding items to a map  ]

        There are 2 ways to add items to a Dictionaruy:
        1) using the insert method.
        3) using [key] = value
    */
    std::map<Weapon, int> dorasBackpack;//will store the counts of each kind of weapon

    //returns an iterator and a bool. 
    //if the key is already in the map, it will NOT insert it -- the bool will be false.
    auto inserted = dorasBackpack.insert(std::make_pair(Weapon::Sword, 5));
    if (inserted.second == false) //meaning not inserted
        std::cout << "The key was already in the map. It was not inserted.\n";
    else
        std::cout << "The key was inserted in the map.\n";

    dorasBackpack[Weapon::Axe] = 3;
    dorasBackpack[Weapon::Axe] = 7;//simply overwrites the value if the key is already in the map




    std::map<std::string, double> menu;

    //2 ways to add to a map:
    //  1) map[key] = value;  -- overwrites existing value
    //  2) map.insert(pair); -- will NOT overwrite

    //keys are unique (meaning only 1)
    //menu[0] = 5.99; doesn't work.
    menu["Pineapple Pizza"] = 14.99;//x-small
    menu["Pineapple Pizza"] = 17.99;//x-small
    menu["Breadsticks"] = 4.99;

    //pair has 2 parts: first and second
    auto pair = std::make_pair("Caesar's Salad", 8.99);
    menu.insert(pair);
    auto result = menu.insert(pair);
    //result.first is the iterator to the pair in the map
    //result.second is a bool. true if inserted, false if NOT inserted
    if (result.second)
        std::cout << "The item was inserted.\n";
    else
        std::cout << "The item was already in the map.\n";

    std::cout << "\nIterator for loop\n";
    for (auto iter = menu.begin(); iter != menu.end(); iter++)
    {
        //iterator points to a key-value pair
        //iterator->first is the key
        //iterator->second is the value
        const std::string& menuItem = iter->first;
        double price = iter->second;
        std::cout << std::setw(20) << std::left << menuItem;
        std::cout << std::setw(7) << std::right << price << "\n";
    }
    std::cout << "\nrange-based for loop\n";
    for (auto& [menuItem, price] : menu)
    {
        std::cout << std::setw(20) << std::left << menuItem;
        std::cout << std::setw(7) << std::right << price << "\n";
    }
    std::cin.get();


    /*
        CHALLENGE 2:

            Create a map that stores names (string) and numeric grades. 
            Call the variable grades.
            Add students and grades to your map.

    */
    srand(time(NULL));
    std::map<std::string, float> grades;
    grades["Gianni"] = rand() % 10001 / 100.0F;
    grades["Austin"] = rand() % 10001 / 100.0F;
    grades["Jorge"] = rand() % 10001 / 100.0F;
    grades["Delvin"] = rand() % 10001 / 100.0F;
    grades["Hemant"] = rand() % 10001 / 100.0F;
    grades["Raymond"] = rand() % 10001 / 100.0F;
    grades["Stephan"] = rand() % 10001 / 100.0F;
    grades["Jerry"] = rand() % 10001 / 100.0F;
    grades["Michael"] = rand() % 10001 / 100.0F;
    grades["Orlinda"] = rand() % 10001 / 100.0F;
    grades["Travis"] = rand() % 10001 / 100.0F;

    /*for (size_t i = 0; i < grades.size(); i++)
    {
        float grade = grades.at(i);
    }*/
    PrintCourse(grades);
    std::cin.get();


    /*
        CHALLENGE 4:

            Loop over your grades map and print each student name and grade.

    */



    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Looping over a map  ]

        You should use a ranged-based for loop when needing to loop over the entire map.

    */
    for (auto const& [key, val] : dorasBackpack) //requires C++ 20
    {
        switch (key)
        {
        case Weapon::Sword:
            std::cout << "Sword: ";
            break;
        case Weapon::Axe:
            std::cout << "Axe: ";
            break;
        case Weapon::Spear:
            std::cout << "Spear: ";
            break;
        case Weapon::Mace:
            std::cout << "Mace: ";
            break;
        default:
            break;
        }
        std::cout << val << "\n";
    }




    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Checking for a key in a map  ]

        use the find method to check if the key is in the map

        will return map.end() if NOT found.

    */
    std::map<Weapon, int>::iterator foundIter = dorasBackpack.find(Weapon::Mace);
    if (foundIter == dorasBackpack.end()) //meaning it was NOT found
    {
        std::cout << "Dora did not find any maces.\n";
    }
    else
    {
        //can safely grab the value for the key
        std::cout << "Dora found " << foundIter->second << " Maces\n";
    }


    std::cout << "\n\nFinding keys...\n";
    std::string keyToFind = "Dino Nuggies";
    //double itemPrice = menu[keyToFind];//???
    auto isFoundIterator = menu.find(keyToFind);
    if (isFoundIterator == menu.end()) //means NOT FOUND
        std::cout << keyToFind << " is not on the menu. Try McDonald's!\n";
    else
    {
        std::cout << keyToFind << " costs " << isFoundIterator->second << "\n";
    }


    /*
        CHALLENGE 5:

            look for a specific student in the map.
            If the student is found, print out the student's grade
            else print out a message that the student was not found

    */
    while (true)
    {
        PrintCourse(grades);
        std::string studentName;
        std::cout << "Student to find and curve: ";
        std::getline(std::cin, studentName);
        if (studentName.size() == 0) break;

        auto foundStudent = grades.find(studentName);
        if (foundStudent == grades.end())
            std::cout << studentName << " is not in PG2 this month.\n";
        else
        {
            float grade = foundStudent->second;
            //grades[studentName] = grade *= 1.05;
            foundStudent->second = grade * 1.05;
            std::cout << studentName << " had a grade of " << grade << "!\n";
            std::cout << "Now the grade is " << grades[studentName] << "!\n";
        }
    }



    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Updating a value for a key in a map  ]

        To update an exisiting value in the map, use the [ ]


    */
    dorasBackpack[Weapon::Axe] = 1;//updates the count for the axe



    /*
        CHALLENGE 6:

            Pick any student and curve the grade (add 5) that is stored in the grades map

    */
}