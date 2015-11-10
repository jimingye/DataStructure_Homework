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
    char data;
    BTnode *left;
    BTnode *right;
    BTnode() = default;
    BTnode(char ch): data(ch), left(NULL), right(NULL) {}
};

class Binary_tree
{
public:
    BTnode *root;
    
public:
    Binary_tree(){root = new BTnode();}
    ~Binary_tree(){}
    
    BTnode* create_tree(string s, int index);
    BTnode*& get_root(){return root;};
    void assign_preorder(BTnode *&root, string s, string::iterator &siter);
    void assign_inorder(BTnode *&root, string s, string::iterator siter);
    void assign_postorder(BTnode *&root, string s, string::iterator siter);
    BTnode* call_assign_preorder(BTnode *&root, string s, int index);
    BTnode* call_assign_inorder(BTnode *&root, string s, int index);
    BTnode* call_assign_postorder(BTnode *&root, string s, int index);
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
    else
    {
        queue<BTnode*> BTqueue;
        auto siter = s.begin() + index;
        root -> data = *siter;
        //cout << *siter << endl;
        //cout << root -> data << endl;
        siter = siter + 2;
        BTqueue.push(root);
        BTnode *p = NULL;
        while(!BTqueue.empty() /*&& siter <= s.end() - 1*/)
        {
            p = BTqueue.front();
            cout << p -> data << endl;
            BTqueue.pop();
            if(siter <= s.end() - 1)
            {
                BTnode *leftnode = new BTnode(*siter);
                //cout << *siter << endl;
                //cout << leftnode -> data << endl;
                p -> left = leftnode;
                BTqueue.push(leftnode);
                siter = siter + 2;
            }
            if(siter <= s.end() - 1)
            {
                BTnode *rightnode = new BTnode(*siter);
                //cout << *siter << endl;
                //cout << rightnode -> data << endl;
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

void Binary_tree::assign_preorder(BTnode *&root, string s, string::iterator &siter)
{
    if(root == NULL && siter > s.end())
        return;
    else
    {
        root -> data = *siter, siter = siter + 2;
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

void Binary_tree::assign_inorder(BTnode *&root, string s, string::iterator siter)
{
    if(root == NULL || siter > s.end())
        return;
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
    if(root == NULL || siter > s.end())
        return;
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
    cout << root -> data << " ";
    traversal_preorder(root -> left);
    traversal_preorder(root -> right);
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
    string s;
    getline(cin,s);
    Binary_tree Tree;
    Tree.create_tree(s, 0);
    Tree.call_assign_preorder(Tree.root, s, 0);
    Tree.traversal_preorder(Tree.root);
    return 0;
}