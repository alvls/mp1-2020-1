#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <iomanip>
typedef unsigned int uint;

class Product
{
public:
	Product(uint _barcode = 0000, const std::string& _name = "", double _price = 0, uint _discount = 0);
	~Product();

	void set_barcode(uint);
	void set_name(std::string);
	void set_price(double);
	void set_discount(uint);
	uint get_barcode() const;
	std::string get_name() const;
	double get_price() const;
	uint get_discount() const;

	bool operator==(const Product&) const;
	bool operator!=(const Product&) const;
	bool operator<(const Product&) const;
	bool operator>(const Product&) const;
	bool operator<=(const Product&) const;
	bool operator>=(const Product&) const;

	Product& operator=(const Product&);

	friend std::istream& operator>>(std::istream&, Product&);
	friend std::ostream& operator<<(std::ostream&, const Product&);
protected:
	uint barcode;
	std::string name;
	double price;
	uint discount;
};

class container
{
public:
	container(size_t size = 0);
	container(const container&);
	~container();

	void emplace(const Product&, size_t);
	void erase(const Product&);
	size_t size();
	void clear();

	container& operator=(const container&);
	std::pair<Product, size_t> operator[](size_t index);
	size_t& operator[](const Product&);
private:
	std::vector<std::pair<Product, size_t>> quantitys;
};

class Stock
{
public:
	Stock();
	Stock(const Stock&);
	~Stock();

	void set_products(const container&);
	container get_products();
protected:
	container products;
};


class Cashbox
	: public Stock
{
public:
	Cashbox();
	~Cashbox();

	void scan(uint);
	std::pair<Product, size_t> get_information();
	bool add();
	void remove();
	double total_price();
	std::string create_check();
private:
	uint barcode;
	container basket;
};

