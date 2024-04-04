#include <bits/stdc++.h>

using namespace std;
class Node
{
public:
    int data;
    Node *next;

public:
    Node(int value, Node *next1)
    {
        data = value;
        next = next1;
    }

public:
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

Node *convertArrayToLL(vector<int> arr)
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

void printLinkedList(Node *head)
{
    if (head == nullptr)
        return;
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << ",";
        temp = temp->next;
    }
    cout << "Done" << endl;
}

// Delete First
Node *deleteFirst(Node *head)
{
    if (head == NULL)
        return head;
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

// delete last
Node *deleteTail(Node *head)
{
    if (head == NULL || head->next == nullptr)
    {
        return NULL;
    }

    Node *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = nullptr;

    return head;
}

Node *reverseLinkedList(Node *head)
{
    Node *newHead = NULL;
    while (head != NULL)
    {
        Node *next = head->next;
        head->next = newHead;
        newHead = head;
        head = next;
    }

    return newHead;
}

Node *findMiddle(Node *head)
{
    if (head == NULL || head->next == nullptr)
        return head;
    Node *slow = head;
    Node *fast = head;
    fast = head->next;

    while (fast != NULL && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

Node *mergeList(Node *l1, Node *l2)
{
    Node *dummy = new Node(-1);
    Node *temp = dummy;

    while (l1 != NULL && l2 != NULL)
    {
        if (l1->data < l2->data)
        {
            temp->next = l1;
            temp = temp->next;
            l1 = l1->next;
        }
        else
        {
            temp->next = l2;
            temp = temp->next;
            l2 = l2->next;
        }
    }

    if (l1)
        temp->next = l1;
    else
        temp->next = l2;

    return dummy->next;
}

Node *sortList(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *middle = findMiddle(head);

    Node *rightHead = middle->next;
    middle->next = nullptr;
    Node *leftHead = head;

    leftHead = sortList(leftHead);
    rightHead = sortList(rightHead);

    return mergeList(leftHead, rightHead);
}

int main()
{
    vector<int> arr = {5, 2, 3, 10, 12, 15, 17};

    Node *head = convertArrayToLL(arr);
    printLinkedList(head);

    sortList(head);

    printLinkedList(head);
}