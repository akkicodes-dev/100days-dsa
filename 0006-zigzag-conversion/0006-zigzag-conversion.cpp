class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;

        vector<string>zigzag(numRows);// 3 strings ka ek vector le lenge 

        int i =0, row =0;//i kya karega jp orignal strign de hai na uspe itrate kareega 
        bool direction = 1;// 1 means top to botttom

        while(true){
            if(direction){// agar apki direction 1 hai to hame kaise chalna hai upeer se chal na hai
             while(row <numRows && i < s.size()) {
                zigzag[row++].push_back(s[i++]);
                //ab hum rowwise chal rahe a ko push back kardege means row++ aur bad me 2 2 karke zigzag kardega 
             } 
             row = numRows -2;
            }else{
                while(row >= 0 && i<s.size()){
                    zigzag[row--].push_back(s[i++]);//anii ki bottom to top jaa rahe hai
                }
                row=1;
            }if(i >= s.size())break;
            direction = !direction; 

        }
        string ans ="";
        for(int i=0; i<zigzag.size(); i++){
            ans += zigzag[i];
            //cout<<zigzag[i]<<endl;
        }
        return ans;
    }
};