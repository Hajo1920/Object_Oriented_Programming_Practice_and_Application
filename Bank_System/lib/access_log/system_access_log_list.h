#pragma once
#include "../user_section/user_lib.h"
#include "../misc/date_lib.h"
#include "../misc/utility_lib.h"
#include "../misc/header_title_screen.h"
#include "../login/global.h"

class clsSystemAccessLogList : protected clsScreen{

    private:
        struct stUserData {
        string date_and_time;
        string user;
        string password;
        int permission;
    };

    static void _ShowTitle(){
           
    cout <<"\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "| " << left << setw(30) << "Date and Time";
    cout << "| " << left << setw(15) << "User Name";
    cout << "| " << left << setw(15) << "Password";
    cout << "| " << left << setw(15) << "Permission";
    cout <<"\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    }

    static void _Print(stUserData Data){
        cout << "| " << left << setw(30) << Data.date_and_time;
        cout << "| " << left << setw(15) << Data.user;
        cout << "| " << left << setw(15) << clsUtilities::DecryptText(Data.password, 7);
        cout << "| " << left << setw(15) << Data.permission;
    }



    static stUserData _ConvertAndSplitLinetoVectorElements(string Line, string Seperator = "#//#")
    {
        vector<string> vLine;
        stUserData Data;
        vLine = clsString::Split(Line, Seperator);

        Data.date_and_time = vLine[0];
        Data.user = vLine[1];
        Data.password = vLine[2];
        Data.permission = stoi(vLine[3]);

        return Data;
    }

    static vector<stUserData> _LoadDataFromFile(){
        fstream File;
        stUserData Data;
        vector<stUserData> vUserData;

        File.open("UsersAccessLog.txt", ios::in);

        if(File.is_open()){
            string Line;
            while(getline(File, Line)){
                Data = _ConvertAndSplitLinetoVectorElements(Line);
                vUserData.push_back(Data);
            }

        }

        return vUserData;
    }

    public:
    static void ShowSystemAcessLogData(){
        
        vector<stUserData> vUserData = _LoadDataFromFile();
        clsScreen::DrawScreenHeader("System Access Log", "Total System Access Times (" + to_string(vUserData.size()) + ")");

        _ShowTitle();

        for(stUserData & U: vUserData){
            _Print(U);
            cout << "\n";
        }
    }
};