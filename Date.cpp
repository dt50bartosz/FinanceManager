#include "Date.h"

 void Date::setCurrentDate(){
    auto now = chrono::system_clock::now();
    time_t now_c = std::chrono::system_clock::to_time_t(now);
    timePtr = std::localtime(&now_c);
}

 string Date::getCurrentDate(){

    char buffer[11]; // Buffer for holding the formatted date string
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", timePtr);
    return string(buffer);

}


int Date::getCurrentMonth() {
    return timePtr->tm_mon + 1;


}

int Date::getCurrentYear() {
    return timePtr->tm_year + 1900;
}

bool Date::checkIfMonthIsJanuary( const int month) {
    int const JANUARY = 1;
    return getCurrentMonth() == JANUARY ? true : false;

}

int Date::getPreviousMonth() {

    int previouseMonth = getCurrentMonth() - 1;
    const int DECEMBER = 12;

    if(checkIfMonthIsJanuary(getCurrentMonth()))
    {
            return DECEMBER;
    }

    return previouseMonth;


}
