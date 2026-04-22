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

int lengthOfLL(Node* head){
    Node* curr = head;
    int length = 0;

    //edge cases!

    while (curr != NULL)
    {
        length++;
        curr = curr->next;
    }
    return length;
}