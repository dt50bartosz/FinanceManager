#include "OperationMethods.h"


void OperationMethods::sortVector(vector <Operation>& vec) {

    try
    {
        sort(vec.begin(), vec.end(), [&](auto& i1, auto& i2)
    {
        return dateMethods.isDate1BeforeDate2(i1.getDate(), i2.getDate());
    });}

    catch(const out_of_range& e)
    {
        cerr << "Error: " << e.what() << std::endl;

    };
}
double OperationMethods::enterAmount() {
    regex moneyPattern(R"(^\d+(\.\d{2}))");
    string input;

    double money;

    while(true){

        cout << "Enter an amount of money: ";
        getline(cin,input);

        if (std::regex_match(input, moneyPattern))
        {
            istringstream iss(input);
            iss >> money;

            break;
        }
        else
        {
            cout << "Invalid format. Please ensure the amount has two decimal places" << endl;

        }
    }

    return money;
}
Operation OperationMethods::addOperationDetails(Type &type) {
    Operation operation;
    string operationType;

    operation.setUserId(LOGGED_USER_ID);
    operation.setOperationId(incomeFile.getLastOperationId());


    switch(type)
    {
       case INCOME:
         operation.setOperationId(incomeFile.getLastOperationId());
         operationType = "income";
         break;
       case EXPENSE:
       operation.setOperationId(expenseFile.getLastOperationId());
       operationType = "expense";
       break;
    }

    system("cls");


    cout << "Please enter " << operationType << " details" << endl << endl;
    operation.setItem(auxiliaryMethods.doWhileStringIsEmpty("item"));
    operation.setAmount(enterAmount());
    operation.setDate(dateMethods.customDateOrCurrentDate());

    cout << operationType << "was added successfully" << endl;
    Sleep(600);


    return operation;
}
void OperationMethods::addIncome() {
    Operation income;
    type = INCOME;
    income = addOperationDetails(type);
    incomes.push_back(income);
    incomeFile.addOperationToXml(income);
}
void OperationMethods::addExpense() {
    Operation expense;
    type = EXPENSE;
    expense = addOperationDetails(type);
    expenses.push_back(expense);
    expenseFile.addOperationToXml(expense);
}
void OperationMethods::displayBalance(const string date1, const string date2) {

    bool hasIncomesInPeriod = false;
    bool hasExpensesInPeriod = false;

    double income{0.00},expense{0.00};

    auto printOperation = [&]( Operation operation)
    {
        cout << "Item: " << operation.getItem() << endl;
        cout << "Date: " << operation.getDate() << endl;
        cout << "Amount: " <<  fixed << setprecision(2) << operation.getAmount() << endl;
        cout << "Operation Id: " << operation.getOperationId() << endl;
        cout << std::endl << std::endl;
    };

    auto currentBalance = [&] () {
        double total = income - expense;
        cout << "Current Balance for " << date1  << " " << date2 << fixed << setprecision(2) << " is " << total << "$" << endl;
        cout << "Income total amount: " << fixed << setprecision(2) << income << "$" << endl;
        cout << "Expense total amount: " << fixed << setprecision(2) << expense << "$" << endl << endl;

    };

    system("cls");

    cout << "Income" << endl << endl;

    for (auto it = incomes.begin(); it != incomes.end(); ++it)
    {
        if (dateMethods.isDateInRangeUserDate(date1, date2, it->getDate())) {
            printOperation(*it);
            hasIncomesInPeriod = true;
            income += it->getAmount();
        }
    }

    if(!hasIncomesInPeriod)
    {
         cout << "No Incomes available in the given period." << endl << endl;
    }

    cout << "Expenses" << endl << endl;

    for (auto it = expenses.begin(); it != expenses.end(); ++it)
    {
        if (dateMethods.isDateInRangeUserDate(date1, date2, it->getDate())) {
            printOperation(*it);
             hasExpensesInPeriod = true;
            expense += it -> getAmount();
        }
    }

    if(!hasExpensesInPeriod){
        cout << "No Expenses available in the given period." << endl << endl;
    }

    currentBalance();

    auxiliaryMethods.waitForCharcter();

}


void OperationMethods::showBalanceCurrentMonth() {

    sortVector(incomes);
    sortVector(expenses);
    displayBalance(dateMethods.getCurtrenMonthFirstDay(),dateMethods.getCurrentDate());
}

void OperationMethods::showBalancePreviousMonth(){

    sortVector(incomes);
    sortVector(expenses);
    displayBalance(dateMethods.getPreviouseMonthFirstDay(),dateMethods.getPreviouseMonthLastDay());
}

void OperationMethods::showCustomBalance() {
    string beginningDate,endingDate;
    sortVector(incomes);
    sortVector(expenses);

    cout << "Please enter a beginning date" << endl;
    beginningDate = dateMethods.userCustomDate();
    cout << "Please enter ending date" << endl;
    endingDate = dateMethods.userCustomDate();

    displayBalance(beginningDate,endingDate);
}


