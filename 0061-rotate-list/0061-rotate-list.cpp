
class Solution {
    public:
    int getLength(ListNode* head) {
        int count = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {

ListNode* curr = head;
// Step 1: Edge case check - agar list empty hai ya sirf 1 node hai,
//         to rotate karne ka koi matlab nahi, seedha head return kardo
    if(head == NULL || head -> next == nullptr){
    return head;
    }
    
    // Step 2: List ki length 'n' nikaalo, traverse karte waqt hi 
    //         last node ko bhi track kar lo (uski pointer save karo)
    int len = getLength(head);
    
    // Step 3: k ko n se mod karo (k = k % n) - bade k ko chhota banane ke liye
    //         agar mod karne ke baad k == 0 ho jaye, to bhi seedha head return kardo
     k = k % len;
    if(k==0){
    return head;
    }   
        while (curr->next != NULL) {
          curr = curr->next;
        }
         
    // Step 4: List ko circular bana do - last node ka next, head se jod do
 
    curr->next = head;
        
    
    // Step 5: Naya tail dhundo - head se (n - k) steps aage jao
    
    ListNode* newTail = head;
    for(int i = 0; i < len - k - 1; i++){
    newTail = newTail->next;
}
    // Step 6: naya head nikaalo (newTail ke next se),
     ListNode* newHead  = newTail->next;
    //         aur newTail ka next NULL kardo (circle todo)
     newTail->next = NULL;
    // Step 7: naya head return karo
     return newHead;
    }
    };