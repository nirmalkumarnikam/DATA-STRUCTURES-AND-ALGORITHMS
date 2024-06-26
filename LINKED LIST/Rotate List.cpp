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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) {
            return head;
        }

        ListNode* end = head;
        int n = 1; // initialize n as 1 since we are already at head node
        
        while (end->next) {
            end = end->next;
            n++;
        }       

        k = k % n; // no need to rotate more than the length of the list
        if (k == 0) {
            return head;
        }

        end->next = head; // create a circular list
        
        // Find the new end, which is (n - k) nodes from the start
        for (int i = 0; i < n - k; i++) {
            end = end->next;
        }

        head = end->next; // new head
        end->next = nullptr; // break the circle
        
        return head;
    }
};
