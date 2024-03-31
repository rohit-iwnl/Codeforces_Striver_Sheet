#include <bits/stdc++.h>

using namespace std;
class Node{
    public:
        int data;
        Node* next;

    public:
        Node(int value,Node* next1){
            data = value;
            next = next1;
        }

    public:
        Node(int value){
            data = value;
            next = nullptr;
        }
};

Node* convertArrayToLL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i=1; i < arr.size(); i++){
        Node* newNode = new Node(arr[i]);
        temp->next = newNode;
        temp = newNode;
    }

    return head;
}

void printLinkedList(Node* head){
    if(head==nullptr) return;
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << ",";
        temp = temp->next;
    }
    cout<<"Done"<<endl;

}

//Delete First
Node* deleteFirst(Node* head){
    if(head==NULL) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}   


int main(){
    vector<int> arr={1,2,3,4,5};

    Node* head = convertArrayToLL(arr);

    printLinkedList(head);

    head = deleteFirst(head);
    printLinkedList(head);
}