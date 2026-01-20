#include <algorithm>    // for reverse
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        stack<pair<char,int>> st;

        for(char ch: s){

            if(!st.empty() && st.top().first == ch){

                st.top().second++;

                if(st.top().second == k){
                    st.pop();
                }
            }
            else{
                st.push({ch,1});
            }
        }

        string result = "";

        // stack is LIFO, so pop gives reverse order
        while(!st.empty()){
            char c = st.top().first;
            int cnt = st.top().second;
            st.pop();

            result.append(cnt, c);
        }

        reverse(result.begin(), result.end());

        return result;
    }
};