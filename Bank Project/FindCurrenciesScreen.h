#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include "Screen.h"
#include "InputValidate.h"
#include "Currency.h"

class FindCurrenciesScreen:protected Screen
{
private:
	static void _PrintCard(Currency C)
	{
		cout << "Currency Card :" << endl;
		cout << "_________________________________\n\n";
		
		cout << "Country    : " << C.Country() << endl;
		cout << "Code       : " << C.CurrencyCode() << endl;
		cout << "Name       : " << C.CurrencyName() << endl;
		cout << "Rate(1$) = : " << C.Rate() << endl;
		cout << "_________________________________\n\n";
	}

	static void _ShowResults(Currency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";
			_PrintCard(Currency);
		}
		else
		{
			cout << "\nCurrency Was not Found :-(\n";
		}
	}

public:
	static void ShowFindCurrenciesScreen()
	{
		string Title="\t  Find Currency Screen ";
		_DrawScreenHeader(Title);

		cout << "Find By :[1] Code or [2] :Country ?";
		short Choose = InputValidate::ReadNumberBetween <short>(1,2);
	if(Choose==1)
	{
		cout << "\n\n Please Enter CurrencyCode ? ";
		string code = InputValidate::ReadNumberOrString <string>();
		Currency Currency = Currency::FindByCode(code);
		_ShowResults(Currency);

	}
	else if (Choose == 2)
	{

		cout << "\n\n Please Enter Country Name : ";
		string Country = InputValidate::ReadNumberOrString <string>();
		Currency Currency = Currency::FindByCountry(Country);
		_ShowResults(Currency);

	}
	
	}
};

