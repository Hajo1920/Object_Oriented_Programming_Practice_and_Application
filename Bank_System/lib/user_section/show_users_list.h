#include "user_lib.h"
#include "../misc/header_title_screen.h"
#include "../misc/utility_lib.h"
#include <iomanip>

class clsShowUsersList : protected clsScreen{

    private: 

   static void _TableTitle(){
    
    cout << "\n";

    clsScreen::_DrawScreenHeader("Show Users List", "(" +  to_string(clsUser::GetUsersList().size()) + ") User(s)");
  
}

static void _TitlesHeader(){
   cout << "\n______________________________________________________________________________";     
   cout << "_________________________________________\n" << endl;     
   cout << "| " << left << setw(30) << "Real Name";     
   cout << "| " << left << setw(30) << "Email";     
   cout << "| " << left << setw(12) << "Phone";   
   cout << "| " << left << setw(12) << "User Name";       
   cout << "| " << left << setw(12) << "Password";     
   cout << "| " << left << setw(12) << "Permission";     
   cout << "\n______________________________________________________________________________";     
   cout << "_________________________________________\n" << endl;
}

static void _PrintUserLine(clsUser& User){
    cout << "| " << left << setw(30) << User.FullName();     
    cout << "| " << left << setw(30) << User.GetEmail();  
    cout << "| " << left << setw(12) << User.GetPhone();  
    cout << "| " << left << setw(12) << User.GetUserName();     
    cout << "| " << left << setw(12) << User.GetPassword();
    cout << "| " << left << setw(12) << User.GetPermissions();
    
}

public:

static void ShowAllUsersList(){
    vector<clsUser> vUsersList = clsUser::GetUsersList();
    _TableTitle();
    _TitlesHeader();
     if(vUsersList.size() == 0){
            cout << setw(40) << right << "Users List Empty !" << endl;
    } else  {

    for(clsUser& User: vUsersList){
       
    _PrintUserLine(User);
    cout << "\n";
    }
    }
  
   cout << "\n______________________________________________________________________________";     
   cout << "_________________________________________\n" << endl;

}
};