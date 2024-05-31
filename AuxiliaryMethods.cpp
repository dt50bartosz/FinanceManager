#include "AuxiliaryMethods.h"

string AuxiliaryMethods::convertSingleDigitToDouble(const int number) {
    stringstream ss;
    ss << setfill('0') << setw(2) << number;
    return ss.str();
}

string AuxiliaryMethods::doWhileStringIsEmpty(string name){
    string item;


    cout << "Please enter " << name << ":";
    cin.sync();
    getline(cin,item);

    while(item.empty()){
        cout << name << " can't be empty" << endl;
        cout << "Please enter: " << name <<endl;
        cin.sync();
        getline(cin,item);
    }

    return item;
}

string AuxiliaryMethods::doubleToString(double money) {
    ostringstream out;
    out << fixed << setprecision(2) << money;
    return out.str();
}

void AuxiliaryMethods::waitForCharcter() {
    cout << ("Press any key to continue...\n");
    cin.sync();
    getchar();
}
