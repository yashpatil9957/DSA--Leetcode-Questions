// Q. Insert at the head of linked list

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    //constructor to assign the values in created node........
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

// Leetcode type solution - function returning

Node* insertHead(Node* head, int val){
    Node* newNode = new Node(val, head);
    return newNode;
}
