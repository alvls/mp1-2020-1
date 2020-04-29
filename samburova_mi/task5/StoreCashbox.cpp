#include "StoreCashbox.h"


Product::Product(uint _barcode, const std::string& _name, double _price, uint _discount) : barcode(_barcode), name(_name), price(_price), discount(_discount) {}

Product::~Product() {}

void Product::set_barcode(uint _barcode)
{
	barcode = _barcode;
}

void Product::set_name(std::string _name)
{
	name = _name;
}

void Product::set_price(double _price)
{
	price = _price;
}

void Product::set_discount(uint _discount)
{
	discount = _discount;
}

uint Product::get_barcode() const
{
	return barcode;
}

std::string Product::get_name() const
{
	return name;
}

double Product::get_price() const
{
	return price;
}

uint Product::get_discount() const
{
	return discount;
}

bool Product::operator==(const Product& other) const
{
	return barcode == other.barcode;
}

bool Product::operator!=(const Product& other) const
{
	return !(*this == other);
}

bool Product::operator<(const Product& other) const
{
	return barcode < other.barcode;
}

bool Product::operator>(const Product& other) const
{
	return barcode > other.barcode;
}

bool Product::operator<=(const Product& other) const
{
	return !(*this > other);
}

bool Product::operator>=(const Product& other) const
{
	return !(*this < other);
}

Product& Product::operator=(const Product& other)
{
	barcode = other.barcode;
	name = other.name;
	price = other.price;
	discount = other.discount;
	return *this;
}

std::istream& operator>>(std::istream& in, Product& product)
{
	in >> product.barcode >> product.price;
	std::getline(in, product.name);
	return in;
}

std::ostream& operator<<(std::ostream& out, const Product& product)
{
	out << std::setfill('0') << std::setw(4) << product.barcode << " " << product.price << " " << product.name;
	return out;
}

container::container(size_t size) : quantitys(size) {}

container::container(const container& other) : quantitys(other.quantitys) {}

container::~container() {}

void container::emplace(const Product& product, size_t quantity)
{
	quantitys.emplace_back(std::pair<Product, size_t>(product, quantity));
}

void container::erase(const Product& product)
{
	size_t size = quantitys.size();
	size_t i;
	for (i = 0; i < size; ++i)
		if (quantitys[i].first == product) break;
	if (i == size) return;
	quantitys.erase(quantitys.begin() + i);
}

size_t container::size()
{
	return quantitys.size();
}

void container::clear()
{
	quantitys.clear();
}

container& container::operator=(const container& other)
{
	quantitys = other.quantitys;
	return *this;
}

std::pair<Product, size_t> container::operator[](size_t index)
{
	return quantitys[index];
}

size_t& container::operator[](const Product& product)
{
	while (true)
	{
		size_t size = quantitys.size();
		size_t i;
		for (i = 0; i < size; ++i)
			if (quantitys[i].first == product) break;
		if (i == size) emplace(product, 0);
		return quantitys[i].second;

	}
}


Stock::Stock() {}

Stock::Stock(const Stock& other) {}

Stock::~Stock() {}

void Stock::set_products(const container& _products)
{

	products = _products;
}

container Stock::get_products()
{
	return products;
}

Cashbox::Cashbox() : Stock() {}

Cashbox::~Cashbox() {}

void Cashbox::scan(uint _barcode)
{
	barcode = _barcode;
}

std::pair<Product, size_t> Cashbox::get_information()
{
	for (size_t i = 0; i < products.size(); ++i)
		if (products[i].first.get_barcode() == barcode) return products[i];
	return std::pair<Product, size_t>(Product(), 0);
}

bool Cashbox::add()
{
	std::pair<Product, size_t> product = get_information();
	if (product.second == 0) return false;
	else
	{
		basket[product.first]++;
		products[product.first]--;
	}
	return true;
}

void Cashbox::remove()
{
	std::pair<Product, size_t> product = get_information();
	size_t qty = basket[product.first];
	basket.erase(product.first);
	products[product.first] += qty;
}

double Cashbox::total_price()
{
	double total = 0;
	for (size_t i = 0; i < basket.size(); ++i)
	{
		total += basket[i].first.get_price() * (1 - basket[i].first.get_discount() / 100.0) * basket[i].second;
	}
	return total;
}

std::string Cashbox::create_check()
{
	std::stringstream check;
	double total = 0;
	for (size_t i = 0; i < basket.size(); ++i)
	{
		double price = basket[i].first.get_price() * basket[i].second * (1 - basket[i].first.get_discount() / 100.0);
		check << std::fixed << std::setprecision(2) << basket[i].first.get_name() << " " << basket[i].first.get_price() << " rub *" << basket[i].second << " " << basket[i].first.get_discount() << "% = " << price << "\n";
		total += price;
	}
	check << "~~~~~~~~~~\n" << total;
	basket.clear();
	return check.str();
}
