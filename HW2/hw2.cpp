/*
Homework_2
Jiming Ye
N16566270
jy1769@nyu.edu
Mac OSX
*/

#include <iostream>

using namespace::std;

struct NODE
{
	int data;
	NODE *next;
	NODE() = default;
	NODE(const int& d):data(d),next(NULL){}
};

class Linkedlist
{
public:
	Linkedlist(){create();}
	~Linkedlist(){clear();}

private:
	
	NODE *head;

public:
	void create();
	void clear();
	void insert(const int &entry);
	void insert_in_sorted_linkedlist(const int &entry);
	void print();
	void reverse();
	int length();
	NODE* find_middle(NODE *head);
	NODE* gethead(){return head;}
};

void concatenate(NODE *head1, NODE *head2);
double median(Linkedlist L);

void Linkedlist::create()
{
	head = new NODE();
}

void Linkedlist::clear()
{
	NODE *p = head;
	while(p)
	{
		NODE *q = p -> next;
		delete p;
		p = q;
	}
}

void Linkedlist::print()
{
	for(NODE *p = head -> next; p; p = p -> next)
	{
		cout << p -> data << ' ';
	}
}

void Linkedlist::insert(const int &entry)
{
	NODE *p = new NODE();
	p -> data = entry, p -> next = NULL;
	if(head == NULL)
		head = p;
	else
	{
		NODE *q = head;
		while(q -> next != NULL)
			q = q -> next;
		q -> next = p;
	}
}

void Linkedlist::insert_in_sorted_linkedlist(const int &entry)
{
	NODE *p1 = head, *p2 = NULL;
	while(p1 -> data < entry && p1 -> next != NULL)
		p2 = p1, p1 = p1 -> next;
	NODE *p = new NODE();
	p -> data = entry;
	if(p1 -> data < entry)
		p1 -> next = p, p -> next = NULL;
	else if (p1 == head)
		p -> next = p1, head = p;
	else
		p2 -> next = p, p -> next = p1;
}

int Linkedlist::length()
{
	int l = 0;
	while(head != NULL)
	{
		head = head -> next;
		++l;
	}
	return l - 1;
}

void concatenate(NODE *head1, NODE *head2)
{
	NODE *p, *q, *r;
	if(head2 -> next == NULL)
		return;
	q = new NODE;
	q -> data = head2 -> next -> data;
	r = q;
	head2 -> next = head2 -> next -> next;
	while(head2 -> next != NULL)
	{
		p =new NODE;
		p -> data = head2 -> next -> data;
		r -> next = p;
		r = p;
		head2 -> next = head2 -> next -> next;
	}
	r -> next = NULL;
	if(head1 -> next== NULL)
		head1 -> next = q;
	else
	{
		for(p = head1 -> next; p -> next != NULL; p = p -> next);
		p -> next = q;
	}
}

void Linkedlist::reverse()
{
	NODE * p = head->next;
    NODE * q = head->next->next;
    NODE * m = head->next->next->next;
    p->next = NULL;
    while(m){
        q->next = p;
        p = q;
        q = m;
        m = m->next;
    }
    q->next = p;
    head ->next = q;
}

NODE* Linkedlist::find_middle(NODE *head)
{
	if(head == NULL || head -> next == NULL)
		return head;
	NODE *p = head, *q = head;
	while(q && q -> next != NULL)
	{
		q = q -> next -> next;
		p = p -> next;
	}
	return p;
}

double median(Linkedlist L)
{
	int i = L.find_middle(L.gethead()) -> data;
	int j = L.find_middle(L.gethead()) -> next -> data;
	if(L.length() % 2 == 1)
		return i;
	else
		return (i + j) / 2.0; 
}

int main()
{
	cout << "Please tell me what to do: concatenate(C), insert(I), median(M), reverse(R), end(E)?" << endl;
	Linkedlist l1, l2;
	char c;
	cin >> c;
	if(c == 'C')
	{
	    cout << "Please input the list1:" << endl;
	    int i;
	    do
	    {
	    	cin >> i;
	    	l1.insert(i);
	    }
	    while(!'\r');
	    cout << "Please input the list2:" << endl;
	    int j;
	    while(cin >> j)
	    	l2.insert(j);
	    NODE *p1 = l1.gethead();
	    NODE *p2 = l2.gethead();
	    concatenate(p1, p2);
	    cout << "The outcome is:" << endl;
	    l1.print();
	}
	else if(c == 'I')
	{
	    cout << "Please input the sorted list:" << endl;
	    int i;
	    do
	    {
	    	cin >> i;
	    	l1.insert(i);
	    }
	    while(!'\r');
	    cout << "Please input the value:" << endl;
	    int j;
	    while(cin >> j)
	    	l1.insert_in_sorted_linkedlist(j);
	    cout << "The outcome is:" << endl;
	    l1.print();
	}
	else if(c == 'M')
	{
	    cout << "Please input the list:" << endl;
	    int i;
	    while(cin >> i)
	    	l1.insert(i);
	    cout << "The outcome is:" << endl;
	    cout << median(l1) << endl;
	}
	else if(c == 'R')
	{
	    cout << "Please input the list:" << endl;
	    int i;
	    while(cin >> i)
	    	l1.insert(i);
	    l1.reverse();
	    cout << "The outcome is:" << endl;
	    l1.print();
	}
	else if(c == 'E')
	{
	    return 0;
	}
}