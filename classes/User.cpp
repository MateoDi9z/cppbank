class User
{
private:
	int id;
	string fullname;
	double balance;

	void postOnFile();

public:
	User(int id, string fullname)
	{
		this->id = id;
		this->balance = 0;
		this->fullname = fullname;
	}

	double getBalance();
	string getFullname();
	void post(string tfullname, int n);
	void printUser(void);
	void printUser(bool x);
	string getDBFormat();
};

void User::postOnFile()
{
	cout << "POSTONFILE" << endl;
	cout << this->id << this->fullname << this->balance;
}

void User::post(string tfullname, int n)
{

	this->id = n;
	this->fullname = tfullname;
	// postOnFile();
}

double User::getBalance()
{
	return balance;
}
string User::getFullname()
{
	return this->fullname;
}

void User::printUser(void)
{
	cout << " id: " << this->id << endl;
	cout << " user: " << this->fullname << endl;
	cout << " balance: " << this->balance << endl;
}
void User::printUser(bool x)
{
	if (this->id)
		cout << " #" << this->id << " - " << this->fullname << endl;
	else if (!this->id && this->id > 0)
		return;
}
string User::getDBFormat()
{
	string res;
	res += to_string(this->id);
	res += " " + this->fullname;
	res += " " + to_string(this->balance);
	return res;
}