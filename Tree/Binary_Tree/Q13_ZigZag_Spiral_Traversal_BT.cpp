#include<iostream>
#include<queue>
#include<stack>
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

class ques13
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

    vector<int> zigzag_traversal_Approach_1(Node* root)
    {
        vector<int>v;
    
        if(root==NULL)
        return v;

        //true means ->left to right;
        bool flag=true;

        queue<Node*>q;
        q.push(root);
        q.push(NULL);

        stack<int>s;
    

        while(!q.empty())
        {
            Node*temp=q.front();
            q.pop();

            if(temp==NULL)
            {
                if(flag==false)
                {
                    while(!s.empty())
                    {
                        v.push_back(s.top());
                        s.pop();
                    }
                }

                flag=!flag;

                if(!q.empty())
                q.push(NULL);
            }

            else
            {
                if(flag==true)
                v.push_back(temp->data);

                else
                {
                    s.push(temp->data);
                }   

                if(temp->left)
                q.push(temp->left);

                if(temp->right)
                q.push(temp->right);
            }
        }
        return v;

    }

    void traverse_vector(vector<int>v)
    {
        for(auto i:v)
        {
            cout<<i<<" ";
        }   
    }

    //without stack
    vector<int>zigzag_traversal_Approach_2(Node* root)
    {
        vector<int>v;
        if(root==NULL)
        return v;

        queue<Node*>q;
        q.push(root);

        //true means left to right
        bool flag=true;

        while(!q.empty())
        {
            int size=q.size();
            vector<int>ans(size);

            //level process

            for(int i=0;i<size;i++)
            {
                Node* temp=q.front();
                q.pop();

                //normal insert or reverse insert
                int index=flag ? i : size - i- 1;
                ans[index]=temp->data;

                if(temp->left)
                q.push(temp->left);
                if(temp->right)
                q.push(temp->right);
            }
            //change flag

            flag=!flag;

            for(auto i:ans)
            v.push_back(i);
        }

        return v;
    }

};

int main()
{
    Node* root=NULL;

    ques13 q;
    
    root=q.buildTree(root);
    cout<<"Tree Created..."<<endl;

    //1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1



    q.levelOrder(root);
    vector<int>ans=q.zigzag_traversal_Approach_1(root);
    q.traverse_vector(ans);




    return 0;

}