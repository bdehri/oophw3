#include "icecream.h"

Icecream::Icecream()
{
}


Icecream::Icecream(std::string name, float amount, float price)
{
	this->amount_ = amount;
	this->name_ = name;
	this->price_ = price;
}


Icecream::~Icecream()
{
}

std::ostream &operator<<(std::ostream &output, const Icecream& icecream) // Operator << overload for print Icecream information
{
	output << icecream.name_ << "#" << icecream.amount_ << " Cost:" << (icecream.amount_ * icecream.price_);

	return output;
}

double &operator<<(double &total_cost, const Icecream& icecream) // Operator << overload for calculate cost
{
	total_cost += (icecream.amount_ * icecream.price_);
	return total_cost;
}