/*
	C++ Bank
	v1.2
*/

//? Macros
#include "macros.cpp"

//? Includes
#include <chrono>
#include <thread>
#include "utils.h"
#include "protos.cpp"

int USERN = 1;
int TXN = 1;

//? Classes
#include "./classes/User.cpp"
#include "./classes/Tx.cpp"
#include "./classes/FileManager.cpp"

/// BUILD & RUN COMMAND:  .\cmd\.ps1
/// RUN COMMAND a.exe

void newUser(void)
{
	clear();

	string name, sur;
	int id = USERN;

	cout << "Ingrese su nombre completo: (ej: Nombre Apellido)" << endl;
	cout << "> ";
	cin >> name >> sur;

	string fullname = name + " " + sur;
	User temp(id, fullname);

	clear();
	cout << "Estas por agregar este usuario:" << endl;
	temp.printUser();

	int res = confirm();
	string ras;
	if (res)
	{
		WriteDB(DBUSER, temp.getDBFormat());
		USERN++;
	}
}

void showUsers(void)
{
	ReadDB(DBUSER);
	askToCLose();
}

void deleteUser(void)
{
	clear();
	string a;
	cout << " ID de usuario a borrar: " << endl;
	cin >> a;
	DeleteLineDB(DBUSER, a);
	cout << "Usuario con ID " << a << " eliminado!" << endl;
	delay(2000);
}

void UserMenu(void)
{
	bool user = true;

	while (user)
	{
		clear();
		string p[] = {"Add user", "Get users", "Delete user"};
		int opt = MenuGenerator("Users Actions", "OPTIONS:", p, 3, true);

		switch (opt)
		{
		case USERNEW:
			newUser();
			break;
		case USERSHOW:
			showUsers();
			break;
		case USERDEL:
			deleteUser();
			break;
		case USERBACK:
			user = false;
			break;
		default:
			askToCLose();
			user = false;
			break;
		}
	};
}

void TxMenu(void)
{
	bool tx = true;

	while (tx)
	{
		clear();
		string p[] = {"Add Tx", "Show Txs", "Delete Tx"};
		int opt = MenuGenerator("Transactions Actions", "OPTIONS:", p, 3, true);

		switch (opt)
		{
		case TXNEW:
			break;
		case TXSHOW:
			break;
		case TXDEL:
			break;
		case TXBACK:
			tx = false;
			break;
		default:
			askToCLose();
			tx = false;
			break;
		}
	}
}

//* MAIN
int main(int argc, char *argv[])
{
	if (ChecksDB())
		return 1;

	while (1)
	{
		clear();
		if (argv[1])
			fastMenu(argv[1]);
		else
		{
			string p[] = {"Users", "Transactions"};
			int opt = MenuGenerator("  Welcome to CPP Bank!", "OPTIONS:", p, 2, false);

			switch (opt)
			{
			case MENU_USER:
				clear();
				UserMenu();
				break;

			case MENU_TX:
				clear();
				TxMenu();
				break;

			default:
				askToCLose();
				break;
			}
		}
	}

	return 0;
}

void fastMenu(string arg)
{
	if ((arg == "user") || (arg == "USER") || (arg == "User"))
	{
		UserMenu();
	}
	else if ((arg == "tx") || (arg == "TX") || (arg == "Tx"))
	{
		TxMenu();
	}
}