class Solution {
public:
    void countArrangementHelper(vector<int>&v, int &n, int &ans, int currNum ){
      //base case   
      if(currNum == n+1){
        // for(int i =1; i<=n ; i++){
        //     cout<<v[i]<<" ";
        // }
        // cout<<endl;
        ++ans;
        return;
      }
      for(int i =1; i<= n; ++i){
        //dono  me  se konsi bhi satisfy  hoo  waha pe me  rakh saktaa huu cuurnumber 
        if(v[i] == 0 && (currNum % i == 0 || i % currNum == 0)){
            v[i] = currNum;
            countArrangementHelper(v, n, ans, currNum + 1 );
            v[i] = 0; // Backtracking  ka step  hai ye 
        }
      }
    }
    int countArrangement(int n) {
     vector<int>v (n +1);
     int ans = 0;
     countArrangementHelper(v, n, ans, 1);
     return  ans;
    }
};