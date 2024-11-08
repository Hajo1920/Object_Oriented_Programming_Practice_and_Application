#pragma once
#include "currency_lib.h"
#include "../misc/header_title_screen.h"
#include "../misc/input_validate_lib.h"
#include "../misc/string_lib.h"


class clsUpdateCurrency : protected clsScreen {
private:
     static void _Print(clsCurrency & Currency){
        cout << "\nCurrency Card:";
        cout << "\n___________________";
        cout << "\nCountry Name   : " << Currency.Country();
        cout << "\nCurrency Name   : " << Currency.CurrencyName();
        cout << "\nCurrency Code   : " << Currency.CurrencyCode();
        cout << "\nRate($1)       : " << Currency.Rate();
        cout << "\n___________________";
     }

      static clsCurrency _SearchByCurrencyCode() {
     string currencyCode = clsInputValidator::ReadString("Enter Currency Code");
     while (!clsCurrency::IsCurrencyExist(currencyCode)) {
       cout << "Invalid Currency Code !" << endl;
       currencyCode = clsInputValidator::ReadString("Enter Currency Code Again");
     }
     clsCurrency Currency = clsCurrency::FindByCode(clsString::UpperAllString(currencyCode));
     
     return Currency;
      }

    public:
      static void ShowUpdateCurrency() {
        system("clear");
        clsScreen::DrawScreenHeader("Update Currency Rate");
        clsCurrency Currency = _SearchByCurrencyCode();
        _Print(Currency);
        char confirm = 'n';
        cout << "\n\nAre you sure to update the current rate of " << Currency.CurrencyCode() << " ? (y) or (n)";
        cin >> confirm;
        if (confirm == 'y' || confirm == 'Y') {
          Currency.UpdateRate(
              clsInputValidator::ReadDoubleInput("Enter New Currency Rate"));
          cout << "Updated Successfuly !" << endl;
        }
      }
};
