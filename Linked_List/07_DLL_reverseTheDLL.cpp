//Q. Reverse the given Doubly linked list

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

// Code for reversing DLL

//Brute approach - O(n)+O(n)=O(2n)
Node* reverseDLL(Node* head){
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* curr = head;
    stack<int> st;

    while(curr != NULL){
        st.push(curr->data);
        curr = curr->next;
    }

    curr = head;
    while(curr != NULL){
        curr->data = st.top();
        st.pop();
        curr = curr->next;
    }

    return head;
}

//Optimal approach - O(n)
Node* reverseDLL(Node* head){
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* curr = head;

    while(curr != NULL){
        Node* temp = curr->next;    //this track is really important!!
        curr->next = curr->prev;
        curr->prev = temp;

        head = curr;    //ultimately head will be last node therefore keeping track
        curr = temp;
    }

    return head;
}
