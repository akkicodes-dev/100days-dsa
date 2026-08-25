class Solution {
public:
    bool findEmptyCell(vector<vector<char>>& board, int & row, int & col){
        for(int i=0; i<9;i++){
            for(int j=0; j<9; j++){
                if(board[i][j] =='.'){
                    row =i, col=j;
                    return true;
                }
            }
        }
        return  false;// hamara best case kya hoga sara fill  hogyahai  done and dusted

    }

    bool isSafe(vector<vector<char>>& board, int & row, int & col, char num){
        // check at current row
        for(int j=0; j<9; j++){
            if(board[row][j] == num)
            {
                return  false;
            }
        }
        // check  at current col
        for(int i=0; i<9; i++){
              if(board[i][col] == num)
            {
                return  false;
            }
        }
        //let,s check  3 x 3 sub-box as well 
        int startRow = row -(row % 3);
        int startCol = col - (col % 3);
        for(int i =0; i<3; i++){
            for(int j = 0; j<3; j++){
                int r = i+ startRow;
                int c = j + startCol;
                if(board[r][c] == num){
                    return false;
                }
            }
        }
        return true;
    }
    bool solveSudokuHelper(vector<vector<char>>& board) {

        //need to write 1 case

        //1.find some empty  cell
        int row, col;
        if(!findEmptyCell(board, row, col)){
            return true;// sab bhar gaya cell  alls

        } 

        //.fill  that with  a sutaible number
        for(int i=1; i<=9; i++){
            char num = i + '0';//convert to  char
            if(isSafe(board, row, col, num)){
                board[row][col] = num;
                if(solveSudokuHelper(board)){
                    return true;
                }
                board[row][col]= '.';//backtrack
            }
        }

        //I was not able to  put any no form 1 to  9 at [ row, col] cell
        return false;

    }
    void solveSudoku(vector<vector<char>>& board) {
        solveSudokuHelper(board);
    }
};