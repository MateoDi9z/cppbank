#include <fstream>

void WriteDB(string db, string a)
{
    ofstream DB(db, ios::app);
    DB << a << endl;
    DB.close();
}

void ReadDB(string db)
{
    ifstream DB(db);
    if (db == DBUSER)
    {
        clear();
        cout << " - Usuarios registrados -" << endl;
        cout << " # "
        << "\t Full name "
        << "\t $ " << endl;
        cout << divr << endl;

        string st;
        while (getline(DB, st))
        {
            DB >> id >> name >> surname >> balance;
            string fullname = name + " " + surname;
            cout << " " << id << "\t " << fullname << "\t " << balance << endl;
        }
    }
    else if (db == DBTX) {
        clear();
        cout << " - Transacciones Registradas -" << endl;
        cout << " # "
        << "\t Full name "
        << "\t $ " << endl;
        cout << divr << endl;

        string st;
        while (getline(DB, st))
        {
            DB >> id >> name >> surname >> balance;
            string fullname = name + " " + surname;
            cout << " " << id << "\t " << fullname << "\t " << balance << endl;
        }
    }
    DB.close();
}