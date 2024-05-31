#ifndef OPERATIONMETHODS_H
#define OPERATIONMETHODS_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <regex>
#include <string>
#include <iomanip>
#include <windows.h>

#include "Type.h"
#include "Operation.h"
#include "OperationFile.h"
#include "DateMethods.h"
#include "AuxiliaryMethods.h"

using namespace std;


class OperationMethods {
    const int LOGGED_USER_ID;

    AuxiliaryMethods auxiliaryMethods;
    OperationFile incomeFile;
    OperationFile expenseFile;
    DateMethods dateMethods;
    Type type;




    vector <Operation> incomes;
    vector <Operation> expenses;

    void displayBalance(const string date1, const string date2);
    double caluclateBalance(const string date1, const string date2, Type& type);
    Operation addOperationDetails(Type &type);
    double enterAmount();
    void sortVector(vector <Operation>& vec);
    void showOperation(vector <Operation>::iterator& ptr);

public:

    OperationMethods(int loggedUserId,string incomeFileName,string expenseFileName) : LOGGED_USER_ID(loggedUserId),incomeFile(incomeFileName,loggedUserId),expenseFile(expenseFileName,loggedUserId) {
     incomes = incomeFile.LoadOperations();
     expenses = expenseFile.LoadOperations();
   }


    void addIncome();
    void addExpense();
    void showBalanceCurrentMonth();
    void showBalancePreviousMonth();
    void showCustomBalance();

};




#endif // END
