#include <bits/stdc++.h>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//Brute approach
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL) return NULL;

        ListNode* curr = head;
        int len=0;
        while(curr != NULL){
            len++;
            curr=curr->next;
        }
        //reach node previous to deleting node
        curr=head;
        int rem = len/2;
        while(rem>1){
            rem--;
            curr=curr->next;
        }
        ListNode* del = curr->next;
        curr->next = curr->next->next;
        delete del;
        return head;

    }
};

//Optimal approach-slow and fast pointer
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL) return NULL;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast != NULL && fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast=fast->next->next;
        }
        ListNode* del = prev->next;
        prev->next=prev->next->next;
        delete del;
        return head;

    }    
};