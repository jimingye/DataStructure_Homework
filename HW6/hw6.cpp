/*
Homework_6
Jiming Ye
N16566270
jy1769@nyu.edu
Mac OSX
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

struct List_NODE
{
	int data;
	List_NODE *next;
	List_NODE() = default;
	List_NODE(const int& d):data(d),next(NULL){}
};

struct BSTnode
{
	int data;
	BSTnode *left;
	BSTnode *right;
	BSTnode() = default;
	BSTnode(int i): data(i), left(NULL), right(NULL) {}
};

class Linkedlist
{
public:
	Linkedlist(){create();}
	~Linkedlist(){clear();}

public:
	
	List_NODE *head;

public:
	void create();
	void clear();
	void insert(const int &entry);
	int search(List_NODE *head, int target);
};

class BS_tree
{
public:                                                                                                
	BSTnode *root;

public:
	BS_tree(){root = new BSTnode();}
	~BS_tree(){};

	BSTnode* create_node(const int &entry);
	void insert(BSTnode *&root, const int &entry);
	int search(BSTnode *root, int target, bool &found, int &count);
	void exist(bool found);
};

void Linkedlist::create()
{
	head = new List_NODE();
}

void Linkedlist::clear()
{
	List_NODE *p = head;
	while(p)
	{
		List_NODE *q = p -> next;
		delete p;
		p = q;
	}
}

void Linkedlist::insert(const int &entry)
{
	List_NODE *p = new List_NODE();
	p -> data = entry, p -> next = NULL;
	if(head == NULL)
		head = p;
	else
	{
		List_NODE *q = head;
		while(q -> next != NULL)
			q = q -> next;
		q -> next = p;
	}
}

int Linkedlist::search(List_NODE *head, int target)
{
	int count = 0;
	List_NODE *p = head;
	while( p != NULL)
	{
		if(p -> data == target)
			break;
		else
		{
			p = p -> next;
			++count;
		}
	}
	return count;
}


BSTnode* BS_tree::create_node(const int &entry)
{
	BSTnode *p = new BSTnode();
	p -> data = entry;
	return p;
}

void BS_tree::insert(BSTnode *&root, const int &entry)
{
	if(root == NULL)
		root = create_node(entry);
	else if(entry <= root -> data)
		insert(root -> left, entry);
	else
		insert(root -> right, entry);
}

int BS_tree::search(BSTnode *root, int target, bool &found, int &count)
{
	if(root == NULL)
	{
		found = false;
	}
	else if(target == root -> data)
	{
		found = true;
	}
	else if(target <= root -> data)
		search(root -> left, target, found, ++count);
	else
		search(root -> right, target, found, ++count);
	return count;
}

void BS_tree::exist(bool found)
{
	if(found)
		cout << "found.";
	else
		cout << "not found.";
}

int main()
{
	BS_tree tree;
	Linkedlist list;
	cout << "Please enter list of integers. If finished, please enter #: " << endl;
	int array[100];
	int m = 0;
	for(int n = 0; n != 100; ++n)
	{
		int i;
		char c;
		if(cin >> i)
		{
			array[n] = i;
			++m;
		}
		else if(cin >> c)
			break;
	}
	for(int n = 0; n != m; ++n)
	{
		list.insert(array[n]);
		tree.insert(tree.root, array[n]);
	}
	cout << "Please enter an integer to search: " << endl;
	int target; 
	cin >> target;
	int list_count, BS_tree_count;
	list_count = list.search(list.head, target);
	bool found;
	int count = 0; 
	BS_tree_count = tree.search(tree.root, target, found, count);
	cout << target << ' ' << "is" << ' ';
	tree.exist(found);
	cout << ' ' << "BST visited " << BS_tree_count << ' ' << "nodes.";
	cout << ' ' << "Linked-list visited " << list_count << ' ' << "nodes.";
	cout << endl;
	return 0;
}