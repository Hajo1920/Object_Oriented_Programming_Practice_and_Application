#pragma once
#include "currency_lib.h"
#include "../misc/header_title_screen.h"
#include "../misc/input_validate_lib.h"
#include "../misc/string_lib.h"
#include <fstream>
#include <string>


class clsFindCurrency : protected clsScreen {
private:
  enum enCountryNameOrCode { eByCountryName = 1, eByCurrencyCode = 2 };
  
  
   static void _Print(clsCurrency & Currency){
           cout << "\nCurrency Card:";
        cout << "\n___________________";
        cout << "\nCountry Name   : " << Currency.Country();
        cout << "\nCurrency Name   : " << Currency.CurrencyName();
        cout << "\nCurrency Code   : " << Currency.CurrencyCode();
        cout << "\nRate($1)       : " << Currency.Rate();
        cout << "\n___________________";
   }
   
   static void _SearchByCurrencyCode() {
     string currencyCode = clsInputValidator::ReadString("Enter Currency Code");
     while (!clsCurrency::IsCurrencyExist(currencyCode)) {
       cout << "Invalid Currency Code !" << endl;
       currencyCode = clsInputValidator::ReadString("Enter Currency Code Again");
     }
     clsCurrency Currency = clsCurrency::FindByCode(clsString::UpperAllString(currencyCode));
     if (Currency.IsEmpty()) {
       cout << "Empty Currency !" << endl;
     } else {
       cout << "Currency Found !" << endl;
       _Print(Currency);
     }
   }

   static void _SearchByCountryName() {
     string countryName = clsInputValidator::ReadString("Enter Country Name");
  
     clsCurrency Currency = clsCurrency::FindByCountry(clsString::UpperAllString(countryName));
     while (Currency.IsEmpty()) {
       cout << "No Currency Found From Provided Country!" << endl;
       countryName = clsInputValidator::ReadString("Enter Country Name");
       Currency = clsCurrency::FindByCountry(clsString::UpperAllString(countryName));
       if (!Currency.IsEmpty()) {
         break;
       }
     }
     cout << "Country Found !" << endl;
    _Print(Currency);
   }

 public:
   static void ShowFindCurrency() {
     system("clear");
     clsScreen::DrawScreenHeader("Find Currency",
                                 "By Country Name [or] Currency Code");
     cout << "\n";
     short choose = clsInputValidator::ReadShortNumberBetween(
         "Find By: [1]Country Name (or) [2]Currency Code", 1, 2);
     switch ((enCountryNameOrCode)choose) {
     case enCountryNameOrCode::eByCurrencyCode:
       _SearchByCurrencyCode();
       break;

     case enCountryNameOrCode::eByCountryName:
       _SearchByCountryName();
       break;

     default:
     break;  

     }
     
   }
};