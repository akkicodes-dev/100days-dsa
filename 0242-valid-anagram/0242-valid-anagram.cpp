class Solution {
public:
    bool isAnagram(const string& s, const string& t) {
     int arr[1000] = {0};
     //for starting s lets ad up counts 
     for(int i =0; i <s.length(); i++){
        char ch = s[i];
        arr[ch]++;
     }
     //for String t, decres the count 
     for(int i =0; i< t. length(); i++)
     {
        char ch = t[i];
        arr[ch]--;
     }

     //check all ocurence are 0 only 
     for(int i = 0; i<1000; i++){
        if(arr[i] != 0){
            return false;
        }
     }
     //agar main ya agyaa
     //iska matlab kahin par bhi 0 nahi mila array me 
     return true;
    }
};