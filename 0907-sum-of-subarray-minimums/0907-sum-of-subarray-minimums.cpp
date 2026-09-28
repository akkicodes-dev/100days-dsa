class Solution {
public:
    vector<int> nextSmallerElment(vector<int>& v){
        stack<int> st;
        st.push(-1);

        vector<int>ans(v.size(),-1);// v.size() evdhi  yachi  pn  size  asel  ani  sagle  elemnt  je  ahet na  tee -1 ne  intilize  hotill bs  evdhach  ahe  akok
        for(int i=v.size()-1; i>=0 ; i--){
            while(!st.empty() &&  st.top() != -1  && v[st.top()] >= v[i]){
                st.pop();
                
            }
            ans[i] = st.top();
                st.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElment(vector<int>& v){
        stack<int> st;
        st.push(-1);

        vector<int>ans(v.size(),-1);// v.size() evdhi  yachi  pn  size  asel  ani  sagle  elemnt  je  ahet na  tee -1 ne  intilize  hotill bs  evdhach  ahe  akok
        for(int i=0; i <= v.size()-1 ; i++){
            while(!st.empty() &&  st.top() != -1  && v[st.top()] > v[i]){
                st.pop();
               
            }
             ans[i] = st.top();
                st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        auto next = nextSmallerElment(arr);
        auto prev = prevSmallerElment(arr);
        long long sum = 0;
        const int MOD = 1e9 + 7;// consatnt kykuii hame  eski  value kabhi  bhi change nahi karni

        for(int i=0; i< arr.size();i++){
            //for each  index elemnt, i want to Find
            //how many times ith elment is contributing to the  sum.
            int nexti = next[i] == -1 ? arr.size(): next[i];
            int previ = prev[i];
            int left = i- previ;
            int right = nexti - i;
            long long no_of_times = (left * right) % MOD;
            long long total = (no_of_times * arr[i]) % MOD;
            sum = (sum + total) % MOD;
        }
        return sum;
    }
};