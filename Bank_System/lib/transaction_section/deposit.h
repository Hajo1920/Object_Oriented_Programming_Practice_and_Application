#include "../client_section/client_lib.h"
#include "../misc/input_validate_lib.h"
#include "../misc/header_title_screen.h"


class clsDepositBalance : protected clsScreen {
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

    static void DepositBalance(){
        clsScreen::_DrawScreenHeader("Deposit Balance");
        string accNum = clsInputValidator::ReadString("Enter Account Number");
        while(!clsBankClient::IsClientExist(accNum)){
            cout <<"Invalid Account Number !" << endl;
            accNum = clsInputValidator::ReadString("Enter Account Again");
        }

        clsBankClient Client = clsBankClient::Find(accNum);

        _Print(Client);

        double amount = 0;
        
        amount  = clsInputValidator::ReadDoubleInput("Please enter amount of balance you want to deposit");

        char confirm = 'n';
        cout << "Are you sure you want to deposit " << amount << " to " << Client.GetFirstName() << ",s balance ? y or n: ";
        cin >> confirm;
        if(confirm == 'y' || confirm == 'Y'){
            Client.Deposit(amount);
            cout << "Updated balance is: " << Client.GetAccountBalance() << endl;
        } else cout << "Deposit Process Unsuccessful !" << endl;
    }
};