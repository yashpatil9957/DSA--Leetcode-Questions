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

//brute approach - using extra ds to store data and then inserting it in reverse order.
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //brute approach
        if(head == NULL || head->next==NULL) return head;

        ListNode* curr = head;
        vector<int>arr;

        while(curr != NULL){
            arr.push_back(curr->val);
            curr = curr->next;
        }

        curr = head;
        for(int i=arr.size()-1; i>=0; i--){
            curr->val = arr[i];
            curr = curr->next;
        }
        return head;
    }
};

//optimal approach - using multiple pointers (3) 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr != NULL){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};