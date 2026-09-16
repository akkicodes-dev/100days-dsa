class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int N = 0;
        auto it = head;
        while(it){
            N++, it = it -> next;
        }

        int idealPartSize = N/k;
        int extraNodes = N % k;

        vector<ListNode*> ans(k, nullptr);
        it = head;
        for(int i = 0; i < k && it; i++){
            ans[i] = it;
            int actualCurrentPartSize = idealPartSize + (extraNodes > 0 ? 1 : 0);
            if (extraNodes > 0) extraNodes--;   // <-- yeh line add ki

            for(int j = 0; j < actualCurrentPartSize - 1; j++){
                it = it -> next;
            }
            auto nwxtPartStarting = it -> next;
            it->next = nullptr;
            it = nwxtPartStarting;
        }
        return ans;
    }
};