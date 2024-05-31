#include "User.h"

void User::setIdUser(int i ) {
    idUser = i;
}
void User::setPassword(string p) {
    password = p;
}
void User::setName(string n) {
    name = n;
}
void User::setSurname(string s) {
    surname = s;
}
void User::setLogin(string l) {
    login = l;
}

int User::getIdUser() { return idUser;}
string User::getPassword() {return password;}
string User::getName() { return name;}
string User::getSurname() {return surname;}
string User::getLogin() {return login;}
