#include "DateMethods.h"

string DateMethods::intMonthToString(int month){

        std::map<int, std::string> monthNames = {
        {1, "January"},{2, "February"},{3, "March"},{4, "April"},
        {5, "May"},{6, "June"},{7, "July"},{8, "August"},
        {9, "September"},{10, "October"},{11, "November"},
        {12, "December"}
    };
    return monthNames[month];
}
string DateMethods::convertIntDateToStringWithDashes(const int year, const int month, const int day){
    return to_string(year) + "-" + auxiliaryMethods.convertSingleDigitToDouble(month) + "-" + auxiliaryMethods.convertSingleDigitToDouble(day);

}
string DateMethods::convertIntDateToYyyyMmDd(const string& date){
      return   date.substr(0,4)+ date.substr(5,2) + date.substr(8,2);
}
int DateMethods::daysInEachMonth(int month,int year) {
    map<int,int> daysInMonth = {
        {1, 31},{2, 28},{3, 31},
        {4, 30},{5, 31},{6, 30},{7, 31},
        {8, 31},{9, 30},{10, 31},
        {11, 30},{12, 31} };

    return (month == 2 && year % 4 == 0) ? 29 : daysInMonth[month];
}
string DateMethods::getCurrentDate() {
    return date.getCurrentDate();
}
string DateMethods::getCurtrenMonthFirstDay() {
    const int FIRST_DAY_MONTH = 1;
    return convertIntDateToStringWithDashes(date.getCurrentYear(),date.getCurrentMonth(),FIRST_DAY_MONTH);
}
string DateMethods::getPreviouseMonthFirstDay() {
    const int FIRST_DAY_MONTH = 1;

    if(date.checkIfMonthIsJanuary(date.getCurrentMonth()))
    {
        int previouseYear = date.getCurrentYear() - 1;
        return convertIntDateToStringWithDashes(previouseYear,date.getCurrentMonth(),FIRST_DAY_MONTH);
    }

    return convertIntDateToStringWithDashes(date.getCurrentYear(),date.getPreviousMonth(),FIRST_DAY_MONTH);
}
string DateMethods::getPreviouseMonthLastDay(){

    if(date.checkIfMonthIsJanuary(date.getCurrentMonth()))
    {
        int previouseYear = date.getCurrentYear() - 1;
        return convertIntDateToStringWithDashes(previouseYear,date.getPreviousMonth(),daysInEachMonth(date.getPreviousMonth(),previouseYear));
    }

    return convertIntDateToStringWithDashes(date.getCurrentYear(),date.getPreviousMonth(),daysInEachMonth(date.getPreviousMonth(),date.getCurrentYear()));
}
int DateMethods::userYear() {
    const int MINIMUM_YEAR = 2020;
    int year = 0;

    while (true) {
        cout << "Please enter a year: ";
        cin >> year;

        if (MINIMUM_YEAR <= year && year <= date.getCurrentYear()) {
            return year;
        }

        cout << "Please enter a year between " << MINIMUM_YEAR << " and " << date.getCurrentYear() << endl;
    }
}
int DateMethods::userMonth() {
    const int JANUARY = 1;
    const int DECEMBER = 12;
    int month = 0;

    while (true) {
        cout << "Please enter a month (1-12): ";
        cin >> month;

        if (JANUARY <= month && month <= DECEMBER) {
            return month;
        }

        cout << "Please enter a valid month between " << JANUARY << " and " << DECEMBER << endl;
    }
}
int DateMethods::userDay(const int month, const int year) {
    const int FIRST_DAY_MONTH = 1;
    int daysInMonth = daysInEachMonth(month, year);
    int day = 0;

    while (true) {
        cout << intMonthToString(month) << " has " << daysInMonth << " days. ";
        cout << "Please enter a day: ";
        cin >> day;

        if (FIRST_DAY_MONTH <= day && day <= daysInMonth) {
            return day;
        }

        cout << "Please enter a valid day between " << FIRST_DAY_MONTH << " and " << daysInMonth << endl;
    }
}
string DateMethods::userCustomDate() {
    int year{0},month{0},day{0};

    year = userYear();
    month = userMonth();
    day = userDay(month,year);

    return convertIntDateToStringWithDashes(year,month,day);
}
string DateMethods::customDateOrCurrentDate() {
    char choice;

    cout << "1.Current Date" << endl;
    cout << "2.Enter date manually" <<endl;

    while(true)
    {
        cin.sync();
        cin >> choice;

        switch(choice)
        {
        case '1':
            return date.getCurrentDate();
        case '2':
            return userCustomDate();
        default:
            cout << "Invalid choice" << endl;
        }
    }
}
bool DateMethods::isDate1BeforeDate2(const string& date1, const string& date2){
    // the comparison is preform by lexicographically
    return convertIntDateToYyyyMmDd(date2) < convertIntDateToYyyyMmDd(date1);
}
bool DateMethods::isDateInRangeUserDate(string date1,string date2,string date)
{

   return convertIntDateToYyyyMmDd(date1) <= convertIntDateToYyyyMmDd(date) && convertIntDateToYyyyMmDd(date) <= convertIntDateToYyyyMmDd(date2);


}

