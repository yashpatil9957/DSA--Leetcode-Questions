#include <bits/stdc++.h>
using namespace std;

 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

//BRUTE SOLUTION - Count the length and return length/2 number element!

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* curr = head;
        //counting the elements in LL
        int count = 0;
        while(curr != NULL){
            count++;
            curr = curr->next;
        }

        curr = head;
        //finding the mid node
        count = (count)/2;
        while(count != 0){
            curr = curr->next;
            count--;
        }
        return curr;

    }
};
 
//OPTIMAL SOUTION - Tortoise and Hair algorithm!
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        //Tortoise-Hair algorithm - fast and slow pointer approach
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};