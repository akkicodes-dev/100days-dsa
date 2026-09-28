
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

    vector<int> nextGretterElment(vector<int>& v){
        stack<int> st;
        st.push(-1);

        vector<int>ans(v.size(),-1);// v.size() evdhi  yachi  pn  size  asel  ani  sagle  elemnt  je  ahet na  tee -1 ne  intilize  hotill bs  evdhach  ahe  akok
        for(int i=v.size()-1; i>=0 ; i--){
            while(!st.empty() &&  st.top() != -1  && v[st.top()] <= v[i]){
                st.pop();
                
            }
            ans[i] = st.top();
                st.push(i);
        }
        return ans;
    }

    vector<int> prevGretterElment(vector<int>& v){
        stack<int> st;
        st.push(-1);

        vector<int>ans(v.size(),-1);// v.size() evdhi  yachi  pn  size  asel  ani  sagle  elemnt  je  ahet na  tee -1 ne  intilize  hotill bs  evdhach  ahe  akok
        for(int i=0; i <= v.size()-1 ; i++){
            while(!st.empty() &&  st.top() != -1  && v[st.top()] < v[i]){
                st.pop();
               
            }
             ans[i] = st.top();
                st.push(i);
        }
        return ans;
    }
    long long sumSubarrayMins(vector<int>& arr) {
        auto next = nextSmallerElment(arr);
        auto prev = prevSmallerElment(arr);
        long long sum = 0;

        for(int i=0; i< arr.size();i++){
            //for each  index elemnt, i want to Find
            //how many times ith elment is contributing to the  sum.
            long long nexti = next[i] == -1 ? arr.size(): next[i];
            long long previ = prev[i];
            long long left = i- previ;
            long long right = nexti - i;
            long long no_of_times = (left * right);
            long long total = (no_of_times * arr[i]);
            sum = (sum + total);
        }
        return sum;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        auto next = nextGretterElment(arr);
        auto prev = prevGretterElment(arr);
        long long sum = 0;

        for(int i=0; i< arr.size();i++){
            //for each  index elemnt, i want to Find
            //how many times ith elment is contributing to the  sum.
            long long nexti = next[i] == -1 ? arr.size(): next[i];
            long long previ = prev[i];
            long long left = i- previ;
            long long right = nexti - i;
            long long no_of_times = (left * right);
            long long total = (no_of_times * arr[i]);
            sum = (sum + total);
        }
        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        auto smallesSums = sumSubarrayMins(nums);
        auto largestSums = sumSubarrayMaxs(nums);
        return largestSums - smallesSums;
    }
};