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

//Brute soln: LL->Array->LL
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> vec;
        //LL to array
        ListNode* curr = head;
        while(curr){
            vec.push_back(curr->val);
            curr = curr->next;
        }
        //reverse in k group
        int left = 0;
        for(int i=0; i<vec.size(); i++){
            if((i+1) % k == 0){
                reverse(vec.begin()+left, vec.begin()+(i+1));
                left=i+1;
            }
        }
        //array to LL
        curr = head;
        for(int i=0; i<vec.size(); i++){
            curr->val = vec[i];
            curr = curr->next;
        }
        return head;
    }
};

//Optimal: Without using extra space - linking the nodes
class Solution {
public:
    ListNode* getKthNode(ListNode* temp, int k){
        for(int i=1; i<k; i++){
            temp = temp->next;
            if(temp == NULL) return temp;
        }
        return temp;
    } 

    ListNode* reverseLL(ListNode* temp){
        ListNode* prev = NULL;
        while(temp){
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = NULL;
        while( temp ){
            ListNode* KthNode = getKthNode(temp, k);
            if(KthNode == NULL){
                if(prevNode) prevNode->next = temp;
                break;
            }

            ListNode* nextNode = KthNode->next;
            KthNode->next = NULL;
            reverseLL(temp);
            if(temp == head){
                head = KthNode;
            }
            else{
                prevNode->next = KthNode; 
            }
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};