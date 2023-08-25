#include<iostream>
#include<queue>

using namespace std;

class Node
{
    public:
    int data;
    Node* left=NULL;
    Node* right=NULL;

    Node(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

class ques0
{
    public:
    Node*  build_tree(Node* root)
    {
        queue<Node*>q;
        int data;
        cout<<"enter data for root Node:";
        cin>>data;

        root=new Node(data);

        q.push(root);

        while(!q.empty())
        {
            Node* temp=q.front();
            q.pop();

            cout<<"enter data  for left of "<<temp->data<<endl;
            int leftdata;
            cin>>leftdata;

            if(leftdata!=-1)
            {
                temp->left=new Node(leftdata);
                q.push(temp->left);
            }

            cout<<"enter data  for right of "<<temp->data<<endl;
            int rightdata;
            cin>>rightdata;

            if(rightdata!=-1)
            {
                temp->right=new Node(rightdata);
                q.push(temp->right);
            }
        }
        return root;
    }

    // //function to print only
    // void level_order(Node* root)
    // {
    //     if(root==NULL)
    //     return;

    //     queue<Node*>q;

    //     q.push(root);
    //     q.push(NULL);

    //     while(!q.empty())
    //     {
    //         Node* temp=q.front();
    //         q.pop();

    //         if(temp==NULL)
    //         {
    //             cout<<endl;

    //             if(!q.empty())
    //             q.push(NULL);
    //         }
            
    //         else
    //         {
    //             cout<<temp->data<<" ";
                
    //             if(temp->left)
    //             q.push(temp->left);
                
    //             if(temp->right)
    //             q.push(temp->right);
    //         }
    //     }
    // }
};


int main()
{
    Node* root=NULL;

    ques0 q;
    root=q.build_tree(root);

    cout<<"Tree implemented..."<<endl;

    // q.level_order(root);
    
    return 0;
    

}