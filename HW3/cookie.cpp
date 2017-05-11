#include "cookie.h"

Cookie::Cookie()
{
}


Cookie::Cookie(std::string name, float amount, float price)
{
	this->amount_ = amount;
	this->name_ = name;
	this->price_ = price;
}


Cookie::~Cookie()
{
}

std::ostream &operator<<(std::ostream &output, const Cookie& cookie) // Operator << overload for print cookie information
{
	output << cookie.name_ << "#" << cookie.amount_ << " Cost:" << ((cookie.amount_/12) * cookie.price_ );

	return output;
}

double &operator<<(double &total_cost, const Cookie& cookie) // Operator << overload for calculate cost
{
	total_cost += ((cookie.amount_ / 12) * cookie.price_);
	return total_cost;
}