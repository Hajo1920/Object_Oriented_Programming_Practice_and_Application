#pragma once
#include "currency_lib.h"
#include "../misc/header_title_screen.h"
#include <fstream>
#include <string>


class clsAllCurrencyList : protected clsScreen {

    private:

    static void _ShowTitle(){
           
    cout <<"\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "| " << left << setw(30) << "Country Name";
    cout << "| " << left << setw(15) << "Currency Code";
    cout << "| " << left << setw(30) << "Currency Name";
    cout << "| " << left << setw(15) << "Rate(1$)";
    cout <<"\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
          }

        static void _Print(clsCurrency Data){
        cout << "| " << left << setw(30) << Data.Country();
        cout << "| " << left << setw(15) << Data.CurrencyCode();
        cout << "| " << left << setw(30) << Data.CurrencyName();
        cout << "| " << left << setw(15) << Data.Rate();
        }

        

  public:
    static void ShowListOfAllCurrencies() {
      vector<clsCurrency> vCurrencyItems = clsCurrency::GetCurrenciesList();
      clsScreen::DrawScreenHeader(
          "List Of All Country Currencies",
          "Total of " + to_string(vCurrencyItems.size()) + " currencies");
      _ShowTitle();

      if (vCurrencyItems.size() == 0) {
        cout << "Currency list is empty. No data available" << endl;
      } else {
      for (clsCurrency &CI : vCurrencyItems) {
        _Print(CI);
        cout << '\n';
        cout <<"_______________________________________________________";
        cout << "_________________________________________\n";
      }
      }
    }
          
  
};