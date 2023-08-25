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


class ques6
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
    void inorder_Recursive(Node* root)
    {
        if(root==NULL)
        return;

        inorder_Recursive(root->left);
        cout<<root->data<<" ";
        inorder_Recursive(root->right);
    }

    //Approach-2 -> Iterative
    void inorder_Iterative(Node* root)
    {
        // create empty stack
        stack<Node*> stack;
 
        // start from the root node
        Node* temp = root;
 
        // if the current node is null and the stack is also empty, we are done
        while (!stack.empty() || temp != NULL)
        {
            if (temp != NULL)
            {
                stack.push(temp);
                temp = temp->left;
            }

            else 
            {
                temp = stack.top();
                stack.pop();
                cout << temp->data << " ";
 
                temp = temp->right;
            }
        }
    }
};

int main()
{
    Node*root=NULL;
    
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    ques6 q;
    root=q.buildTree(root);
    cout<<"Tree Created..."<<endl;

    q.inorder_Recursive(root);
    cout<<endl;
    q.inorder_Iterative(root);

    return 0;
}