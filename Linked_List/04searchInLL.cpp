// Q. length of the linked list

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

// Leetcode type solution - function returning....

bool searchInLL(Node* head, int val){
    Node* curr = head;

    while(curr != NULL){
        if(curr->data == val){
            return true;
        }
        curr = curr->next;
    }
    return false;
}