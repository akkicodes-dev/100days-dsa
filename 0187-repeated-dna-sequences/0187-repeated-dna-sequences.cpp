
using namespace std;
class Solution {
public:
   std::vector<std::string> findRepeatedDnaSequences(std::string s) {
        vector<string> result;
        //If String is smaller than 10, we cannot form a single sequnce 
        if(s.length() < 10) return result;

        unordered_map<string,int> freq; //store the frequency of each 10 letter Substring 

        //Sliding window of 10 acroos the string 
        for(int i =0; i <= s.length()-10; i++){
            string sub = s.substr(i,10); // extract 10-letter substring 
            freq[sub]++;


            //we add this substring to  result only ONCE
            if(freq[sub] == 2){
                result.push_back(sub);
            }
        }
        return result;
    }
};
