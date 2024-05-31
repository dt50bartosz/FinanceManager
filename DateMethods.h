#ifndef DATEMETHODS_H
#define DATEMETHODS_H

#include <iostream>
#include <string>
#include <map>




#include "Date.h"
#include "AuxiliaryMethods.h"



using namespace std;

class DateMethods {

    Date date;
    AuxiliaryMethods auxiliaryMethods;

    string intMonthToString(int month);
    string convertIntDateToYyyyMmDd(const string &date);
    string convertSingleDigitToDouble(const int number);
    int userYear();
    int userMonth();
    int daysInEachMonth(int month,int year);
    int userDay(const int month, const int year);


public:

   string convertIntDateToStringWithDashes(const int year, const int month,const int day);
   string getCurtrenMonthFirstDay();
   string getPreviouseMonthFirstDay();
   string getPreviouseMonthLastDay();
   string customDateOrCurrentDate();
   string getCurrentDate();
   string userCustomDate();
   bool isDate1BeforeDate2(const string& date1, const string& date2);
   bool isDateInRangeUserDate(string date1, string date2,string date3);





};




#endif // END
