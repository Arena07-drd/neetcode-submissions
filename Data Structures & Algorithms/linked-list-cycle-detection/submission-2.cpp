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
    bool hasCycle(ListNode* head) {
        
        if (head) {
            unordered_set<int> freq;

            while(head->next != nullptr && head->next->next != nullptr) {

                if (freq.count(head->val)) {
                    return true;
                }

                freq.insert(head->val);
                head = head->next;
            }

            return false;
        } else {
            return false;
        }
    }
};
