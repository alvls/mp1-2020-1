#include <iostream>
using namespace std;

class weightkg
{
private:
    double weight = 0;
public:

    void set(double x)
    {
        weight = x;
    }

    void print()
    {
        std::cout << "weight now:" << weight << " kg\n\n" << std::endl;
    }

    double kg_oz()
    {
        double weightoz;
        weightoz = weight * 35.27;
        return weightoz;
    }

    double kg_pound()
    {
        double weightpo;
        weightpo = weight * 2.2;
        return weightpo;
    }

    double kg_stone()
    {
        double weightst;
        weightst = weight * 0.16;
        return weightst;
    }

    double kg_ruspound()
    {
        double weightrus;
        weightrus = weight * 2.44;
        return weightrus;
    }
    double kg_carat()
    {
        double weightcar;
        weightcar = weight * 5000;
        return weightcar;
    }
    double kg_apothecarypound()
    {
        double weightapo;
        weightapo = weight * 2.68;
        return weightapo;
    }
};

int main()
{
    weightkg a;
    int mainchoice;
    int choice;
    double k;
    while (true)
    {
       

        do
        {
            cout << "Please select an action\n 1) find out the current weight\n 2) Set a new weight\n 3) Transfer to another measure of weight\n 4) Exit\n";
            cin >> mainchoice;
            if (mainchoice < 1 || mainchoice > 4) cout << "You entered the wrong answer.\nPlease try again:\n\n";
        } while (mainchoice < 1 || mainchoice > 4);

        switch (mainchoice)
        {
        case 1:
            a.print();
            break;
        case 2:
            do
            {
                cout << "Please enter the weight you want to work with (kg)\n";
                cin >> k;
                if (k < 0) cout << "Yours weight is less than zero. Please try again:\n\n";
            } while (k < 0);
            a.set(k);
            break;
        case 3:
            do
            {
                cout << "in what measure of weight do you want to transfer?\n 1) ounce\n 2) pound\n 3) stone\n 4) russian pound\n 5) carat\n 6) apothecary pound\n";
                cin >> choice;
                if (choice < 1 || choice > 6) cout << "You entered the wrong answer.\nPlease try again:\n\n";
            } while (choice < 1 || choice > 6);

            switch (choice)
            {
            case 1:
                cout << "Result:" << weight << "kg =  " << a.kg_oz() << " ounces'\n\n";
                break;
            case 2:
                cout << "Result:" << weight << "kg =  " << a.kg_pound() << " pounds'\n\n";
                break;
            case 3:
                cout << "Result:" << weight << "kg =  " << a.kg_stone() << " stones'\n\n";
                break;
            case 4:
                cout << "Result:" << weight << "kg =  " << a.kg_ruspound() << " russian pounds'\n\n";
                break;
            case 5:
                cout << "Result:" << weight << "kg =  " << a.kg_carat() << " carats'\n\n";
                break;
            case 6:
                cout << "Result:" << weight << "kg =  " << a.kg_apothecarypound() << " apothecary pounds'\n\n";
                break;
            }
            break;
        case 4:
            return 0;
            break;
        }
    }
}