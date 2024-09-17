/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // Function to reverse the linked list
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* cur = head;
        ListNode* prev = NULL;
        while (cur != NULL) {
            ListNode* front = cur->next;
            cur->next = prev;
            prev = cur;
            cur = front;
        }
        return prev;
    }
    
    // Function to check if the linked list is a palindrome
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;  // Empty or single node lists are palindromes
        
        // Step 1: Find the midpoint of the linked list using slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Step 2: Reverse the second half of the linked list
        ListNode *secondHalfHead = reverseLinkedList(slow);
        ListNode *firstHalfHead = head;
        
        // Step 3: Compare both halves
        ListNode *first = firstHalfHead;
        ListNode *second = secondHalfHead;
        bool isPalin = true;  // Assume the list is a palindrome unless proven otherwise
        
        while (second != NULL) {  // Compare nodes in both halves
            if (first->val != second->val) {
                isPalin = false;  // If a mismatch is found, mark it as not a palindrome
                break;
            }
            first = first->next;
            second = second->next;
        }
        
        // Step 4: Restore the original list by reversing the second half back
        reverseLinkedList(secondHalfHead);
        
        return isPalin;
    }
};
