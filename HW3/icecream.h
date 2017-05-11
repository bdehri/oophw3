#pragma once

#include <string>

class Icecream
{
public:
	Icecream();
	Icecream(std::string name, float amount, float price);
	~Icecream();
	friend std::ostream &operator<<(std::ostream &output, const Icecream& icecream);
	friend double &operator<<(double &total_cost, const Icecream& icecream);
private:
	float amount_, price_;
	std::string name_;
};

