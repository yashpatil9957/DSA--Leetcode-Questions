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
 

//Brute approach - extra space to store odd-even node and then override original LL
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        if(head == NULL || head->next == NULL)
            return head;

        vector<int> odd;
        vector<int> even;

        ListNode* curr = head;
        int pos = 1;

        // Store values
        while(curr != NULL) {
            if(pos % 2 == 1)
                odd.push_back(curr->val);
            else
                even.push_back(curr->val);

            curr = curr->next;
            pos++;
        }

        // Rewrite odd values
        curr = head;
        for(int x : odd) {
            curr->val = x;
            curr = curr->next;
        }

        // Rewrite even values
        for(int x : even) {
            curr->val = x;
            curr = curr->next;
        }

        return head;
    }
};

//Optimal approach - rearranging the connections
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* oddHead = new ListNode(-1), *odd = oddHead;
        ListNode* evenHead = new ListNode(-1), *even = evenHead;

        ListNode* curr = head;
        bool oddNode = true;

        while(curr != NULL){
            if(oddNode) {
                odd->next = curr;
                odd = curr;
                oddNode = false;
            }
            else{
                even->next = curr;
                even = curr;
                oddNode = true;
            }
            curr = curr->next;
        }
        even->next = NULL;
        odd->next = evenHead->next;
        return oddHead->next;
    }
};