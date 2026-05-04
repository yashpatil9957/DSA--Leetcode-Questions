#include<bits/stdc++.h>
using namespace std;


 // Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

//Brute solution :- hash set

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return NULL;

        unordered_set<ListNode*>hash;
        ListNode* temp = head;
        while(temp != NULL){
            if(hash.find(temp) != hash.end()) return temp;
            hash.insert(temp);
            temp = temp->next;
        }
        return NULL;
    }
};

//Optimal approach - DETECT AND REINITIALISE FAST POINTER

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
                fast = head;

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