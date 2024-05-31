#include "OperationFile.h"


void OperationFile::addOperationToXml(Operation& operation){

    bool fileExists = xml.Load(OPERATAION_FILE_NAME);

    if(!fileExists) {
       xml.AddElem("OPERATION");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("operation");
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("userId",operation.getUserId());
    xml.AddElem("operationId",operation.getOperationId());
    xml.AddElem("item",operation.getItem());
    xml.AddElem("date",operation.getDate());
    xml.AddElem("amount",auxiliaryMethods.doubleToString(operation.getAmount()));


    xml.Save(OPERATAION_FILE_NAME);

}

vector <Operation> OperationFile::LoadOperations() {
    Operation operation;

    vector <Operation> operations;
    bool fileExists = xml.Load(OPERATAION_FILE_NAME);

    if(!fileExists)
    {

        cout << "Empty File" << endl;
        Sleep(600);
        system("cls");
        return operations;
    }

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();


    while(xml.FindElem()) {
     xml.FindChildElem("userId");
     if(stoi(xml.GetChildData()) == USER_ID){
         operation.setUserId(stoi(xml.GetChildData()));
         xml.FindChildElem("operationId");
         operation.setOperationId(stoi(xml.GetChildData()));
         xml.FindChildElem("item");
         operation.setItem(xml.GetChildData());
         xml.FindChildElem("date");
         operation.setDate(xml.GetChildData());
         xml.FindChildElem("amount");
         operation.setAmount(stod(xml.GetChildData()));

         operations.push_back(operation);}
     }


    return operations;
}

int OperationFile::getLastOperationId(){



    const int FIRST_OPERATION = 1;
    int lastOperationId{0};

    bool fileExists = xml.Load(OPERATAION_FILE_NAME);

    if(!fileExists)
    {

        return FIRST_OPERATION;
    }

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();

    while(xml.FindElem())
    {
        xml.FindChildElem("operationId");
        lastOperationId = stoi(xml.GetChildData());
    }

    return lastOperationId + 1;

}





