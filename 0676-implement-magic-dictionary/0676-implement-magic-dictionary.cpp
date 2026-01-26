class MagicDictionary {
private:
    unordered_set<string> dictionary_set;

public:
    vector<string> dict;

    MagicDictionary() {
    }

    void buildDict(vector<string> dictionary) {  
        dict = dictionary;
    }

    bool search(const string& searchWord) {
        
        for(string &w: dict){
            
            //rule 1: length must match means same size ke hone chiye wo dono
            if(w.length() != searchWord.length()) continue;

            int mismatch = 0;

            //rule 2: count mismatches
            for(int i=0; i<w.length(); i++){
                if(w[i] != searchWord[i]) mismatch++;
                if(mismatch >1)break;
            }

            //rule 3: exactly  one mistmatched allowed
            if(mismatch == 1) return true;
        }
        return false;

    }
};
