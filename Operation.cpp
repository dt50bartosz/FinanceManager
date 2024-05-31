#include "Operation.h"


void Operation:: setItem(string i){item = i;}
void Operation::setDate(string d){date = d;}
void Operation::setOperationId(int id) {operationId = id;}
void Operation::setAmount(double a) {amount = a;}
void Operation::setUserId(int i) {userId = i;}

string Operation::getItem() {return item;}
string Operation::getDate() {return date;}
int Operation::getOperationId() {return operationId;}
int Operation::getUserId() {return userId;}
double Operation::getAmount() {return amount;}
