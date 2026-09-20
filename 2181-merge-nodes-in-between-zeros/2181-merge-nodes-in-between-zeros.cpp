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
    ListNode* mergeNodes(ListNode* head) {
       if(!head) return 0;
       ListNode* slow = head;
       ListNode* fast = head->next, *newLastNode = 0;
       int sum = 0;
       while(fast){
        if(fast -> val != 0){
            sum += fast -> val;
        }
        else{
            // fast -> val == 0
            slow -> val = sum;
            newLastNode = slow;
            slow = slow -> next;
            sum = 0;
        }
        fast = fast->next;
       }
       ListNode* temp = newLastNode -> next;
       //just foremed newList
       newLastNode -> next = NULL;

    //    //delting old list
    //    while(temp){
    //     ListNode* nxt = temp->next;
    //      delete temp;
    //      temp = nxt;
    //    }
      
    return head;

    }
};







// class Solution {
// public:
//     ListNode* mergeNodes(ListNode* head) {

//         ListNode* temp = head->next;      // FIX 3: head khud 0 hai, isliye head->next se shuru
//         int sum = 0;

//         ListNode* ans = new ListNode(-1); // dummy node (starting marker)
//         ListNode* tail = ans;             // FIX 2: naya pointer, jo result list me "last node" track karega

//         while (temp != NULL) {
//             if (temp->val != 0) {         // FIX 1: value check karo (0 hai ya nahi), next ka existence nahi
//                 sum += temp->val;
//             } else {
//                 // 0 mil gaya -> matlab ek group khatam, naya node banao
//                 ListNode* newNode = new ListNode(sum);  // FIX 2: naya node banao
//                 tail->next = newNode;      // purane last node se jodo
//                 tail = tail->next;         // tail ko aage badhao (ab ye naya node hi "last" hai)
//                 sum = 0;                   // reset, agle group ke liye
//             }
//             temp = temp->next;             // list me aage badho
//         }

//         return ans->next;   // dummy ke next se asli answer shuru hota hai
//     }
// };