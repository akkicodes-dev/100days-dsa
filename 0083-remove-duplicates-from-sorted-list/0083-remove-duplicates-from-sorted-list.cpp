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
    ListNode* deleteDuplicates(ListNode* head) {
        //Empty Linklist
        if(head == NULL){
            return head;
        }
        //single node wali linklist agaye to 
        if(head-> next== NULL){
            return head;
        }

        //Main Logic            kam se  kam 2 nodes to  hai  yaah tak hum aye to
        ListNode* prev = head;
        ListNode* curr = head-> next;

        while(curr != NULL){
            if(curr -> val != prev->val){
                curr = curr->next;
                prev = prev->next;
            }
            else{
                //equal to wali  case
                prev->next = curr -> next;
                curr -> next = NULL;
                delete curr;

                //fisre intilize karna padega 
                curr = prev->next;
            }
           
        }

         return head;
    }
};