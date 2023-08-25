#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//Approach -2
class Node
{
    public:
    int data;
    Node* prev;


    //constructor
    Node(int d)
    {
        this->data=d;
        this->prev=NULL;
    }
};


class ques22
{
    public:

    //APPROACH-1 using ARRAYS
    vector<int>factorial_AP_1(int n)
    {
        vector<int>ans;
        ans.push_back(1);

        for(int i=2;i<=n;i++)
        {
            int carry=0;

            for(int j=0;j<ans.size();j++)
            {
                int data=ans[j]*i+carry;
                ans[j]=data%10;
                carry=data/10;
            }

            while(carry!=0)
            {
                int data=carry%10;
                ans.push_back(data);
                carry=carry/10;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

    //APPROACH-2 USING linkedList
    Node*factorial_AP_2(int n)
    {
        Node*tail=new Node(1);

        for(int i=2;i<=n;i++)
        {
            Node*temp=tail;
            Node*prevNode=tail;
            int carry=0;

            while(temp!=NULL)
            {
                int data=temp->data*i+carry;
                temp->data=data%10;
                carry=data/10;
                prevNode=temp;
                temp=temp->prev;
            }

            while(carry!=0)
            {
                int data=carry%10;
                Node*newNode=new Node(data);
                prevNode->prev=newNode;
                carry=carry/10;
                prevNode=prevNode->prev;
            }
        }
        return tail;
    }
};

//For Approach-1
void printvector(vector<int>&ans)
{

    for(auto i:ans)
    cout<<i<<" ";
}

//For Approach -2

//we print linked list in reverse using recursion
void printLinkedList_reverse(Node*tail)
{
    if(tail==NULL)
    return;

    printLinkedList_reverse(tail->prev);
    cout<<tail->data<<" ";
}



int main()
{
    int n;
    cout<<"enter value of n:";
    cin>>n;

    ques22 q;
    vector<int>ans=q.factorial_AP_1(n);
    printvector(ans);
    // Node*tail=q.factorial_AP_2(n);
    // printLinkedList_reverse(tail);
    return 0;

}