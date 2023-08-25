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

    void level_order(Node* root)
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

    int height(Node* root)
    {
        if(root==NULL)
        return 0;

        int l=height(root->left);
        int r=height(root->right);

        return max(l,r)+1;
    }

    int diameter_Approach_1(Node *root)
    {
        if(root==NULL)
        return 0;

        int op1=diameter_Approach_1(root->left);
        int op2=diameter_Approach_1(root->right);

        int op3=height(root->left)+height(root->right)+1;

        return max(op1,max(op2,op3));
    }


    pair<int,int>diameter_Approach_2(Node* root)
    {
        //first int for diameter,second int for height
        if(root==NULL)
        {
            pair<int,int>p=make_pair(0,0);
            return p;
        }

        pair<int,int>left=diameter_Approach_2(root->left);
        pair<int,int>right=diameter_Approach_2(root->right);

        int op1=left.first;
        int op2=right.first;

        int op3=left.second + right.second + 1;

        pair<int,int>ans;

        ans.first=max(op1,max(op2,op3));;
        ans.second=max(left.second,right.second) + 1;

        return ans;
    }
};

int main()
{

    Node* root=NULL;
    
    //1 2 -1 -1 3 4 -1 -1 -1 
    ques4  q;
    root=q.buildTree(root);
    cout<<"Tree Implemented..."<<endl;
    q.level_order(root);
   cout<<q.diameter_Approach_1(root);
   pair<int,int>p=q.diameter_Approach_2(root);
    cout<<p.first<<" "<<p.second<<endl;
    return 0;
}