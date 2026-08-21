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

//Brute approach:
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0)
            return head;

        while (k--) {
            ListNode* temp = head;

            while (temp->next->next != nullptr) {
                temp = temp->next;
            }

            ListNode* last = temp->next;

            temp->next = nullptr;

            last->next = head;  // ⭐ missing line
            head = last;
        }

        return head;
    }
};

//Optimal approach:
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0)
            return head;

        // Find length and tail
        int n = 1;
        ListNode* tail = head;

        while (tail->next != nullptr) {
            tail = tail->next;
            n++;
        }

        k %= n;

        if (k == 0)
            return head;

        // Make circular
        tail->next = head;

        // Move to new tail
        int steps = n-k;
        while(steps!=0){
            tail = tail->next;
            steps--;
        }
        // New head
        head = tail->next;

        // Break circular link
        tail->next = nullptr;

        return head;
    }
};