#include "StoreCashbox.h"

int main(void)
{
	Cashbox cashbox;
	uint barcode;
	std::pair<Product, size_t> product;
	{
		size_t n, qty;
		uint discount;
		container products;
		std::cout << "Enter quantity of products in Stock: ";
		std::cin >> n;
		Product product;
		for (size_t i = 0; i < n; ++i)
		{
			std::cout << "Enter product <barcode price name>" << std::endl;
			std::cin >> product;
			std::cout << "Enter discount" << std::endl;
			std::cin >> discount;
			product.set_discount(discount);
			std::cout << "Enter quantity of product: ";
			std::cin >> qty;
			products.emplace(product, qty);
		}
		cashbox.set_products(products);
	}
	int variable;
	do
	{
		system("cls");
		std::cout << "What is needed?" << std::endl
			<< "1) Scan" << std::endl
			<< "2) Get product information" << std::endl
			<< "3) Add product to check" << std::endl
			<< "4) Create check" << std::endl
			<< "5) Get total amount" << std::endl
			<< "6) Remove product from check" << std::endl
			<< "7) Exit" << std::endl;
		std::cout << "Your variable - ";
		std::cin >> variable;
		switch (variable)
		{
		case 1:
			std::cout << "Enter barcode: ";
			std::cin >> barcode;
			cashbox.scan(barcode);
			break;
		case 2:
			product = cashbox.get_information();
			if (product.first.get_barcode() != 0)
				std::cout << product.first << "\tquantity - " << product.second << std::endl;
			else
				std::cout << "There is no such product in Stock";
			system("pause");
			break;
		case 3:
			if (!cashbox.add())
			{
				std::cout << "There is no such product in Stock";
				system("pause");
			}
			break;
		case 4:
			system("cls");
			std::cout << cashbox.create_check() << std::endl;
			system("pause");
			break;
		case 5:
			std::cout << std::fixed << std::setprecision(2) << cashbox.total_price() << std::endl;
			system("pause");
			break;
		case 6:
			cashbox.remove();
			break;
		}
	} while (variable != 7);
	return 0;
}