class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // Dummy node
        ListNode* dummy = new ListNode(-1);

        // tail always points to the last node
        // of our merged list
        ListNode* temp = dummy;

        // Compare both lists
        while (list1 != NULL && list2 != NULL) {

            if (list1->val <= list2->val) {

                // Attach list1 node
                temp->next = list1;

                // Move list1
                list1 = list1->next;
            }
            else {

                // Attach list2 node
                temp->next = list2;

                // Move list2
                list2 = list2->next;
            }

            // Move tail forward
            temp = temp->next;
        }

        // Attach remaining nodes
        if (list1 != NULL) {
            temp->next = list1;
        }
        else {
            temp->next = list2;
        }

        // Dummy itself is not part of answer
        return dummy->next;
    }
};