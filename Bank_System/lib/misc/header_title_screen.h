#pragma once
#include <iostream>
#include "utility_lib.h"
#include "date_lib.h"
#include "../user_section/user_lib.h"
#include "../login/global.h"
using namespace std;

class clsScreen
{
protected :

    static void ShowDateAndUser(){
        
        cout << clsUtilities::Tab(6) << "User: " << CurrentUser.GetUserName() << endl;
        cout << clsUtilities::Tab(6)  << "Date: " << clsDate::DateToString(clsDate()) << endl;
    }
    static void _DrawScreenHeader(string Title,string SubTitle ="")
    {
        cout << "\n"<< clsUtilities::Tab(5) << "______________________________________\n";
        cout << "\n" << clsUtilities::Tab(6) << Title;
        if (SubTitle != "")
        {
            cout << "\n" << clsUtilities::Tab(6)  << SubTitle;
        }
        cout << "\n" << clsUtilities::Tab(5) << "______________________________________\n";
        cout << "\n";
        ShowDateAndUser();
    }

    static bool CheckUserAccess(clsUser::enPermissionList Permission){
         system("clear");
        if(!CurrentUser.CheckPermissions(Permission)){
           
            cout << "\n------------------------------------------------------------------------\n";
            cout << clsUtilities::Tab(5) << "Access Denied !" << "\n";
            cout << clsUtilities::Tab(3) << "This user is not allowed to access this section" << "\n";
            cout << clsUtilities::Tab(5) << "Contact Admin" << "\n";
            cout << "\n------------------------------------------------------------------------\n";
         
            return false;
        }
        return true;
    }

 public:
 static void DrawScreenHeader(string title, string subtitle=""){
    _DrawScreenHeader(title, subtitle);
 }
};

