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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *total = new ListNode();
        ListNode *ptr = total;

        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {

            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;

            int sum = val1 + val2 + carry;
            carry = sum / 10;
            sum = sum % 10;
            ptr->next = new ListNode(sum);

            ptr = ptr->next;
            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }

        ListNode *res = total->next;
        delete total;
        return res;
    }

};
