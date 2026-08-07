// class Solution {
// public:
//     void addRE(string& num1, int p1, string& num2, int p2, int carry , string& ans){  // if humne carry character niche call karte wakt passs bhi nahi kiya  phir bhi  by defualt 0 (zero) mann legi default always should have to  be rightmost

//         //base case
//         if(p1 < 0 && p2 <0){
//             if(carry != 0){
//                 //return string(1,carry + '0'); // temprorary string baniyee 1     ^ length ki 

//                  ans.push_back(carry + '0'); // carry aya to  pushback kardena hai
//             }
//             return ;
//         }
//         //ek case solve
//         int n1 = (p1 >= 0 ? num1[p1] : '0') - '0';//this is the logic of extracting the no and '0' use kiya hai wo  string ko  integer me convert karne ke liyee
//         int n2 = (p2 >= 0 ? num2[p2] : '0') - '0';
//         int csum = n1 + n2 + carry;
//         int digit = csum % 10;//digit nial rahe hai
//         carry = csum/10 ;
//         ans.push_back(digit + '0'); //digit ek integer hai usko  character me convert karna padega karliya main me hai  copy  hojayega 

//         //RE sabmhal lega
//         addRE(num1, p1-1, num2, p2 - 1, carry,ans);
       

//     }
//     string addStrings(string num1, string num2) {
//           string  ans = "";
//         addRE(num1, num1.size()-1, num2, num2.size()-1,0,ans);
//         reverse(ans.begin(), ans.end());
//         return ans;

//     }
// };

class Solution {
public:
    string addRE(string num1, int p1, string num2, int p2, int carry = 0){  // if humne carry character niche call karte wakt passs bhi nahi kiya  phir bhi  by defualt 0 (zero) mann legi

        //base case
        if(p1 < 0 && p2 <0){
            if(carry != 0){
                return string(1,carry + '0'); // temprorary string baniyee 1     ^ length ki 
            }
            return "";
        }
        //ek case solve
        int n1 = (p1 >= 0 ? num1[p1] : '0') - '0';//this is the logic of extracting the no and '0' use kiya hai wo  string ko  integer me convert karne ke liyee
        int n2 = (p2 >= 0 ? num2[p2] : '0') - '0';
        int csum = n1 + n2 + carry;
        int digit = csum % 10;//digit nial rahe hai
        carry = csum/10 ;
        string ans = "";
        ans.push_back(digit + '0'); //digit ek integer hai usko  character me convert karna padega karliya

        //RE sabmhal lega
        ans += addRE(num1, p1-1, num2, p2 - 1, carry);
        return ans;

    }
    string addStrings(string num1, string num2) {
       
        string  ans = addRE(num1, num1.size()-1, num2, num2.size()-1);
        reverse(ans.begin(), ans.end());
        return ans;

    }
};