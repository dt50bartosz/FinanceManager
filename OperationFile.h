#ifndef OPERATIONFILE_H
#define OPERATIONFILE_H

#include <iostream>
#include "Markup.h"
#include <vector>
#include <windows.h>
#include <string>

#include "Operation.h"
#include "AuxiliaryMethods.h"

using namespace std;


class OperationFile {
    AuxiliaryMethods auxiliaryMethods;

    CMarkup xml;
    const string OPERATAION_FILE_NAME;
    const int USER_ID;

public:

    OperationFile(string operationFileName,int userId) : OPERATAION_FILE_NAME(operationFileName),
    USER_ID(userId) {}

    void addOperationToXml(Operation& operation);
    vector <Operation> LoadOperations();
    int getLastOperationId();

};




#endif // END
