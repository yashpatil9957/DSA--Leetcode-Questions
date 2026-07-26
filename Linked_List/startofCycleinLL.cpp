#include <bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//Brute sloution - set to keep track of visited nodes
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> mpp;
        if(head == NULL || head->next == NULL) return NULL;

        ListNode* curr = head;
        while(curr != NULL){
            if(mpp.find(curr) != mpp.end()){
                return curr;
            }
            mpp.insert(curr);
            curr = curr->next;
        }
        return NULL;
    }
};
 
//Optimal solution - slow and fast pointer:First detect the cycle and redirect one of the pointer to head and move each pointer by each step, at every step check slow == fast
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return NULL;

        ListNode* slow = head;
        ListNode* fast = head;

        //1.Detect the loop first
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            //2.Reset the one pointer to head
            if(slow == fast){
                slow = head;

                while(fast != slow){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
           
        }        
        return NULL;
    }
};