#pragma once
#include "../misc/input_validate_lib.h"
#include "../client_section/client_lib.h"
#include "../misc/header_title_screen.h"
#include "transfer_balance_log_saver.h"


class clsTransferBalance : protected clsScreen{
    private:

    static void _Print(clsBankClient& Client){
        cout << "\nClient Info:";
        cout << "\n___________________";
        cout << "\nFull Name         : " << Client.FullName();
         cout << "\nAccount Number   : " << Client.AccountNumber();
        cout << "\nLastName          : " << Client.GetAccountBalance();
        cout << "\n___________________\n";
}
        
    public:
      static void TransferBalanceBetweenClients() {
        clsScreen::DrawScreenHeader("Transfer Balance");
    string accountNum = clsInputValidator::ReadString("Enter account number you want to send from");

        while(!clsBankClient::IsClientExist(accountNum)){
            cout << "Invalid client number !" << endl;
            accountNum = clsInputValidator::ReadString("Enter account number you want to send from");

        }
        clsBankClient Sender = clsBankClient::Find(accountNum);
        _Print(Sender);

        accountNum = clsInputValidator::ReadString("Enter account number you want to send to");
         while(!clsBankClient::IsClientExist(accountNum)){
            cout << "Invalid client number !" << endl;
            accountNum = clsInputValidator::ReadString("Enter account number you want to send to");
         }
         clsBankClient Receiver = clsBankClient::Find(accountNum);
         _Print(Receiver);

         int transferAmount = clsInputValidator::ReadIntInput("Enter transfer amount");

         char confirm = 'n';
         cout << "Are you sure to transfer " << transferAmount << " from " << Sender.FullName() << ",s balance to " << Receiver.FullName() << " balance ? (y or n) ";
         cin >> confirm;

         if(confirm == 'y' || confirm == 'Y'){
             if(Sender.Transfer(transferAmount, Receiver)){
                 clsTransferBalanceLogSaver::SaveBalanceTransferLogToFile(Sender.FullName(), Receiver.FullName(), transferAmount, Sender.GetAccountBalance(), Receiver.GetAccountBalance());
                 cout << "Transfer Operation Successful !" << endl;
                 _Print(Sender);
                 cout << "\n";
                 _Print(Receiver);
             } else {
                 cout << "Transfer Operation Unsuccessful" << endl;
             }
         }
    }
};
