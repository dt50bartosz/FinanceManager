#ifndef OPERATION_H
#define OPERATION_H

#include <iostream>




using namespace std;


class Operation {

    string item;
    string date;
    int userId;
    int operationId;
    double amount;

public:

    void setItem(string i);
    void setDate(string d);
    void setOperationId(int id);
    void setAmount(double a);
    void setUserId(int i);

    string getItem();
    string getDate();
    int getOperationId();
    int getUserId();
    double getAmount();


};




#endif // END
