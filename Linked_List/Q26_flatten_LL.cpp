#include <iostream>
using namespace std;
 
// Data structure to represent a special linked list node with
// an additional `down` pointer
struct Node
{
    int data;
    Node* next;
    Node* down;
 
    Node(int data)
    {
        this->data = data;
        this->next = this->down = nullptr;
    }
};
 
// Utility function to print a list with `down` and `next` pointers
void printOriginalList(Node* head)
{
    if (head == nullptr) {
        return;
    }
 
    cout << ' ' << head->data << ' ';
 
    if (head->down)
    {
        cout << "[";
        printOriginalList(head->down);
        cout << "]";
    }
 
    printOriginalList(head->next);
}
 
// Utility function to print a linked list
void printFlatenedList(Node* head)
{
    while (head)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
 
    cout << "null" << '\n';
}
 
// Recursive function to flatten a multilevel linked list
Node* flattenList(Node* head)
{
    // base case
    if (head == nullptr) {
        return nullptr;
    }
 
    // keep track of the next pointer
    Node* next = head->next;
 
    // process the down list first
    head->next = flattenList(head->down);
 
    // go to the last node
    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
    }
 
    // process the next list after the down list
    tail->next = flattenList(next);
 
    // return head node
    return head;
}

//Approach 2

Node* mergeTwoLists(Node* a, Node* b)
{
    
    Node *temp = new Node(0);
    Node *res = temp; 
    
    while(a != NULL && b != NULL)
    {
        if(a->data < b->data)
        {
            temp->down = a; 
            temp = temp->down; 
            a = a->down; 
        }

        else
        {
            temp->down = b;
            temp = temp->down; 
            b = b->down; 
        }
    }
    
    if(a)
    temp->down = a; 

    else temp->down = b; 
    
    return res -> down; 
    
}

Node *flatten(Node *root)
{
   
        if (root == NULL || root->next == NULL) 
            return root; 
  
        // recur for list on right 
        root->next = flatten(root->next); 
  
        // now merge 
        root = mergeTwoLists(root, root->next); 
  
        // return the root 
        // it will be in turn merged with its left 
        return root; 
}
 
int main()
{
    // create individual nodes and link them together later
    Node* one = new Node(1);
    Node* two = new Node(2);
    Node* three = new Node(3);
    Node* four = new Node(4);
    Node* five = new Node(5);
    Node* six = new Node(6);
    Node* seven = new Node(7);
    Node* eight = new Node(8);
    Node* nine = new Node(9);
    Node* ten = new Node(10);
    Node* eleven = new Node(11);
    Node* twelve = new Node(12);
    Node* thirteen = new Node(13);
    Node* fourteen = new Node(14);
    Node* fifteen = new Node(15);
 
    // set head node
    Node* head = one;
 
    // set next pointers
    one->next = four;
    four->next = fourteen;
    fourteen->next = fifteen;
    five->next = nine;
    nine->next = ten;
    seven->next = eight;
    eleven->next = thirteen;
 
    // set down pointers
    one->down = two;
    two->down = three;
    four->down = five;
    five->down = six;
    six->down = seven;
    ten->down = eleven;
    eleven->down = twelve;
 
    cout << "The original list is :" << '\n';
    printOriginalList(head);
 
    head = flattenList(head);
    cout << "\n\nThe flattened list is :" << '\n';
    printFlatenedList(head);
 
    return 0;
}
