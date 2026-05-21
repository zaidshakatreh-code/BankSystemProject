#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "Screen.h"
#include "InputValidate.h"
#include "ListCurrenciesScreen.h"
#include "FindCurrenciesScreen.h"
#include "UpdateRateScreen.h"
#include "CurrencyCalculatorScreen.h"
class CurrnecyExchangeScreen :protected Screen
{
private:
    enum _eCurrencyMenueOptions
    {
        eListCurrencies = 1,
        eFindCurrencies = 2,
        eUpdateRate = 3,
        eCurrencyCalculator = 4,
        eMainMenue = 5

    };

    static short ReadCurrencyExchangeMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short choose = InputValidate::ReadNumberBetween<short>(1, 5);
        return choose;
    }

    static void _GoBackCurrencyExchangeMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Currencies Menu...\n";

        system("pause>0");
        ShowCurrencyExchangeScreen();

    }

    static void _ShowListCurrencies()
    {
        //cout << "List Currencies Screen will Be Here \n\n";
    
        ListCurrenciesScreen::ShowListCurrenciesScreen();
    }
  
    static void _ShowFindCurrencies()
    {
      //  cout << "Find Currencies Screen will Be Here \n\n";
        FindCurrenciesScreen::ShowFindCurrenciesScreen();
    }
    
    static void _ShowUpdateRate()
    {
     //   cout << "Update Rate Currencies Screen will Be Here \n\n";
    
        UpdateRateScreen::ShowUpdateCurrencyRateScreen();
    }
    
    static void _ShowCurrencyCalculator()
    {
      //  cout << "Currency Calculator Currencies Screen will Be Here \n\n";
        CurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }
    
    static void _PerformCurrencyMenueOption(_eCurrencyMenueOptions CurrencyEnum)
    {
        switch (CurrencyEnum)
        {
        case _eCurrencyMenueOptions::eListCurrencies:
        {
            system("cls");
            _ShowListCurrencies();
            _GoBackCurrencyExchangeMenue();
            break;
        }
        case _eCurrencyMenueOptions::eFindCurrencies:
        {
            system("cls");
            _ShowFindCurrencies();
            _GoBackCurrencyExchangeMenue();
            break;
        }
        case _eCurrencyMenueOptions::eUpdateRate:
        {
            system("cls");
            _ShowUpdateRate();
            _GoBackCurrencyExchangeMenue();
            break;
        }
        case _eCurrencyMenueOptions::eCurrencyCalculator:
        {
            system("cls");
            _ShowCurrencyCalculator();
            _GoBackCurrencyExchangeMenue();
            break;
        }
        case _eCurrencyMenueOptions::eMainMenue:
        {
        }
        }
    }
public:
    static void ShowCurrencyExchangeScreen()
    {
        if (!CheckAccessRights(User::enPermissions::pShowCurrnciesExchange))
        {
            return;// this will exit the function and it will not continue
        }
        system("cls");
        string Title = "\t Currency Exchange Main Screen";
        _DrawScreenHeader(Title);


        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Currency Exchange Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currencies.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformCurrencyMenueOption((_eCurrencyMenueOptions)ReadCurrencyExchangeMenueOption());
    }
   

};

