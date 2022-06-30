#pragma once
namespace myProducts
{
	class Product {
		static int staticId;
		int id;
		string name;
		double price;
		string color;
	public:
		Product(string name, double price, string color)
			:id(++staticId), name(name), price(price), color(color) {}

		int getId()const { return id; }
		string getName()const { return name; }
		string getColor()const { return color; }
		double getPrice()const { return price; }

		friend ostream& operator<<(ostream& output, const Product& p);
	};
	int Product::staticId = 0;;
	ostream& operator<<(ostream& output, const Product& p)
	{
		cout << "Id: " << p.id
			<< endl << "Name: " << p.name
			<< endl << "Price: " << p.price
			<< endl << "Color: " << p.color << endl;

		return output;
	}

	class ProductItem {
		static int staticId;
		int id;
		Product* product;

	public:
		int quantity;
		ProductItem(int quantity, Product* product)
			:id(++staticId), quantity(quantity), product(product) {}

		double TotalPrice() { return product->getPrice() * quantity; }
		Product getProduct() { return *product; }
		int getId()const { return id; }
		int getQuantity()const { return quantity; }
		friend ostream& operator<<(ostream& output, const ProductItem& p);
	};
	int ProductItem::staticId = 0;
	ostream& operator<<(ostream& output, const ProductItem& p) {
		cout << "Product Item Id: " << p.id << endl << "Quantity: " << p.quantity << endl;
		cout << "Product: " << *p.product << endl;
		return output;
	}
}