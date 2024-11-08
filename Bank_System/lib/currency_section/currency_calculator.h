#pragma once
#include "currency_lib.h"
#include "../misc/header_title_screen.h"
#include "../misc/input_validate_lib.h"
#include "../misc/string_lib.h"


class clsCalculateCurrency : protected clsScreen {
private:
  static void _Print(clsCurrency & Currency){
        cout << "\n\nCurrency Card:";
        cout << "\n___________________";
        cout << "\nCountry Name   : " << Currency.Country();
        cout << "\nCurrency Name   : " << Currency.CurrencyName();
        cout << "\nCurrency Code   : " << Currency.CurrencyCode();
        cout << "\nRate($1)       : " << Currency.Rate();
        cout << "\n___________________\n\n";
  }
  
  static double _GetDolarResult(double amount) {
    clsCurrency usd = clsCurrency::FindByCode("usd");
    return amount / usd.Rate();
  }

   static clsCurrency _SearchByCurrencyCode(string msg) {
     string currencyCode = clsInputValidator::ReadString(msg);
     while (!clsCurrency::IsCurrencyExist(currencyCode)) {
       cout << "Invalid Currency Code !" << endl;
       currencyCode = clsInputValidator::ReadString(msg + " Again");
     }
     clsCurrency Currency = clsCurrency::FindByCode(currencyCode);
     
     return Currency;
   }

   static double DollarCalculation(clsCurrency Currency1, clsCurrency Currency2, double amount) {
     
     return amount / Currency1.Rate();

   }

 public:
   static void ShowCurrencyCalculator() {
     system("clear");
     clsScreen::DrawScreenHeader("Convert and Calculate Currencies");
     clsCurrency Currency1 = _SearchByCurrencyCode("Enter First Country Currency Code");
     clsCurrency Currency2 = _SearchByCurrencyCode("Enter Second Country Currency Code");
     double amount = clsInputValidator::ReadDoubleInput("Enter Amount To Calculate");
     if (Currency2.CurrencyCode() == "USD") {
        cout << "Convert from:" << endl;
       _Print(Currency1);
       cout << "To:" << endl;
       _Print(Currency2);
        cout << "\n\n";
       cout << amount << " " << Currency1.CurrencyCode() << " = " << DollarCalculation(Currency1, Currency2, amount) << " " << Currency2.CurrencyCode();
      
     } else {
       double dollarResult = _GetDolarResult(amount) / Currency1.Rate();
         cout << "Convert from:" << endl;
       _Print(Currency1);
       cout << "To:" << endl;
       _Print(Currency2);
       cout << "\n\n";
        cout << amount << " " << Currency1.CurrencyCode() << " = " << dollarResult * Currency2.Rate() << " " << Currency2.CurrencyCode();
     }
   }

};