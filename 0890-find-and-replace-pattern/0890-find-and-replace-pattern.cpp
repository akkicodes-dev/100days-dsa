class Solution {
public:

    void normalizeString(string &str){
        // isss function ko me, main hr ek string ko Standard  format ko Normailze kardunga 
        //createMapping
        char start = 'a';
        unordered_map<char,char> mapping;
        for(int i=0; i<str.length(); i++){
            char ch = str[i];
            if(mapping.find(ch) == mapping.end()){
                //agar phele se mapping nahi hai then create a recoed 
                mapping[ch] = start;
                start++;
            }
        }
        //useMapping
        for(int i =0; i<str.length(); i++){
            char ch = str[i];
            char mappedCharacter = mapping[ch];
            //orignal character ko hi replace kr deta huu
            //if you want, then you can create a new normalised string
            //i am doing the changes in the orginal string only
            str[i] = mappedCharacter;  // eseme aor ek way hota hai konsa wala copy bana ke usme chnage karne wala 
            
        }
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
       
        vector<string> ans;
        normalizeString(pattern);

        for(int i=0; i<words.size(); i++){
            string currentWord = words[i];
            normalizeString(currentWord);
          // i just have to check the normalise currentword string with the normalised patterns   string
          if(pattern == currentWord){
            // include in ans 
            ans.push_back(words[i]);
          }
        }
        return ans;
    }
};