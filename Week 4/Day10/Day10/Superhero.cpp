#include "Superhero.h"
#include <sstream>

void Superhero::Serialize(std::ofstream& outFile, char delimiter)
{
	outFile << name_ << delimiter << secret_ << delimiter << age_;
}

void Superhero::Deserialize(const std::string& csvData, char delimiter)
{
	//parse the csvData string using the delimiter
	std::stringstream dataStream(csvData);

	std::getline(dataStream, name_, delimiter);
	std::getline(dataStream, secret_, delimiter);

	std::string ageStr;
	std::getline(dataStream, ageStr, delimiter);
	age_ = std::stoi(ageStr);
}
