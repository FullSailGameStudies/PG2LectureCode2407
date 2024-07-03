// Day02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include "../../Day01/Day01/Menu.h"
#include <iomanip>

bool postFix(std::string& hero)
{
    srand((unsigned int)time(NULL));
    int postFixNumber = rand() % 1000;
    hero = hero + "-" + std::to_string(postFixNumber);
    return postFixNumber % 2 == 0;
}

float average(const std::vector<int>& scores)
{
    //scores.push_back(5); //not allowed because it is marked as const
    float sum = 0;
    for (auto score : scores)
        sum += score;

    return sum / scores.size();
}

void print(const std::vector<int>& scores)
{
    std::cout << "----SCORES----\n";
    int index = 1;
    for (int score : scores)
        std::cout << index++ << ". " << score << "\n";
}

void printInfo(const std::vector<int>& scores)
{
    std::cout << "size: " << scores.size() << "\tcapacity: " << scores.capacity() << "\n";
}

void FillGrades(std::vector<float>& course)
{
    srand((unsigned int)time(NULL));
    for (size_t i = 0; i < 10; i++)
    {
        //% modulo. returns remainder of a division
        course.push_back(rand() % 10001 / 100.f);
    }

}
void PrintGrades(const std::vector<float>& course)
{
    std::cout << "\nPG2 2407\n";
    for (auto& grade : course)
    {
        std::cout << std::setw(7) << std::right << grade << "\n";
    }
}
void CalculateStats(const std::vector<float>& course, float& minGrade, float& maxGrade)
{
    minGrade = maxGrade = course[0];
    for (size_t i = 1; i < course.size(); i++)
    {
        if (course[i] > maxGrade) maxGrade = course[i];
        else if (course[i] < minGrade) minGrade = course[i];
        //or...
        //maxGrade = std::max(maxGrade, course[i]);
        //minGrade = std::min(minGrade, course[i]);
    }
}

int main()
{
    Menu cafe;
    std::string item = "fries";
    cafe.AddMenuItem("Burger", 10.99f);
    std::cout << "\nmemory address of item: " << &item << "\n";
    cafe.AddMenuItem(item, 1.49f);

    std::vector<std::string> names{ "Pancakes","Waffles","French Toast","Omelette","Bacon" };
    std::vector<float> prices{ 4.99F,5.99f,8.99F,9.99f,2.99f };
    cafe.AddMenuItems(names, prices);
    cafe.PrintMenu();
    std::cin.get();
    //-------------------------------------------------//
    //                                                 //
    // Copy the Menu files from Day01 to Day02 project //
    //                                                 //
    //-------------------------------------------------//

    //DAY 02 (pass by reference, const, removing in a loop)
    // 
    //Fields to add:
    // add prices vector to class
    // 
    //Methods to add:
    //
    //Add menu items (vector of names, vector of prices)
    // should it return anything? 
    // does it need data passed to it? 
    // 
    //Remove items (price threshold) -- remove all items that are priced above the threshold
    // should it return anything? 
    // does it need data passed to it? 
    // 
    //go back and apply const to prior methods where applicable



    /*
        ╔══════════════════════════════╗
        ║Parameters: Pass by Reference.║
        ╚══════════════════════════════╝
        Sends the variable itself to the method. The method parameter gives the variable a NEW name (i.e. an alias)

        NOTE: if the method assigns a new value to the parameter, the variable used when calling the method will change too.
            This is because the parameter is actually just a new name for the other variable.
    */
    std::string spider = "Spiderman";
    bool isEven = postFix(spider);
    std::string evenResult = (isEven) ? "TRUE" : "FALSE";
    std::cout << spider << "\n" << "Is Even postfix? " << evenResult << "\n";


    /*
        CHALLENGE 1:

            Write a method to fill the vector of floats with grades.
            1) pass it in by reference
            2) add 10 grades to the vector

    */

    /*
        CHALLENGE 2:

            Write a method to calculate the stats on a vector of grades
            1) create a method to calculate the min, max. 
                pass the grades vector as a const reference. Use ref parameters for min and max.
            2) call the method in main and print out the min, max.

    */
    std::vector<float> grades;
    FillGrades(grades);
    PrintGrades(grades);
    float min, max;
    CalculateStats(grades, min, max);
    std::cout << "Min: " << min << "\nMax: " << max << "\n";



    /*
        ╔══════════════════╗
        ║ const parameters ║
        ╚══════════════════╝
        const is short for constant. It prevents the variable from being changed in the method.

        This is the way you pass by reference and prevent the method from changing the variable.
    */
    std::vector<int> highScores;
    for (int i = 0; i < 10; ++i)
        highScores.push_back(rand());
    float avg = average(highScores);







    /*
        ╔═══════════╗
        ║ vector<T> ║
        ╚═══════════╝

        [  Removing from a vector  ]

        clear() - removes all elements from the vector
        erase(position) - removes the element at the position
        erase(starting position, ending position) - removes a range of elements. the end position is not erased.

    */
    print(highScores);

    for (size_t i = 0; i < highScores.size();)
    {
        if (highScores[i] < 2500)
            highScores.erase(highScores.begin() + i);
        else
            ++i;
    }


    /*
        INTERMEDIATE LEVEL...
        a way using std::remove_if and a lambda
    highScores.erase(
        std::remove_if(highScores.begin(),
            highScores.end(),
            [](int score) { return score < 2500; }),
        highScores.end());
    */


    print(highScores);



    /*
        CHALLENGE 3:

            Using the vector of grades you created.
            Remove all the failing grades (grades < 59.5).
            Print the grades.
    */





    /*
        ╔═══════════╗
        ║ vector<T> ║
        ╚═══════════╝

        
        size(): # of items that have been ADDED
        capacity(): length of the internal array
        reserve(n): presizes the internal array
    */
    std::vector<int> scores;
    scores.reserve(10); //makes the internal array to hold 10 items.

    printInfo(scores);
}