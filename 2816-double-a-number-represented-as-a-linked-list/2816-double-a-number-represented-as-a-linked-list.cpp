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
    ListNode* reverseLL(ListNode* &head){
        if(head == NULL){
            return head;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        // Node* temp = head;   // ❌ REMOVED: temp aur curr same node point karte the,
                                 // aur curr->next=prev wali line ne us node ko modify kar diya,
                                 // isliye temp->next galat (corrupted) value deta tha — loop
                                 // sirf 1 baar chalke ruk jaata tha poori list traverse kiye bina.

        while(curr != NULL){        // ✅ FIX: temp ki jagah seedha curr ko hi condition mein check kar
                                     // curr khud hi NULL ho jayega jab list end tak pahunch jayegi

            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            // temp = temp->next;   // ❌ REMOVED: ab iski zarurat nahi, curr hi apna kaam kar raha hai
        }
        //new head
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
          //step! is reverseLL
        head = reverseLL(head);
        
        //s2: add 1 logic
        int carry = 0;
        ListNode* temp = head;
        
        while(temp!= NULL){
            
            int data = temp -> val;
            int sum = data +  data + carry;
            
            int digit = sum % 10;
            carry = sum / 10;
            
            
            //insert digit into current  node
            temp-> val = digit;
            
            if(temp-> next == NULL && carry != 0){
                //i need tp  create the extra  node
                
                ListNode* newNode = new ListNode(carry);
                //link  tis node  with  the temp
                 temp-> next = newNode;
                 temp  = newNode;
            }
            //move to next node otherwise loop stuck
            temp = temp -> next;
        }
        //step3 reverse  to  get  the Anwser
        
        head = reverseLL(head);
        
        return head;
    }
};
