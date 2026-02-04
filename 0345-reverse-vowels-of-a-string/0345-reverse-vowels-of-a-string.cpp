class Solution {
public:
    bool isVowel(char ch){
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'; 
    }
    string reverseVowels( string& s) {
      
      int start = 0, end = s.size()-1;
      
      while(start < end){
        if(isVowel(s[start]) && isVowel(s[end])){
            swap(s[start], s[end]);
            start++, end--;
        }
      else if(isVowel(s[start]) == 0){ // ye jo start hai vo Vowel nahi agge badenge
    start++; 
}
        else{ //vowel nahi piche ayinge smj gay biduu
            end--;
        }
      }
        return s;
    }
};