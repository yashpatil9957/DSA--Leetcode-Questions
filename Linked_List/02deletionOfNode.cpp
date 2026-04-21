// Q. delete the last node of linked list

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    //constructor to assign the values in created node
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

//Main solution

Node* deleteTail(Node* head){
    //edge cases
    if(head == NULL || head->next == NULL){
        delete head;
        return NULL;
    }

    Node* curr = head; //took reference

    while(curr->next->next != NULL){
        curr = curr->next;
    }

    delete curr->next;
    curr->next = NULL;

    return head;
}