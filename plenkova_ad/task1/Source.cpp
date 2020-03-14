#include <iostream>
using namespace std;

class weight_converter
{
private:
    double weight;

public:
    double get_kg()
    {
        return weight;
    }
    void show_kg()
    {
        cout << "Weight in kg = " << weight << endl;
    }
    void set(double x)
    {
        weight = x;
    }
    double convert_to_carat()
    {
        double weight_1;
        weight_1 = weight * 5000;
        return weight_1;
    }
    double convert_to_g()
    {
        double weight_1;
        weight_1 = weight * 1000;
        return weight_1;
    }
    double convert_to_mg()
    {
        double weight_1;
        weight_1 = weight * 1000000;
        return weight_1;
    }
    double convert_to_ounce()
    {
        double weight_1;
        weight_1 = weight * 35.27396194958048;
        return weight_1;
    }
    double convert_to_pound()
    {
        double weight_1;
        weight_1 = weight * 2.2046226218488;
        return weight_1;
    }
    double convert_to_ton()
    {
        double weight_1;
        weight_1 = weight * 0.001;
        return weight_1;
    }
};

int main()
{
    weight_converter mass1;
    double n;
    cout << "Enter the weight in kg: ";
    cin >> n;
    mass1.set(n);
    cout << "Print the value in kilograms?\n1)Yes\n2)No" << endl;
    int a;
    cin >> a;
    if (a == 1)
        mass1.show_kg();

    cout << "Choose weight system:\n1)carat\n2)gram\n3)milligram\n4)ounce\n5)lb.\n6)ton" << endl;
    int s;
    cin >> s;

    switch (s)
    {
    case(1):
        cout << "Weight in carat = " << mass1.convert_to_carat();
        break;
    case(2):
        cout << "Weight in gram = " << mass1.convert_to_g();
        break;
    case(3):
        cout << "Weight in milligram = " << mass1.convert_to_mg();
        break;
    case(4):
        cout << "Weight in ounce = " << mass1.convert_to_ounce();
        break;
    case(5):
        cout << "Weight in lb = " << mass1.convert_to_pound();
        break;
    case(6):
        cout << "Weight in ton = " << mass1.convert_to_ton();
        break;
    }
    system("pause");
}

