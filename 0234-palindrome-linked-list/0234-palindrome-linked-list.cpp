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
    
    // return  s  the head  of reversed  linklist
    ListNode* reverseList(ListNode* head) {
        //Empty Linked  list
        if(head == NULL){
            return head;//hamne head return  kiya kyuki  head  bhi  null nhai  edhar Direct Null  nahi  return kiya  
        }
        ListNode* prev =NULL; // head ke pehle ka pointer
        ListNode* curr = head;//hame head pe  current  rakh ke  waha se hi  start karna hai  

        while(curr != NULL){
            ListNode* forward = curr -> next; // agae badh  rahe hai  
            curr -> next = prev; // link ko  reverse kr rahe hai
            prev = curr;//revrse hogay 
            curr = forward;// age badh jao 
        }
        //update head
         head = prev;
          return prev;// apun kaun head means previous  reverse kela karna khali  ek print function  lavla ashin  ji ki head pasun  nulll paryent print karin mahunnn

    //     if(head == NULL){
    //         return head;
    //     }

    //     //1 case  mai  Slove karunga baki  recursion sambhal  lega 
    //     ListNode* curr = head;
    //     ListNode* prev = NULL;
    //     ListNode* forward = curr-> next;

    //    curr-> next = prev;
    //    //ab tak maine 1 node ko  revrse karliya hai  
    //    //baki  recursion sambhal  lega 
    //    return  prev;
    }


    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        //agar fast ke pass 2 step chalne ka time/ chance hai, to  mai  slow and fast  pointer ko  agge Badhungaa nahi  to  loop  se bahar nikaloo
        
        while(fast != NULL && fast->next != NULL){
            slow = slow -> next;
            fast = fast->next -> next;
        }
        return slow;
    }

   int getlengthOfLinkedList(ListNode* head){
    int len =0;

    ListNode* temp = head;
    while(temp != NULL){
        //count
        len++;
        //move to next node;
          temp = temp->next;
    }
    return len;
}
    bool isPalindrome(ListNode* head) {
        ///find kr  lete hai length of ll
       int  len = getlengthOfLinkedList(head);
        //find mid
        ListNode* mid = middleNode(head);
        //update kr lete mid as per even/ odd length
        //even length me mid as it is use karna hai
        //odd wale case main  finalmid, mid->next ko lunga
        ListNode* finalMid = NULL;
        if(len & 1)
        {
            //odd wala case &1
            finalMid = mid ->next;
        }
        else{
            //even wala case
            finalMid = mid;
        }
        //revers  LL is using mid node
        finalMid = reverseList(finalMid);
        //now i have 2 linked list with starting pointer as head and finalmid

        //compare and return true  and  false
        ListNode* temp = head;
        while(temp != NULL && finalMid != NULL){
            if(temp -> val != finalMid -> val){
                return false;
            }
            //1 step Agge BadhJao
            temp = temp->next;
            finalMid = finalMid -> next;
        }
        //agar mai yahatak  agya  eska matlab palindrome hai sara dtat matach  hogya
        return true;
        
    }
};