#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>

#include "User.h"
#include "UserXmlManager.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UserManager
{
    UserXmlManager userXmlManager;
    AuxiliaryMethods auxiliaryMethods;

    int idUser;
    vector <User> users;

    bool checkIfloginExist(string login);
    bool findUserByLogin(const string login, vector<User>::iterator& ptr);
    bool findUserById(vector<User>::iterator& ptr);
    int userIdForNewUser();


  public:
      UserManager(const string UserFileName) : userXmlManager(UserFileName) {
      users = userXmlManager.LoadUsers();
      this -> idUser = 0;}

      void changePassword();
      void regiserUser();
      void loginUser();
      void logoutUser();
      int getIdUser();
      bool isUserLoggedIn();


};

#endif // USER_H
