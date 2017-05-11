#pragma once

#include <string>


class Candy
{
public:
	Candy();
	Candy(std::string name, float amount, float price);
	~Candy();
	friend std::ostream &operator<<(std::ostream &output, const Candy& candy);
	friend double &operator<<(double &total_cost, const Candy& candy);
private:
	float amount_, price_;
	std::string name_;

};

