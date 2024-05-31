#include "FinanceApp.h"

 void FinanceApp::registerUser(){
     userManager.regiserUser();
}
void FinanceApp::login(){

    userManager.loginUser();

    if(userManager.isUserLoggedIn())
    {
        operationMethods = new OperationMethods(userManager.getIdUser(),INCOME_FILE_NAME,EXPENSE_FILE_NAME);

    }
}

bool FinanceApp::isUserLoggenId() {
    return userManager.isUserLoggedIn();
}

void FinanceApp::addIncome(){
    if(userManager.isUserLoggedIn())
    {
        operationMethods ->addIncome();
    }
}

void FinanceApp::addExpense() {

    if(userManager.isUserLoggedIn())
    {
        operationMethods ->addExpense();
    }
}

void FinanceApp::showCurrentBalance() {

    if(userManager.isUserLoggedIn())
    {
        operationMethods -> showBalanceCurrentMonth();
    }
}
void FinanceApp::showPreviouseMonthBalance() {

    if(userManager.isUserLoggedIn())
    {
        operationMethods ->showBalancePreviousMonth();
    }

}
void FinanceApp::showCustomPeriodBalance() {

        if(userManager.isUserLoggedIn())
        {
            operationMethods -> showBalanceCurrentMonth();
        }

}
void FinanceApp::logout() {
    userManager.logoutUser();
    delete operationMethods;
    operationMethods = nullptr;
}

void FinanceApp::changePassword(){
    userManager.changePassword();

}

 void FinanceApp::loggedUserMenu() {
    cout << "1.Add Income" << endl;
    cout << "2.Add Expense" << endl;
    cout << "3.Change Password" << endl;
    cout << "4.Show Current Month Balance" << endl;
    cout << "5.Show Previous Month Balance" << endl;
    cout << "6.Show Custom Period Balance" << endl;
    cout << "7.Logout" << endl;
}


void FinanceApp::maninMenu() {

    cout << "1.Register new user" << endl;
    cout << "2.Login" << endl;
    cout << "3.Exit" << endl;
}


