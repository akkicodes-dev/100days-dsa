class Solution {
    void nextSmallerElement(vector<int>& heights,vector<int>& nextAns ){
        stack<int>st;
        st.push(-1);
        int  n  = heights.size();

        for(int i = n-1; i >= 0; i--){
            int element = heights[i];
            while(st.top() != -1 && heights[st.top()] >= element){
                st.pop();
            }
            //agar yaha tak pocha huu, iska matlab
            //k ya  toh  chotaa no stack top  pr h
            //ye fer -1 stack top pr hai
            nextAns.push_back(st.top());
            //current number ko  toh stack me  psuh  karna hai hii
            st.push(i);
        }

    }
    void prevSmallerElement(vector<int>& heights,vector<int>& prevAns ){
        stack<int>st;
        st.push(-1);
        int  n  = heights.size();

        for(int i = 0; i < n; i++){
            int element = heights[i];
            while(st.top() != -1 && heights[st.top()] >= element){
                st.pop();
            }
            //agar yaha tak pocha huu, iska matlab
            //k ya  toh  chotaa no stack top  pr h
            //ye fer -1 stack top pr hai
            prevAns.push_back(st.top());
            //current number ko  toh stack me  psuh  karna hai hii
            st.push(i);
        }

    }

    int largestRectangleArea(vector<int>& heights) {

        vector<int>nextAns;
        vector<int>prevAns;
        nextSmallerElement(heights, nextAns);
        reverse(nextAns.begin(), nextAns.end());

        //yehi maibhul jata huu
        //next ko  -1 index wala logic
        for(int i=0; i< nextAns.size(); i++){
            if(nextAns[i] == -1){
                nextAns[i] = nextAns.size();
            }
        }
        //corner case -> = wala main bhul  jata hu wo  nahi bhulna hai
        prevSmallerElement(heights, prevAns);

       int maxArea = INT_MIN;
        for(int i=0; i< nextAns.size(); i++){
            int width = nextAns[i] - prevAns[i] - 1;
            int height = heights[i];
            int currArea = width * height;
            maxArea = max(maxArea, currArea);
        }
        
         return maxArea;
    }   // FIX 1: ye closing } missing tha

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        // FIX 5: khali matrix ka guard
        if(matrix.empty() || matrix[0].empty()) return 0;

        vector<vector<int>> v;
        int n = matrix.size();       // FIX 2: row/col ki jagah n, m (neeche n, m hi use ho rahe the)
        int m = matrix[0].size();

        for(int i=0; i<n; ++i){
             vector<int>t;
            for(int j=0; j<m; ++j){
               t.push_back(matrix[i][j] - '0');
            }
            v.push_back(t);
        }
        int area = largestRectangleArea(v[0]);
        for(int i=1; i<n; ++i){
            for(int j =0; j<m ; ++j){
                //let,s update currrent row with preivious values;
                if(v[i][j]){
                    v[i][j] += v[i-1][j];   // FIX 3: = ki jagah += (height badhni chahiye)
                }
                else{
                    v[i][j] =0;
                }
            }
            area = max(area,  largestRectangleArea(v[i]));   // FIX 4: ; missing tha
        }
        return area;
    }
    
};