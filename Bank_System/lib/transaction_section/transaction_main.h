#pragma once
#include "../misc/input_validate_lib.h"
#include "../client_section/client_lib.h"
#include "deposit.h"
#include "withdraw.h"
#include "transfer_balance.h"
#include "transfer_balance_log_list.h"
#include "show_clients_total_balance.h"
#include "../misc/header_title_screen.h"


class clsTransactionMainMenu : protected clsScreen {
    private:
  enum enTransactionMenu {
            eDeposit = 1, eWithDraw = 2, eTotalBalance = 3,
            eTransferBalance = 4,
            eTransferHistory = 5,
            eExitToMainMenu = 6
        };

    
       static short _ReadMainMenueOption()
        {
            cout <<setw(37) << left << ""<< "Choose what do you want to do? [1 to 6]? ";
            short Choice = clsInputValidator::ReadShortNumberBetween("Enter Number between 1 to 6? ", 1,6);
            return Choice;
        }

       static  void _GoBackToTransactionMainMenue()
        {
            cout << setw(37) << left << ""<<"\n\tPress any key to go back to Main Menue...\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.get();
            ShowTransactionMainMenue();
           
        }
       
       static void _Deposit()
       {
        clsDepositBalance::DepositBalance();
       }

       static void _WithDraw()
       {
        clsWithdrawBalance::WithdrawBalance();         
       }

       static void _ShowTotalBalances()
       {
        clsShowTotalClientsBalance::ShowTotalBalances();
       }

       static void _TransferBalance(){
        clsTransferBalance::TransferBalanceBetweenClients();
       }

       static void _TransferBalanceHistory(){
           clsTransferBalanceLogList::ShowTransferBalanceLogList();
       }

       static void _ExitToMainMenue()
       {
       
       }


       static void _PerfromTransactionMainMenueOption(enTransactionMenu MainMenueOption){
            switch (MainMenueOption){
            case enTransactionMenu::eDeposit:
            
                system("clear");
                _Deposit();
                _GoBackToTransactionMainMenue();
                break;
            
            case enTransactionMenu::eWithDraw:
                system("clear");
                _WithDraw();
                _GoBackToTransactionMainMenue();
                break;

            case enTransactionMenu::eTotalBalance:
                system("clear");
                _ShowTotalBalances();
                _GoBackToTransactionMainMenue();
                break;
            case enTransactionMenu::eTransferBalance:
             system("clear");
            _TransferBalance();
            _GoBackToTransactionMainMenue();  

             case enTransactionMenu::eTransferHistory:
             system("clear");
             _TransferBalanceHistory();
             _GoBackToTransactionMainMenue();    

            case enTransactionMenu::eExitToMainMenu:
            {
              
            }

            }
       }

       public:

         
       static void ShowTransactionMainMenue()
        {
           
            system("clear");
            _DrawScreenHeader("Transaction Main Screen");

            cout << setw(37) << left <<""<< "===========================================\n";
            cout << setw(37) << left << "" << "Transactions\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] Deposit.\n";
            cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
            cout << setw(37) << left << "" << "\t[3] Show Clients Total Balance.\n";
            cout << setw(37) << left << "" << "\t[4] Transfer Balance.\n";
            cout << setw(37) << left << "" << "\t[5] Show Transfer History.\n";
            cout << setw(37) << left << "" << "\t[6] Exit To Main Menue.\n";
            cout << setw(37) << left << "" << "===========================================\n";

            _PerfromTransactionMainMenueOption((enTransactionMenu)_ReadMainMenueOption());
        }
            
};