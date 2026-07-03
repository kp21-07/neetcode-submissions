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
    ListNode *findMid(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode *curr = head;
        ListNode *prev = nullptr; 
        ListNode *next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
    
    void reorderList(ListNode* head) {
        ListNode *mid = findMid(head);
        ListNode *head2 = reverseList(mid->next);
        mid->next = nullptr;
        while(head2) {
            ListNode *temp = head->next;
            head->next = head2;
            ListNode *temp2 = head2->next;
            head2->next = temp;
            head = temp;
            head2 = temp2;
        }
    }
};