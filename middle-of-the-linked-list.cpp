/*
Title: Middle of the Linked List
Link: https://leetcode.com/problems/middle-of-the-linked-list/
*/

// Naive Approach
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* temp = head;
        int N = 0;

        while(temp){
            temp = temp->next;
            N++;
        }

        int count = N/2;
        
        while(count > 0){
            head = head->next;
            count--;
        }

        return head;
    }
};

// Slow and Fast pointer approach
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};
