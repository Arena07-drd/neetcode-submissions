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
    void reorderList(ListNode* head) {

       ListNode *fast = head;
       ListNode *slow = head;

       while (fast->next != nullptr && fast->next->next != nullptr) {

            fast = fast->next->next;
            slow = slow->next;
        }


        ListNode *curr = slow->next, *prev = nullptr, *next;

        slow->next = nullptr;

        while (curr != nullptr) {

            next = curr->next;

            curr->next = prev;

            prev = curr;
            curr = next;
        }

        ListNode *ptr = head;

        while (prev != nullptr) {
            ListNode* firstNext = ptr->next;
            ListNode* secondNext = prev->next;

            ptr->next = prev;
            prev->next = firstNext;

            ptr = firstNext;
            prev = secondNext;
        }

        
    }
};
