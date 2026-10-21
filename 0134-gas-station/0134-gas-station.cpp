class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start =0;
        int balance = 0;
        int deficit = 0;


        for(int i=0; i< gas.size(); i++){
            //ya to main agge ja saktaa huu , ya to main agg nahi  jaha saktaa
            if(balance + gas[i] < cost[i]){
                //deficit wala case hai - k maine aggea nahi  ja sakta, petrol kam padega

                deficit += balance + gas[i] - cost[i];
                start = i+1;
                balance = 0;
            }
            else{
                //agge ja sakta hu -> possiblity hai  petrorl extra hojayee mere pass
                  balance +=  gas[i] - cost[i];
            }
        }
        //ab loop atham hoo chuka hai
        if(balance + deficit >= 0){
           //iska matlab balance ne deficit ko fill kardiyaa yaa exceed kardiyaa
           return start;
        }else{
            //petrol kam padgaya, no anwser
            return -1;
        }
    }
};