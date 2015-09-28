#include<iostream>
using namespace std;

template <class T>
struct Node 
{
    T data;
    Node *next;
    Node(int x): data(x), next(NULL){}
};

template <class T>
class Stack 
{
private:
    Node<T> *head;
    int sizeOfStack;
public:
    Stack(): head(NULL), sizeOfStack(0){}
    ~Stack() 
    {
        while(head != NULL)
        {
            Node<T> *p = head;
            head = head->next;
            delete p;
        }
    }

    int size()
    {
        return sizeOfStack;
    }
    
    bool empty()
    {
        return size() == 0;
    }

    void push(T x)
    {
        Node<T> *newNode = new Node<T>(x);
        newNode->next = head;
        head = newNode;
        sizeOfStack++;
    }

    T pop()
    {
        T temp;
    if(empty())
        return -1;
    else
    {
        temp = head -> data;
        Node<T> *p = head;
        head = head -> next;
        delete p;
        --sizeOfStack;
        return temp;
    }
    }
};

int main()
{
    Stack<int> st;
    int arr[] = {
        8, 2, 1, 2, 5, 9, 3
    };
    for(int i = 0; i < 4; ++i)
        st.push(arr[i]);
    cout<<"size:"<<st.size()<<endl;
    //st.pop();
    cout<<st.pop()<<st.pop()<<endl;
    
    return 0;
}