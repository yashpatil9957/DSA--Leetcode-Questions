# include<bits/stdc++.h>
using namespace std;

 // Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

//BRTUE APPROACH - USING HASHMAP

class Solution {
public:
    int lengthOfCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return 0;

        int length = 0;
        unordered_map<ListNode*, int>hash;
        ListNode* temp = head;

        while(temp != NULL){
            if(hash.find(temp) != hash.end()){
                return length - hash[temp];
            }
            length++;
            hash[temp] = length;
            temp = temp->next;    
            
        }
        return 0;
    }
};

//OPTIMAL APPROACH - FLOYD'S ALGORITHM

 // Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

int lengthOfLoop(ListNode* head) {
    // Initialize slow and fast pointers
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        // If slow and fast meet, loop detected
        if (slow == fast) {
            // Count the length of the loop
            int length = 1;
            slow = slow->next;
            while(slow != fast){
                length++;
                slow=slow->next;
            }
            return length;
        }
    }
    return 0;
}