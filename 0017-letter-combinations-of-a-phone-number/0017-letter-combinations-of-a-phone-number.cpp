class Solution {
public:
    void solve(  unordered_map<int, string>&map, string &digits,  string& output,  vector<string>&ans, int i){
        if( i == digits.size() ){
            ans.push_back(output);
            return;
        }
        //itreate over ith number's mapped strings
        char num = digits[i];
        string mappedString = map[num];
        for(int j=0; j < mappedString.size(); j++){
            char ch = mappedString[j];
            output.push_back(ch);
            solve(map, digits,output, ans,i+1);
            //backtracking kar rahe hai
            output.pop_back(); 
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)return {};
        unordered_map<int, string>map;
        map['2'] = "abc";
        map['3'] = "def";
        map['4'] = "ghi";
        map['5'] = "jkl";
        map['6'] = "mno";
        map['7'] = "pqrs";
        map['8'] = "tuv";
        map['9'] = "wxyz";
        string output;
        vector<string>ans;
        solve(map, digits,output, ans,0);
        return ans;
    }
};