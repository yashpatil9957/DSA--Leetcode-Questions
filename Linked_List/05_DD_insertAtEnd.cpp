//Q. Insert node at end of Dobly linked list

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

//Q. Code for inserting node at last of DLL

Node* insertAtEnd(Node* head, int val){
    Node* curr = head;
    Node* last = new Node(val);
    
    if(head == NULL){
        return last;
    }

    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = last;
    last->prev = curr;

    return head;
}
