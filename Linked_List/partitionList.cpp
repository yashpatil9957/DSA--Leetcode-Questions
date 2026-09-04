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

//Brute approach - Using extra space - array!

//Optimal Aprroach - DUMMY NODES CREATION AND RELINKING.
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* curr = head;
        ListNode* dummy1 = new ListNode(-1);
        ListNode* dummy2 = new ListNode(-1);
        ListNode* first = dummy1;
        ListNode* second = dummy2;
        
        while(curr){
            if(curr->val < x){
                first->next = curr;
                first = first->next;
            }
            else{
                second->next = curr;
                second = second->next;
            }

            curr = curr->next;
        }
        first->next = dummy2->next;
        second->next = NULL;
        
        return dummy1->next;
    }
};