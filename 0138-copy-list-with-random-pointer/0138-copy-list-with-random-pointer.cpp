
class Solution {
public:
    // Node* helperold(Node* head,  unordered_map<Node*, Node*>&mp){
    //     if(head == NULL){
    //         return 0;
    //     }

    //     Node* newHead = new Node(head -> val);
    //     mp[head] = newHead;
    //     newHead -> next = helper(head -> next, mp);\
    //     if(head -> random){
    //         newHead -> random = mp[head -> random];
    //     }
    //     return newHead;
    // }

    // Node* helper(Node -> next){
    //     //SC : O(1)
    // }
    Node* copyRandomList(Node* head) {
        // unordered_map<Node*, Node*>mp; // old node --> new Node
        // return  helperold(head, mp);



        if(!head) return 0;

        //step 1: Clone A -> A'
        Node *it = head;// itreate over old head
        while(it){
            Node* cloneNode = new Node( it -> val);
            cloneNode -> next = it -> next;
            it-> next = cloneNode;
            it = it->next -> next;
        }
        
        //step 2: Assgin Random links of A' with the  helper of OldNode A

        it =  head;
        while(it){
            Node* cloneNode = it -> next;
            cloneNode -> random = it -> random ? it->random -> next: nullptr;
            it = it->next->next;
        }
        //step 3 : Detach A from A'
        it = head;
        Node* cloneHead = it->next;
        while(it){
            Node* cloneHead = it->next;
            it->next = it->next -> next;
            if(cloneHead -> next){
                cloneHead -> next = cloneHead -> next -> next;
            }
            it = it-> next;
        }
        return cloneHead;
    }
};


