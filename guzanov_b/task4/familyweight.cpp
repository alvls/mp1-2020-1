#include <iostream>
#include "slaves.h"
#include "locale.h"
int main()
{
    slaves A;
    A.add("Petia", 20, 4, 2020, 25);
    A.add("Vania", 20, 4, 2020, 45);
    A.add("Petia", 22, 4, 2020, 24);
    A.add("Petia", 10, 4, 2020, 48);
    A.add("Petia", 21, 5, 2020, 60);
    A.add("Petia", 21, 6, 2020, 55);
    for (int i = 0; i < A.Getcount_measurement("Petia"); i++)
    {
        cout << A.GetWeight("Petia")[i] << endl;
    }
    for (int i = 0; i < A.Getcount_people(); i++)
    {
        cout << A[i] << endl;
    }
    cout << endl;
    cout << "Min weight Peti " << A.Getminweight("Petia", 4) << endl;
    cout << endl;
    cout << "Max weight Peti " << A.Getmaxweight("Petia", 4) << endl;
    cout << endl;
    cout << "Middle weight Peti " << A.Getmiddleweight("Petia", 4) << endl;
    cout << endl;
    A.save_data();
    //A.add("Ann", 20, 4, 2020, 45);
    /*
     for (int i = 0; i < A.Getcount_people(); i++)
    {
        cout << A[i] << endl;
        for (int j = 0; j < A.Getcount_measurement(A[i]); j++)
        {
            cout << A.GetWeight(A[i])[j] << endl;
        }
    }
    */

    A.read_file();
    /*for (int i = 0; i < A.Getcount_people(); i++)
    {
        cout << A[i] << endl;
        for (int j = 0; j < A.Getcount_measurement(A[i]); j++)
        {
            cout << A.GetWeight(A[i])[j] << endl;
        }
    }
    */
}