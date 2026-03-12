#include <iostream>
using namespace std;
class product
{

    string name;
    float price, tax;
    int serial;
    static int count;
    static int generator;

public:
    product()
    {
        count++;
        generator += 11111;
        serial = generator;
    }
    void read()
    {
        cout << "please enter the name\n";
        cin >> name;
        cout << "please enter the price\n";
        cin >> price;
        cout << "please enter the tax\n";
        cin >> tax;
    }
    float netPrice()
    {
        return tax + price;
    }

    void display()
    {
        cout << "the name is " << name;
        cout << " the price is " << price;
        cout << " the tax is " << tax;
        cout << " the serial is " << serial;
        cout << " the net price is " << netPrice();
    }
    static void display_count();
};
int product::count = 0;
int product::generator = 0;
void product::display_count()
{
    cout << "the number of products is : " << count << endl;
}
int main()
{
    product products[2];
    for (int i = 0; i < 2; i++)
        products[i].read();
    for (int i = 0; i < 2; i++)
        products[i].display();
        product::display_count();

    return EXIT_SUCCESS;

}
