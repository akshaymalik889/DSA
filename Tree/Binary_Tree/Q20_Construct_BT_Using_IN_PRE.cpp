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

class ques20
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

    int findPosition(int in[],int element,int n)
    {
        for(int i=0;i<n;i++)
        {
            if(in[i]==element)
            return i;
        }
        return -1;
    }

    Node* solve(int in[],int pre[],int preIndex,int inorderStart,int inorderEnd,int n)
    {
        //base case->if preorder array full traverse or inorder start > inorder end
        if(preIndex>=n || inorderStart>inorderEnd)
        return NULL;

        //find element of preorder
        int element=pre[preIndex];

        //increase index after taking element
        preIndex++;

        //create New Node
        Node* root=new Node(element);

        //find element pos in inorder array
        int pos=findPosition(in,element,n);

        //bcoz in inorder for left we start from starting to till position of element 
        root->left=solve(in,pre,preIndex,inorderStart,pos-1,n);
        
        //for right call we place from pos+1 to inorder end
        root->right=solve(in,pre,preIndex,pos+1,inorderEnd,n);
        
        return root;
    }

    void postOrderTraversal(Node* root)
    {
        if(root==NULL)
        return ;

        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout<<root->data<<" ";
    }


    Node*BT_inOrder_preorder()
    {   
        int in[]={1,6,8,7};
        int pre[]={1,6,7,8};
        int n=4;
        int preIndex=0;
    
        //inorder array,preorder array,preorderStartindex,inorderStartindex,inorderLastindex,size
        Node*ans=solve(in,pre,preIndex,0,n-1,n);
        return ans;
    }


};

int main()
{
    //Node* root=NULL;

    ques20 q;
    
    // root=q.buildTree(root);
    // cout<<"Tree Created..."<<endl;

    //1 2 4 -1 -1 5 -1 -1 3 -1 -1
    //1 2 -1 3 -1 -1 -1 -1
    //8 3 1 -1 -1 -1 10 6 4 -1 -1 7 -1 -1 14 13 -1 -1 -1


    Node* root=q.BT_inOrder_preorder();
    
    //printing post order traversal
    q.postOrderTraversal(root);
    
    return 0;

}