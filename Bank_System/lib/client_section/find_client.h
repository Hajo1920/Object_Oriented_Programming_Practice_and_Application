#pragma once
#include "client_lib.h"
#include "../misc/input_validate_lib.h"
#include "../misc/header_title_screen.h"


class clsFindClient : protected clsScreen{
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

    static void FindClient(){
        clsScreen::_DrawScreenHeader("Find Client Record");
        string accountNumber = clsInputValidator::ReadString("Enter Account Number");
    while(!clsBankClient::IsClientExist(accountNumber)){
        cout << "This Account Number is Unavailabe !" << endl;
        accountNumber = clsInputValidator::ReadString("Enter Account Number");
    }

    clsBankClient Client = clsBankClient::Find(accountNumber);
    cout << "Client Found" << endl;
    _Print(Client);

    }
};