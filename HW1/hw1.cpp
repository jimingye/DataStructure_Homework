/*
Homework_1
Jiming Ye
N16566270
jy1769@nyu.edu
*/

//grading comments
/*Remove account doesn't return -1 if target not found (-1) Min dollars is 51, not 50 and min call length is 11 sec not 10 (-1) Constructor takes a value for balance and that is used instead of the addBalance function in main (-1) Graded the insert1 function for the complexity analysis (there was no reason provided for the other)*/

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
	AccountStore():used(0){}
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

void AccountStore::insert(PrepaidAccount entry)                               //insert method 1，insert with sorting.
{
	account[used] = entry;
	for(int i=0; i<used; ++i)
	{
		if(compareAccount(account[i], entry) == 1)
		{
			for(int j=used; j>=i; --j)
				account[j + 1] = account[j];
			account[i] = entry;
			break;                                                           //if without break, the comparing will continue untill i = used.
		}
	}
	++used;
}

void AccountStore::insert1(PrepaidAccount entry)                             //insert method 2 with sorting() function.
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
	int count = 0;
	AccountStore AS;
	stringstream strstream;
	srand(time(NULL));
	for(int n = 0; n < 5; ++n)
	{
		long m = rand() % 9000000000 + 1000000000;
		strstream << m;
		string s = strstream.str();
		double am = rand() % 50 + 50;
		int sec = rand() % 190 + 10;
		double cost = (rand() % 5 + 1)/10.0;
		PrepaidAccount a(s, am);
		a.PayForCall(sec, cost);
		AS.insert(a);
		//AS.insert1(a);
		strstream.str("");
		++count;
	}
	//AS.sorting();
	//AS.remove(AS.getAccount(2));
	//--count;
	for(int i = 0; i < count; ++i)
	{
		cout << AS.getAccount(i + 1).getnumber() << ' ' << AS.getAccount(i + 1).availablebalance() << endl;
	}
	return 0;
}
	