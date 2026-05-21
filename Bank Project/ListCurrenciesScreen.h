#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include "Screen.h"
#include "InputValidate.h"
#include "Currency.h"

class ListCurrenciesScreen :protected Screen
{
private:
	static void _PrintData(Currency Currency)
	{
		cout << setw(8) << left << "" << "| " << left << setw(30) << Currency.Country();
		cout << "| " << left << setw(8) << Currency.CurrencyCode();
		cout << "| " << left << setw(45) << Currency.CurrencyName();
		cout << "| " << left << setw(10) << Currency.Rate();

	}
public:
	static void ShowListCurrenciesScreen()
	{
		vector <Currency> vCurrency = Currency::GetCurrenciesList();
		string Title = "\t Currencies List Screen";
		string SubTitle = "\t  ("+to_string(vCurrency.size()) + ") Currency.";
		_DrawScreenHeader(Title, SubTitle);
	
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
		cout << "| " << left << setw(8) << "Code";
		cout << "| " << left << setw(45) << "Name";
		cout << "| " << left << setw(10) << "Rate/(1$)";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;

		if (vCurrency.size()==0)
		{

			cout << "\t\t\t\tNo Currencies Available In the System!";
		}
		else
		{
			for (Currency C : vCurrency)
			{
				_PrintData(C);
				cout << endl;
			}
		}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;
	}
};

