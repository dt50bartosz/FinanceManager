#include <iostream>
#include <windows.h>
#include  <stdio.h>
#include "FinanceApp.h"


using namespace std;





int main()
{
    FinanceApp financeApp("User.xml","Income.xml","Expense.xml");
    char userChoice;

    while(true)
    {
        system("cls");




        if(!financeApp.isUserLoggenId())
        {
                FinanceApp::maninMenu();
                cin.sync();
            cin  >> userChoice;
            switch(userChoice)
            {
                case '1':
                    financeApp.registerUser();
                    break;
                case '2':
                   financeApp.login();
                    break;
                case '3':
                    exit(0);
                default:
                    cout << "Invalid input" << endl;
            }
        }
        else
        {
            system("cls");
            FinanceApp ::loggedUserMenu();
            cin.sync();
            cin >> userChoice;

            switch(userChoice)
            {
            case '1':
                financeApp.addIncome();
                break;
            case '2':
                financeApp.addExpense();
                break;
            case '3':
                financeApp.changePassword();
                break;
            case '4':
                financeApp.showCurrentBalance();
                break;
            case '5':
                financeApp.showPreviouseMonthBalance();
                break;
            case '6':
                financeApp.showCustomPeriodBalance();
                break;
            case '7':
                financeApp.logout();
                break;
            default:
            cout << "Invalid input" << endl;


            }
        }
    }

    return 0;
}
