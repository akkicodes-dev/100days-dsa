class Solution {
public:
    unordered_map<int,bool>leftHorizontalCheck;
    unordered_map<int,bool>upperDaigonalCheck;
    unordered_map<int,bool>lowerDaigonalCheck;
    bool isSafe(int row, int col,vector<string> &board ){
        int n = board.size();
        //i nedd to  check  the three 3  directions 
        //left  horizonatl 
        // for(int i =0; i<=col; i++){
        //     if(board[row][i] == 'Q'){
        //         //iska matlab same row  me queen rakhna safe nahi  hai  , attack  paka hoga
        //         return false;
        //     }
        // }
        // left upper  daigonal
        // int i = row-1;
        // int j = col-1;
        // while(i>= 0 && j >= 0){
        //   if(board[i][j] == 'Q'){
        //     return false;
        //   }
        //   i--;
        //   j--;
        // }
        //right upper  daigonal
        // int x = row+1;
        // int y = col-1;
        // while(x<n && y>= 0){
        //     if(board[x][y] == 'Q'){
        //         return false;
        //     }
        //     x++;
        //     y--;
        // }

        // leftHorizontal
        if(leftHorizontalCheck[row] == true){
            //iska matlb same row me pehle se koi queen baithi h
            return false;
        }
        //Upperdaigonal
        if(upperDaigonalCheck[row-col] == true){
            return false;
        }
        //LowerDaigonal
        if(lowerDaigonalCheck[row+col] == true){
            return false;
        }
        // there is no attack
        return true;
    }
    // void storeSolution(vector<vector<char>> &board, vector<vector<string>> &ans,int n){
    //     vector<string>temp;
    //     for(int row =0; row<n; row++){
    //         string output ="";
    //         for(int col=0; col<n; col++){
    //             char ch = board[row][col];
    //             output.push_back(ch);
    //         }
    //         //ek  string ready  hogyi'
    //         temp.push_back(output);
    //     }
    //     //temp ready  hogya 
    //     ans.push_back(temp);
        
    // }
    void solve(vector<string> &board,  vector<vector<string>> &ans, int n, int col ){
        //base case
        if(col >= n){
            //iska matlab 1 ans ready  hogaya hai mhuje kya karna hai store karna hai eske andar 
           // storeSolution(board, ans, n);
           ans.push_back(board);
            return;
        }
        // 1 case hum solve karnge baki  recursion  sambhal  lega
        //hum kya kr rahe the pehle queen ko  pehle colum ke har ek  rows pr rakh ke dekh rahe the 

        for(int row=0; row<n; row++){
            if(isSafe(row,col, board)){
             board[row][col] ='Q';
             leftHorizontalCheck[row] = true;
             upperDaigonalCheck[row-col] = true;
             lowerDaigonalCheck[row+col] = true;
            // baki  recursion sambhal  lega 
            solve(board, ans, n,col+1);
            //Backtracking
            board[row][col] ='.';
             leftHorizontalCheck[row] = false;
             upperDaigonalCheck[row-col] = false;
             lowerDaigonalCheck[row+col] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
          vector<vector<string>> ans;
          // n*n board initlized with '.'  kitini  row s n rows har row ke anar '.' hoga 
         // vector<vector<char>> board(n,vector<char>(n,'.'));
        //  vector<string>board;
        //  string temp = "";
        //  for(int i=0; i<n; i++){
        //     temp.push_back('.');
        //  }
        //  for(int  i=0; i<n; i++){
        //     board.push_back(temp);
        //  }
        vector<string> board(n, string(n,'.'));
          //starting with the colum = 0;
          int col = 0;

          solve(board, ans, n, col);
          return ans;
    }
};