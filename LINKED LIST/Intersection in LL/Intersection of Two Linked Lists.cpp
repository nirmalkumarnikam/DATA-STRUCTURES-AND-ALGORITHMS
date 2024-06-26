/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
Brute Force: this code will work if both the list have distinct elements till intersection
                because we are compairing data of each LL (see line 27)
                instead of that if we compaired  Node then this problem will not arise(line 28)
Time Complexity: O(n*m) ... length of both LL
Space Complexity:O(1)
Algo:
    select one element and check if its present in other LL by iterating over other LL
*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        while(temp1 != NULL){
            while(temp2!=NULL){
                // if(temp1->val== temp2->val)return temp1;
                if(temp1== temp2)return temp1;
                else temp2 = temp2->next;
            }
            temp1 = temp1->next;
            temp2 = headB;
        }
        return NULL;
    }
};

/*
Better:
use 'unordered_map<ListNode*, bool>mapp' to store Nodes of one List and mark true
iterate over next list if mapp[Node] is true... thats our ans. 

Time Complexity: O(n+m)
Space Complexity:O(n)
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        unordered_map<ListNode*, bool>mapp;
        ListNode* temp = headA;

        while(temp != NULL){
            mapp[temp]=true;
            temp = temp->next;
        }
        
        temp = headB;

        while(temp != NULL){
            if(mapp[temp]==true)return temp;
            temp = temp->next;
        }
        return NULL;
    }
};


/*
Best Approach:
Algo:
    find the difference between lengths of array 
    traverse longer array till diff, 
    now iterate over both array simultaneously and chech if temp1 == temp2;
    if temp1 == temp2 return that Node


deeper explaination:
    find the difference between lengths of array 
    now enter the findIntersection:
    (keep in mind we are entering function based on lenA and lenB)
    if(lenA>LenB) move lena till diff else move lenB till difference 
            move longer array till the difference
            now iterate over both array simultaneously and chech if temp1 == temp2;
            if temp1 == temp2 return that Node, else they are goinh to be equal when they will be null at end;


Time Complexity: O(n+2m)=  O(n) + O(m) + O(m-n) +O(n) -- m is longest
Space Complexity:O(1)
*/
class Solution {
public:

    ListNode *findIntersection(int diff, ListNode *headA, ListNode *headB){
        ListNode* temp1=headA;
        ListNode* temp2=headB;

        while(diff != 0){
            diff--;
            temp1= temp1->next;
        }  

        while(temp1 != NULL){
            if(temp1== temp2)return temp1;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return temp1;

    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int LenA=0;
        int LenB=0;
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        while(temp1 -> next != NULL){
            LenA++;
            temp1= temp1->next;
        }
        while(temp2 -> next != NULL){
            LenB++;
            temp2= temp2->next;
        }


        if(LenA>LenB)
        {//note here we are entering grater list first
           return findIntersection(LenA-LenB, headA,headB);
        }
        else if(LenA<LenB)
        {
           return findIntersection(LenB-LenA, headB,headA); 
        }
        else
        {
           return findIntersection(0, headA,headB);
        }

        return NULL;
    }
};



/*
optimal:
algo:
iterate both list simultaneously till they reach intersection...
if one list reaches null, move its pointer to others head.
else keep moving forward.

Time Complexity: O(n+m) ... length of both LL
Space Complexity:O(1)
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA=headA;
        ListNode* tempB=headB;

        while(tempA!=tempB){
            //if one list reaches null, move its pointer to others head.
            if(tempA == NULL){
                tempA=headB;
            }
            //else keep moving forward.
            else
            {
                tempA = tempA->next;
            }

            if(tempB == NULL)
            {
                tempB=headA;
            }
            else
            {
                tempB = tempB->next;
            }
        }
        return tempA;
      
    }
};
        
