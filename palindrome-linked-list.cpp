/*
Title: Palindromic Linked List
Link: https://leetcode.com/problems/palindrome-linked-list
*/

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> nums;

        while(head != NULL){
            nums.push_back(head->val);
            head = head->next;
        }

        int n = nums.size();
        for(int i = 0; i < n/2; i++){
            if(nums[i] != nums[n-i-1]){
                return false;
            }
        }

        return true;
    }
};
