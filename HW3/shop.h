#pragma once

#include "candy.h"
#include "cookie.h"
#include "icecream.h"
#include <string>

template <class T>

class Shop
{
public:
	Shop()
	{
		this->discount = 0;
		this->size = 0;
	}

	Shop(T first)
	{
		elements = new T[1];
		elements[0] = first;
		size = 1;
		discount_ = 0;
	}

	void add(T obj)
	{
		T *temp; // temporary array
		temp = new T[size]; // temporary element size 
		for (int i = 0; i < size; i++)
		{
			temp[i] = elements[i];
		}
		delete[] elements; // Old memory deallocate
		elements = new T[size + 1]; // New array memory area
		for (int i = 0; i < size; i++)
		{
			elements[i] = temp[i];
		}
		elements[size] = obj;
		size++;
		delete[] temp;  // Temp array memory deallocate
	}

	
	~Shop()
	{
		delete[] this->elements;
	}


	void setDiscount(float discount)
	{
		if (discount>0 && discount <= 30) // It must be between 0 and 30
			this->discount_ = discount;
		else // Otherwise error
		{
			string error;
			error = "Discount rate is out of range!";
			throw error;
		}
	}



	friend std::ostream &operator<<(std::ostream &os, Shop<T> const &m) {

		double total = 0;
		os << "Number of Items:" << m.size << std::endl;
		for (int i = 0; i < m.size; i++)
		{
			os << i + 1 << ":" << m.elements[i] << std::endl << std::endl;
			total << m.elements[i]; // overloaded operator will be invoked
		}

		os << "**********************" << std::endl;
		os << "Total cost:" << total << std::endl;

		if (m.discount_ != 0)
		{
			os << "Discount\t: %" << m.discount_ << endl;
			os << "Discount amount\t: -" << (total / 100) * m.discount_ << endl;
			total = total - ((total / 100) * m.discount_);
			os << "Discounted cost\t: " << total << endl;
		}

		os << "*************************************" << std::endl;
		return os;
	}


	friend double &operator<<(double &total_cost, const Shop<T>& m) // Overload << operator for calculating  multiple trips cost
	{
		for (int i = 0; i < m->size; i++)
		{
			total_cost << m->elements[i];
		}

		if (m->discount != 0) // We passed discounted cost to next trip in multiple trips 
		{
			total_cost = total_cost - ((total_cost / 100) * m->discount_);
		}

		return total_cost;
	}
private:
	T *elements;
	float discount_;
	int size;
	
};




