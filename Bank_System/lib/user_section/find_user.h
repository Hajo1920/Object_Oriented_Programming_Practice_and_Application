#include "../misc/input_validate_lib.h"
#include "../misc/header_title_screen.h"
#include "user_lib.h"

class clsFindUser : protected clsScreen {
    private:
     static void _Print(clsUser & User){
        cout << "\nUser Info:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.GetFirstName();
        cout << "\nLastName    : " << User.GetLastName();
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.GetEmail();
        cout << "\nPhone       : " << User.GetPhone();
        cout << "\nUserName    : " << User.GetUserName();
        cout << "\nPassword    : " << User.GetPassword();
        cout << "\nPermission     : " << User.GetPermissions();
        cout << "\n___________________\n";
}

     public:
     static void FindUser(){
        string userName = clsInputValidator::ReadString("Enter User Name");
        while(!clsUser::IsUserExist(userName)){
            cout << "User Not Found !" << endl;
            userName = clsInputValidator::ReadString("Enter User Name Again");
        }

        clsUser User = clsUser::Find(userName);
        _Print(User);
     }

};