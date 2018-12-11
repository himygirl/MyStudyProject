#pragma once
#include<iostream>
#include<string>

using namespace std;


class Sales_item
{
public:
	Sales_item();
	~Sales_item();


	//ÖØÔØº¯Êı +
	const Sales_item operator+(Sales_item&Test);
	Sales_item(string name, unsigned number, double MyValue)
	{
		isbn = name;
		units_sold = number;
		MyValue = revenue;
	};

	void display() 
	{
		std::cout << "isbin----" << isbn << "units_sold------" << units_sold << "revenue----" << revenue << std::endl;	
	}

	void cin();
	void cout() const;
	Sales_item &sum(const Sales_item &item);
	double avg_price();
private:

	string isbn;
	unsigned units_sold;
	double revenue;

};




/*
class Sales_item
{
public:
	
	//Sales_item() : units_sold(0), revenue(0.0) {};
	Sales_item();
	~Sales_item();
	

	std::istream& input(std::istream& in);
	std::ostream& output(std::ostream& out) const;
	double avg_price() const;
	bool same_isbn(const Sales_item &rhs) const
	{
		return isbn == rhs.isbn;
	}


private:
	std::string isbn;
	unsigned units_sold;
	double revenue;
};
*/