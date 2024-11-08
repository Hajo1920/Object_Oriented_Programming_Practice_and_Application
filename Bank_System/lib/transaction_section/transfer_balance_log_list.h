#pragma once
#include "../misc/input_validate_lib.h"
#include "../misc/header_title_screen.h"

class clsTransferBalanceLogList : protected clsScreen {
    private:

    struct stTransferData
    {
        string date_and_time;
        string sender_name;
        string recevier_name;
        double transferAmount;
        double sender_balance;
        double recevier_balance;
        string user;
    };
    
    static void _ShowTitle(){
           
    cout <<"\n______________________________________________________________";
    cout << "_______________________________________________________________________\n" << endl;
    cout << "| " << left << setw(20) << "Date/Time";
    cout << "| " << left << setw(20) << "From Client";
    cout << "| " << left << setw(20) << "To Client";
    cout << "| " << left << setw(15) << "Transfer Amount";
    cout << "| " << left << setw(15) << "Sender Balance";
    cout << "| " << left << setw(15) << "Recevier Balance";
    cout << "| " << left << setw(15) << "Done By User";
    cout <<"\n______________________________________________________________";
    cout << "_______________________________________________________________________\n" << endl;

    }

     static void _Print(stTransferData Data){
        cout << "| " << left << setw(20) << Data.date_and_time;
        cout << "| " << left << setw(20) << Data.sender_name;
        cout << "| " << left << setw(20) << Data.recevier_name;
        cout << "| " << left << setw(15) << Data.transferAmount;
        cout << "| " << left << setw(15) << Data.sender_balance;
        cout << "| " << left << setw(15) << Data.recevier_balance;
        cout << "| " << left << setw(15) << Data.user;
    }

     static stTransferData _ConvertAndSplitLinetoVectorElements(string Line, string Seperator = "#//#")
    {
        vector<string> vLine;
        stTransferData Data;
        vLine = clsString::Split(Line, Seperator);

        Data.date_and_time = vLine[0];
        Data.sender_name = vLine[1];
        Data.recevier_name = vLine[2];
        Data.transferAmount = stod(vLine[3]);
        Data.sender_balance = stod(vLine[4]);
        Data.recevier_balance = stod(vLine[5]);
        Data.user = vLine[6];

        return Data;
    }

   static struct vector<stTransferData> _LoadDataFromFile(){
        fstream File;
        vector<stTransferData> vTransferData;
        stTransferData Data;

        File.open("BalanceTransferLog.txt", ios::in);

        if(File.is_open()){
            string Line;

            while(getline(File, Line)){
                Data = _ConvertAndSplitLinetoVectorElements(Line);
                vTransferData.push_back(Data);
            }
        }
        return vTransferData;
    }

    public:

    static void ShowTransferBalanceLogList(){
        
        vector<stTransferData> vTransferData = _LoadDataFromFile();
        clsScreen::DrawScreenHeader("Clients Balance Transfer History", "Total Transfer Operations (" + to_string(vTransferData.size()) + ")");
        _ShowTitle();
        for(stTransferData& Data: vTransferData){
            _Print(Data);
            cout << "\n";
        }
    }


};