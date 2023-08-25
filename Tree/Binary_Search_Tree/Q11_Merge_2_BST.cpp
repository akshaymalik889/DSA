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

class ques11
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

    void inorder_BST(Node* root,vector<int>&v)
    {
        if(root==NULL)
        return ;

        inorder_BST(root->left,v);
        v.push_back(root->data);
        inorder_BST(root->right,v);  
    }

    vector<int>mergeArray(vector<int>v1,vector<int>v2)
    {
        vector<int>v;
        int i,j;
        for(i=0,j=0;i<v1.size() && j<v2.size();)
        {
            if(v1[i]<v2[j])
            {
                v.push_back(v1[i]);
                i++;
            }
            else
            {
                v.push_back(v2[j]);
                j++;
            }
        }
        while(i<v1.size())
            v.push_back(v1[i++]);

        while(j<v2.size())
            v.push_back(v2[j++]);
        

        // for(auto i:v)
        // {
        //     cout<<i<<" ";
        // }
        
        return v;

    }

    Node* inorder_to_BST(vector<int>inorder,int start,int end)
    {
        if(start>end)
        return NULL;

        int mid=start+((end-start)/2);
        Node* newRoot=new Node(inorder[mid]);
        
        newRoot->left=inorder_to_BST(inorder,start,mid-1);
        newRoot->right=inorder_to_BST(inorder,mid+1,end);

        return newRoot;
    }

    Node* merge_2_BST_Approach_1(Node* root1,Node* root2)
    {
        //step 1 find inorder for both both BST
        vector<int>v1;
        vector<int>v2;
        inorder_BST(root1,v1);
        inorder_BST(root2,v2);

        //Step 2: merge two inorders(arrays)
        vector<int>merge=mergeArray(v1,v2);

        //step 3:inorder 2 BST
        Node*newRoot=inorder_to_BST(merge,0,merge.size()-1);
        return newRoot;
    }

};


int main()
{
    Node* root1=NULL;
    Node* root2=NULL;

    ques11 q;
    q.inputData(root1);
    cout<<"Tree1 Created.."<<endl;
    //50 40 60 70 -1

    q.inputData(root2);
    cout<<"Tree2 Created.."<<endl;
    //55 45 65 35 47 -1

    q.levelOrder(root1);
    q.levelOrder(root2);

    Node* newRoot=q.merge_2_BST_Approach_1(root1,root2);

    q.levelOrder(newRoot);

    return 0;
}