#include <iostream>
using namespace std;

//Write a program contains a class Toy that has data members : name(string),
//price(float), tax(float), and Net_price(float).It contains a function to read data
//members(name, price, tax),
// and set the Net_price(net price is the price and the tax on this price)
// , a function to display the data members, and a function
//	compares between net price for two objects and return the object with max
//	value.
// 
// In main function define an array of Toy class of length n, read the
//	elements of array, and display the elements which their net price > 50. Compare
//	between the net price for first object and last object in the array, and display the
//	max object.

class Toy {public:
	string name;
	float price;
	float tax;
	float Net_price;

	void read() {
		cin >> name >> price >> tax;
		Net_price = price + tax;
	}
	void display() {
		cout << "the name is :" << name << endl;
		cout << "the tax is :" << tax << endl;
		cout << "the price is :" << price << endl;
		cout << "the net prcie is :" << Net_price << endl;
	}
	Toy compare(Toy a) {
		if (Net_price < a.Net_price)return a;
		return *this;
	}
};

int main() {
	int n;cin >> n;
	Toy x[100];
	for (int i = 0; i < n; i++)
		x[i].read();
	for (int i = 0; i < n; i++)
		if (x[i].Net_price > 50)
			x[i].display();
	x[0].compare(x[n - 1]).display();

	return 0;
}