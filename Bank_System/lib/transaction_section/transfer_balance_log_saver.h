#pragma once
#include "transfer_balance.h"
#include "../login/global.h"


class clsTransferBalanceLogSaver {

    private:

    static string _ConverTransferDataToLine(string senderClient, string recevierClient, int transferAmount, int senderBalance, int receiverBalance ,string Seperator = "#//#")
    {
    
        string UserRecord = "";
        UserRecord += clsDate::GateSystemDateAndTime() + Seperator;
        UserRecord += senderClient + Seperator;
        UserRecord += recevierClient + Seperator;
        UserRecord += to_string(transferAmount) + Seperator;
        UserRecord += to_string(senderBalance) + Seperator;
        UserRecord += to_string(receiverBalance) + Seperator;
        UserRecord += CurrentUser.GetUserName();

        return UserRecord;

    }
    static void _SaveTransferLogToFile(string senderClient, string recevierClient, int transferAmount, int senderBalance, int receiverBalance )
    {

        fstream MyFile;
        MyFile.open("BalanceTransferLog.txt", ios::out | ios::app);

        string DataLine;

        if (MyFile.is_open())
        {
          DataLine = _ConverTransferDataToLine(senderClient, recevierClient, transferAmount, senderBalance, receiverBalance);
          MyFile << DataLine << endl;

            MyFile.close();

        }

    }


    public:

    static void SaveBalanceTransferLogToFile(string senderClient, string recevierClient, int transferAmount, int senderBalance, int receiverBalance){
        _SaveTransferLogToFile(senderClient, recevierClient, transferAmount, senderBalance, receiverBalance);
    }
};
