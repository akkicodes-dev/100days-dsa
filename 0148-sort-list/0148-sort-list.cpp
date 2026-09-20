class Solution {
public:

    // Find Middle Node
    ListNode* findMid(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    // Merge Two Sorted Linked Lists
    ListNode* merge(ListNode* left, ListNode* right) {

        // Dummy node
        ListNode* ans = new ListNode(-1);

        ListNode* temp = ans;

        // Compare both LL
        while(left != NULL && right != NULL) {

            if(left->val <= right->val) {
                temp->next = left;
                temp = left;
                left = left->next;
            }
            else {
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }

        // If left LL still has nodes
        while(left != NULL) {
            temp->next = left;
            temp = left;
            left = left->next;
        }

        // If right LL still has nodes
        while(right != NULL) {
            temp->next = right;
            temp = right;
            right = right->next;
        }

        // Dummy node hata ke actual head return
        ans = ans->next;

        return ans;
    }

    // Merge Sort
    ListNode* sortList(ListNode* head) {

        // Base Case
        if(head == NULL || head->next == NULL) {
            return head;
        }

        // Find Middle
        ListNode* mid = findMid(head);

        // Break into two halves
        ListNode* left = head;
        ListNode* right = mid->next;

        mid->next = NULL;

        // Sort Left Half
        left = sortList(left);

        // Sort Right Half
        right = sortList(right);

        // Merge both sorted halves
        ListNode* mergedLL = merge(left, right);

        return mergedLL;
    }
};