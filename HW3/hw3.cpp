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

template<class T>
struct NODE
{
	T data;
	NODE *next;
	NODE() = default;
	NODE(const T& d):data(d),next(NULL){}
};

template<class T>
class stack
{
private:
	NODE<T> *head;
	int sizeofstack;

public:
	stack():head(NULL), sizeofstack(0){}
	~stack();

	int size(){return sizeofstack;}
	bool empty(){return (size() == 0);}
	void push(const T &c);
	T pop();
};

template<class T>
stack<T>::~stack()
{
	while(head != NULL)
	{
		NODE<T> *p = head;
		head = head -> next;
		delete p;
		p = NULL;
	}
}

template<class T>
void stack<T>::push(const T &c)
{
	NODE<T> *p = new NODE<T>();
	p -> data = c, p -> next = head;
	head = p;
	++sizeofstack;
}

template<class T>
T stack<T>::pop()
{
	T temp;
	if(empty())
		return -1;
	else
	{
		temp = head -> data;
		NODE<T> *p = head;
		head = head -> next;
		delete p;
		p = NULL;
		--sizeofstack;
		return temp;
	}
}

template<class T>
string inverse(stack<T> &s)
{
	string str;
	vector<string> svec;
	s.pop();
	while(!s.empty())
	{
		T c = s.pop();
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

template<class T>
class queue
{
private:
	stack<T> s1;
	stack<T> s2;

public:
	queue() = default;

	void insert(const T &c);
	T get_front();
	bool empty(){return (s1.size() + s2.size() == 0);}
};

template<class T>
void queue<T>::insert(const T &c)
{
	s1.push(c);
}

template<class T>
T queue<T>::get_front()
{
	if(s2.empty())
	{
		while(!s1.empty())
			s2.push(s1.pop());
		return s2.pop();
	}
	else
		return s2.pop();
}

int main()
{
	stack<char> stk;	
	queue<char> que;
	char c;
	while(cin >> noskipws >> c)
	{
		que.insert(c);
		stk.push(c);
	}
	cout << endl;
	while(!que.empty())
		cout << que.get_front();
	cout << endl;
	cout << inverse(stk);
	cout << endl;
	return 0;

}