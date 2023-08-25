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

class ques4
{
    public:

    Node* buildTree(Node* root,int d)
    {
        

        if(root==NULL)
        {
            root=new Node(d);
            return root;
        }
        else if(d < root->data)
        root->left=buildTree(root->left,d);

        else
        root->right=buildTree(root->right,d);

        return root;
    }

    void inputData(Node* &root)
    {
        int data;
        cout<<"enter data for BST.."<<endl;
        cin>>data;

        while(data!=-1)
        {
            root=buildTree(root,data);
            cin>>data;
        }
    }

    void levelOrder(Node* root)
    {
        if(root==NULL)
        return ;

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

    pair<int,int>inorder_p_s(Node* root,int key)
    {
        int pred=-1;
        int succ=-1;
        Node* temp=root;

        //finding key and also update pred/succ till current node
        while(temp->data!=key)
        {
            if(temp->data>key)
            {
                succ=temp->data;
                temp=temp->left;
            }

            else
            {
                pred=temp->data;
                temp=temp->right;
            }
        }

        //finding pred && succ

        //pred-> finding largest value from left subtree
        Node*leftTree=temp->left;
        
        while(leftTree!=NULL)
        {
            pred=leftTree->data;
            leftTree=leftTree->right;
        }

        //succ-> finding smallest value from right subtree
        Node* rightTree=temp->right;
        
        while(rightTree!=NULL) //handling NULL case also 
        {
            succ=rightTree->data;
            rightTree=rightTree->left;
        }

        pair<int,int>p=make_pair(pred,succ);
        return p;
    }

};


int main()
{
    Node* root=NULL;

    ques4 q;
    q.inputData(root);
    cout<<"Tree Created.."<<endl;
    //10 8 21 7 27 5 4 3 -1

    q.levelOrder(root);
    pair<int,int>p=q.inorder_p_s(root,21);
    cout<<"predecessor="<<p.first<<" successor="<<p.second<<endl;

    return 0;
}