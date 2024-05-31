#include "UserXmlManager.h"

void UserXmlManager::addElement(User& user,CMarkup& xml) {


    xml.AddElem("user");
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("userId",user.getIdUser());
    xml.AddElem("Name",user.getName());
    xml.AddElem("Surname",user.getSurname());
    xml.AddElem("Login",user.getLogin());
    xml.AddElem("Password",user.getPassword());
    xml.OutOfElem();



}
void UserXmlManager::addUserToXml(User& user) {

    CMarkup xml;


    bool fileExists = xml.Load(USER_FILE_NAME);

    if(!fileExists) {
       xml.AddElem("User");
    }
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    addElement(user,xml);

    xml.Save(USER_FILE_NAME);
}
vector <User> UserXmlManager::LoadUsers() {
    CMarkup xml;
    User user;

    vector <User> users;
    bool fileExists = xml.Load(USER_FILE_NAME);

    if(!fileExists) {
        cout << "Empty File" << endl;
        Sleep(600);
        return users;
    }

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();


    while(xml.FindElem()) {
     xml.FindChildElem("userId");
     user.setIdUser(stoi(xml.GetChildData()));
     xml.FindChildElem("Name");
     user.setName(xml.GetChildData());
     xml.FindChildElem("Surname");
     user.setSurname(xml.GetChildData());
     xml.FindChildElem("Login");
     user.setLogin(xml.GetChildData());
     xml.FindChildElem("Password");
     user.setPassword(xml.GetChildData());
     users.push_back(user);
     }

    return users;
}
void UserXmlManager::changePasswordInXml(vector <User>& vec) {

   CMarkup xml;

   const string TEMP_FILE_NAME = "temp.xml";

    // create temp file

    xml.ResetPos();
    xml.AddElem("User");
    xml.IntoElem();

    // add users from vector to xml file

    for (std::vector<User>::iterator ptr = vec.begin(); ptr != vec.end(); ++ptr)
    {
        addElement(*ptr,xml);
    }

    xml.Save(TEMP_FILE_NAME);


    remove(USER_FILE_NAME.c_str());

    rename(TEMP_FILE_NAME.c_str(), USER_FILE_NAME.c_str());
    cout << "Password changed successfully." << std::endl;
    Sleep(600);


}


