class Solution {
public:
    int longestValidParentheses(string s) {
      int maxLength =0; // ab tak ka sabse lamba valid tukda

      stack<int> st;   // stack me characters nahi, INDEX rakhenge
      st.push(-1);  // base (zameen): "valid tukda yahan se shuru hota hai" ka marker

      for(int i=0; i< s.length(); i++){
        if(s[i] == '('){
             // opening bracket aaya, to uska index yaad rakh lo
                // taaki baad me `)` aaye to length nikal sake
                st.push(i);
        }
        else{
             // closing bracket aaya, to top wale ko pop karo
                // (top ya to matching '(' hoga, ya base -1)
                st.pop();
                if (st.empty()) {
                    // pop ke baad stack khali: matlab is `)` ka koi '(' tha hi nahi (orphan)
                    // ye valid tukde ko tod deta hai, to iska index naya base bana do
                    st.push(i);
                }
                else {
                    // match ho gaya, stack ka top ab "valid tukde se just pehle wala index" hai
                    // current valid tukde ki length = i - top
                    maxLength = max(maxLength, i - st.top());
                }
        }
      }
      return maxLength;
    }
};