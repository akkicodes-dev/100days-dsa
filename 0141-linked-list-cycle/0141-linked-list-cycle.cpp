/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        //no  cycle -> fast == NULL
        //Yes cycle ->  slow == fast ye hi  logic hai
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!= NULL){
            fast = fast-> next;
            if(fast!= NULL){
                fast = fast -> next;// null pointer exception  yeu shakte mahnu ek ek da chalavla ahe  fast pn slow 1 tr  fast 2 same ch ahe 
                 slow = slow ->next;
                 //check  weather they  are meeting 
                 if(slow == fast){
                    return true;
                 }
            }
           
        }
        //loop se  bahar tabhi ayega jab fast null  hogaa
        return false;
    }
};