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

//Brute approach - store the traversed node in set of LL1 and check LL2's node in set.
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curr1 = headA;
        ListNode* curr2 = headB;

        unordered_set<ListNode*> check;

        while(curr1 != NULL){
            check.insert(curr1);
            curr1 = curr1->next;
        }

        while(curr2 != NULL){
            if(check.find(curr2) != check.end()){
                return curr2;
            }
            curr2 = curr2->next;
        }
        return NULL;
    }
};

//Optimal approach - slow and fast pointer
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* fast = headA;
        ListNode* slow = headB;

        while(fast != slow){
            if(fast == NULL) fast=headB;
            else fast = fast->next;

            if(slow == NULL) slow=headA;
            else slow = slow->next; 
            
        }
        return fast;
    }
};
