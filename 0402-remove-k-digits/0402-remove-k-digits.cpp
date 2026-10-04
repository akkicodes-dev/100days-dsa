class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(int i=0; i<num.size(); i++){
            while(!st.empty() && k>0 && (st.top() - '0') > (num[i] - '0')){
                st.pop();
                k = k-1;
            }
            st.push(num[i]);
        }
        while(k > 0) st.pop(), k--;
        if(st.empty()) return "0";
        string res ="";

        while(!st.empty()){
            res += st.top(); //res = res + st.top(); ess har bar ek new string ban  rahi thi  usse achha to ye hai ki hum n += karke wo rok liyanahi to tle de raha tha
            st.pop();
        }
        while(res.size() != 0 && res.back() == '0')
        {
            res.pop_back();
        }
        reverse(res.begin(),res.end());
        if(res.empty()) return "0";
        return res;
    }
};