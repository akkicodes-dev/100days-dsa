class Solution {
public:
    int minAddToMakeValid(string s) {

       int  balance = 0;// check  karnya  sathi  ki  kuthe kami jast brackets houn  rahile 
       int ans =0;

       for(char ch: s){

            if(ch == '('){
                balance++;// opening brackets bhetlaa ++ kart jaye
            }
            else{
                // hee ahe  closing  brackets sathi
                if(balance > 0){
                    balance--;// check kaun kela kadhi  opening brackets ch  nastil  aplyakade tr mg o/p chudel
                }
                else{
                    //no opening brackets avilabel 
                    ans++;
                }
            }
       }
        ans += balance;// means ekde jevde bhi  opening brackets closing bracets lagle 2ghancha  balence anya  sathi  te apla  ans  ahe samhjla

        return ans;
    }
};