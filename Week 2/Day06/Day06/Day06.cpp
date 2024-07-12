// Day06.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <iomanip>


enum class Weapon
{
    Sword, Axe, Spear, Mace
};

void PrintGrades(const std::map<std::string, double>& grades)
{
    std::cout << "\nGrades for PG2: 2407\n";
    for (auto& [student,grade] : grades)
    {
        std::cout << std::setw(10) << std::left << student;
        std::cout << std::setw(7) << std::right << grade << "\n";
    }
    //iterator for loop
    //for (auto iter = grades.begin(); iter != grades.end(); iter++)
    //{
    //    std::cout << std::setw(10) << std::left << iter->first;
    //    std::cout << std::setw(7) << std::right << iter->second << "\n";
    //}
}
int main()
{

    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Removing a key and its value from a map  ]

        erase(iterator) -- returns an iterator that points to the first item AFTER the ones that were removed OR end() if no element exist
        erase(key) -- returns the # of items removed

    */
    std::map<Weapon, int> dorasBackpack;
    auto inserted = dorasBackpack.insert(std::make_pair(Weapon::Sword, 5));
    dorasBackpack[Weapon::Axe] = 3;

    size_t numberErased = dorasBackpack.erase(Weapon::Mace);

    auto foundPairIterator = dorasBackpack.find(Weapon::Axe);
    if (foundPairIterator == dorasBackpack.end())
        std::cout << "Sorry Dora. You don't have any axes to sell.\n";
    else
    {
        auto nextIterator = dorasBackpack.erase(foundPairIterator);
    }





    /*
        CHALLENGE 1:

            print the students and grades below
                use std::setw and std::left and std::right to format the output
            ask for the name of the student to drop from the grades map
                use std::getline to get the user's input
            remove the student from the map
            print message indicating what happened
            if not found print an error message
            else print the map again and print that the student was removed


    */
    srand((unsigned int)time(NULL));
    std::map<std::string, double> grades;
    grades["Bruce"] = rand() % 101;
    grades["Dick"] = rand() % 101;
    grades["Diana"] = rand() % 101;
    grades["Alfred"] = rand() % 101;
    grades["Clark"] = rand() % 101;
    grades["Arthur"] = rand() % 101;
    grades["Barry"] = rand() % 101;

    do
    {
        PrintGrades(grades);
        std::string studentToDrop;
        std::cout << "Name of student to drop: ";
        std::getline(std::cin, studentToDrop);
        if (studentToDrop.size() == 0) break;

        int numberDropped = grades.erase(studentToDrop);
        if (numberDropped == 0)
            std::cout << studentToDrop << " is not in PG2 this month.\n";
        else
        {
            std::cout << studentToDrop << " was kicked from PG2.\n";
        }
    } while (true);
}