#pragma once

#include<iostream>
#include<iomanip>
#include <string>
#include "Screen.h"
#include "User.h"
using namespace std;

class UserListScreen:protected Screen
{

private:
	static void _PrintUserRecordline(User User)
	{
		cout << setw(8) << left << "" << "| " << setw(12) << left << User.UserName;
		cout  << "| " << setw(25) << left << User.FullName();
		cout  << "| " << setw(12) << left << User.Phone;
		cout  << "| " << setw(20) << left << User.Email;
		cout  << "| " << setw(10) << left << User.Password;
		cout  << "| " << setw(12) << left << User.Permissions;
	}
public:

	static void ShowUserList()
	{
		vector <User> vUsers = User::GetUsersList();
		string Title = "\t  User List Screen";
		string SubTitle = "\t  (" + to_string(vUsers.size()) + ") User(s).";
		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t______________________________________________________________";
		cout << "____________________________________________\n"<<endl;
		
		cout << setw(8) << left << "" << "| " << left << setw(12) << "User Name";
		cout  << "| " << left << setw(25) << "Full Name";
		cout  << "| " << left << setw(12) << "Phone";
		cout  << "| " << left << setw(20) << "Email";
		cout  << "| " << left << setw(10) << "Password";
		cout  << "| " << left << setw(12) << "Permissions";
		cout << setw(8) << left << "" << "\n\t______________________________________________________________";
		cout << "____________________________________________\n"<<endl;
	
		if (vUsers.size()==0)
		{
			cout << "\t\t\t\tNo Users Available In the System! ";
	}
		else
		{
			for (User User:vUsers)
			{
				_PrintUserRecordline(User);
				cout << endl;
			}
		}
		cout << setw(8) << left << "" << "\n\t______________________________________________________________";
		cout << "____________________________________________\n" << endl;

	
	}

};

