#include "../misc/input_validate_lib.h"
#include "../misc/header_title_screen.h"
#include "user_lib.h"

class clsDeleteUser : protected clsScreen {
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
    static void DeleteUser(){
        clsScreen::_DrawScreenHeader("Delete User");
        string userName = clsInputValidator::ReadString("Enter User Name");
    while(!clsUser::IsUserExist(userName)){
        cout << "No User Found !" << endl;
        userName = clsInputValidator::ReadString("Enter User Name Again");
    }
    clsUser User = clsUser::Find(userName);
    if(User.GetPermissions() == -1){
        cout << "This user is Admin! you can't delete this user !" << endl;
    } else {
     _Print(User);

    char confirm = 'n';

    cout << "Are you sure you want to delete this user record ? : ";
    cin >> confirm;

    if(confirm == 'y' || confirm == 'Y'){
        if(User.Delete()){
            cout << "User Deleted Successfuly" << endl;
            _Print(User);
        } else cout << "Operation Unsuccessful." << endl;
    }
    }
    }
};