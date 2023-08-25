#include<iostream>
#include<queue>
using namespace std;


class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

class ques18
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

    void levelOrder(Node* root)
    {
        if(root==NULL)
        return;

        queue<Node*>q;
        q.push(root);
        q.push(NULL);

        while(!q.empty())
        {
            Node* temp=q.front();
            q.pop();

            if(temp==NULL)
            {
                cout<<endl;

                if(!q.empty())
                q.push(NULL);
            }

            else
            {
                cout<<temp->data<<" ";

                if(temp->left)
                q.push(temp->left);

                if(temp->right)
                q.push(temp->right);
            }
        }
    }

    void solve(Node* root,Node* &head,Node* &prev,int &flag)
    {
        if(root==NULL)
        return;
        
        //doing inorder ->left call
        solve(root->left,head,prev,flag);
        
        //root node 
        //means first node
        if(flag==0)
        {
            flag=1;
            head=root;
            prev=root;
        }
        else
        {
            prev->right=root;
            prev->right->left=prev;
            prev=prev->right;
        }
        
        //right call
        solve(root->right,head,prev,flag);
    }

    Node * bToDLL(Node *root)
    {
        Node* head=NULL;
        Node* prev=NULL;
        
        //two cases 1.first node. 2.other nodes
        int flag=0;
        
        solve(root,head,prev,flag);
        return head;
    }

    //traverse doubly linked list 
    //we treat prev=left  and next=right
    void traverseList(Node* head)
    {
        Node* temp=head;

        while(temp!=NULL)
        {
            if(temp->left==NULL)
            cout<<"NULL->";
            else
            cout<<temp->left->data<<"->";

            cout<<temp->data<<"->";

            if(temp->right==NULL)
            cout<<"NULL ";
            else
            cout<<temp->right->data<<" ";

            temp=temp->right;
        }
    }


};

int main()
{
   Node* root=NULL;
    
    ques18 q;
    root=q.buildTree(root);
    //10 12 25 -1 -1 30 -1 -1 15 36 -1 -1 -1

    cout<<"Tree Created..."<<endl;

    q.levelOrder(root);
    Node* head=q.bToDLL(root);

    cout<<"doubly linked list"<<endl;
    q.traverseList(head);

    return 0;

}