#include <bits/stdc++.h>
#include <vector>

using namespace std;

struct Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node* convertArrayToLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);
        temp->next = newNode;
        temp = newNode;
    }

    return head;
}

Node* insertFirst(Node* head, int newValue){
    Node* newNode = new Node(newValue);
    if(head==nullptr) return newNode;
    else{
        Node* temp = head;
        newNode -> next = head;
    }
    return newNode;
}

void printLinkedList(Node* head){
    Node* temp = head;
    while(temp!=nullptr){
        cout << temp->data << " // ";
        temp = temp->next;
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = convertArrayToLL(arr);
    Node* newHead = insertFirst(head,0);
    printLinkedList(head);
} 