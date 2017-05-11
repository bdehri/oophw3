#include "candy.h"

Candy::Candy()
{
}


Candy::Candy(std::string name, float amount, float price)
{
	this->amount_ = amount;
	this->name_ = name;
	this->price_ = price;
}


Candy::~Candy()
{
}


std::ostream &operator<<(std::ostream &output, const Candy& candy)  // Operator << overload for print candy information
{
	output << candy.name_ << "#" << candy.amount_ << " Cost:" << (candy.amount_ * candy.price_);

	return output;
}

double &operator<<(double &total_cost, const Candy& candy) // Operator << overload for calculate cost
{
	total_cost += (candy.amount_ * candy.price_);
	return total_cost;
}
