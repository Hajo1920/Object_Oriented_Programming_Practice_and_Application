#include "../client_section/client_lib.h"
#include "../misc/header_title_screen.h"
#include <iomanip>

class clsShowTotalClientsBalance : protected clsScreen {

    private:

    static void _ShowTitle(vector <clsBankClient> vClients){
           
    cout <<"\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "| " << left << setw(12) << "Accout Number";
    cout << "| " << left << setw(30) << "Client Name";
    cout << "| " << left << setw(12) << "Balance";
    cout <<"\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    }

    static void _PrintClientRecordBalanceLine(clsBankClient Client){
    cout << "| " << left << setw(12) << Client.AccountNumber();      
    cout << "| " << left << setw(30) << Client.FullName();  
    cout << "| " << left << setw(12) << Client.GetAccountBalance();
    
}

    public:

static void ShowTotalBalances(){
   
    vector <clsBankClient> vClients = clsBankClient::AllClientsList();
    clsScreen::_DrawScreenHeader("Clients Total Balance", "Balances List Of ("  + to_string(vClients.size()) + ")Client(s).");
    if (vClients.size() == 0){
        cout << "Client Table is Empty !" << endl;
    } else {
        _ShowTitle(vClients);
        for (clsBankClient& Client : vClients){
            _PrintClientRecordBalanceLine(Client);
            cout << "\n";
        }
    }
    cout <<"\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
 
    cout << "\n";
    cout << setw(30) << right << "Total Clients Balance: " << clsBankClient::GetTotalBalancesAmount(vClients) << endl;
    cout << setw(10) << right << "(" << clsUtilities::ConvertNumberToText(clsBankClient::GetTotalBalancesAmount(vClients)) << ")";
    cout << "\n\n";
}

};
