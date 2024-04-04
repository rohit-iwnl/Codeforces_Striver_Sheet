#include <bits/stdc++.h>
using namespace std;


class Node{
    public:
    int val;
    Node* prev;
    Node* next;

    public:
    Node(int data){
        val = data;
        prev = nullptr;
        next = nullptr;
    }

    public:
    Node(int data, Node* next1){
        val = data;
        prev = nullptr;
        next = next1;
    }

    public:
    Node(int data,Node* next1, Node* prev1){
        val = data;
        next = next1;
        prev = prev1;
    }
};

Node* convertArrayToList(vector<int> arr){
    Node* head = new Node(arr[0]);

    Node* temp = head;

    for(int i=1; i<arr.size();i++){
        Node* newNode = new Node(arr[i],nullptr,temp);
        temp->next = newNode;
        temp = newNode;
    }

    return head;
}

Node* deleteHead(Node* head){
    if(head == NULL)return NULL;
    if(head->next == nullptr){
        delete(head);
        return NULL;
    }

    Node* temp = head;
    head = head->next;
    head->prev = nullptr;
    temp->next = nullptr;
    free(temp);

    return head;
}

void printLL(Node* head){
    if(head==NULL || head->next == nullptr){
        return;
    }

    Node* temp = head;
    while(temp!=NULL){
        cout << temp->val << "/";
        temp = temp->next;
    }
    cout<<"Done"<<endl;
}

Node* deleteTail(Node* head){
    if(head == NULL || head->next == NULL){
        free(head);
        return NULL;
    }

    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }

    temp->prev->next = nullptr;
    free(temp);
    return head;
}

Node* reverseList(Node* head){
    if(head == NULL || head->next == nullptr){
        return head;
    }

    Node* previous = NULL;
    Node* current = head;
    while(current!=NULL){
        previous = current->prev;
        current->prev = current->next;
        current->next = previous;
        current = current->prev;
    }

    return previous->prev;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    Node* head = convertArrayToList(arr);
    printLL(head);
    head = deleteHead(head);
    printLL(head);
    head = reverseList(head);
    printLL(head);
}
