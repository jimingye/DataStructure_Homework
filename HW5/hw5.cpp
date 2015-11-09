/*
Homework_4
Jiming Ye
N16566270
jy1769@nyu.edu
Mac OSX
*/

#include <iostream>
#include <string>
#include <queue>

using std::string;
using std::queue;
using std::cout;
using std::cin;
using std::endl;

struct BTnode
{
	string data;
	BTnode *left;
	BTnode *right;
	BTnode(string str): data(str), left(NULL), right(NULL) {}
};

class Binary_tree
{
public:
	BTnode *root;

public:
	Binary_tree(){root = NULL}

	BTnode* create_tree(string s, int index);
	BTnode* call_assign_preorder(BTnode *&root, string s, int index);
	BTnode* call_assign_inorder(BTnode *&root, string s, int index);
	BTnode* call_assign_postorder(BTnode *&root, string s, int index);
	void assign_preorder(BTnode *&root, string s, string::iterator siter);
	void assign_inorder(BTnode *&root, string s, string::iterator siter);
	void assign_postorder(BTnode *&root, string s, string::iterator siter);
	void traversal_preorder(BTnode *root);
	void traversal_inorder(BTnode *root);
	void traversal_postorder(BTnode *root);
};

BTnode* Binary_tree::create_tree(string s, int index)
{
	//int length;
	//for(; siter <= s.end() - 1; siter = siter + 2)
	//{
	//	++length;
	//}
	if(s.begin() == s.end())
		return NULL;
	queue<BTnode*> BTqueue;
	auto siter = s.begin() + index;
	BTnode *root = new BTnode(*siter);
	siter = siter + 2;
	queue.push(root);
	BTnode *p = NULL;
	while(!queue.empty() && siter <= s.end() - 1)
	{
		p = queue.front();
		queue.pop();
		if(siter <= s.end() - 1)
		{
			BTnode *leftnode = new BTnode(*siter);
			p -> left = leftnode;
			queue.push(leftnode);
		}
		siter = siter + 2;
		if(siter <= s.end() - 1)
		{
			BTnode *righttnode = new BTnode(*siter);
			p -> right = rightnode;
			queue.push(rightnode);
		}
		siter = siter + 2;
	}
	return root;
}

BTnode* Binary_tree::call_assign_preorder(BTnode *&root, string s, int index)
{
	auto siter = s.begin() + index;
	assign_preorder(root, s, siter);
	return root;
}

void Binary_tree::assign_preorder(BTnode *&root, string s, string::iterator siter)
{
	if(siter > s.end())
		root = NULL;
	else 
		{
			root -> data = *siter;
			assign_preorder(root -> left, s, siter = siter + 2 );
			assign_preorder(root -> right, s, siter = siter + 2);
		}
}

BTnode* Binary_tree::call_assign_inorder(BTnode *&root, string s, int index)
{
	auto siter = s.begin() + index;
	assign_inorder(root, s, siter);
	return root;
}

void Binary_tree::assign_inorder(BTnode *&root, string s, string::iterator siter)
{
	if(siter > s.end())
		root = NULL;
	else 
		{
			assign_inorder(root -> left, s, siter = siter + 2 );
			root -> data = *siter;
			assign_inorder(root -> right, s, siter = siter + 2);
		}
}

BTnode* Binary_tree::call_assign_postorder(BTnode *&root, string s, int index)
{
	auto siter = s.begin() + index;
	assign_postorder(root, s, siter);
	return root;
}

void Binary_tree::assign_postorder(BTnode *&root, string s, string::iterator siter)
{
	if(siter > s.end())
		root = NULL;
	else 
		{
			assign_postorder(root -> left, s, siter = siter + 2 );
			assign_postorder(root -> right, s, siter = siter + 2);
			root -> data = *siter;
		}
}

void Binary_tree::traversal_preorder(BTnode *root)
{
	if(root == NULL)
		return;
	else
	{
		cout << root -> data << " ";
		traversal_preorder(root -> left);
		traversal_preorder(root -> right);
	}
}

void Binary_tree::traversal_inorder(BTnode *root)
{
	if(root == NULL)
		return;
	else
	{
		traversal_inorder(root -> left);
		cout << root -> data << " ";
		traversal_inorder(root -> right);
	}
}

void Binary_tree::traversal_postorder(BTnode *root)
{
	if(root == NULL)
		return;
	else
	{
		traversal_postorder(root -> left);
		traversal_postorder(root -> right);
		cout << root -> data << " ";
	}
}

int main()
{
	string s1, s2;
	Binary_tree Tree;
	cout << "Please enter the create command and numbers in the tree: " << endl;
	getline(cin, s1);
	auto iter_1 = s1.begin();
	if(*(iter_1 + 3) == 'r' || *(iter_1 + 3) == 'R')
	{
		Tree.create_tree(s1, 6);
	}
	else if(*(iter_1 + 3) == 'o' || *(iter_1 + 3) == 'O')
	{
		Tree.create_tree(s1, 7);
	}
	else if(*(iter_1 + 3) == 'n' || *(iter_1 + 3) == 'N')
	{
		Tree.create_tree(s1, 5);
	}
	cout << "Constructed!" << endl;
	cout << "Please enter the print command: " << endl;
	getline(cin, s2);
	auto iter_2 = s2.begin();
	if(*(iter_2 + 3) == 'r' || *(iter_2 + 3) == 'R')
	{
		Tree.call_assign_preorder(Tree.root, s1, 6);
		cout << "Output: " << endl;
		Tree.traversal_preorder(Tree.root);
		cout << endl;
	}
	else if(*(iter_2 + 3) == 'o' || *(iter_2 + 3) == 'O')
	{
		Tree.call_assign_postorder(Tree.root, s1, 7);
		cout << "Output: " << endl;
		Tree.traversal_postorder(Tree.root);
		cout << endl;
	}
	else if(*(iter_2 + 3) == 'n' || *(iter_2 + 3) == 'N')
	{
		Tree.call_assign_inorder(Tree.root, s1, 5);
		cout << "Output: " << endl;
		Tree.traversal_inorder(Tree.root);
		cout << endl;
	}
	return 0;
}