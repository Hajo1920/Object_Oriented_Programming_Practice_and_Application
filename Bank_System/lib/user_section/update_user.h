#include "../misc/input_validate_lib.h"
#include "../misc/header_title_screen.h"
#include "user_lib.h"


class clsUpdateUser : protected clsScreen {
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
        cout << "\nPermission  : " << User.GetPermissions();
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

    cout << "\nDo you want to give access to: Show User List [y] or [n])? ";
    cin >> Answer;

    if(tolower(Answer) == 'y') permission+= clsUser::enPermissionList::allowShowClientList;

    cout << "\nDo you want to give access to: Add New User [y] or [n])? ";
    cin >> Answer;

    if(tolower(Answer) == 'y') permission+= clsUser::enPermissionList::allowAddNewClient;

    cout << "\nDo you want to give access to: Delete User Record [y] or [n])? ";
    cin >> Answer;

    if(tolower(Answer) == 'y') permission+= clsUser::enPermissionList::allowDeleteClient;

    cout << "\nDo you want to give access to: Update User Record [y] or [n])? ";
    cin >> Answer;

    if(tolower(Answer) == 'y') permission+= clsUser::enPermissionList::allowUpdateClient;
    cout << "\nDo you want to give access to: Find User Record [y] or [n])? ";
    cin >> Answer;

    if(tolower(Answer) == 'y') permission+= clsUser::enPermissionList::allowFindClient;

    cout << "\nDo you want to give access to: Transactions [y] or [n])? ";
    cin >> Answer;

    if(tolower(Answer) == 'y') permission+= clsUser::enPermissionList::allowTransactionAccess;

     cout << "\nDo you want to give access to: Manage Users [y] or [n])? ";
    cin >> Answer;

    if(tolower(Answer) == 'y') permission+= clsUser::enPermissionList::allowManageUsersAccess;

    return permission;
}
    public:
    static void UpdateUser(){
        clsScreen::_DrawScreenHeader("Update User");
        string userName = clsInputValidator::ReadString("Enter User Name");

        while(!clsUser::IsUserExist(userName)){
            cout << "User Not Found !" << endl;
            userName = clsInputValidator::ReadString("Enter User Name Again");
        }
        clsUser User = clsUser::Find(userName);
        _Print(User);

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
            cout << "User have been updated successfuly !" << endl;
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