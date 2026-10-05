class Solution {
public:
    string decodeString(string s) {
        stack<string>st;                       // chunks (strings) ka stack
        for(auto ch:s){
            if(ch == ']'){
                string stringToRepeat = "";
                // "[" milne tak andar ke chunks nikalo
                while(!st.empty() && st.top() != "["){
                    string top = st.top();
                    stringToRepeat += top;     // pop order me jodna (ulta form)
                    st.pop();
                }
                st.pop();                      // "[" hata do
                string numericTimes = "";
                // "[" ke pehle wale digits nikalo
                while(!st.empty() && isdigit(st.top()[0])){
                    numericTimes += st.top();
                    st.pop();
                }
                // digits ulte nikle the ("100" -> "001"), seedha karo
                reverse(numericTimes.begin(), numericTimes.end());
                int n = stoi(numericTimes);    // repeat count

                //final decoding
                string currentdecode = "";
                while(n--){
                    currentdecode += stringToRepeat;   // n baar repeat
                }
                st.push(currentdecode);        // decoded chunk wapas stack me
            }
            else {
                string temp(1, ch);
                st.push(temp);                 // letter, digit ya "[" push
            }
        }
        string ans;
        // stack ke saare chunks jodo
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());       // ek baar me poora seedha karo
        return ans;
    }
};