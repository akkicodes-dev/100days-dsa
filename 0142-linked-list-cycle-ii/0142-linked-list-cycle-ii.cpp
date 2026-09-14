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
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, bool>visited;

        ListNode* temp = head;

    while(temp!= NULL){

            if(visited[temp] == true){
                return temp;
            }
            else{
                visited[temp] = true;
                temp = temp -> next;
            }
        }
        //agar main  yaha  tak  agaya 
        //iska mtlb
        //temp == NULL huaa HOga
        // noloop found
        return NULL;
    }
};