#pragma once
#include "../user_section/user_lib.h"
#include "../misc/date_lib.h"
#include "../login/global.h"

class clsSystemAccessLog {

    private:

    static string _ConverUserObjectToLine(string Seperator = "#//#")
    {
        time_t t = time(0);
        tm* now = localtime(&t);

        string hour = to_string(now->tm_hour);
        string min = to_string(now->tm_min);
        string sec = to_string(now->tm_sec);

        string time = hour + ":" + min + ":" + sec;

        string UserRecord = "";
        UserRecord += clsDate::DateToString(clsDate()) + " - " + time + Seperator;
        UserRecord += CurrentUser.GetUserName() + Seperator;
        UserRecord += CurrentUser.GetPassword() + Seperator;
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