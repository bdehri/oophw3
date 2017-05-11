#pragma once

#include <string>

class Cookie
{
public:
	Cookie();
	Cookie(std::string name, float amount, float price);
	~Cookie();
	friend std::ostream &operator<<(std::ostream &output, const Cookie& cookie);
	friend double &operator<<(double &total_cost, const Cookie& cookie);
private:
	float amount_, price_;
	std::string name_;
};

