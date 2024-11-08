#pragma once
#include "currency_lib.h"
#include "../misc/header_title_screen.h"
#include "../misc/input_validate_lib.h"
#include "currency_list_view.h"
#include "find_currency.h"
#include "currency_update.h"
#include "currency_calculator.h"
class clsCurrencyExchanageMenue : protected clsScreen {

    private:
        enum enCurrenyMenue
        {
            eListCurrency=1, eFindCurrency=2, eUpdateCurrency=3, eCurrencyCalculator=4, eExitMenue=5
        };

        static short _ReadMainMenueOption()
        {
            cout <<setw(37) << left << ""<< "Choose what do you want to do? [1 to 5]? ";
            short Choice = clsInputValidator::ReadShortNumberBetween("Enter Number between 1 to 5? ", 1,5);
            return Choice;
        }

        static void _ShowCurrencyList(){
            clsAllCurrencyList::ShowListOfAllCurrencies();
        }
        static void _ShowFindCurrency(){
            clsFindCurrency::ShowFindCurrency();
        }
        static void _ShowUpdateCurrency(){
            clsUpdateCurrency::ShowUpdateCurrency();
        }
        static void _ShowCurrencyCalculator(){
          clsCalculateCurrency::ShowCurrencyCalculator();
        }

        static void _BackToCurrencyManiMenue(){
            cout << setw(37) << left << ""<<"\n\tPress any key to go back to Previous Menue...\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.get();
            ShowMainMenue();
        }
        
    public:

    static void _PerfromMainMenueOption(enCurrenyMenue CurrencyMenue){
        
        
        switch (CurrencyMenue)
        {
        case enCurrenyMenue::eListCurrency:
            _ShowCurrencyList();
            _BackToCurrencyManiMenue();
            break;

         case enCurrenyMenue::eFindCurrency:
            _ShowFindCurrency();
            _BackToCurrencyManiMenue();
            break;

         case enCurrenyMenue::eUpdateCurrency:
            _ShowUpdateCurrency();
            _BackToCurrencyManiMenue();
            break;

         case enCurrenyMenue::eCurrencyCalculator:
            _ShowCurrencyCalculator();
            _BackToCurrencyManiMenue();
            break;

         case enCurrenyMenue::eExitMenue:
           {

           }
        
        default:
            break;
        }
    }

    static void ShowMainMenue(){
         system("clear");
            _DrawScreenHeader("\tCurrency Exchange");

            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
            cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
            cout << setw(37) << left << "" << "\t[3] Update Currency Rate.\n";
            cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
            cout << setw(37) << left << "" << "\t[5] Exit Menue.\n";

            _PerfromMainMenueOption((enCurrenyMenue)_ReadMainMenueOption());
    }

};