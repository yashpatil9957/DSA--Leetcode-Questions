//Q. delete last node of Doubly linked list

#include <bits/stdc++.h>
using namespace std;

//Doubly linked list defination:
class Node{
public:
    int data;
    Node* next;
    Node* prev;

    //constructor to assign the values
    Node(int data1, Node* next1 = nullptr, Node* prev1 = nullptr){
        data = data1;
        next = next1;
        prev = prev1;
    }

};

// Code for deleting last node of DLL

Node* deleteLastNode(Node* head){
    Node* curr = head;

    if(head == NULL) return NULL;
    if(head->next == NULL) {
        delete head;
        return NULL;
    }

    while(curr->next->next != NULL){
        curr = curr->next;
    }

    Node* last = curr->next;
    curr->next = NULL;
    delete last;

    return head;
}