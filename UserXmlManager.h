#ifndef USERXMLMANAGER_H
#define USERXMLMANAGER_H

#include <iostream>
#include "Markup.h"
#include <vector>
#include <windows.h>
#include <cstdio>

#include "User.h"
#include "AuxiliaryMethods.h"

using namespace std;


class UserXmlManager {

    const string USER_FILE_NAME;
    void addElement(User& user,CMarkup& xml);
public:
    UserXmlManager(const string userFileName) : USER_FILE_NAME(userFileName){}

    void addUserToXml(User& user);
    vector <User> LoadUsers();
    void changePasswordInXml(vector <User>& users);



};




#endif // END
