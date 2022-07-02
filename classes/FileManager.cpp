#include <fstream>

void WriteDB(string db, string line)
{
	ofstream DB(db, ios::app);
	DB << line << endl;
	DB.close();
}

void ReadDB(string db)
{
	ifstream DB(db);

	if (db == DBUSER)
	{
		int id;
		string name, surname;
		float balance;
		clear();
		cout 	<< " - Usuarios registrados -" << endl;
		cout 	<< " # "
					<< "\t Full name "
					<< "\t $ " << endl;
		cout 	<< divr << endl;

		string st;
		int prev = 0;

		do
		{
			DB >> id >> name >> surname >> balance;
			if (id != prev)
			{
				string fullname = name + " " + surname;
				cout << " " << id << "\t " << fullname << "\t " << balance << endl;
				prev = id;
			}
		} while (getline(DB, st));
	}
	else if (db == DBTX)
	{
		int id;
		string from, to;
		float balance;
		clear();
		cout 	<< " - Transacciones Registradas -" << endl;
		cout 	<< " # "
					<< "\t From "
					<< "\t To "
					<< "\t $ " << endl;
		cout 	<< divr << endl;

		string st;
		int prev = 0;

		do
		{
			DB >> id >> from >> to >> balance;
			if (id != prev)
			{
				cout 	<< " " << id << "\t " << from << "\t " << to << "\t " << balance
							<< endl;
				prev = id;
			}
		} while (getline(DB, st));
	}
	DB.close();
}

bool ChecksDB(void)
{
	ifstream userDB(DBUSER);
	ifstream txDB(DBTX);
	string a;

	if (!userDB.is_open())
	{
		cout << "ERROR: User DB not found";
		return 1;
	}
	else
	{
		int id;
		do
		{
			userDB >> id;
			if (id > USERN)
			{
				USERN = id;
			}
		} while (getline(userDB, a));
		USERN++;
	}

	if (!txDB.is_open())
	{
		cout << "ERROR: Tx DB not found";
		return 1;
	}
	else
	{
		int id;
		do
		{
			userDB >> id;
			if (id > TXN)
			{
				TXN = id;
			}
		} while (getline(txDB, a));
		TXN++;
	}

	userDB.close();
	txDB.close();
	return 0;
}

void DeleteLineDB(string db, string eraseID)
{
	string id, name, sur, balance;

	string line;
	ifstream fin;

	fin.open(db);
	// contents of path must be copied to a temp file then
	// renamed back to the path file
	ofstream temp;
	temp.open("./db/tmp.txt");

	string prev = "0";
	string tmp;
	do
	{
		// write all lines to temp other than the line marked for erasing
		fin >> id >> name >> sur >> balance;
		if (id != eraseID && id != prev)
		{
			tmp += id + " " + name + " " + sur + " " + balance;
			temp << tmp << endl;
			tmp = "";
			prev = id;
		}
	} while (getline(fin, line));

	temp.close();
	fin.close();

	// required conversion for remove and rename functions
	const char *p = db.c_str();
	remove(p);
	rename("./db/tmp.txt", "./db/UserDB.txt");
}
