#pragma once
#include "../misc/header_title_screen.h"
#include "../misc/input_validate_lib.h"
#include "../misc/utility_lib.h"
#include "../user_section/user_lib.h"
#include "../main/main_screen.h"
#include "../access_log/system_access_log_saver.h"
#include "../access_log/system_access_log_list.h"

#include "global.h"

class clsLogIn : protected clsScreen{
    private:

    static void _LogIn(){
        
        bool LoginFail = false;
        short trial = 3;
        string userName = "", password = "";
        do {
        system("clear");
        clsScreen::DrawScreenHeader("Login Screen", "Credential Required !");
        if(LoginFail){
            cout << "Wrong Username or  Password !" << endl;
            trial--;
            cout << "\n"
            << "You have only " << trial << " chance(s) left" << endl;
        }
        if(trial == 0){
            system("clear");
            cout << "System Locked !" << endl;
            exit(0);
        }
        userName = clsInputValidator::ReadString("Enter User Name");
        password = clsInputValidator::ReadString("Enter Password");
        CurrentUser = clsUser::Find(userName, password);
        if(CurrentUser.IsEmpty()){
            LoginFail = true;
        }else{
            LoginFail = false;
        }
        }while (LoginFail);
        clsSystemAccessLog::SystemAccessLog();
        clsMainScreen::ShowMainMenue();
    }

    public:

    static void ShowLogInScreen(){
        _LogIn();
    }

};