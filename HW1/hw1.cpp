/*
Homework_1
Jiming Ye
N16566270
jy1769@nyu.edu
*/

#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace::std;

class PrepaidAccount
{
public:
	PrepaidAccount() = default;	
	PrepaidAccount(const string &number, double bal): pnumber(number), abalance(bal){}
	//PrepaidAccount(const string &number): pnumber(number){}
	//PrepaidAccount(double bal): abalance(bal){}
	double addbalance(double howMuch);
	double PayForCall(int callDuration, double tariff);
	double availablebalance();
	string getnumber() const {return pnumber;}
private:
	string pnumber = " ";
	double abalance = 0;
};

int compareAccount(const PrepaidAccount a1, const PrepaidAccount a2);

double PrepaidAccount::addbalance(double howMuch)
{
	abalance += howMuch;
	return abalance;
}

double PrepaidAccount::PayForCall(int callDuration, double tariff)
{
	int timeInMin = 0;
	double totalcost = 0.0;
	if (callDuration % 60 == 0)
		timeInMin = callDuration / 60;
	else
		timeInMin = (callDuration / 60) + 1;
	totalcost = timeInMin * tariff;
	if (totalcost <= abalance)
		{
			abalance = abalance - totalcost;
			return totalcost;
		}
	else
		return -1;
}

double PrepaidAccount::availablebalance()
{
	return abalance;
}

int compareAccount(const PrepaidAccount a1, const PrepaidAccount a2)
{
	if (a1.getnumber() < a2.getnumber())
		return -1;
	else if (a1.getnumber() == a2.getnumber())
		return 0;
	else 
		return 1;
}

class AccountStore
{
public:
	AccountStore();
	void insert(PrepaidAccount entry);
	void insert1(PrepaidAccount entry);
	void remove(PrepaidAccount target);
	int getSize() const;
	PrepaidAccount getAccount(int i);
	void sorting();
private:
	PrepaidAccount account[100];
	int used;
};

AccountStore::AccountStore()
{
	used = 0;
}

void AccountStore::insert(PrepaidAccount entry)                                    //insert method 1
{
	account[used] = entry;
	for(int i=0; i<used; ++i)
	{
		for(int j=used; j>i; --j)
		{
			//if(account[j - 1].getnumber() > account[j].getnumber())
			if(compareAccount(account[j - 1], account[j]) == 1)
				{
					PrepaidAccount temp;
					temp = account[j];
					account[j] = account[j - 1];
					account[j - 1] = temp;
				}
		}
	}
	++used;
}

void AccountStore::insert1(PrepaidAccount entry)                                   //insert method 2 with sorting() function.
{
	account[used] = entry;
	++used;
}

void AccountStore::sorting()
{
	for(int i=0; i<used-1; ++i)
	{
		for(int j=used-1; j>i; --j)
		{
			//if(account[j - 1].getnumber() > account[j].getnumber())
			if(compareAccount(account[j - 1], account[j]) == 1)
				{
					PrepaidAccount temp;
					temp = account[j];
					account[j] = account[j - 1];
					account[j - 1] = temp;
				}
		}
	}
}

void AccountStore::remove(PrepaidAccount target)
{
	for(int i = 0; i < used; ++i)
	{
		if(compareAccount(account[i], target) == 0)
			{
				for(int j = i; j < used; ++j)
					account[j] = account[j + 1];
			}
	}
	--used;
}

int AccountStore::getSize() const
{
	return used;
}

PrepaidAccount AccountStore::getAccount(int i)
{
	return account[i - 1];
}

int main()
{	
	AccountStore AS;
	stringstream strstream0, strstream1, strstream2, strstream3, strstream4;
	srand(time(NULL));
	long m0 = rand() % 9000000000 + 1000000000;
	long m1 = rand() % 9000000000 + 1000000000;
	long m2 = rand() % 9000000000 + 1000000000;
	long m3 = rand() % 9000000000 + 1000000000;
	long m4 = rand() % 9000000000 + 1000000000;
	strstream0 << m0;
	strstream1 << m1;
	strstream2 << m2;
	strstream3 << m3;
	strstream4 << m4;
	string s0 = strstream0.str();
	string s1 = strstream1.str();
	string s2 = strstream2.str();
	string s3 = strstream3.str();
	string s4 = strstream4.str();
	double am0 = rand() % 50 + 51;
	double am1 = rand() % 50 + 51;
	double am2 = rand() % 50 + 51;
	double am3 = rand() % 50 + 51;
	double am4 = rand() % 50 + 51;
	int sec0 = rand() % 190 + 11;
	int sec1 = rand() % 190 + 11;
	int sec2 = rand() % 190 + 11;
	int sec3 = rand() % 190 + 11;
	int sec4 = rand() % 190 + 11;
	double cost0 = (rand() % 5 + 1)/10.0;
	double cost1 = (rand() % 5 + 1)/10.0;
	double cost2 = (rand() % 5 + 1)/10.0;
	double cost3 = (rand() % 5 + 1)/10.0;
	double cost4 = (rand() % 5 + 1)/10.0;
	PrepaidAccount a0(s0, am0);
	PrepaidAccount a1(s1, am1);
	PrepaidAccount a2(s2, am2);
	PrepaidAccount a3(s3, am3);
	PrepaidAccount a4(s4, am4);
	a0.PayForCall(sec0, cost0);
	a1.PayForCall(sec1, cost1);
	a2.PayForCall(sec2, cost2);
	a3.PayForCall(sec3, cost3);
	a4.PayForCall(sec4, cost4);
	//cout << s0 << ' ' << am0 << ' ' <<  a0.PayForCall(sec0, cost0) << ' ' << a0.availablebalance() << endl;
	//cout << s1 << ' ' << am1 << ' ' <<  a1.PayForCall(sec1, cost1) << ' ' << a1.availablebalance() << endl;
	//cout << s2 << ' ' << am2 << ' ' <<  a2.PayForCall(sec2, cost2) << ' ' << a2.availablebalance() << endl;
	//cout << s3 << ' ' << am3 << ' ' <<  a3.PayForCall(sec3, cost3) << ' ' << a3.availablebalance() << endl;
	//cout << s4 << ' ' << am4 << ' ' <<  a4.PayForCall(sec4, cost4) << ' ' << a4.availablebalance() << endl;
	int count = 0;
	AS.insert(a0);
	++count;
	AS.insert(a1);
	++count;
	AS.insert(a2);
	++count;
	AS.insert(a3);
	++count;
	AS.insert(a4);
	++count;
	//AS.remove(a2);
	//--count;
	//cout << AS.getSize() << endl;
	/*AS.insert1(a0);
	AS.insert1(a1);
	AS.insert1(a2);
	AS.insert1(a3);
	AS.insert1(a4);
	AS.sorting();*/
	for(int i = 0; i < count; ++i)
	{
		cout << AS.getAccount(i + 1).getnumber() << ' ' << AS.getAccount(i + 1).availablebalance() << endl;
	}
	return 0;
}
	