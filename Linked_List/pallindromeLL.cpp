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

//BRUTE approach - using stack
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL) return false;
        if(head->next == NULL) return true;

        ListNode* curr = head;
        stack<int> st;
        
        while(curr != NULL){
            st.push(curr->val);
            curr = curr->next;
        }
        curr = head;
        while(curr != NULL){
            if(curr->val != st.top()) 
                return false;
            st.pop();
            curr = curr->next;
        }
        return true;
    }
};

//OPTIMAL approach - reversing the LL from mid and comparing each val from start and end
class Solution {
public:
///helper function
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }    

    //Actual function
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;

        ListNode* slow = head;
        ListNode* fast = head;
        //find mid
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        //Reverse the second half
        ListNode* newHead = reverse(slow);
        ListNode* curr = head;
        //comparing both pointers from start and end
        while(newHead != NULL){
            if(newHead->val != curr->val) return false;
            newHead = newHead->next;
            curr = curr->next;
        }
        return true;
    }
};