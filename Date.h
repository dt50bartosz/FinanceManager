#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <chrono>
#include <windows.h>


using namespace std;


class Date {

    tm* timePtr;

    void setCurrentDate();



public:

    Date() {setCurrentDate();}

    string getCurrentDate();
    int getPreviousMonth();
    int getCurrentMonth();
    int getCurrentYear();
    int getCurrentDay();

    bool checkIfMonthIsJanuary(const int month);


};




#endif // END
