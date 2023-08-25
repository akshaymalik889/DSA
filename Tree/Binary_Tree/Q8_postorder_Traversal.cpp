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


class ques8
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
    void postorder_Recursive(Node* root)
    {
        if(root==NULL)
        return;

        postorder_Recursive(root->left);
        postorder_Recursive(root->right);
        cout<<root->data<<" ";
    }

    //Approach-2 -> Iterative
    void postorder_Iterative(Node* root)
    {
        if (root == NULL)
        return;
 
        // create an empty stack and push the root node
        stack<Node*> s;
        s.push(root);

        //create another stack to store postorder traversal
        stack<int>post;
 
        // loop till stack is empty
        while (!s.empty())
        {
            // pop a node from the stack and print it
            Node* temp = s.top();
            s.pop();

            post.push(temp->data);
 
            if (temp->left)
            s.push(temp->left);

            if (temp->right)
            s.push(temp->right);
        }

        //print post order
        while(!post.empty())
        {
            cout<<post.top()<<" ";
            post.pop();
        }
    }
};

int main()
{
    Node*root=NULL;
    
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    ques8 q;
    root=q.buildTree(root);
    cout<<"Tree Created..."<<endl;

    q.postorder_Recursive(root);
    cout<<endl;
    q.postorder_Iterative(root);

    return 0;
}