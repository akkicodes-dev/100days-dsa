class Solution {
public:
    bool isValid(string s) {
        stack<char>st;

        for(int i =0; i<s.length(); i++){
            char ch = s[i];

            //agar ye  charcter opneing bracket hai
            if(ch == '(' ||ch =='[' || ch == '{' ){
                //Insert kardo  stack  me
                st.push(ch);
            }else{
                //closing Bracket
                //Match
                //No Match
                //pre-check -> stack  empty
                if(st.empty()){
                    //no match 
                    return false;
                }
                if(ch ==')' && st.top() != '('){
                    //No match
                    return false;
                }
                else if(ch =='}' && st.top() != '{'){
                    //No match
                    return false;
                }
                else if(ch ==']' && st.top() != '['){
                    //No match
                    return false;
                }
                else{
                    //match 
                    st.pop();
                }
            }
        }

        // //yaha pr main  galti  kartaa huu 
        // //ye  bhul jata huu
        // if(s.empty()){
        //     //iska  matlab saree brackets cancel  out hogaye succesfully
        //     return true; 
        // }
        // else{
        //     //cancel out hogaye but still  something left in this stack
        //     return false
        // }

        return st.empty();// true nahi  to  false
    }
};