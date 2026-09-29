class Solution {
public:
 string removeDuplicates(string s) {

        stack<char> st;

        for(int i = 0; i < s.length(); i++){
            char ch = s[i];
            //2 option
            //1)insert kardo -> ch and stack ka top different hoga ya stack Empty hoga

            if(st.empty()){
                st.push(ch);
            }
            else if(ch != st.top()){
                st.push(ch);
            }
            else{
                //ch and stack ka top same hai
                //2) Dont Insert, remove top from stack
                st.pop();
            }
        }

        // stack me answer ulta bana hai (top pe last character),
        // isliye pop karke string banao, phir reverse kar do
        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
        // string removeDuplicates(string s) {


        // string ans = "";

        // for(int i = 0; i < s.length(); i++){
        //   char ch = s[i];
        //   //2 option
        //   //1)insert kardo -> ch and right most difrrebt hoga or Ans Empty Hoga

        //   if(ans.empty()){
        //     ans.push_back(ch);
        //   }else if(ch != ans.back()){
        //     ans.push_back(ch);
        //   }
        //   else{
        //     //ch and Rightmost Character is same 
        //     //remove the rightmost character 
        //     ans.pop_back();
        //   }  
        //   //2) Dont Insert reomvoe Right Most from Ans->  ch and rightmost Same hoga    
   
        // }    

        //          return ans;






        // int i = 0, n = s.length();
        // for (int j = 0; j < n; ++j, ++i) {
        //     s[i] = s[j];
        //     if (i > 0 && s[i - 1] == s[i]) // count = 2
        //         i -= 2;
        // }
        // return s.substr(0, i);
    //}
};