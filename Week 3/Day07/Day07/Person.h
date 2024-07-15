#pragma once
#include <string>
#include <iostream>
class Person
{
public:

	Person(int age, const std::string& name)
		: age_(age), name_(name)
	{
	}

	void ItsMyBirthday()
	{
		age_++;
		std::cout << "It's my birthday! Let's eat some cake!\n";
	}

	int Age() { return age_; }
	void Age(int age) {
		if (age >= 0 && age <= 150)
			age_ = age;
	}
	std::string Name() { return name_; }
	void Name(std::string name)
	{
		if (name.size() > 0)
			name_ = name;
	}


private:
	int age_;
	std::string name_;

};

