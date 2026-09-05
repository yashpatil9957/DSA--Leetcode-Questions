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

//Brute approach - LL->Array->Reverse->LL

//Optimal Aprroach - DUMMY NODES CREATION AND REVERSE THE PART.
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (left == right)
            return head;

        ListNode dummy(0);
        dummy.next = head;

        // Find node before left
        ListNode* first = &dummy;

        for (int i = 1; i < left; i++) {
            first = first->next;
        }

        // First node of the reversing section
        ListNode* leftNode = first->next;

        // Move nodes to the front one by one
        ListNode* prev = NULL;
        ListNode* curr = first->next;
        
        for(int i=0; i<=right-left; i++){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next; 
        }
        //re-linking
        first->next = prev;
        leftNode->next = curr;

        return dummy.next;
    }
};