#ifndef FINANCEAPP_H
#define FINANCEAPP_H

#include <iostream>
#include <windows.h>

#include "UserManager.h"
#include "OperationMethods.h"

using namespace std;


class FinanceApp {

    UserManager userManager;
    const string INCOME_FILE_NAME;
    const string EXPENSE_FILE_NAME;
    OperationMethods* operationMethods;

public:
    FinanceApp(string fileUserName,string incomeFileName,string expenseFileName) :
        userManager(fileUserName),
        INCOME_FILE_NAME(incomeFileName),
        EXPENSE_FILE_NAME(expenseFileName) {
        operationMethods = nullptr;}



    static void maninMenu();
    static void loggedUserMenu();
    void registerUser();
    void login();
    bool isUserLoggenId();
    void addIncome();
    void addExpense();
    void showCurrentBalance();
    void showPreviouseMonthBalance();
    void showCustomPeriodBalance();
    void changePassword();
    void logout();
};




#endif // END
