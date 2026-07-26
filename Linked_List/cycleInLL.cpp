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

//Brute approach - store the addresses of visited nodes in SET and simultaneously check curr node address in SET as well

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> mpp;
        if(head == NULL || head->next == NULL) return false;

        ListNode* curr = head;
        while(curr != NULL){
            if(mpp.find(curr) != mpp.end()){
                return true;
            }
            mpp.insert(curr);
            curr = curr->next;
        }
        return false;
    }
};

//Optimal approach - slow and fast pointer algorithm
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return false;

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) return true;
        }
        return false;
    }
};