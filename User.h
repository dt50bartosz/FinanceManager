#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User
{
  int idUser;
  string password;
  string name;
  string surname;
  string login;

  public:

      void setIdUser(int i );
      void setPassword(string p);
      void setName(string name);
      void setSurname(string s);
      void setLogin(string l);

      int getIdUser();
      string getPassword();
      string getName();
      string getSurname();
      string getLogin();
};

#endif // USER_H
