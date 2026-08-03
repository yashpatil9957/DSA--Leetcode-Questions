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

//Brute
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return head;

        ListNode* curr = head;
        int len = 0;

        while(curr != NULL){
            len++;
            curr = curr->next;
        }

        // Remove first node
        if(len == n){
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        int rem = len - n;
        curr = head;

        while(rem > 1){
            curr = curr->next;
            rem--;
        }

        ListNode* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;

        return head;
    }
};

//Optimal
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return head;

        ListNode* fast = head;
        ListNode* slow = head;

        int rem = n;
        while(rem != 0){
            fast = fast->next;
            rem--;
        }
        if(fast == NULL) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        //slow and fast pointer
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* del = slow->next;
        slow->next = slow->next->next;
        delete del; 
        return head;
    }
};