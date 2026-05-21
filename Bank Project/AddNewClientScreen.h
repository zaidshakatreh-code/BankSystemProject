#pragma once

#include <iostream>
#include "Screen.h"
#include "BankClient.h"
#include "InputValidate.h"
#include <iomanip>

class AddNewClientScreen : protected Screen
{
private:
    static void _ReadClientInfo(BankClient& Client)
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
        Client.AccountBalance = InputValidate::ReadNumberOrString<float>();
    }

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

public:

    static void ShowAddNewClientScreen()
    {
        if (!CheckAccessRights(User::enPermissions::pAddNewClient))
        {
            return;// this will exit the function and it will not continue
        }


        _DrawScreenHeader("\t  Add New Client Screen");

        string AccountNumber = "";

        cout << "\nPlease Enter Account Number: ";
        AccountNumber = InputValidate::ReadNumberOrString <string>();
        while (BankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number Is Already Used, Choose another one: ";
            AccountNumber = InputValidate::ReadNumberOrString<string>();
        }

        BankClient NewClient = BankClient::GetAddNewClientObject(AccountNumber);


        _ReadClientInfo(NewClient);

        BankClient::enSaveResults SaveResult;

        SaveResult = NewClient.Save();

        switch (SaveResult)
        {
        case  BankClient::enSaveResults::svSucceeded:
        {
            cout << "\nAccount Addeded Successfully :-)\n";
            _PrintClient(NewClient);
            break;
        }
        case BankClient::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError account was not saved because it's Empty";
            break;

        }
        case BankClient::enSaveResults::svFaildAccountNumberExists:
        {
            cout << "\nError account was not saved because account number is used!\n";
            break;

        }
        }
    }



};

