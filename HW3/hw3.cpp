/*
Homework_2
Jiming Ye
N16566270
jy1769@nyu.edu
Mac OSX
*/

#include <iostream>
#include <vector>
#include <string>

using namespace::std;

struct NODE
{
	char data;
	NODE *next;
	NODE() = default;
	NODE(const char& d):data(d),next(NULL){}
};

class stack
{
private:
	NODE *head;
	int sizeofstack;

public:
	stack():head(NULL), sizeofstack(0){}
	~stack();

	int size(){return sizeofstack;}
	bool empty(){return (size() == 0);}
	void push(const char &c);
	char pop();
};

stack::~stack()
{
	while(head != NULL)
	{
		NODE *p = head;
		head = head -> next;
		delete p;
	}
}

void stack::push(const char &c)
{
	NODE *p = new NODE();
	p -> data = c, p -> next = head;
	head = p;
	++sizeofstack;
}

char stack::pop()
{
	char temp;
	if(empty())
		return -1;
	else
	{
		temp = head -> data;
		NODE *p = new NODE();
		p = head;
		head = head -> next;
		delete p;
		--sizeofstack;
		return temp;
	}
}

string inverse(stack s)
{
	string str;
	vector<string> svec;
	s.pop();
	while(!s.empty())
	{
		char c = s.pop();
		if(c != ' ')
		{
			str += c;
			//c = '\0';
		}
		else
		{
			svec.push_back(str);
			str.clear();
			//c = '\0';
		}
	}
	svec.push_back(str);
	str.clear();
	for(auto iter = svec.rbegin(); iter != svec.rend(); ++iter)
		str += *iter + " ";
	return str;
}

int main()
{
	stack stk;
	char c; 
	while(cin >> noskipws >> c)
		stk.push(c);
	//while(!stk.empty())
	//	cout << stk.pop();
	//cout << endl;
	cout << inverse(stk);
	return 0;
}