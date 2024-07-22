#pragma once
#include <string>
#include <fstream>
#include <iostream>

class Superhero
{
public:

	Superhero(const std::string& name, const std::string& secret, int age)
		: name_(name), secret_(secret), age_(age)
	{
	}
	//another ctor that will call Deserialize
	Superhero(const std::string& csvData, char delimiter)
	{
		Deserialize(csvData, delimiter);
	}

	void Serialize(std::ofstream& outFile,/*where to save it*/ char delimiter /*delimiter to use*/);

	void WhoAmI()
	{
		std::cout << "Hello citizen. I am " << name_ << "! (aka " << secret_ << "). ";
		std::cout << "And I am " << age_ << " years old.\n";
	}
private:
	std::string name_, secret_;
	int age_;	
	
	void Deserialize(const std::string& csvData, char delimiter);

};

