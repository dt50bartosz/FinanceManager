#include "UserManager.h"




bool UserManager::findUserByLogin(const string login, vector<User>::iterator& ptr){

    ptr = find_if(users.begin(),users.end(),[&](User user){ return user.getLogin() == login;});

    return ptr != users.end();

}

bool UserManager::checkIfloginExist(string login){
    vector<User>::iterator ptr;
     return findUserByLogin(login,ptr);


}
void UserManager::loginUser() {

    int attempt = 3;
    bool isAuthenticated = false;
    string password{""},login{""};
    vector <User>::iterator ptr;


    auto isLogginAndPasswordCorrect = [&] () {

        system("cls");
        cout<< "Please enter login: ";
        cin.sync();
        getline(cin,login);
        cout << "Please enter password: ";
        cin.sync();
        getline(cin,password);

        if(findUserByLogin(login,ptr))
        {
            if(ptr->getPassword()== password)
            {

                idUser = ptr->getIdUser();
                cout << "Password and Login are correct" << endl;
                Sleep(600);
                return true;

            }
        }

        return false;

    };



    do {

        isAuthenticated = isLogginAndPasswordCorrect();

        if (!isAuthenticated) {

            cout << "Incorrect login or password you have " << attempt << " attempts left"<< endl;
            Sleep(600);
            --attempt;
        }



    }while(!isAuthenticated && attempt >= 0);

    if(!isAuthenticated)
    {
        cout << "Too many failed attempts. Exiting." << endl;
        Sleep(600);

    }


}
void UserManager::logoutUser() {
    this -> idUser = 0;
}
int UserManager::getIdUser(){
    return idUser;
}
bool UserManager::isUserLoggedIn() {
    return idUser != 0 ? true : false;
}
void UserManager::regiserUser(){
    User user;

    auto IdForNewUser = [&]() { return users.empty() == true ? 1 : users.back().getIdUser() + 1 ;};

    auto promptForLogin = [&] () {
        string login;

        do {
             login = auxiliaryMethods.doWhileStringIsEmpty("login");

            if (checkIfloginExist(login)) {
                cout << "This login is already taken, please choose a different login" << endl;
            }
        } while (checkIfloginExist(login));

        return login;
    };

    user.setIdUser(IdForNewUser());
    user.setName(auxiliaryMethods.doWhileStringIsEmpty("name"));
    user.setSurname(auxiliaryMethods.doWhileStringIsEmpty("surname"));
    user.setLogin(promptForLogin());
    user.setPassword(auxiliaryMethods.doWhileStringIsEmpty("password"));

    users.push_back(user);
    userXmlManager.addUserToXml(user);

    cout << "User was registered successfully";
    Sleep(600);
}
void UserManager::changePassword() {

    int position{0};
    string password{0};

    auto it = find_if(users.begin(),users.end(),[&]( User user) {return user.getIdUser() == idUser;});

    position = distance(users.begin(),it);

    password = auxiliaryMethods.doWhileStringIsEmpty("password");

    users[position].setPassword(password);

    userXmlManager.changePasswordInXml(users);


}

