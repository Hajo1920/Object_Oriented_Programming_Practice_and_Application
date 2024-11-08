#pragma once
#include <iostream>
#include <string>
#include "../misc/person_lib.h"
#include "../misc/string_lib.h"
#include <vector>
#include <fstream>

using namespace std;

class clsBankClient : public clsPerson
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode=2 };
    enMode _Mode;

    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    bool markForDelete = false;

    static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
    {
        vector<string> vClientData;
        vClientData = clsString::Split(Line, Seperator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
    }

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    static clsBankClient _GetAddNewClientObject(string accountNumber){
        return clsBankClient(enMode::AddNewMode, "", "", "", "", accountNumber , "" , 0);
    }

        static  vector <clsBankClient> _LoadClientsDataFromFile()
    {

        vector <clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsBankClient Client = _ConvertLinetoClientObject(Line);

                vClients.push_back(Client);
            }

            MyFile.close();

        }

        return vClients;

    }
        static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
    {

        string stClientRecord = "";
        stClientRecord += Client.GetFirstName() + Seperator;
        stClientRecord += Client.GetLastName() + Seperator;
        stClientRecord += Client.GetEmail() + Seperator;
        stClientRecord += Client.GetPhone() + Seperator;
        stClientRecord += Client._AccountNumber + Seperator;
        stClientRecord += Client._PinCode + Seperator;
        stClientRecord += to_string(Client._AccountBalance);

        return stClientRecord;
    }

        static void _SaveCleintsDataToFile(vector <clsBankClient> vClients)
    {

        fstream MyFile;
        MyFile.open("Clients.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsBankClient C : vClients)
            {
               if(C.markForDelete == false){
                 DataLine = _ConverClientObjectToLine(C);
                 MyFile << DataLine << endl;
               }

            }

            MyFile.close();

        }

    }

    void _AddNew(){
        _AddNewDataLineToFile(_ConverClientObjectToLine(*this));
    }

    void _AddNewDataLineToFile(string DataLine){
        fstream myFile;

        myFile.open("Clients.txt", ios::out | ios::app);

        if(myFile.is_open()){
            myFile << DataLine << endl;
        }

        myFile.close();
    }
        void _Update()
    {
        vector <clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C = *this;
                break;
            }

        }

        _SaveCleintsDataToFile(_vClients);

    }

public:

    clsBankClient(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string AccountNumber, string PinCode,
        float AccountBalance) :
        clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;

    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    string AccountNumber()
    {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }
  

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }

    static vector<clsBankClient> AllClientsList(){
        return _LoadClientsDataFromFile();
    }

    
   static int GetTotalBalancesAmount(vector<clsBankClient> vClients){
        int TotlaBalance = 0;
        for(clsBankClient &Client: vClients){
            TotlaBalance += Client._AccountBalance;
        }

        return TotlaBalance;
    }

     bool Transfer(int amount, clsBankClient& Receiver){
        if(amount > _AccountBalance){
            cout << "Transfer amount excceded current user balance" << endl;
            return false;
        }

        if(this->_AccountNumber == Receiver.AccountNumber()){
            cout << "Balance transfer to the same client number is not allowed" << endl;
            return false;
        }
        Receiver.Deposit(amount);
        this->WithDraw(amount);
        
        return true;
     }

     void Deposit(double amount){
         _AccountBalance += amount;
          Save();     
    }

    bool WithDraw(double amount){
        if(amount > _AccountBalance){
            return false;
        }else{

        _AccountBalance -= amount;
        Save();
        return true;
        }
        
    }

    static clsBankClient Find(string AccountNumber)
    {

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode
        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }

        return _GetEmptyClientObject();
    }

   

    static clsBankClient Find(string AccountNumber, string PinCode)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber && Client.GetPinCode() == PinCode)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }
        return _GetEmptyClientObject();
    }

       static clsBankClient GetAddNewClientObject(string accountNumber){
        return _GetAddNewClientObject(accountNumber);
    }

    bool Delete(){
        vector<clsBankClient> vClientInfo;

        vClientInfo = _LoadClientsDataFromFile();

        for(clsBankClient& C: vClientInfo){
            if(C.AccountNumber() == _AccountNumber){
                C.markForDelete = true;
                break;
            }
        }

        _SaveCleintsDataToFile(vClientInfo);
        *this = _GetEmptyClientObject();

        return true;
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svAccountNumberExists=2 };

    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
        
                return enSaveResults::svFaildEmptyObject;
        }

        case enMode::UpdateMode:
        {


            _Update();

            return enSaveResults::svSucceeded;

            break;
        }

        case enMode::AddNewMode:
         _AddNew();
        _Mode = enMode::UpdateMode;
        return enSaveResults::svSucceeded;

        }

        return svFaildEmptyObject;

    }

    static bool IsClientExist(string AccountNumber)
    {

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        return (!Client1.IsEmpty());
    }

};