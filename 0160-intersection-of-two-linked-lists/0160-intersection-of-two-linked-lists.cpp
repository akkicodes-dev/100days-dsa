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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        // 1. Dono pointers ko respective heads se start karo
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        // 2. Jab tak dono pointers same node par nahi aa jaate
        while (temp1 != temp2) {

            // 3. temp1 ko next node par move karo
            //    Agar NULL ho gaya, toh doosri list ke head par switch karo
            if (temp1 == NULL) {
                temp1 = headB;
            }
            else {
                temp1 = temp1->next;
            }

            // 4. temp2 ko next node par move karo
            //    Agar NULL ho gaya, toh doosri list ke head par switch karo
            if (temp2 == NULL) {
                temp2 = headA;
            }
            else {
                temp2 = temp2->next;
            }
        }

        // 5. Do possibilities:
        //    - temp1 == temp2 == intersection node
        //    - temp1 == temp2 == NULL (no intersection)
        return temp1;
    }
};