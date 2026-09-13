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
    ListNode* reverseKGroup(ListNode* head, int k) {
        //step 1 check group of len k
        int count = 0;
        ListNode* temp = head;

        while(temp != NULL && count < k){
            temp = temp-> next;
            count++;
        }//check kr pa rahe hai karta hai  ki nahi karta hai

     //if group exist
     if(count == k){
            //reverse one group baki recursion dekh lega
            ListNode* prev = NULL;
            ListNode* curr = head;
            ListNode* forward = NULL;
            //i need to reverse only k nodes
            int i = 0;

            while(i<k){
                forward = curr->next;
                curr->next= prev;
                prev = curr;
                curr = forward;
                i++;
            }
            //hamne ek  grroup ko  reverse kardiyahai 
            //bakki rec karke ke dega
            ListNode* recursionKaHead = reverseKGroup(forward,k);
            //Dono Link list ko Join karna hai
            head->next = recursionKaHead;
            //return starting node of the modifies list
            return prev;
     }
     else{
        //if group does not exist
        return head;
     }


    }
};