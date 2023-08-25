#include<iostream>
#include<queue>
#include<vector>
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

class ques15
{
    public:
    Node* buildTree(Node* root)
    {
        int data;
        cout<<"enter data:";
        cin>>data;

        root=new Node(data);

        if(data==-1)
        {
            return NULL;
        }

        cout<<"enter data for left of "<<data<<endl;
        root->left=buildTree(root->left);

        cout<<"enter data for right of "<<data<<endl;
        root->right=buildTree(root->right);

        return root;
    }

    void levelOrder(Node * root)
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

    vector<int> diagonal_Traversal(Node* root)
    {
        queue<Node*>q;
        vector<int>ans;

        if(root==NULL)
        return ans;

        q.push(root);

        while(!q.empty())
        {
            Node* temp=q.front();
            q.pop();

            while(temp!=NULL)
            {
                //if left present then push in queue for traverse next diagonal
                if(temp->left)
                q.push(temp->left);
                
                ans.push_back(temp->data);

                //traverse right only
                temp=temp->right;
            }
            cout<<endl;
        }
        return ans;   
    }


    void traverse_vector(vector<int>v)
    {
        for(auto i:v)
        {
            cout<<i<<" ";
        }   
    }

};

int main()
{
    Node* root=NULL;

    ques15 q;
    
    root=q.buildTree(root);
    cout<<"Tree Created..."<<endl;

    //1 2 4 -1 -1 5 -1 -1 3 -1 -1
    //1 2 -1 3 -1 -1 -1 -1
    //8 3 1 -1 -1 -1 10 6 4 -1 -1 7 -1 -1 14 13 -1 -1 -1



    q.levelOrder(root); 
    vector<int>ans=q.diagonal_Traversal(root);

    q.traverse_vector(ans);




    return 0;

}