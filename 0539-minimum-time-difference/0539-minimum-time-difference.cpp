class Solution {
public:
    int convertToMin(string &time){
        int hr = stoi(time.substr(0,2)); // stoi for string tho  integer and the substr use for substring 
        // yee kya kya return karega  hh 
        // substr(0,2) -> first 2 characters return karega (HH)
        // stoi -> us string ko integer me convert karega

        int min = stoi(time.substr(3,2));
         // yee kya kya return karega  mm
         // substr(3,2) -> minute wala part return karega (MM)
         // stoi -> usko integer bana dega

         //yaha pe ho input string di gaye 24 hours timeline ki usko ko maine minitues mai chnage kar liya hai
         return 60 * hr + min;

    }
    int findMinDifference(vector<string>& timePoints) {
        vector<int>mins;
        for(auto time:timePoints)
            mins.push_back(convertToMin(time));
            
            //kisi 2 elemetns ka hame diffrinace nikala  na hai to tarika haya 2 tarike hai
            //phela ek to hum 2 lopp chlaye aur har ek element ko  array ke sare elemnts compare karle 
            // aur dusra kya hai ki hum array ko sort karle aur 2 2 elemts ka diffince nikal ke aur compare karke minimum return karde
        sort(mins.begin(), mins.end());

        int ans = INT_MAX;// ye kya store karega minimum diff ke liye;
        // INT_MAX ka matlab hai sabse bada possible integer
        // taki jab hum min() kare to actual minimum aa sake

        //sare adjecent ke beach me ka minimum nikalo aur return kardo  
        for(int i=0; i<mins.size()-1;++i) // 🔥 FIX: start from 0 instead of 1
            ans = min(ans, mins[i+1] - mins[i]);

        //last diff
        int lastdiff = mins[0] + 1440 - mins [mins.size()-1];
        // 1440 = total minutes in a day
        // ye circular difference hai (23:59 -> 00:00 type case)

        ans = min(ans, lastdiff);
        return ans;
        }
    
};
