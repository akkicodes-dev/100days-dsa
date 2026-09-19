
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
       if(!head || head-> next == 0) return head;
       
       ListNode* h1 = head;//odd Node  list
       ListNode* h2 = head -> next;//even  Node List

       ListNode* evenHead = h2;
       while(h2 && h2 -> next){
        h1 -> next = h2 ->next;
        h2 -> next = h2->next ->next;
        h1 = h1->next;
        h2 = h2 -> next;
       }

       //the two Independant Prepared list hasBeen  reGrouped
       // odd-> index wali list ha -> even wali list
       h1->next = evenHead;
       return head;

    }
};