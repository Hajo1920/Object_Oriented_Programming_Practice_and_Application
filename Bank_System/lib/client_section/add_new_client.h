#include "client_lib.h"
#include "../misc/header_title_screen.h"
#include "../misc/input_validate_lib.h"

class clsAddNewClient : protected clsScreen {

    private:

static void _ReadNewClientInfo(clsBankClient & Client){
    Client.SetFirstName(clsInputValidator::ReadString("Enter First Name"));
    Client.SetLastName(clsInputValidator::ReadString("Enter Last Name"));
    Client.SetEmail(clsInputValidator::ReadString("Enter New Email"));
    Client.SetPhone(clsInputValidator::ReadString("Enter New Phone"));
    Client.SetPinCode(clsInputValidator::ReadString("Enter New PinCode"));
    Client.SetAccountBalance(clsInputValidator::ReadDoubleInput("Enter Account Balance"));
}

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

static void AddNewClient(){
    clsScreen::_DrawScreenHeader("Add New Client");
     string accountNumber = clsInputValidator::ReadString("Enter New Account Number");
    while(clsBankClient::IsClientExist(accountNumber)){
        cout << "This Account Number is Unavailabe !" << endl;
        accountNumber = clsInputValidator::ReadString("Enter New Account Number");
    }

    clsBankClient NewClient = clsBankClient::GetAddNewClientObject(accountNumber);

    _ReadNewClientInfo(NewClient);

    clsBankClient::enSaveResults SaveResults;
    SaveResults = NewClient.Save();

    switch (SaveResults) {
        case clsBankClient::enSaveResults::svSucceeded:
        cout << "New Client Added Successfuly !" << endl;
       _Print(NewClient);
        break;

        case clsBankClient::enSaveResults::svAccountNumberExists:
        cout << "The account number you entred is in use, operation unsuccessful" << endl;
        break;

        case clsBankClient::enSaveResults::svFaildEmptyObject:
        cout << "Error: Client Information is empty! operation unsuccessful" << endl;
    }
}
};