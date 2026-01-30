class Solution {
public:
    static bool myComp(string a, string b){
        string t1 = a+b;
        string t2 = b+a;
        return t1 > t2;//agar t1 bada hua to  a ko phele rakh denge agar false to  b ko age rakh denge

    }
    string largestNumber(vector<int>& nums) {
        //ans ko string me convert kr deta huu
        vector<string>snums;
        for(auto n:nums){
            snums.push_back(to_string(n));
        }

        //step 2 sort karte hai in assceinding 
        //ye hai singel digit ke liyee
        sort(snums.begin(),snums.end(),myComp);
        if(snums[0] == "0") return "0";
        string ans = "";
        for(auto str:snums){
            ans+=str;
        }
        return ans;
    }
};