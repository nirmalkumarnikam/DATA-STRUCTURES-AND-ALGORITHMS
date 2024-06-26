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
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
        
//         // 2nd from the last is N-2+1 from start.

//         //count No of nodes
//         ListNode*temp = head;
//         int count = 0;
//         while(temp!=nullptr){
//             count++;
//             temp=temp->next;
//         }

//         temp = head;
//         int positionToRemove = count - n + 1;
//         ListNode*prev = nullptr;

//         if (positionToRemove == 1) {
//             ListNode* newHead = head->next;
//             delete head;
//             return newHead;
//         }

        
        
//         while(positionToRemove>1)
//         {
//             positionToRemove--;
//             prev = temp;
//             temp=temp->next;
//         }

//         prev->next = temp ->next;
//         delete temp;

//         return head;
//    }
// };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        // 2nd from the last is N-2+1 from start.

        //count No of nodes
        ListNode* start = new ListNode();
        start ->next = head;
        ListNode*slow = start;
        ListNode*fast = start;

        

        for(int i = 1; i<=n; i++)
        {
            fast = fast->next;
        }

        while(fast -> next != nullptr){
            fast=  fast -> next;
            slow = slow -> next;
        }

        slow -> next = slow ->next ->next;

        return start ->next;
   }
};
