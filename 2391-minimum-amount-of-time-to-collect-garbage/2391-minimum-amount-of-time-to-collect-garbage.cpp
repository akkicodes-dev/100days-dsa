class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        // 3 type ke truck hai P truck 
        int pickP =0;
        int lastHouseP =0;
        //G truck
        int pickG =0;
        int lastHouseG =0;
        //M truck
        int pickM =0;
        int lastHouseM =0;

        //eske badd apan start karte hai travel karna road pr
        for(int i=0; i<garbage.size();i++){
            //maine kisi  ek ghar pr truck lekar pohacgaya 
            string currHouseGarbage = garbage[i];
            for(int j=0; j<currHouseGarbage.size();j++){
                char garbageType = currHouseGarbage[j];
                if(garbageType == 'P'){
                    pickP++;
                    lastHouseP =i;
                }else if(garbageType == 'M'){
                    pickM++;
                    lastHouseM =i;
                }else if(garbageType == 'G'){
                    pickG++;
                    lastHouseG =i;
                }
            }
        }
        //ab mere passs  ha truck ka pick and lasthouse ka data present h
        //mhuje har truck travel time ka data nikalana hai 
        //travel time ka data nikalna ke liye house index ka data use hoga 
        int travelP =0;
        int travelM =0;
        int travelG =0;

        //lets find out the tarvel time for Truck p
        for(int i=0; i<lastHouseP;i++){
            travelP = travelP + travel[i];
        }

        //lets find out the tarvel time for Truck p
        for(int i=0; i<lastHouseM;i++){
            travelM = travelM + travel[i];
        }

        //lets find out the tarvel time for Truck G
        for(int i=0; i<lastHouseG;i++){
            travelG = travelG + travel[i];
        }
        int totalTime = (pickP + pickM + pickG) + (travelP + travelM + travelG);
        return totalTime;
    }
};
