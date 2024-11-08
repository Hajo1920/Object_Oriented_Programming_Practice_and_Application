#include "client_lib.h"
#include "../misc/header_title_screen.h"
#include "../misc/utility_lib.h"
#include <iomanip>

class clsShowClientList : protected clsScreen{

    private: 

   static void _TableTitle(){
    
    cout << "\n";

    clsScreen::_DrawScreenHeader("Show Client List", "(" +  to_string(clsBankClient::AllClientsList().size()) + ") Client(s)");
  
}

static void _TitlesHeader(){
   cout << "\n______________________________________________________________________________";     
   cout << "_________________________________________\n" << endl;     
   cout << "| " << left << setw(12) << "Accout Number";     
   cout << "| " << left << setw(12) << "Pin Code";     
   cout << "| " << left << setw(30) << "Client Name";   
   cout << "| " << left << setw(30) << "Email";       
   cout << "| " << left << setw(12) << "Phone";     
   cout << "| " << left << setw(12) << "Balance";     
   cout << "\n______________________________________________________________________________";     
   cout << "_________________________________________\n" << endl;
}

static void _PrintClientLine(clsBankClient Client){
    cout << "| " << left << setw(12) << Client.AccountNumber();     
    cout << "| " << left << setw(12) << Client.GetPinCode();  
    cout << "| " << left << setw(30) << Client.FullName();  
    cout << "| " << left << setw(30) << Client.GetEmail();     
    cout << "| " << left << setw(12) << Client.GetPhone();
    cout << "| " << left << setw(12) << Client.GetAccountBalance();
    
}

public:

static void ShowAllClientsList(){
    vector<clsBankClient> vClientsList = clsBankClient::AllClientsList();
    _TableTitle();
    _TitlesHeader();
     if(vClientsList.size() == 0){
            cout << setw(40) << right << "Users List Empty !" << endl;
    } else  {
    for(clsBankClient& Clients: vClientsList){
    _PrintClientLine(Clients);
    cout << "\n";
    }
    }
  
   cout << "\n______________________________________________________________________________";     
   cout << "_________________________________________\n" << endl;

}
};