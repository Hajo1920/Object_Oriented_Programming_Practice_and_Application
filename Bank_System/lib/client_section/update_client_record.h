#include "../misc/header_title_screen.h"
#include "../misc/input_validate_lib.h"
#include "client_lib.h"

class clsUpdateClient : protected clsScreen{
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

 static void _ReadUpdateClientInfo(clsBankClient & Client){
    Client.SetFirstName(clsInputValidator::ReadString("Enter First Name"));
    Client.SetLastName(clsInputValidator::ReadString("Enter Last Name"));
    Client.SetEmail(clsInputValidator::ReadString("Enter New Email"));
    Client.SetPhone(clsInputValidator::ReadString("Enter New Phone"));
    Client.SetPinCode(clsInputValidator::ReadString("Enter New PinCode"));
    Client.SetAccountBalance(clsInputValidator::ReadDoubleInput("Enter Account Balance"));
}

public:
static void UpdateClientInfo(){
    clsScreen::_DrawScreenHeader("Update Client Record");
    string accountNumber = "";
    accountNumber = clsInputValidator::ReadString("Enter Client Account Number");
    while(!clsBankClient::IsClientExist(accountNumber)){
        cout << "Invalid account number !" << endl;
        accountNumber = clsInputValidator::ReadString("Please Enter Account Number Again");
    }
    clsBankClient Client = clsBankClient::Find(accountNumber);
    _Print(Client);
    _ReadUpdateClientInfo(Client);

    clsBankClient::enSaveResults SaveResults;

    SaveResults = Client.Save();

    switch (SaveResults) {
    case clsBankClient::enSaveResults::svSucceeded:
    cout << "Client Info Updated Successfuly !" << endl;
    Client.Print();
    break;

    case clsBankClient::enSaveResults::svFaildEmptyObject:
    cout << "Error: Client Information is Empty. Operation Unsuccessful !" << endl;
    break;

    default:
    break;
    }
}
};