#pragma once
#include <iostream>
#include "../misc/header_title_screen.h"
#include "../misc/input_validate_lib.h"
#include "../client_section/show_client_list.h"
#include "../client_section/add_new_client.h"
#include "../client_section/delete_client.h"
#include "../client_section/update_client_record.h"
#include "../client_section/find_client.h"
#include "../transaction_section/transaction_main.h"
#include "../user_section/manage_users_screen.h"
#include "../currency_section/currency_exchange_menu.h"
#include "../login/global.h"
#include "../access_log/system_access_log_list.h"
#include <iomanip>

using namespace std;

class clsMainScreen:protected  clsScreen{

    private:
        enum enMainMenueOptions {
            eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
            eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
            eManageUsers = 7, eSystemAccessLog = 8, eCurrencyExchange = 9,  eExit = 10
        };

       static short _ReadMainMenueOption()
        {
            cout <<setw(37) << left << ""<< "Choose what do you want to do? [1 to 10]? ";
            short Choice = clsInputValidator::ReadShortNumberBetween("Enter Number between 1 to 10? ", 1,10);
            return Choice;
        }

       static  void _GoBackToMainMenue()
        {
            cout << setw(37) << left << ""<<"\n\tPress any key to go back to Main Menue...\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.get();
            ShowMainMenue();
        }

    
       static void _ShowAllClientsScreen()
       {
        if(!CheckUserAccess(clsUser::allowShowClientList)){
            return;
        }
        clsShowClientList::ShowAllClientsList();

       }

       static void _ShowAddNewClientsScreen()
       {
        if(!CheckUserAccess(clsUser::allowAddNewClient)){
            return;
        }
        clsAddNewClient::AddNewClient();
         
       }

       static void _ShowDeleteClientScreen()
       {
        if(!CheckUserAccess(clsUser::allowDeleteClient)){
            return;
        }
        clsDeleteClientRecord::DeleteClient();

       }

       static void _ShowUpdateClientScreen()
       {
        if(!CheckUserAccess(clsUser::allowUpdateClient)){
            return;
        }
        clsUpdateClient::UpdateClientInfo();

       }

       static void _ShowFindClientScreen()
       {
        if(!CheckUserAccess(clsUser::allowFindClient)){
            return;
        }
        clsFindClient::FindClient();

       }

       static void _ShowTransactionsMenue()
       {
        if(!CheckUserAccess(clsUser::allowTransactionAccess)){
            return;
        }
        clsTransactionMainMenu::ShowTransactionMainMenue();

       }


       static void _ShowManageUsersMenue()
       {
        if(!CheckUserAccess(clsUser::allowManageUsersAccess)){
            return;
        }
           clsManageUsersScreen::ShowManageUsersMenue();

       }

       static void _ShowSystemAccessLog(){
        if(!CheckUserAccess(clsUser::allowSystemAccessLogAccess)){
            return;
        }
           clsSystemAccessLogList::ShowSystemAcessLogData();
       }

        static void _ShowCurrencyExchangeMenue(){
        if(!CheckUserAccess(clsUser::allowCurrencyExchangeAccess)){
            return;
        }
        clsCurrencyExchanageMenue::ShowMainMenue();
       }

       static void _Logout(){
        CurrentUser = clsUser::Find("","");
       }

       static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
        {
            switch (MainMenueOption)
            {
            case enMainMenueOptions::eListClients:
            {
                system("clear");
                _ShowAllClientsScreen();
                _GoBackToMainMenue();
                break;
            }
            case enMainMenueOptions::eAddNewClient:
                system("clear");
                _ShowAddNewClientsScreen();
                _GoBackToMainMenue();
                break;

            case enMainMenueOptions::eDeleteClient:
                system("clear");
                _ShowDeleteClientScreen();
                _GoBackToMainMenue();
                break;

            case enMainMenueOptions::eUpdateClient:
                system("clear");
                _ShowUpdateClientScreen();
                _GoBackToMainMenue();
                break;

            case enMainMenueOptions::eFindClient:
                system("clear");
                 _ShowFindClientScreen();
                 _GoBackToMainMenue();     
                break;

            case enMainMenueOptions::eShowTransactionsMenue:
                system("clear");
                _ShowTransactionsMenue();
                _GoBackToMainMenue();
                break;

            case enMainMenueOptions::eManageUsers:
                system("clear");
                _ShowManageUsersMenue();
                _GoBackToMainMenue();
                break;

            case enMainMenueOptions::eSystemAccessLog:
            _ShowSystemAccessLog();
            _GoBackToMainMenue();
            break; 

            case enMainMenueOptions::eCurrencyExchange:
            _ShowCurrencyExchangeMenue();
            _GoBackToMainMenue();
            break;    

            case enMainMenueOptions::eExit:
              {
              _Logout();
              }
            }

        }

	public:


       static void ShowMainMenue()
        {
           
            system("clear");
            _DrawScreenHeader("\tMain Screen");

            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] Show Clients List.\n";
            cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
            cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
            cout << setw(37) << left << "" << "\t[4] Update Client.\n";
            cout << setw(37) << left << "" << "\t[5] Find Client.\n";
            cout << setw(37) << left << "" << "\t[6] Transactions.\n";
            cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
            cout << setw(37) << left << "" << "\t[8] System Access Logs.\n";
            cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
            cout << setw(37) << left << "" << "\t[10] Logout.\n";
            cout << setw(37) << left << "" << "===========================================\n";

            _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
        }

};

