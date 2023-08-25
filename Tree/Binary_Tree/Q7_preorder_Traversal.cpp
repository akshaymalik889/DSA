#include<iostream>
#include<stack>

using namespace std;

class Node
{
    public:

    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};


class ques7
{
    public:

    Node* buildTree(Node* root)
    {
        int data;
        cout<<"enter data:";
        cin>>data;

        root=new Node(data);

        if(data==-1)
        return NULL;

        cout<<"enter data for left of "<<data<<endl;
        root->left=buildTree(root->left);
        
        cout<<"enter data for right of "<<data<<endl;
        root->right=buildTree(root->right);

        return root;
    }

    //Approach-1 -> Recursive
    void preorder_Recursive(Node* root)
    {
        if(root==NULL)
        return;

        cout<<root->data<<" ";
        preorder_Recursive(root->left);
        preorder_Recursive(root->right);
    }

    //Approach-2 -> Iterative
    void preorder_Iterative(Node* root)
    {
        if (root == NULL)
        return;
 
        // create an empty stack and push the root node
        stack<Node*> s;
        s.push(root);
 
        // loop till stack is empty
        while (!s.empty())
        {
            // pop a node from the stack and print it
            Node* temp = s.top();
            s.pop();
 
            cout << temp->data << " ";
 
            if (temp->right)
            s.push(temp->right);

            if (temp->left)
            s.push(temp->left);
        }
    }
};

int main()
{
    Node*root=NULL;
    
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    ques7 q;
    root=q.buildTree(root);
    cout<<"Tree Created..."<<endl;

    q.preorder_Recursive(root);
    cout<<endl;
    q.preorder_Iterative(root);

    return 0;
}