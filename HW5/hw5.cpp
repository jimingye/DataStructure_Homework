/*
Homework_5
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
using std::cerr;

struct BTnode
{
	char data;
	BTnode *left;
	BTnode *right;
	BTnode() = default;
	BTnode(char ch): data(ch), left(NULL), right(NULL) {}
};

class Binary_tree
{
public:                                                                                                //can call the root directly(Tree.root).
	BTnode *root;

public:
	Binary_tree(){root = new BTnode();}
	~Binary_tree(){};

	BTnode* create_tree(string s, int index);
	void assign_preorder(BTnode *&root, string s, string::iterator &siter);
	void assign_inorder(BTnode *&root, string s, string::iterator &siter);
	void assign_postorder(BTnode *&root, string s, string::iterator &siter);
	BTnode* call_assign_preorder(BTnode *&root, string s, int index);
	BTnode* call_assign_inorder(BTnode *&root, string s, int index);
	BTnode* call_assign_postorder(BTnode *&root, string s, int index);
	void traversal_preorder(BTnode *root);
	void traversal_inorder(BTnode *root);
	void traversal_postorder(BTnode *root);
};

BTnode* Binary_tree::create_tree(string s, int index)                                                  //create a complete binary tree.
{
	if(s.begin() == s.end())
		return NULL;
	else
	{
		queue<BTnode*> BTqueue;
		auto siter = s.begin() + index;
		root -> data = *siter;
		siter = siter + 2;
		BTqueue.push(root);
		BTnode *p = NULL;
		while(!BTqueue.empty())
		{
			p = BTqueue.front();
			BTqueue.pop();
			if(siter <= s.end() - 1)
			{
				BTnode *leftnode = new BTnode(*siter);
				p -> left = leftnode;
				BTqueue.push(leftnode);
				siter = siter + 2;
			}
			if(siter <= s.end() - 1)
			{
				BTnode *rightnode = new BTnode(*siter);
				p -> right = rightnode;
				BTqueue.push(rightnode);
				siter = siter + 2;
			}
		}
	}
	return root;
}

BTnode* Binary_tree::call_assign_preorder(BTnode *&root, string s, int index)
{
	auto siter = s.begin() + index;
	assign_preorder(root, s, siter);
	return root;
}

void Binary_tree::assign_preorder(BTnode *&root, string s, string::iterator &siter)                    //iterator is used by reference. Always change itself.
{
	if(root == NULL && siter > s.end())                                                                //decide whether reaching the leaves or the last element in string.
		return;
	else 
		{
			root -> data = *siter, siter = siter + 2;                                                  //assign the element to root, and skip ' '.
			assign_preorder(root -> left, s, siter);
			assign_preorder(root -> right, s, siter);
		}
}

BTnode* Binary_tree::call_assign_inorder(BTnode *&root, string s, int index)
{
	auto siter = s.begin() + index;
	assign_inorder(root, s, siter);
	return root;
}

void Binary_tree::assign_inorder(BTnode *&root, string s, string::iterator &siter)
{
	if(root == NULL && siter > s.end())
		return;
	else 
		{
			assign_inorder(root -> left, s, siter);
			root -> data = *siter, siter = siter + 2;
			assign_inorder(root -> right, s, siter);
		}
}

BTnode* Binary_tree::call_assign_postorder(BTnode *&root, string s, int index)
{
	auto siter = s.begin() + index;
	assign_postorder(root, s, siter);
	return root;
}

void Binary_tree::assign_postorder(BTnode *&root, string s, string::iterator &siter)
{
	if(root == NULL && siter > s.end())
		return;
	else 
		{
			assign_postorder(root -> left, s, siter);
			assign_postorder(root -> right, s, siter);
			root -> data = *siter, siter = siter + 2;
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
	if(*(iter_1 + 3) == 'R' || *(iter_1 + 3) == 'r')
	{
		Tree.create_tree(s1, 6);
	}
	else if(*(iter_1 + 3) == 'O' || *(iter_1 + 3) == 'o')
	{
		Tree.create_tree(s1, 7);
	}
	else if(*(iter_1 + 3) == 'N' || *(iter_1 + 3) == 'n')
	{
		Tree.create_tree(s1, 5);
	}
	cout << "Constructed!" << endl;

	cout << "Please enter the print command: " << endl;
	start:
	getline(cin, s2);
	auto iter_2 = s2.begin();

	if(*(iter_1 + 3) != *(iter_2 + 3))
		{
			cerr << "the creat command and print command are different!" << endl;
			cout << "Please enter the print command again: " << endl;
			goto start;
		}
		
	else
	{
		if(*(iter_2 + 3) == 'R' || *(iter_2 + 3) == 'r')
		{
			Tree.call_assign_preorder(Tree.root, s1, 6);
			cout << "Output: " << endl;
			Tree.traversal_preorder(Tree.root);
			cout << endl;
		}
		else if(*(iter_2 + 3) == 'O' || *(iter_2 + 3) == 'o')
		{
			Tree.call_assign_postorder(Tree.root, s1, 7);
			cout << "Output: " << endl;
			Tree.traversal_postorder(Tree.root);
			cout << endl;
		}
		else if(*(iter_2 + 3) == 'N' || *(iter_2 + 3) == 'n')
		{
			Tree.call_assign_inorder(Tree.root, s1, 5);
			cout << "Output: " << endl;
			Tree.traversal_inorder(Tree.root);
			cout << endl;
		}
	}
	return 0;
}