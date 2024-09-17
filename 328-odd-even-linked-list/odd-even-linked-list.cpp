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
    ListNode* oddEvenList(ListNode* head) {
        if (head==NULL) return head;

        ListNode* temp = head;
        int index = 0;
        ListNode* evenhead=nullptr;
        ListNode* eventail=nullptr;
        ListNode* oddhead=nullptr;
        ListNode* oddtail=nullptr;

        while (temp != nullptr) {
           

             if (index % 2 == 0) { 
                if (oddhead == nullptr) {
                    oddhead = temp;
                    oddtail = oddhead;
                } else {
                    oddtail->next = temp;
                    oddtail = oddtail->next;
                }
                
            } else { 
                if (evenhead == nullptr) {
                    evenhead = temp;
                    eventail = evenhead;
                } else {
                    eventail->next = temp;
                    eventail = eventail->next;
                }
               
            }

            temp = temp->next;
            index++;
        }

        if (oddtail != nullptr) {
        oddtail->next = evenhead;
    }
    
    if (eventail != nullptr) {
        eventail->next = nullptr;  
    }
    
    return oddhead; 
    }
};