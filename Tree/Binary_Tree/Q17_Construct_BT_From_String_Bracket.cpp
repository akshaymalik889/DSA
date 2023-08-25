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

class ques17
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

    int i=0;
    Node* GenerateTree(string str)
    {
        string no;
        while(i <= str.size()-1 && !(str[i] == '(' || str[i] == ')'))
        {
            no.push_back(str[i]);
            i++;
        }

        //Node* root = new Node(atoi(no.c_str()));
        Node* root=new Node(stoi(no));

        // Left child if is there according to string
        if(str[i] == '(')
        {
            i++;
            root->left = GenerateTree(str);
            i++;
        }

        // Right child optionally if exist
        if(str[i] == '(')
        {
            i++;
            root->right = GenerateTree(str);
            i++;
        }   

        return root;
    }

    // function to construct tree from string
    Node *treeFromString(string str)
    {
        if(str.size()==0)  
        return NULL;

        return GenerateTree(str);
    }
};

int main()
{
   Node* root=NULL;
    
    ques17 q;
    //root=q.buildTree(root);

    //cout<<"Tree Created..."<<endl;

    string str="4(2(3)(1))(6(5))";
    root=q.treeFromString(str);
    q.levelOrder(root);

    return 0;

}