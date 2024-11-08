#pragma once
#include "../user_section/user_lib.h"
#include "../misc/date_lib.h"
#include "../misc/utility_lib.h"
#include "../login/global.h"


class clsSystemAccessLog {

    private:

    static string _ConverUserObjectToLine(string Seperator = "#//#")
    {
       

        string UserRecord = "";
        UserRecord += clsDate::GateSystemDateAndTime() + Seperator;
        UserRecord += CurrentUser.GetUserName() + Seperator;
        UserRecord += clsUtilities::EncryptText(CurrentUser.GetPassword(), 7) + Seperator;
        UserRecord += to_string(CurrentUser.GetPermissions());
        return UserRecord;

    }
    static void _SaveAccessLogToFile()
    {

        fstream MyFile;
        MyFile.open("UsersAccessLog.txt", ios::out | ios::app);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {
          DataLine = _ConverUserObjectToLine();
          MyFile << DataLine << endl;

            MyFile.close();

        }

    }

    public:

    static void SystemAccessLog(){
        _SaveAccessLogToFile();
    }
};