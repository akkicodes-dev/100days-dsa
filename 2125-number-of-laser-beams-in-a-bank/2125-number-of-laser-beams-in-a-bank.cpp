class Solution {
public:
    int countDevices(string& binary) {
       int c=0;
       for(auto b:binary){
        c += b - '0';//0me se 0 - karunga to 0 hi ayega or 1 me se 1 - minus karunga to  1 aygaaaa
        
       }
       return c;
    }

    int numberOfBeams(vector<string>& bank) {
        vector<int> devices;
        for (auto row : bank){
            devices.push_back(countDevices(row));
        }
        int beams =0;
        for(int i=0; i<devices.size()-1;++i){
            int j=i+1;
            while(j<devices.size()){
                beams += devices[i]*devices[j];
                if(devices[j]==0){
                    j++;
                }else{
                    break;
                }
            }
        }
return beams;
        
    }
};