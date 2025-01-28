class Solution {
public:

    bool isValid(vector<vector<char>>& board,int val,int row,int col){
        for(int i=0; i<9; i++){
            if(board[row][i]-'0'==val)return false;
        }
        for(int i=0; i<9; i++){
            if(board[i][col]-'0'==val)return false;
        }
        
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(board[((row/3)*3)+i][((col/3)*3)+j]-'0'==val)return false;
            }
        }
        return true;
    }
  
    bool fun(vector<vector<char>>& board,int row,int col){
        if(row==9)return true;
        if(col==9){
            return fun(board,row+1,0);
        }
        if(board[row][col]!='.')
        {
            return fun(board,row,col+1);
        }
        for(int i=1; i<=9; i++){
            if(isValid(board,i,row,col)){
                board[row][col]='0'+i;
                if(fun(board,row,col+1))return true;
                board[row][col]='.';
                
            }
            
        }
            
        return false;
       

        
    }
 
    void solveSudoku(vector<vector<char>>& board) {
        fun(board,0,0);
    }
};