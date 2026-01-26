class Solution {
public:
    string intToRoman(int num) {
       string romamSymbols[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

        int values[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};

        string ans ="";

        for(int i=0; i<13; i++){
            while(num >= values[i]){
                ans+=romamSymbols[i];//add karte jaynge
                num -= values[i];//values ko chota karte jaynge means 1000 aya 1994 ke liye to nikal diyaa aur bad me 900 aya to bhi nikal diyaa like that
            }
        }
        return ans;
    }
};