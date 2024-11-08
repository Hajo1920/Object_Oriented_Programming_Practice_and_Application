#include "client_lib.h"
#include "../misc/header_title_screen.h"
#include "../misc/input_validate_lib.h"

class clsDeleteClientRecord : protected clsScreen{

    private:
    static void _Print(clsBankClient & Client){
           cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.GetFirstName();
        cout << "\nLastName    : " << Client.GetLastName();
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.GetEmail();
        cout << "\nPhone       : " << Client.GetPhone();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.GetPinCode();
        cout << "\nBalance     : " << Client.GetAccountBalance();
        cout << "\n___________________\n";
}

    public:
    static void DeleteClient(){
    clsScreen::_DrawScreenHeader("Delete Client Record");
    string accNum = clsInputValidator::ReadString("Enter Account Number");
    while(!clsBankClient::IsClientExist(accNum)){
        cout << "Invalid Account Number !" << endl;
        accNum = clsInputValidator::ReadString("Enter Account Number Again");
    }
    
    clsBankClient Client = clsBankClient::Find(accNum);
    _Print(Client);

    char confirm = 'n';

    cout << "Are you sure you want to delete this client record ? : ";
    cin >> confirm;

    if(confirm == 'y' || confirm == 'Y'){
        if(Client.Delete()){
            cout << "Client Deleted Successfuly" << endl;
           _Print(Client);
        } else cout << "Operation Unsuccessful." << endl;
    }
}
};