#pragma once
#include <iostream>
#include "Screen.h"
#include "Person.h"
#include "BankClient.h"
#include "InputValidate.h"

class UpdateClientScreen :protected Screen

{
private:

    static void _PrintClient(BankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

    static void ReadClientInfo(BankClient& Client)
    {
        cout << "\nEnter FirstName: ";
        Client.FirstName = InputValidate::ReadNumberOrString <string> ();

        cout << "\nEnter LastName: ";
        Client.LastName = InputValidate::ReadNumberOrString <string>();

        cout << "\nEnter Email: ";
        Client.Email = InputValidate::ReadNumberOrString <string>();

        cout << "\nEnter Phone: ";
        Client.Phone = InputValidate::ReadNumberOrString <string>();

        cout << "\nEnter PinCode: ";
        Client.PinCode = InputValidate::ReadNumberOrString <string>();

        cout << "\nEnter Account Balance: ";
        Client.AccountBalance = InputValidate::ReadNumberOrString <float>();
    }

public:

    static void ShowUpdateClientScreen()
    {
        if (!CheckAccessRights(User::enPermissions::pUpdateClients))
        {
            return;// this will exit the function and it will not continue
        }

        _DrawScreenHeader("\tUpdate Client Screen");

        string AccountNumber = "";

        cout << "\nPlease Enter client Account Number: ";
        AccountNumber = InputValidate::ReadNumberOrString <string>();

        while (!BankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = InputValidate::ReadNumberOrString <string>();
        }

        BankClient Client1 = BankClient::Find(AccountNumber);

        _PrintClient(Client1);

        cout << "\nAre you sure you want to update this client y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            cout << "\n\nUpdate Client Info:";
            cout << "\n____________________\n";


            ReadClientInfo(Client1);

            BankClient::enSaveResults SaveResult;

            SaveResult = Client1.Save();

            switch (SaveResult)
            {
            case  BankClient::enSaveResults::svSucceeded:
            {
                cout << "\nAccount Updated Successfully :-)\n";

                _PrintClient(Client1);
                break;
            }
            case BankClient::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError account was not saved because it's Empty";
                break;

            }

            }

        }

    }
};

