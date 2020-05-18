#include "credit.h"
#include "processingcenterr.h"
int main()
{
    processingcenter Horribleloan;
    string passpetia = Horribleloan.add_client("Petia", 20000);
    Horribleloan.base_out("");
    string passvasia = Horribleloan.add_client("Vasia", 100000);
    Horribleloan.base_out("admin");
    string passrom = Horribleloan.add_client("Rom", 150000);
    string passvitia = Horribleloan.add_client("Vitia", 112000);
    Horribleloan.base_out("admin");
    Horribleloan.add_money("Petia", passpetia, 12232);
    Horribleloan.add_money("Vasia", passvasia, 50000);
    Horribleloan.base_out("admin");
    Horribleloan.get_money("Vasia", passvasia, 50000);
    Horribleloan.base_out("admin");
    Horribleloan.get_money("Vasia", passvasia, 150000);
    Horribleloan.base_out("admin");
    credit mycredit(&Horribleloan);
    string ns = Horribleloan.serch("Petia", passpetia);
    mycredit.autorization("Petia", passpetia, ns);
    int l = mycredit.get_procents(12323, 4);
    cout << l << endl;
    l = mycredit.get_credit("Petia", passpetia, 2000, 4);
    cout << l << endl;
    int dolg = mycredit.getdolg("Petia", passpetia);
    cout << dolg << endl;
    system("pause");
}
