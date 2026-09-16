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
//Iterative Approach
    // ListNode* iterative(ListNode* l1, ListNode* l2){
    //      auto ans = new ListNode(-1);
    //     auto it = ans;
    //     int c = 0; //Carry
    //     int sum = 0;
    //     while(l1 || l2 || c){ //l1 l2 jab tak null nahi  hote ya carry bacha  hua hai tab tak chalta rahega

    //     int a = l1 ? l1->val : 0;
    //     int b = l2 ? l2->val : 0;
    //     sum = a+b+c;
    //     int digit = sum % 10;
    //     c = sum /10; //carry  update hojayega

    //     // store the digit in  the anwser link list 
    //      it -> next = new ListNode(digit);
    //      it = it->next;
    //      l1 = l1 ? l1 -> next : 0;
    //      l2 = l2 ? l2 -> next : 0;
    //     }
    //     return ans -> next;
    // }

//Recursive Approach
     ListNode* recursive(ListNode* l1, ListNode* l2, int  carry = 0) {
      if(!l1 && !l2 && !carry) return NULL;
        int a = l1 ? l1->val : 0;
        int b = l2 ? l2->val : 0;
        int sum = a+b+carry;
        int digit = sum % 10;
        carry = sum /10; //carry  update hojayega

        ListNode* ans = new ListNode(digit);
        ans -> next = recursive(l1 ? l1->next : l1, l2 ? l2-> next : l2, carry);
        return ans;

    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      // return iterative(l1,l2);
      
      return recursive(l1,l2);
    }
};