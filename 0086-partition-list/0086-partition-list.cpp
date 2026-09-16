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
    ListNode* partition(ListNode* head, int x) {
        ListNode* fp = new ListNode(-1);// ye mera First Part hai  jisem  <3 means less than < x ki sari nodes aynge 
        ListNode* sp = new ListNode(-1);// ye mera secondd part hai  jissme >x wali sari nodes aynge  

        // reltive order aur done  me order same  hi  rahega  chnage nahi  hona  chiye 

        auto fpTail = fp;
        auto spTail = sp;
        //step 1
        auto it = head; // auto ky  karte pahile he  samjun gehjoo 

        while(it){
            if(it->val < x){
                //first part me ayega 
                fpTail->next = it;
                fpTail = fpTail -> next;
            }
            else{
                //greter than equal to wala
                spTail->next =  it;
                spTail =  spTail->next;
            }
            it = it->next;
        }

        //2nd step fp last to sp cha first to sp last = null;

        //fp->sp->NULL
        fpTail->next = sp->next;// yaha pe na  jo -1 wala sceen hai wo hum lenge hi nahi  kyukuii   sp->next  kiya  = sp hota  to  wo  atta nahi  to  nahi 
        spTail-> next = NULL;
  
       //
        return fp->next;//samjla fp ky ahe -1 ahe baraobar tr aplyalaa ky karyacha ahe tyacha pudcyaa pasun itreate karyacha ahe na  barobar  // ek dobut ahe mg je sp madhala -1 ahe tyachaa kyy hoil

    }
};