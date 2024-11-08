#pragma once
#include "user_lib.h"
#include "../misc/header_title_screen.h"
#include "../misc/input_validate_lib.h"
#include <iostream>

class clsAddNewUser : protected clsScreen {
    private:

    static void _Print(clsUser & User){
        cout << "\nNew User Info:";
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
    static void _ReadNewUserInfo(clsUser & User){
    User.SetFirstName(clsInputValidator::ReadString("Enter First Name"));
    User.SetLastName(clsInputValidator::ReadString("Enter Last Name"));
    User.SetEmail(clsInputValidator::ReadString("Enter New Email"));
    User.SetPhone(clsInputValidator::ReadString("Enter New Phone"));
    User.SetPassword(clsInputValidator::ReadString("Enter New Password"));
    
}
   static int _ReadAllowedPermissions(){

    char Answer = 'n';
    int permission = 0;

    cout << "\nDo you want to give access to: Show Client List [y] or [n])? ";
    cin >> Answer;

    if(tolower(Answer) == 'y') permission+= clsUser::enPermissionList::allowShowClientList;

    cout << "\nDo you want to give access to: Add New Client [y] or [n])? ";
    cin >> Answer;

    if(tolower(Answer) == 'y') permission+= clsUser::enPermissionList::allowAddNewClient;

    cout << "\nDo you want to give access to: Delete Client Record [y] or [n])? ";
    cin >> Answer;

    if(tolower(Answer) == 'y') permission+= clsUser::enPermissionList::allowDeleteClient;

    cout << "\nDo you want to give access to: Update Client Record [y] or [n])? ";
    cin >> Answer;

    if(tolower(Answer) == 'y') permission+= clsUser::enPermissionList::allowUpdateClient;
    cout << "\nDo you want to give access to: Find Client Record [y] or [n])? ";
    cin >> Answer;

    if(tolower(Answer) == 'y') permission+= clsUser::enPermissionList::allowFindClient;

    cout << "\nDo you want to give access to: Transactions [y] or [n])? ";
    cin >> Answer;

    if(tolower(Answer) == 'y') permission+= clsUser::enPermissionList::allowTransactionAccess;

     cout << "\nDo you want to give access to: Manage Users [y] or [n])? ";
    cin >> Answer;

    if(tolower(Answer) == 'y') permission+= clsUser::enPermissionList::allowManageUsersAccess;

    cout << "\nDo you want to give access to: System Access Log [y] or [n])? ";
    cin >> Answer;

    if(tolower(Answer) == 'y') permission+= clsUser::enPermissionList::allowSystemAccessLogAccess;

    return permission;
}
    
    
    public:
   static void AddNewUser(){
        clsScreen::_DrawScreenHeader("Add New User");
        string UserName = clsInputValidator::ReadString("Enter a new user name");

        while(clsUser::IsUserExist(UserName)){
            cout << "This username is not available !" << endl;
            UserName = clsInputValidator::ReadString("Enter a new user name");
        }

        clsUser User = clsUser::GetAddNewUserObject(UserName);
        _ReadNewUserInfo(User);

        char confirmPermission = 'n';
        cout << "Allow maximum previllages for this user (y or n) ? ";
        cin >> confirmPermission;

        if(confirmPermission == 'y' || confirmPermission == 'Y'){
            User.SetPermissions(-1);
        }else {
            User.SetPermissions(_ReadAllowedPermissions());
        }

        clsUser::enSaveResults SaveResults;

        SaveResults = User.Save();

        switch (SaveResults)
        {
        case clsUser::enSaveResults::svSucceeded:
            cout << "User have been added successfuly !" << endl;
            _Print(User);
            break;
        case clsUser::enSaveResults::svFaildUserExists:
             cout << "User Exists ! Operation unsuccessful !";
             break;
        case clsUser::enSaveResults::svFaildEmptyObject:
             cout <<  "User Information is Empty ! Operation unsuccessful !" << endl;
             break;
        default:
            break;
        }


    }
};