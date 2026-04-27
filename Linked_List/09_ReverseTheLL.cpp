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
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr != NULL){
            ListNode* front = curr->next;  //important to observe why not and end?
            curr->next = prev;
            prev = curr;
            curr = front;  
            //front = curr->next;     //gives runtime error if used here like this!!      
        }
        return prev;
    }
};